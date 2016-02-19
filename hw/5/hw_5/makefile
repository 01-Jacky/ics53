my_shell: my_shell.o
	gcc -std=gnu99 my_shell.o -o my_shell

my_shell.o: my_shell.c
	gcc my_shell.c -c

handle_signals: handle_signals.o
	gcc -std=gnu99 handle_signals.o -o handle_signals

handle_signals.o: handle_signals.c
	gcc handle_signals.c -c

clean:
	rm *.o handle_signals my_shell
