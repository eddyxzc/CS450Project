# CS450Project
 Operation Systerm Project about XV6


PA1:
1.Add a program execution command called “nonohup”If the user types nonohup prog args, when the user hits return, the prompt appears in a new line and the program prog and its arguments args will execute in the background.
2.write a program called whatIf. If invoked without an argument, it will take input from what you type into the keyboard until you hit a “ctl+d.” If you give it a filename, it takes its input from that file. As soon as whatIf is invoked, it forks a child process. Then both the parent and the child will read from the same input, one line at a time. 

PA2:
Implementing the alsoNice(int n) system call that will increase the time slice allocated to the program that calls it by n times.


PA3: Part1,Test valgrind with memory leak program.
     Part2, System calls on memory management, Develop the myV2p() system call on xv6 returns the corresponding physical address or the appropriate error condition.
     Develop the hasPages()system call on xv6. It takes a process id as argument and
     will display the different kinds of user pages that have been allocated to the process
     or returns an error code.
     
PA4：
   1, Add an O_EXTENT flag to the open() system call that will create an extent based
      file.
   2, Modify the fstat() system call such that it will dump information about each
    extent of an extent based file in addition to file size, etc
   3, Add the new system call lseek() which takes a file descriptor and an integer
     offset as arguments. It sets the current offset of the open file to the specified
     offset upon success.
