/*	Thomas Tang
	82502633
	ICS 53 
	HW5 part 3
	Signal Handling
*/
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
int inter = 0, qui = 0, sto = 0;
void handle_interrupt()
{
	putc('I', stdout);
	fflush(stdout);
}

void handle_quit()
{
	putc('Q', stdout);
	fflush(stdout);
}

void handle_stop()
{
	putc('S', stdout);
	fflush(stdout);
	if (sto++ == 2)
	{
		printf("Interrupt: %d\nSTOP: %d\nQuit: %d\n", inter, sto, qui);
		exit(0);
	}
	else
		raise(SIGSTOP);
}

void handle_signal(int signum, siginfo_t *si, void *context)
{
	switch(signum)
	{
		case SIGINT:
			inter++;
			handle_interrupt();
			break;
		case SIGQUIT:
			qui++;
			handle_quit();
			break;
		case SIGTSTP:
			handle_stop();
			break;
	}

}

void init_signal_handlers()
{
	struct sigaction sig_act;
	sig_act.sa_sigaction = handle_signal;
	sig_act.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &sig_act, NULL);
	sigaction(SIGQUIT, &sig_act, NULL);
	sigaction(SIGTSTP, &sig_act, NULL);
}

int main(int argc, char* argv[])
{
	init_signal_handlers();
	while(1)
	{
		printf("X");
		fflush(stdout);
		sleep(1);
	}
	return 0;
}
