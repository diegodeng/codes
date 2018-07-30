#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


void my_func(int sign_no) { 
    if (sign_no == SIGINT) { 
		printf("I have get SIGINT\n");

	} else if (sign_no == SIGQUIT) { 
		printf("I have get SIGQUIT\n");

	} 
} 


int main (int argc, char *argv[])
{
	struct sigaction action;
	printf("waiting for signal SIGINT or SIGQUIT ... \n");
	//settings args
	action.sa_handler = my_func;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	//register
	sigaction(SIGINT, &action, 0);
	sigaction(SIGQUIT, &action, 0);
	pause();
	exit(0);
}
