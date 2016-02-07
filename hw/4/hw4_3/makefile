my_copy: my_copy.o Timer.o
	gcc my_copy.o Timer.o -o my_copy
my_copy.o: my_copy.c Timer.h
	gcc -c my_copy.c
Timer.o: Timer.c Timer.h
	gcc -c Timer.c
clean:
	rm *.o my_copy output[123]


