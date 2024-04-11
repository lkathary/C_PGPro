.PHONY: test quadratic_equation.a

CC=gcc
CAR=ar
CRANLIB=ranlib

FLAGS=-Wall -Werror -Wextra -std=c11
# FLAGS=-Wall -Wextra -std=c11


OS = $(shell uname)

ifeq ($(OS), Linux)
	LINUX_LIBS=-lm
else
	LINUX_LIBS=
endif


TARGETDIR=./

FILE_TEST=test_lib
FILE_LIB=quadratic_equation

all: clean test

quadratic_equation.a: $(FILE_LIB).c
	$(CC) -c $(FLAGS) $(TARGETDIR)$(FILE_LIB).c
	$(CAR) rc $(FILE_LIB).a $(FILE_LIB).o
	$(CRANLIB) $(FILE_LIB).a

test: quadratic_equation.a
	$(CC) -c $(FLAGS) $(FILE_TEST).c
	$(CC) -o $(TARGETDIR)$(FILE_TEST) $(FLAGS) $(FILE_TEST).o -L. $(FILE_LIB).a $(LINUX_LIBS)
	-$(TARGETDIR)$(FILE_TEST)

cpp_check:
	cppcheck --enable=all --check-config --suppress=missingIncludeSystem --std=c11 *.c *.h


clang_check:
	-rm -rf .clang-format
	-ln -s ../linters/.clang-format
	clang-format -n *.c *.h


clang_fix:
	-rm -rf .clang-format
	-ln -s ../linters/.clang-format
	clang-format -i *.c *.h


leaks: test
ifeq ($(OS), Linux)
# 	Clear the log
	echo "Leaks check" > __leaks_check.out

	-CK_FORK=no valgrind --leak-check=full $(TARGETDIR)$(FILE_TEST) 2>> __leaks_check.out
	-grep -e leaks __leaks_check.out
	-grep -e error __leaks_check.out
else
	CK_FORK=no leaks -atExit -- $(TARGETDIR)$(FILE_TEST)
endif


clean:
	rm -rf  *.o *.a *.out
	rm -rf $(TARGETDIR)$(FILE_TEST)

	rm -rf CPPLINT.cfg cpplint.py
	rm -rf *.exe

# Frequent typos/synonyms
claen:	clean
clear:	clean
claer:	clean


rebuild:
	make clean
	make all
	rm -rf  *.o *.a
