TC_FOLDER = tests
EXT_IN = in
EXT_OUT = out
EXT_ANS = ans
EXECUTABLE_FILENAME = main
ALL_SRCS := $(wildcard *.cpp)
SRCS     := $(filter-out check.cpp, $(ALL_SRCS))

all: compile build-actual check

# Compile all cpp files except check.cpp
compile:
	g++ -std=c++17 -Wall -o $(EXECUTABLE_FILENAME) $(SRCS)

build-actual: $(TC_FOLDER)/*.$(EXT_IN) $(EXECUTABLE_FILENAME)
	for inputfile in $(TC_FOLDER)/*.$(EXT_IN); do \
		./$(EXECUTABLE_FILENAME) < $$inputfile; \
	done;

# Check
check: check.cpp
	g++ -std=c++17 -o check check.cpp
	./check

.PHONY: check