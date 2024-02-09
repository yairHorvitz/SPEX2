
.PHONY: clean all
  
all: my_graph my_mat.a

clean: 
	rm -f *.o *.a my_graph
	
my_graph.o: my_graph.c my_mat.h
	gcc -Wall -c my_graph.c -o my_graph.o

my_mat.o: my_mat.c my_mat.h
	gcc -Wall -c my_mat.c -o my_mat.o

my_mat.a: my_mat.o
	ar rcs my_mat.a my_mat.o

my_graph: my_graph.o my_mat.a
	gcc -Wall  my_graph.c my_mat.a -o my_graph
