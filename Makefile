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
	@g++ -std=c++17 -I"./src/headers" -Wall -o bin/main $(ALL_SRCS)

compile: ./bin/main

build-actual: $(TC_FOLDER)/*.$(EXT_IN) compile
	@mkdir -p tests/outputs
	@for inputfile in $(TC_FOLDER)/*.$(EXT_IN); do \
		./bin/main < $$inputfile; \
	done;

# Check
test-io: tests/engine/check.cpp ./bin/main
	@mkdir -p bin
	@g++ -std=c++17 -Wall -o ./bin/checker $<
	@./bin/checker

e2e: build-actual test-io

unit-test:	$(ALL_UNIT_TEST) $(SRCS_NO_MAIN)
	@mkdir -p bin
	@g++ -std=c++17 -Wall -o ./bin/test $^ -lgtest
	@./bin/test

install:
	@sudo apt install libgtest-dev

test: unit-test e2e

clean:
	@rm -rf bin/*

.PHONY: check e2e build-actual test-io clean
