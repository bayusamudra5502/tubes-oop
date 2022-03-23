TC_FOLDER = tests/test_case
EXT_IN = in
EXT_OUT = out
EXT_ANS = ans
ALL_SRCS = $(shell find src -type f -name "*.cpp")
ALL_UNIT_TEST = $(shell find ./tests/unit -type f -name "*.cpp")
SRCS_NO_MAIN  = $(filter-out src/main.cpp, $(ALL_SRCS))


all: compile build-actual e2e

# Compile all cpp files except check.cpp
./bin/main:
	@mkdir -p bin
	@g++ -std=c++17 -I"./src/headers" -Wall -O3 -o bin/main $(ALL_SRCS)

main-debugger:
	@mkdir -p bin
	@g++ -g -std=c++17 -I"./src/headers" -Wall -o bin/main $(ALL_SRCS)

compile: ./bin/main

build-actual: $(TC_FOLDER)/*.$(EXT_IN) compile
	@mkdir -p tests/outputs
	@for inputfile in $(TC_FOLDER)/*.$(EXT_IN); do \
		./bin/main < $$inputfile; \
	done;

# Check
test-io: tests/engine/check.cpp ./bin/main
	@mkdir -p bin
	@g++ -g -std=c++17 -Wall -o ./bin/checker $<
	@./bin/checker

e2e: build-actual test-io

unit-test-build: $(SRCS_NO_MAIN) $(ALL_UNIT_TEST)
	@mkdir -p bin
	@g++ -g -I"./src/headers" -std=c++17 -Wall -o ./bin/test $^ -lgtest -pthread

unit-test: unit-test-build
	@./bin/test

install:
	@sudo apt install libgtest-dev

test: unit-test e2e

clean:
	@rm -rf bin/*

run:
	@mkdir -p bin
	@g++ -g -std=c++17 -I"./src/headers" -Wall -o bin/main $(ALL_SRCS)
	@./bin/main

build: compile

.PHONY: check e2e build-actual test-io clean test build unit-test ./bin/main main-debugger
