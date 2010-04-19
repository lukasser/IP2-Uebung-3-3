cc = g++ 
all: uebung3_3

uebung3_3: array.o app.o binary_tree.o main.o
	$(cc) main.o app.o array.o binary_tree.o -Wall -o uebung3_3

main.o: main.cc
	$(cc) -c main.cc -Wall

array.o: array.cc
	$(cc) -c array.cc -Wall

app.o: app.cc
	$(cc) -c app.cc -Wall 

binary_tree.o: binary_tree.cc
	$(cc) -c binary_tree.cc -Wall 

clean:
	rm -r *.o uebung3_3
