a.out : intarray.o main.o
	gcc intarray.o main.o -o a.out

intarray.o : intarray.c intarray.h
	gcc -c intarray.c

main.o : main.c intarray.h
	gcc -c main.c

clean : 
	rm a.out
	rm *.o