Developed and tested on Ubuntu 18.04

to Run:
go to xv6-public
make clean
make qemu

after shell init there will be:

$S20 ls
.              1 1 512
..             1 1 512
README         2 2 2170
data.txt       2 3 1782
cat            2 4 13612
echo           2 5 12624
forktest       2 6 8052
grep           2 7 15488
init           2 8 13208
kill           2 9 12676
ln             2 10 12572
ls             2 11 14760
mkdir          2 12 12756
rm             2 13 12732
sh             2 14 24028
stressfs       2 15 13404
usertests      2 16 56336
wc             2 17 14152
zombie         2 18 12396
whatIf         2 19 14768
console        3 20 0


Here data.txt is the test data for whatIf;
nonohup is a built-in command of shell program.
whatIf is an application.

Run whatIf

$S20 whatIf data.txt