main: main.o
	@gcc main.o -o main

main.o: main.c
	@gcc main.c -c

run: main
	@./main

clean:
	@rm *.o main
