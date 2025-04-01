# The -I flag in g++ specifies the directory where the compiler should look for header files (#include statements) 
# in addition to the default system include directories.
# For example, -I$(SOURCE_DIR) tells the compiler to search for headers in the SOURCE_DIR directory,
# allowing us to include headers from that location without writing the full path.
# After linking the object files, the executable is created and in the next line it is executed by valgrind.




SOURCE_DIR = ../ex5v01
SOURCE_FILES = $(SOURCE_DIR)/Movie.cpp \
               $(SOURCE_DIR)/RecommendationSystem.cpp \
               $(SOURCE_DIR)/RecommendationSystemLoader.cpp \
               $(SOURCE_DIR)/User.cpp \
               $(SOURCE_DIR)/UsersLoader.cpp

OBJ_FILES = Movie.o \
            RecommendationSystem.o \
            RecommendationSystemLoader.o \
            User.o \
            UsersLoader.o

GCC_FLAGS = -Wall -Wvla -Wextra -Werror -g -std=c++20

VALGRIND_CMD = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes


.PHONY: clean all run_basic_tests run_advanced_tests run_compilation_tests

all: run_basic_tests run_advanced_tests

clean:
	rm -f *.o runTest* runTestComparison_* runPresubmit *.out


##############################################
########### compile basic files ###############
##############################################

run_basic_tests: runTest_1 runTest_2 runTest_3 runTest_4 runTestComparison_1 runTestComparison_2 runTestComparison_3 runTestComparison_4 runPresubmit

runTest_1: $(OBJ_FILES) ../ex5/Basic_tests/Test_1.cpp
	g++ $(GCC_FLAGS) $(OBJ_FILES) Basic_tests/Test_1.cpp -I$(SOURCE_DIR) -o runTest_1
	./runTest_1

runTest_2: $(OBJ_FILES) ../ex5/Basic_tests/Test_2.cpp
	g++ $(GCC_FLAGS) $(OBJ_FILES) Basic_tests/Test_2.cpp -I$(SOURCE_DIR) -o runTest_2
	./runTest_2

runTest_3: $(OBJ_FILES) ../ex5/Basic_tests/Test_3.cpp
	g++ $(GCC_FLAGS) $(OBJ_FILES) Basic_tests/Test_3.cpp -I$(SOURCE_DIR) -o runTest_3
	./runTest_3

runTest_4: $(OBJ_FILES) ../ex5/Basic_tests/Test_4.cpp
	g++ $(GCC_FLAGS) $(OBJ_FILES) Basic_tests/Test_4.cpp -I$(SOURCE_DIR) -o runTest_4
	./runTest_4

#run the program and save the output to a file
runTestComparison_1: $(OBJ_FILES) ../ex5/Basic_tests/TestComparison_1.cpp
	g++ $(GCC_FLAGS) $(OBJ_FILES) Basic_tests/TestComparison_1.cpp -I$(SOURCE_DIR) -o runTestComparison_1
	./runTestComparison_1 > test_1.out

#use diff to compare the output of the program to the expected output, if the files are identical, diff will not print anything
runTestComparison_2: $(OBJ_FILES) ../ex5/Basic_tests/TestComparison_2.cpp
	g++ $(GCC_FLAGS) $(OBJ_FILES) Basic_tests/TestComparison_2.cpp -I$(SOURCE_DIR) -o runTestComparison_2
	./runTestComparison_2 > test_2.out
	diff test_2.out Basic_tests/TestComparison_2.stdout

runTestComparison_3: $(OBJ_FILES) ../ex5/Basic_tests/TestComparison_3.cpp
	g++ $(GCC_FLAGS) $(OBJ_FILES) Basic_tests/TestComparison_3.cpp -I$(SOURCE_DIR) -o runTestComparison_3
	./runTestComparison_3

#run the program with valgrind to check for memory leaks
#instead of writing the valgrind command every time, we can define a variable for it
runTestComparison_4: $(OBJ_FILES) ../ex5/Basic_tests/TestComparison_4.cpp
	g++ $(GCC_FLAGS) $(OBJ_FILES) Basic_tests/TestComparison_4.cpp -I$(SOURCE_DIR) -o runTestComparison_4
	$(VALGRIND_CMD) ./runTestComparison_4


runPresubmit: $(OBJ_FILES) ../ex5/Basic_tests/presubmit.cpp
	g++ $(GCC_FLAGS) $(OBJ_FILES) Basic_tests/presubmit.cpp -I$(SOURCE_DIR) -o runPresubmit
	$(VALGRIND_CMD) ./runPresubmit


##############################################
########### compile advanced files ###########
##############################################

run_advanced_tests: runTestComparison_5 runTestComparison_6 runTestComparison_7 runTestComparison_8 runTestComparison_9 runTestComparison_10 \
               runTestComparison_11 runTestComparison_12 runTestComparison_13 runTestComparison_14 runTestComparison_15 runTestComparison_16 \
               runTestComparison_17 runTestComparison_18 runTestComparison_19

runTestComparison_5: $(OBJ_FILES) ../ex5/Advanced_tests/TestComparison_5.cpp
	g++ $(GCC_FLAGS) $(OBJ_FILES) Advanced_tests/TestComparison_5.cpp -I$(SOURCE_DIR) -o runTestComparison_5
	./runTestComparison_5

runTestComparison_6: $(OBJ_FILES) ../ex5/Advanced_tests/TestComparison_6.cpp
	g++ $(GCC_FLAGS) $(OBJ_FILES) Advanced_tests/TestComparison_6.cpp -I$(SOURCE_DIR) -o runTestComparison_6
	./runTestComparison_6

runTestComparison_7: $(OBJ_FILES) ../ex5/Advanced_tests/TestComparison_7.cpp
	g++ $(GCC_FLAGS) $(OBJ_FILES) Advanced_tests/TestComparison_7.cpp -I$(SOURCE_DIR) -o runTestComparison_7
	./runTestComparison_7

runTestComparison_8: $(OBJ_FILES) ../ex5/Advanced_tests/TestComparison_8.cpp
	g++ $(GCC_FLAGS) $(OBJ_FILES) Advanced_tests/TestComparison_8.cpp -I$(SOURCE_DIR) -o runTestComparison_8
	./runTestComparison_8 > test_8.out
	diff test_8.out Advanced_tests/TestComparison_8.stdout

runTestComparison_9: $(OBJ_FILES) ../ex5/Advanced_tests/TestComparison_9.cpp
	g++ $(GCC_FLAGS) $(OBJ_FILES) Advanced_tests/TestComparison_9.cpp -I$(SOURCE_DIR) -o runTestComparison_9
	./runTestComparison_9 > test_9.out
	diff test_9.out Advanced_tests/TestComparison_9.stdout

runTestComparison_10: $(OBJ_FILES) ../ex5/Advanced_tests/TestComparison_10.cpp
	g++ $(GCC_FLAGS) $(OBJ_FILES) Advanced_tests/TestComparison_10.cpp -I$(SOURCE_DIR) -o runTestComparison_10
	./runTestComparison_10 > test_10.out
	diff test_10.out Advanced_tests/TestComparison_10.stdout

runTestComparison_11: $(OBJ_FILES) ../ex5/Advanced_tests/TestComparison_11.cpp
	g++ $(GCC_FLAGS) $(OBJ_FILES) Advanced_tests/TestComparison_11.cpp -I$(SOURCE_DIR) -o runTestComparison_11
	./runTestComparison_11

runTestComparison_12: $(OBJ_FILES) ../ex5/Advanced_tests/TestComparison_12.cpp
	g++ $(GCC_FLAGS) $(OBJ_FILES) Advanced_tests/TestComparison_12.cpp -I$(SOURCE_DIR) -o runTestComparison_12
	./runTestComparison_12 > test_12.out
	diff test_12.out Advanced_tests/TestComparison_12.stdout

runTestComparison_13: $(OBJ_FILES) ../ex5/Advanced_tests/TestComparison_13.cpp
	g++ $(GCC_FLAGS) $(OBJ_FILES) Advanced_tests/TestComparison_13.cpp -I$(SOURCE_DIR) -o runTestComparison_13
	./runTestComparison_13 > test_13.out
	diff test_13.out Advanced_tests/TestComparison_13.stdout

runTestComparison_14: $(OBJ_FILES) ../ex5/Advanced_tests/TestComparison_14.cpp
	g++ $(GCC_FLAGS) $(OBJ_FILES) Advanced_tests/TestComparison_14.cpp -I$(SOURCE_DIR) -o runTestComparison_14
	$(VALGRIND_CMD) ./runTestComparison_14

runTestComparison_15: $(OBJ_FILES) ../ex5/Advanced_tests/TestComparison_15.cpp
	g++ $(GCC_FLAGS) $(OBJ_FILES) Advanced_tests/TestComparison_15.cpp -I$(SOURCE_DIR) -o runTestComparison_15
	./runTestComparison_15

runTestComparison_16: $(OBJ_FILES) ../ex5/Advanced_tests/TestComparison_16.cpp
	g++ $(GCC_FLAGS) $(OBJ_FILES) Advanced_tests/TestComparison_16.cpp -I$(SOURCE_DIR) -o runTestComparison_16
	./runTestComparison_16

runTestComparison_17: $(OBJ_FILES) ../ex5/Advanced_tests/TestComparison_17.cpp
	g++ $(GCC_FLAGS) $(OBJ_FILES) Advanced_tests/TestComparison_17.cpp -I$(SOURCE_DIR) -o runTestComparison_17
	./runTestComparison_17

runTestComparison_18: $(OBJ_FILES) ../ex5/Advanced_tests/TestComparison_18.cpp
	g++ $(GCC_FLAGS) $(OBJ_FILES) Advanced_tests/TestComparison_18.cpp -I$(SOURCE_DIR) -o runTestComparison_18
	./runTestComparison_18

runTestComparison_19: $(OBJ_FILES) ../ex5/Advanced_tests/TestComparison_19.cpp
	g++ $(GCC_FLAGS) $(OBJ_FILES) Advanced_tests/TestComparison_19.cpp -I$(SOURCE_DIR) -o runTestComparison_19
	./runTestComparison_19



##############################################
########### compile source files #############
##############################################


Movie.o: $(SOURCE_DIR)/Movie.cpp $(SOURCE_DIR)/Movie.h
	g++ $(GCC_FLAGS) -c -I$(SOURCE_DIR) $(SOURCE_DIR)/Movie.cpp -o Movie.o

User.o: $(SOURCE_DIR)/User.cpp $(SOURCE_DIR)/User.h $(SOURCE_DIR)/RecommendationSystem.h $(SOURCE_DIR)/Movie.h
	g++ $(GCC_FLAGS) -c -I$(SOURCE_DIR) $(SOURCE_DIR)/User.cpp -o User.o

RecommendationSystem.o: $(SOURCE_DIR)/RecommendationSystem.cpp $(SOURCE_DIR)/RecommendationSystem.h  $(SOURCE_DIR)/User.h
	g++ $(GCC_FLAGS) -c -I$(SOURCE_DIR) $(SOURCE_DIR)/RecommendationSystem.cpp -o RecommendationSystem.o

RecommendationSystemLoader.o: $(SOURCE_DIR)/RecommendationSystemLoader.cpp $(SOURCE_DIR)/RecommendationSystemLoader.h $(SOURCE_DIR)/RecommendationSystem.h
	g++ $(GCC_FLAGS) -c -I$(SOURCE_DIR) $(SOURCE_DIR)/RecommendationSystemLoader.cpp -o RecommendationSystemLoader.o

UsersLoader.o: $(SOURCE_DIR)/UsersLoader.cpp $(SOURCE_DIR)/UsersLoader.h $(SOURCE_DIR)/User.h
	g++ $(GCC_FLAGS) -c -I$(SOURCE_DIR) $(SOURCE_DIR)/UsersLoader.cpp -o UsersLoader.o