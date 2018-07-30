#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


void my_func(int sign_no) { 
    if (sign_no == SIGINT) { 
		printf("I have get SIGINT\n");

	} else if (sign_no == SIGQUIT) { 
		printf("I have get SIGQUIT\n");

	}
	return ; 
} 


int main (int argc, char *argv[])
{
    printf("waiting for signal SIGINT or SIGQUIT ... \n");
	signal(SIGINT, my_func);
	signal(SIGQUIT, my_func);
	pause();
	exit(0);
}
