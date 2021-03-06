all : stats intarray
	echo "Compilation terminee"

stats : stats.o intarray.o tools.o
	gcc stats.c intarray.o tools.o -o stats

intarray : intarray.o main.o jstr.o tools.o 
	gcc intarray.o main.o jstr.o tools.o -o intarray

intarray.o : intarray.c intarray.h tools.h
	gcc -c intarray.c

jstr.o : jstr.c jstr.h tools.h intarray.h
	gcc -c jstr.c 

main.o : main.c intarray.h jstr.h tools.h
	gcc -c main.c

tools.o : tools.c tools.h
	gcc -c tools.c

stats.o : stats.c intarray.h tools.h
	gcc -c stats.c
clean : 
	rm intarray
	rm stats
	rm *.o