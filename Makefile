CC=gcc
AR=ar
OBJECT_MAIN=my_graph.o
OBJECT_MAIND=my_knapsack.o
OBJECT_LIB=my_mat.o
FLAGS= -Wall -g

all: my_graph my_mat.a my_knapsack
graph: my_graph my_mat.a
knap: my_knapsack

my_graph: $(OBJECT_MAIN) my_mat.a
	$(CC) $(FLAGS) -o my_graph $(OBJECT_MAIN) my_mat.a
my_knapsack: $(OBJECT_MAIND)
	$(CC) $(FLAGS) -o my_knapsack $(OBJECT_MAIND)
my_mat.a: $(OBJECT_LIB)
	$(AR) -rcs my_mat.a $(OBJECT_LIB)


my_graph.o: my_graph.c my_mat.h
	$(CC) $(FLAGS) -c my_graph.c
my_knapsack.o: my_knapsack.c
	$(CC) $(FLAGS) -c my_knapsack.c
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

.PHONY: clean all

clean:
	rm -f *.o *.a   my_graph my_knapsack