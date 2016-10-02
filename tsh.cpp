#include "tsh.h"
#include <signal.h>


using namespace std;

void simple_shell::parse_command(char *cmd, char **cmdTokens) {
	// TODO: tokenize the command string into arguments
	int i =0;
	  char * t= strtok(cmd,"\n ");
	  while( t!= NULL)
	  {
	  	cmdTokens[i] = t;
	  	t =strtok(NULL,"\n ");
	  	i++;
	  }
		cmdTokens[i] =NULL;		}

void simple_shell::exec_command(char **argv)
{
	// TODO: fork a child process to execute the command. 
	// parent process should wait for the child process to complete and reap it
	// should be easy peezy here
		int rc =fork();
	   if (rc < 0) { // fork failed; exit
                 fprintf(stderr, "fork failed\n");
                 exit(1);
         } else if (rc == 0) { // child (new process)
                 execvp(argv[0],argv);
                
         } else { // parent goes down this path (main)
                 int wc = wait(NULL);
                 //kill(getpid(),SIGKILL);
         }
}


bool simple_shell::isQuit(char *cmd){
	// TODO: check for the command "quit" that terminates the shell
	   if (strcmp(cmd, "quit") == 0){
	   		return true;
	   	}
	   	else
	   	{
	   		return false;
	   	}
	  
	}
	