# Project2 : ./shell
# Group Member: Kyeongtak Han, Dongha Kang, Vedaant Sukhtankar
# x500: Han00127, kangx637, sukht002
# File list : du.c grep.c shell.c (util.c util.h) testfile.txt

#information:
This program creates and runs our own shell command. This program includes the files shell.c
(runs the shell, combines du.c grep.c cd function to run in the program), du.c (du function), grep.c (grep function).
To run the shell, type "make all" then execite "./shell". Also, to re-run type "make clean", "make all"
and "./shell".

# Contribution:
Kyeongtak Han mostly outlined the whole program in shell command. Vedaant Sukhtankar worked on
du.c, and redirection. Dongha Kang worked on pipe, and debugging. Group members contributed on
this project equally.

# Brief overview (du.c)
1. findSize - Simply finding the size of the file by using stat
2. d_u - By using recursion, this function goes through all the files and sums up the size of the file.
3. main - main just calls the previous functions and print out the total size in the folder.
          if there is no argument, it prints out the total size of current file.

# Brief overview (grep.c)
main - If there is one argument after ./grep call, Everytime the user type something in the shell, it checks whether or not
       user's command contains the argument. If so, it prints out one more time on the next line; if not, it goes to next line
       without printing any objects. However, if there are two arguments after ./grep call, the function looks for the word (first argument)
       in the file (second argument) at each line. It prints out every line that contains the word (first argument) in the file (second argument)
       on the shell.

# Brief overview (shell.c):
1. cd - Same as cd in terminal. checked whether or not it was valid Directory and returned the current working directory as character array to print out in the terminal.
2. redirect - Redirected file information to different file (or new file). a > b will put whatever was in 'a' to 'b' and make them equivalent.
3. redirect_append - Similar to redirect function but append. a >> b will append a's data to b.
4. is_redirection - Check whether or not the string command contains redirection or not.
5. first_index_redirection - This function is for multiple redirection. If there are multiple redirections, it only do the first redirection in the argument.
6. make_command - Get the command value in the terminal's first command and take the new char* to use them easier in exec function.
7. main - Inside the infinite while loop, it checks if it has pipe or not. Each contains extra child process and for Piped function contains another process inside the parent process.
          str_ptr and str_ptr contain character array that contains the arguments that was parsed.
          cmd and cmd2 contain 'get the command type' and return as ./ format to put in args and args2
          args and args2 are character array that put directly to execp function.



# Test cases used: (in terminal)
 1. ./du
 2. ./du ..
 3. ./grep grep testfile.txt
 4. ./grep rwx testfile.txt

# Test cases used: ./shell
 1. ls -l
 2. top
 3. cat du.c
 4. cd ..
 5. ls -l > outfile.txt
 6. du .. >> outfile.txt
 7. cat outfile.txt | grep grep
 8. cat testfile.txt | grep rwx > outfile.txt
 9. cd .. | grep h
 10. cat outfile.txt > out.txt > out1.txt >> out2.txt
 11. echo hello | echo bye

#Examples:

kangx637@csel-kh4250-43:/home/kangx637/4061/Project2 $ ./shell
[4061-shell] /home/kangx637/4061/Project2 $ ls -l

1.
[4061-shell] /home/kangx637/4061/Project2 $ ls -l
total 211
drwxr-xr-x 2 kangx637 CSEL-student      5 Mar  9 13:35 4061_project_2
-rw------- 1 kangx637 CSEL-student   2151 Mar 11 23:08 data.txt
-rwx------ 1 kangx637 CSEL-student   8720 Mar 12 05:05 du
-rw------- 1 kangx637 CSEL-student   1293 Mar 10 20:41 du.c
-rwx------ 1 kangx637 CSEL-student  12944 Mar 12 05:05 grep
-rw-r--r-- 1 kangx637 CSEL-student   1342 Mar 10 23:01 grep.c
drwxr-xr-x 3 kangx637 CSEL-student      4 Feb 20 22:50 __MACOSX
-rw------- 1 kangx637 CSEL-student    227 Mar 11 20:00 Makefile
-rw------- 1 kangx637 CSEL-student   2022 Mar 12 05:02 outfile.txt
-rw-r--r-- 1 kangx637 CSEL-student 107782 Feb 20 22:23 project2.pdf
-rw------- 1 kangx637 CSEL-student   8088 Mar 12 05:01 README
-rwx------ 1 kangx637 CSEL-student  17928 Mar 12 05:05 shell
-rw------- 1 kangx637 CSEL-student  11314 Mar 11 20:53 shell2.c
-rw------- 1 kangx637 CSEL-student  11222 Mar 12 05:04 shell.c
-rw-r--r-- 1 kangx637 CSEL-student   5236 Mar 10 18:13 shell.c~
-rwx------ 1 kangx637 CSEL-student  13944 Feb 20 18:31 sol
-rw------- 1 kangx637 CSEL-student   1135 Mar 10 16:00 test
-rw------- 1 kangx637 CSEL-student   2031 Mar 12 04:44 testfile.txt
-rw------- 1 kangx637 CSEL-student    988 Mar 10 17:19 util.c
-rw------- 1 kangx637 CSEL-student    564 Feb 20 19:09 util.h
-rw------- 1 kangx637 CSEL-student   2704 Mar 12 05:05 util.o


2. top
[4061-shell] /home/kangx637/4061/Project2 $ top

top - 05:07:55 up  3:22,  1 user,  load average: 1.98, 1.85, 1.67
Tasks: 317 total,   1 running, 251 sleeping,   0 stopped,   0 zombie
%Cpu(s):  3.7 us,  9.8 sy,  0.0 ni, 86.4 id,  0.0 wa,  0.0 hi,  0.1 si,  0.0 st
KiB Mem : 32846740 total, 27490944 free,  2820320 used,  2535476 buff/cache
KiB Swap:  7811068 total,  7811068 free,        0 used. 28813548 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU %MEM     TIME+ COMMAND
 5529 kangx637  20   0    4520   1184   1084 S  11.9  0.0  21:57.38 shell
 2264 kangx637  20   0 4025228 220472  75036 S   2.5  0.7   3:58.06 gnome-shell
...


3. cat du.c
[4061-shell] /home/kangx637/4061/Project2 $ cat du.c
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

long int findSize(char *file)//find the size of the file
{
  struct stat s;
  if(stat(file,&s)<0){
    return -1;//get stat for file
  }else{
    return (s.st_size);//return the size of the file
  }
}
....


4. cd ..
[4061-shell] /home/kangx637/4061/Project2 $ cd ..
[4061-shell] /home/kangx637/4061 $


5. ls -l > outfile.txt
[4061-shell] /home/kangx637/4061/Project2 $ ls -l > outfile.txt
[4061-shell] /home/kangx637/4061/Project2 $

############### In outfile.txt ###############
total 211
drwxr-xr-x 2 kangx637 CSEL-student      5 Mar  9 13:35 4061_project_2
-rw------- 1 kangx637 CSEL-student   2151 Mar 11 23:08 data.txt
-rwx------ 1 kangx637 CSEL-student   8720 Mar 12 05:05 du
-rw------- 1 kangx637 CSEL-student   1293 Mar 10 20:41 du.c
-rwx------ 1 kangx637 CSEL-student  12944 Mar 12 05:05 grep
-rw-r--r-- 1 kangx637 CSEL-student   1342 Mar 10 23:01 grep.c
drwxr-xr-x 3 kangx637 CSEL-student      4 Feb 20 22:50 __MACOSX
-rw------- 1 kangx637 CSEL-student    227 Mar 11 20:00 Makefile
-rw------- 1 kangx637 CSEL-student      0 Mar 12 05:09 outfile.txt
-rw-r--r-- 1 kangx637 CSEL-student 107782 Feb 20 22:23 project2.pdf
-rw------- 1 kangx637 CSEL-student  10316 Mar 12 05:08 README
-rwx------ 1 kangx637 CSEL-student  17928 Mar 12 05:08 shell
-rw------- 1 kangx637 CSEL-student  11314 Mar 11 20:53 shell2.c
-rw------- 1 kangx637 CSEL-student  11222 Mar 12 05:04 shell.c
-rw-r--r-- 1 kangx637 CSEL-student   5236 Mar 10 18:13 shell.c~
-rwx------ 1 kangx637 CSEL-student  13944 Feb 20 18:31 sol
-rw------- 1 kangx637 CSEL-student   1135 Mar 10 16:00 test
-rw------- 1 kangx637 CSEL-student   2031 Mar 12 04:44 testfile.txt
-rw------- 1 kangx637 CSEL-student    988 Mar 10 17:19 util.c
-rw------- 1 kangx637 CSEL-student    564 Feb 20 19:09 util.h
-rw------- 1 kangx637 CSEL-student   2704 Mar 12 05:05 util.o


6. du .. >> outfile.txt
############### In outfile.txt ###############
total 211
drwxr-xr-x 2 kangx637 CSEL-student      5 Mar  9 13:35 4061_project_2
-rw------- 1 kangx637 CSEL-student   2151 Mar 11 23:08 data.txt
-rwx------ 1 kangx637 CSEL-student   8720 Mar 12 05:05 du
-rw------- 1 kangx637 CSEL-student   1293 Mar 10 20:41 du.c
-rwx------ 1 kangx637 CSEL-student  12944 Mar 12 05:05 grep
-rw-r--r-- 1 kangx637 CSEL-student   1342 Mar 10 23:01 grep.c
drwxr-xr-x 3 kangx637 CSEL-student      4 Feb 20 22:50 __MACOSX
-rw------- 1 kangx637 CSEL-student    227 Mar 11 20:00 Makefile
-rw------- 1 kangx637 CSEL-student      0 Mar 12 05:09 outfile.txt
-rw-r--r-- 1 kangx637 CSEL-student 107782 Feb 20 22:23 project2.pdf
-rw------- 1 kangx637 CSEL-student  10316 Mar 12 05:08 README
-rwx------ 1 kangx637 CSEL-student  17928 Mar 12 05:08 shell
-rw------- 1 kangx637 CSEL-student  11314 Mar 11 20:53 shell2.c
-rw------- 1 kangx637 CSEL-student  11222 Mar 12 05:04 shell.c
-rw-r--r-- 1 kangx637 CSEL-student   5236 Mar 10 18:13 shell.c~
-rwx------ 1 kangx637 CSEL-student  13944 Feb 20 18:31 sol
-rw------- 1 kangx637 CSEL-student   1135 Mar 10 16:00 test
-rw------- 1 kangx637 CSEL-student   2031 Mar 12 04:44 testfile.txt
-rw------- 1 kangx637 CSEL-student    988 Mar 10 17:19 util.c
-rw------- 1 kangx637 CSEL-student    564 Feb 20 19:09 util.h
-rw------- 1 kangx637 CSEL-student   2704 Mar 12 05:05 util.o
1233783


7. cat outfile.txt | grep grep
[4061-shell] /home/kangx637/4061/Project2 $ cat outfile.txt | grep grep
-rwx------ 1 kangx637 CSEL-student  12944 Mar 12 05:05 grep
-rw-r--r-- 1 kangx637 CSEL-student   1342 Mar 10 23:01 grep.c


8. cat testfile.txt | grep rwx > outfile.txt
[4061-shell] /home/kangx637/4061/Project2 $ cat testfile.txt | grep rwx > outfile.txt
[4061-shell] /home/kangx637/4061/Project2 $

############### In outfile.txt ###############
drwxr-xr-x 2 kangx637 CSEL-student      5 Mar  9 13:35 4061_project_2/
-rwx------ 1 kangx637 CSEL-student   8816 Mar 10 17:56 cd*
-rwx------ 1 kangx637 CSEL-student   8720 Mar 12 04:15 du*
-rwx------ 1 kangx637 CSEL-student   8432 Mar  9 18:55 exit*
-rwx------ 1 kangx637 CSEL-student  12944 Mar 12 04:15 grep*
drwxr-xr-x 3 kangx637 CSEL-student      4 Feb 20 22:50 __MACOSX/
-rwx------ 1 kangx637 CSEL-student   8608 Mar 11 21:05 practice*
-rwx------ 1 kangx637 CSEL-student  17928 Mar 12 04:15 shell*
-rwx------ 1 kangx637 CSEL-student  13944 Feb 20 18:31 sol*


9. cd .. | grep h
[4061-shell] /home/kangx637/4061/Project2 $ cd .. | grep h
[4061-shell] /home/kangx637/4061/Project2 $


10. cat data.txt > out.txt > out1.txt >> out3.txt
this will be same as "cat data.txt > out.txt"
nothing will change for out1.txt, and out3.txt


11. echo hello | echo bye
[4061-shell] /home/kangx637/4061/Project2 $ echo hello | echo bye
bye
[4061-shell] /home/kangx637/4061/Project2 $
--> only do echo bye since it takes echo hello as STDIN.
