#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main() {
    int i;
    for (i = 0; i < 3; i++) {
        fork();
        printf("i=%d\n", i);
    }
    return 0;
}

/*#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main()
{ 
	int pid;
	printf("I’m the original process with PID %d and PPID %d.\n",getpid(), getppid());
	pid = fork(); 
	if (pid>0) 
	{
		printf("I’m the parent process with PID %d and PPID %d. \n",getpid(), getppid());
		printf("My child’s PID is %d \n", pid );
	}
	else 
	{
		printf("I’m the child process with PID %d and PPID %d. \n",getpid(), getppid());
	}
	printf("PID %d terminates. \n", getpid());
}*/
