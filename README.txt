# Once you have written your version of the shell, write a design document that documents your design choices here.

My approach to completing this assignment was to read and understand the main.cpp as well the tsh.cpp.

parse_command takes in the command string as well as an empty command array. I use strtok to split the given command into tokens to be stored in array. 
I pass two parameters or requirements into strtok i.e end of line and empty space. I initially only used empty space but that resulted in errors in the exec_command. Hence, after consulting with TA Wenzhao, we realized that the line end '\n' was necessary in preventing errors.

I store the first value returned by strtok in commandTokens, then I continue to put the values returned by strtok into the commandTokens array in the while loop.At the end of the loop I set the last index of the cmdTokens array to NULL. This decision was also made the hard way after realizing that execvp() returned errors if the array was not null terminated.

In exec_command I fork a child process, if fork executes successfully, I execute the new program by parsing in the program name found in argv[0] and then the entire input arguments in argv.

I also wait make the parent process wait for the child process to complete execution by waiting in the else statement.

isQuit simply checks if the input command is quit then returns a boolean.I didn't have to use the null pointer at the end of the quit string because I had already taken care of that in parse command

