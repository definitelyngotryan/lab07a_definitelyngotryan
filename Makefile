# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++11

# Source files
SRC = WordCount.cpp tddFuncs.cpp Lab07Test.cpp #lab07Test01.cpp lab07Test02.cpp
OBJ = $(SRC:.cpp=.o)

# Output executables
TARGETS = Lab07Test #lab07Test01 lab07Test02

# Default rule
all: $(TARGETS)

# Linking rules for each test file
Lab07Test: WordCount.o tddFuncs.o Lab07Test.o
	$(CXX) $(CXXFLAGS) -o Lab07Test WordCount.o tddFuncs.o Lab07Test.o

############## INCASE WE NEED MORE THAN 1 TEST FILE (CODE FROM 6A MAKE FILE EDITED WITH "07" instead of "06") #####################
# lab07Test01: WordCount.o tddFuncs.o lab07Test01.o
#   $(CXX) $(CXXFLAGS) -o lab07Test01 WordCount.o tddFuncs.o lab07Test01.o

# lab07Test02: WordCount.o tddFuncs.o lab07Test02.o
#   $(CXX) $(CXXFLAGS) -o lab07Test02 WordCount.o tddFuncs.o lab07Test02.o

# Compilation rule for .cpp files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean .o files
clean:
	rm -f $(OBJ) $(TARGETS)