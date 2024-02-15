CC=gcc
AR=ar
OBJECT_MAIN=Main.o
OBJECT_LIB=StrList.o
FLAGS= -Wall -g

all: StrList StrList.a

StrList: $(OBJECT_MAIN) StrList.a
	$(CC) $(FLAGS) -o StrList $(OBJECT_MAIN) StrList.a
StrList.a: $(OBJECT_LIB)
	$(AR) -rcs StrList.a $(OBJECT_LIB)


StrList.o: StrList.c StrList.h
	$(CC) $(FLAGS) -c StrList.c
Main.o: Main.c StrList.h
	$(CC) $(FLAGS) -c Main.c

.PHONY: clean all

clean:
	rm -f *.o *.a   StrList