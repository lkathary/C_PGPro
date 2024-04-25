.PHONY: test check quadratic_equation.a

CC=gcc
CXX=g++
CAR=ar
CRANLIB=ranlib

FLAGS_C=-Wall -Werror -Wextra -std=c11
FLAGS_CPP=-Wall -Werror -Wextra --std=c++17

OS = $(shell uname)

ifeq ($(OS), Linux)
	LINUX_LIBS=-lm
else
	LINUX_LIBS=
endif

GTEST=-lgtest_main -lgtest -lpthread
LCHECK=`pkg-config --cflags --libs check`


TARGETDIR=./

FILE_TEST=test_lib
FILE_LIB=quadratic_equation
INSTALL_DIR=../quadratic_equation

all: clean check

quadratic_equation.a:
	$(CC) -c $(FLAGS_C) $(FILE_LIB).c
	$(CAR) rc $(FILE_LIB).a $(FILE_LIB).o
	$(CRANLIB) $(FILE_LIB).a

test: quadratic_equation.a
	$(CC) -c $(FLAGS_C) $(FILE_TEST).c
	$(CC) -o $(FILE_TEST) $(FLAGS) $(FILE_TEST).o -L. $(FILE_LIB).a $(LCHECK) $(LINUX_LIBS)
	-$(TARGETDIR)$(FILE_TEST)

check: quadratic_equation.a
	$(CXX) -c $(FLAGS_CPP) $(FILE_TEST).cpp $(GTEST)
	$(CXX) -o $(FILE_TEST) $(FLAGS) $(FILE_TEST).o $(FILE_LIB).a -L $(GTEST)
	-$(TARGETDIR)$(FILE_TEST)


cppcheck:
	cppcheck --enable=all --check-config --suppress=missingIncludeSystem --std=c11 *.c *.h
	cppcheck --enable=all --check-config --suppress=missingIncludeSystem --std=c++17 --language=c++ *.cpp *.h

clang:
	-rm -rf .clang-format
	-ln -s ../linters/.clang-format
	clang-format -n *.c *.h *.cpp

clang_fix:
	-rm -rf .clang-format
	-ln -s ../linters/.clang-format
	clang-format -i *.c *.h *.cpp


leaks: check
ifeq ($(OS), Linux)

	echo "Leaks check" > __leaks_check.out

	-CK_FORK=no valgrind --leak-check=full $(TARGETDIR)$(FILE_TEST) 2>> __leaks_check.out
	-grep -e leaks __leaks_check.out
	-grep -e error __leaks_check.out
else
	CK_FORK=no leaks -atExit -- $(TARGETDIR)$(FILE_TEST)
endif

arhive: clean
	-rm	$(INSTALL_DIR).tar
	rm -rf $(INSTALL_DIR)
	mkdir $(INSTALL_DIR)
	cp -R ../src $(INSTALL_DIR)
	cp -R ../linters $(INSTALL_DIR)
	cp ../*.* ../.gitignore $(INSTALL_DIR)
	tar -cvf $(INSTALL_DIR).tar $(INSTALL_DIR)
	rm -rf $(INSTALL_DIR)

clean:
	rm -rf  *.o *.a *.out
	rm -rf $(TARGETDIR)$(FILE_TEST)
	-rm -rf .clang-format

rebuild:
	make clean
	make all
	rm -rf  *.o *.a
