CC=gcc
CAR=ar
CRANLIB=ranlib

OS = $(shell uname)

ifeq ($(OS), Linux)
	LINUX_LIBS=-lsubunit -lrt -lpthread -lm
else
	LINUX_LIBS=
endif

# FLAGS=-Wall -Werror -Wextra -std=c11
FLAGS=-Wall -Wextra -std=c11
# FLAGS=-Wall -Wextra -g
# FLAGS+= -g


# CHECKLIB=-I../../.brew/include
# CHECKLIB=-I../../../.brew/include -L../../../.brew/Cellar/check/0.15.2/lib
LCHECK=`pkg-config --cflags --libs check`
CHECKLIB1=-I../../.brew/include


GCOV=-fprofile-arcs -ftest-coverage

TARGETDIR=./
REPORTDIR=gcovdir/

FILE1=test_lib
FILE_LIB=s21_matrix

all: clean s21_matrix.a

s21_matrix.a: $(FILE_LIB).c
	$(CC) -c $(FLAGS) $(TARGETDIR)$(FILE_LIB).c
	$(CAR) rc $(FILE_LIB).a $(FILE_LIB).o
	$(CRANLIB) $(FILE_LIB).a

s21_matrix.a.gcov: $(FILE_LIB).c
	$(CC) -c $(FLAGS) -o $(FILE_LIB)_gcov.o $(TARGETDIR)$(FILE_LIB).c $(GCOV)
	$(CAR) rc $(FILE_LIB)_gcov.a $(FILE_LIB)_gcov.o
	$(CRANLIB) $(FILE_LIB)_gcov.a

test: s21_matrix.a
	$(CC) -c $(FLAGS) $(FILE1).c $(CHECKLIB1)
	$(CC) -o $(TARGETDIR)$(FILE1) $(FLAGS) $(FILE1).o -L. $(FILE_LIB).a $(CHECKLIB) $(LCHECK)
	-$(TARGETDIR)$(FILE1)

check:
	-rm -rf cpplint.py CPPLINT.cfg
	-ln -s ../materials/linters/cpplint.py
	-ln -s ../materials/linters/CPPLINT.cfg
	python3 cpplint.py --extensions=c *.c *.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h


gcov_report:
	rm -rf  *.o *.a *.out
	rm -rf $(FILE1).gcno
	rm -rf $(FILE1).gcda
	rm -rf $(FILE1).gcov
	rm -rf $(FILE1).info
	rm -rf $(REPORTDIR)

	$(CC) -c $(FLAGS) $(FILE1).c $(GCOV) $(CHECKLIB1)

	make s21_matrix.a.gcov
	$(CC) -o $(TARGETDIR)$(FILE1) $(FLAGS) $(FILE1).o $(GCOV) -L. $(FILE_LIB)_gcov.a $(CHECKLIB) $(LCHECK)

	-$(TARGETDIR)$(FILE1)
	gcov $(FILE1).c
	lcov -b ./ -d ./ --gcov-tool /usr/bin/gcov -c -o $(FILE_LIB).info
	genhtml -o $(REPORTDIR) -t "Unit-tests of $(FILE_LIB)" $(FILE_LIB).info
ifeq ($(OS), Linux)
	xdg-open $(REPORTDIR)index.html
else
	open $(REPORTDIR)index.html
endif

leaks: test
ifeq ($(OS), Linux)
# 	Clear the log
	echo "Leaks check" > __leaks_check.out

	-CK_FORK=no valgrind --tool=memcheck ./test_lib 2>> __leaks_check.out
	-grep -e leaks __leaks_check.out
	-grep -e error __leaks_check.out
else
	CK_FORK=no leaks -atExit -- ./test_lib
endif



clean:
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.gcov
	rm -rf *.info
	rm -rf $(REPORTDIR)

	rm -rf  *.o *.a *.out
	rm -rf $(TARGETDIR)$(FILE1)

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