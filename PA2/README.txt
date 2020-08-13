To Run:
in xv6-public, 
..make clean
..make qemu


Run foo in xv6 shell, then type Ctrl+P to run processdump.
This will print all the processes and a process running history,
 where you can find all the processes in last 32 time slices.
foo is a long loop, it creat three processes with different nice value.
foo won't stop,you have to close the qemu.

Run bar in xv6 shell to test turnaround time and response time.
bar is a short loop will finish in few seconds.
..bar  -------three processes A B C all have only one slice.
..bar 5 3 1    process A has 5 slices while B has 3, C has 1
