#!/bin/bash

#######################################################################
# ASSIGNMENT 1 -> QUESTION A

# Name     : Ansh Kumar Singh, Trisanjit Das, Aritra Mondal
# Section  : A2
# Roll No  : 002311001073, 002311001089, 002311001091
# Team No  : 04
# Date     : 23/07/2025
#
# Objective: Familiarity with User and System level OS Commands
# Task     : Run the commands and validate the output
#######################################################################


# Q1) who
#
# Description:
#   Displays the list of users currently logged into the system.
#
# Command:
#   who
#
# Output:
#   (unknown) :0           2024-10-21 11:46 (:0)
#   be2341     pts/0        2025-07-23 12:17 (172.16.4.211)
#   be2368     pts/1        2025-07-23 12:18 (172.16.4.204)
#   be2354     pts/3        2025-07-23 12:25 (172.16.4.201)
#   be2362     pts/4        2025-07-23 12:25 (172.16.4.220)
#   be23L07    pts/6        2025-07-23 12:25 (172.16.4.215)
#   be2365     pts/7        2025-07-23 12:27 (172.16.4.227)
#   be2356     pts/8        2025-07-23 12:27 (172.16.4.209)
#   be2373     pts/9        2025-07-23 12:28 (172.16.4.221)
#   be2355     pts/10       2025-07-23 12:29 (172.16.4.216)
#   be2391     pts/12       2025-07-23 12:29 (172.16.4.226)
#


# Q2) whomai
#
# Description: 
#    It displays Current username, Terminal number, date and time at which user logged into the system
#
# Command:
#    whomai
# 
# Output:
#    be2373
#


# Q3) pwd
# 
# Description: 
#    It displays current working directory
#
# Command:
#    pwd
# 
# Output:
#    /home/usr/student/ug/yr23/be2373
#


# Q4) date
# 
# Description: 
#    It displays system date and time
#
# Command:
#    data
# 
# Output:
#    Wed Jul 23 12:45:09 IST 2025
#


# Q5) ls
# 
# Description: 
#    It lists the files and directories stored in the current directory. To list the files in a directory use the following syntax: $ls dirname
#
# Command:
#    ls
# 
# Output:
#    a4q2  a.out  as3p3.  CN  cpnm  cpnm73  DSA  OOPS  oopsEvaluation  OOS  OOSEvaluation  SE  skel
#
# Command:
#    ls OOS
# 
# Output:
#    Assignment1  Assignment2  Assignment3  Assignment5  Practice  ThreadPractice
#


# Q6) mkdir
# 
# Description: 
#    It is used to create directories by using the command: $mkdir dirname
#
# Command:
#    mkdir tryDirectory
#    ls
# 
# Output:
#    a4q2  a.out  as3p3.  CN  cpnm  cpnm73  DSA  OOPS  oopsEvaluation  OOS  OOSEvaluation  SE  skel  tryDirectory
#


# Q7) clear
# 
# Description: 
#    It clears the screen
#
# Command:
#    clear
# 
# Output:
#    [be2373@localhost ~]$
#


# Q8) cd
# 
# Description: 
#    It is used to change the current working directory to any other directory specified
#
# Command:
#    cd tryDirectory
# 
# Output:
#    [be2373@localhost tryDirectory]$
#


# Q9) df
# 
# Description: 
#    It displays currently mounted file systems.
#
# Command:
#    df
# 
# Output:
#     Filesystem                   1K-blocks      Used  Available Use% Mounted on
#     /dev/mapper/scientific-root   52399104  27796000   24603104  54% /
#     devtmpfs                      32758584         0   32758584   0% /dev
#     tmpfs                         32774652     10340   32764312   1% /dev/shm
#     tmpfs                         32774652    789224   31985428   3% /run
#     tmpfs                         32774652         0   32774652   0% /sys/fs/cgroup
#     /dev/sda2                      1039616    238088     801528  23% /boot
#     /dev/mapper/scientific-home 2256669952 136333972 2120335980   7% /home
#     tmpfs                          6554932        16    6554916   1% /run/user/42
#     tmpfs                          6554932         0    6554932   0% /run/user/3067
#     tmpfs                          6554932         0    6554932   0% /run/user/3097
#     tmpfs                          6554932         0    6554932   0% /run/user/3014
#     tmpfs                          6554932         0    6554932   0% /run/user/3107
#     tmpfs                          6554932         0    6554932   0% /run/user/3218
#     tmpfs                          6554932         0    6554932   0% /run/user/3213
#     tmpfs                          6554932         0    6554932   0% /run/user/3271
#     tmpfs                          6554932         0    6554932   0% /run/user/3292
#     tmpfs                          6554932         0    6554932   0% /run/user/3211
#     tmpfs                          6554932         0    6554932   0% /run/user/3209
#     tmpfs                          6554932         0    6554932   0% /run/user/3223
#     tmpfs                          6554932         0    6554932   0% /run/user/3275
#     tmpfs                          6554932         0    6554932   0% /run/user/3244
#     tmpfs                          6554932         0    6554932   0% /run/user/3265
#     tmpfs                          6554932         0    6554932   0% /run/user/3354
#     tmpfs                          6554932         0    6554932   0% /run/user/3216
#     tmpfs                          6554932         0    6554932   0% /run/user/3268
#     tmpfs                          6554932         0    6554932   0% /run/user/3259
#     tmpfs                          6554932         0    6554932   0% /run/user/3276
#     tmpfs                          6554932         0    6554932   0% /run/user/3294
#     tmpfs                          6554932         0    6554932   0% /run/user/3260
#     tmpfs                          6554932         0    6554932   0% /run/user/3262
#     tmpfs                          6554932         0    6554932   0% /run/user/3258
#     tmpfs                          6554932         0    6554932   0% /run/user/3261
#     tmpfs                          6554932         0    6554932   0% /run/user/3274
#     tmpfs                          6554932         0    6554932   0% /run/user/3257
#     tmpfs                          6554932         0    6554932   0% /run/user/3264


# Q10) rmdir
# 
# Description: 
#    Directories can be deleted using the rmdir command - $rmdir dirname
#
# Command:
#    rmdir tryDirectory
#    ls
# 
# Output:
#    a4q2  a.out  as3p3.  CN  cpnm  cpnm73  DSA  OOPS  oopsEvaluation  OOS  OOSEvaluation  SE  skel
#


# Q11) cat
# 
# Description: 
#    It displays the contents of a file - $cat filename
#
# Command:
#    cat as3p3.
# 
# Output:
#    #include<stdio.h>
#     int main(){
#         int size;
#         printf("Enter the size of the array: ");
#         scanf("%d",&size);
#         int a[size];
#         printf("Enter the array elements \n");
#         int i;
#         for(i = 0; i < size; i++){
#             scanf("%d", &a[i]);  // Read each element
#         }
#         for(i = 0; i < size/2; i++){
#             int temp = a[size - 1 - i];
#             a[size - 1 - i] = a[i];
#             a[i] = temp;
#         }
#         printf("The array elements in reverse order is: \n");
#         for(i = 0; i < size; i++){
#             printf("\n %d", a[i]);
#         }
#         return 0;
#     }
#     [be2373@localhost ~]$


# Q12) cp
# 
# Description: 
#    It is used to copy a file - $ cp source_file destination_file
#
# Command:
#    cp as3p3. revArray.c
#    ls
# 
# Output:
#    a4q2  a.out  as3p3.  CN  cpnm  cpnm73  DSA  OOPS  oopsEvaluation  OOS  OOSEvaluation  revArray.c  SE  skel
#


# Q13) mv
# 
# Description: 
#    It is used to change the name of a file - $ mv old_file new_file
#
# Command:
#    mv as3p3. as3p3.c
#    ls
# 
# Output:
#    a4q2  a.out  as3p3.c  CN  cpnm  cpnm73  DSA  OOPS  oopsEvaluation  OOS  OOSEvaluation  revArray.c  SE  skel
#


# Q14) rm
# 
# Description: 
#    It is used to delete an existing file - $ rm filename
#
# Command:
#    rm revArray.c
# 
# Output:
#    a4q2  a.out  as3p3.c  CN  cpnm  cpnm73  DSA  OOPS  oopsEvaluation  OOS  OOSEvaluation  SE  skel
#


# Q15) stat
# 
# Description: 
#    It is used to delete an existing file - $ rm filename
#
# Command:
#    stat as3p3.c
# 
# Output:
#    File: ‘as3p3.c’
#    Size: 391             Blocks: 8          IO Block: 4096   regular file
#    Device: fd02h/64770d  Inode: 537418274   Links: 1
#    Access: (0644/-rw-r--r--)  Uid: ( 3276/  be2373)   Gid: ( 2926/  ugyr23)
#    Context: unconfined_u:object_r:user_home_t:s0
#    Access: 2025-07-23 13:03:52.982500442 +0530
#    Modify: 2024-05-09 16:37:23.839466082 +0530
#    Change: 2025-07-23 13:10:02.732508963 +0530
#    Birth: -
#


# Q16) ln
# 
# Description: 
#    It is used to create links between files and directories.
#
# Command: (Hard Link)
#    ln as3p3.c arrayReversal.txt
#    ls
# 
# Output:
#    a4q2  a.out  arrayReversal.txt  as3p3.c  CN  cpnm  cpnm73  DSA  OOPS  oopsEvaluation  OOS  OOSEvaluation  SE  skel
#
# Command: (Symbolic Link)
#    ln -s as3p3.c arrs.txt
#    ls
# 
# Output:
#    a4q2   arrayReversal.txt  as3p3.c  cpnm    DSA   oopsEvaluation  OOSEvaluation  skel
#    a.out  arrs.txt           CN       cpnm73  OOPS  OOS             SE
#


# Q17) tty
# 
# Description: 
#    It prints the filename of the terminal connected to standard input.
#
# Command:
#    tty
# 
# Output:
#    /dev/pts/9
#


# Q18) uname
# 
# Description: 
#    It prints system information
#
# Command:
#    uname
# 
# Output:
#    Linux
#


# Q19) umask
# 
# Description: 
#    It specifies user file creation mask, implying which of the 3 permissions are to be denied to the owner,group and others.
#
# Command:
#    umask
# 
# Output:
#    0022
#


# Q20) find
# 
# Description:
#    It searches for files in a directory hierarchy
#
# Command:
#    find . -name tcpserver.c
# 
# Output:
#    ./CN/tcpserver.c
#


# Q21) sort
# 
# Description:
#    It sorts the lines of text files
#
# Command:
#    sort newText.txt
# 
# Output:
#    Have a great day!
#    - Item 1: Remember to stay hydrated.
#    - Item 2: Take regular breaks while working.
#    - Item 3: Keep your code clean and documented.
#    This file contains a few lines of generic content.
#    Welcome to your new text file!
#    You can add notes, ideas, tasks, or anything else here.
#


# Q22) ps
#
# Description:
#    It displays information about the current processes.
#
# Command:
#    ps
#
# Output:
#    PID TTY          TIME CMD
#    17952 pts/31   00:00:00 bash
#    18259 pts/31   00:00:00 ps
#


# Q23) chmod 777 file1
#
# Description:
#    gives full permission to owner, group and others
#
# Command:
#    chmod 777 intro.txt
#
# Output:
#    No output as it gives only permisssion.
#


# Q24) grep
#
# Description:
#    It finds specific patterns in files.
# Command:
#    grep "i" intro.txt
#
# Output:
#    Hello my name is Trisanjit Das.
#    I am currently a pre-final year undergrad at the Dept. of I.T., J.U.
#    (It gives all the i in red-colour and is case-sensitive)
#


# Q25) touch
#
# Description:
#    It creates an empty file or updates the timestamp of an existing file.
# Command:
#    touch new.txt
#
# Output:
#    ls
#    new.txt
#


# Q26) more/less
#
# Description:
#    It displays file content one screen at a time, allowing you to scroll.
# Command:
#    more os_poem.txt
#
# Output:
#    Ode to the Operating System
#    
#    Beneath the screens and glowing light,
#    An unseen force works day and night.
#    It wakes the silence, stirs the core,
#    The OS, we all adore.
#    
#    It bridges gaps 'twixt man and machine,
#    In every task, both seen and unseen.
#    Managing memory, CPU dance,
#    Giving every process a chance.
#    
#    With threads and queues, it weaves the flow,
#    So apps and hardware smoothly go.
#    It guards our data, keeps it tight,
#    A silent sentinel in the night.
#    
#    Though oft unnoticed, it’s the heart,
#    The vital pulse, the system’s art.
#    Oh OS, you make it true—
#    The dreams we build start all with you.
#
# Command:
#    less os_poem.txt
#
# Output:
#    Ode to the Operating System
#    
#    Beneath the screens and glowing light,
#    An unseen force works day and night.
#    It wakes the silence, stirs the core,
#    The OS, we all adore.
#    
#    It bridges gaps 'twixt man and machine,
#    In every task, both seen and unseen.
#    Managing memory, CPU dance,
#    Giving every process a chance.
#    
#    With threads and queues, it weaves the flow,
#    So apps and hardware smoothly go.
#    It guards our data, keeps it tight,
#    A silent sentinel in the night.
#    
#    Though oft unnoticed, it’s the heart,
#    The vital pulse, the system’s art.
#    Oh OS, you make it true—
#    The dreams we build start all with you.
#    os_poem.txt (END)
#


# Q27) head/tail
#
# Description:
#    It displays First/Last 10 lines of a File.
# Command:
#    head os_poem.txt
#
# Output:
#    Ode to the Operating System
#    
#    Beneath the screens and glowing light,
#    An unseen force works day and night.
#    It wakes the silence, stirs the core,
#    The OS, we all adore.
#    
#    It bridges gaps 'twixt man and machine,
#    In every task, both seen and unseen.
#    Managing memory, CPU dance,
#
# Command:
#    tail os_poem.txt
#
# Output:
#    With threads and queues, it weaves the flow,
#    So apps and hardware smoothly go.
#    It guards our data, keeps it tight,
#    A silent sentinel in the night.
#    
#    Though oft unnoticed, it’s the heart,
#    The vital pulse, the system’s art.
#    Oh OS, you make it true—
#    The dreams we build start all with you.
#


# Q28) top
#
# Description:
#    It dynamically displays real-time information about system statistics.
# Command:
#    top
#
# Output:
#    top - 13:48:50 up 275 days,  2:02, 29 users,  load average: 0.00, 0.01, 0.05
#    Tasks: 418 total,   1 running, 412 sleeping,   2 stopped,   0 zombie
#    %Cpu(s):  0.0 us,  0.0 sy,  0.0 ni, 99.9 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
#    KiB Mem : 65549308 total, 53845912 free,  2407840 used,  9295556 buff/cache
#    KiB Swap: 32899068 total, 32899068 free,        0 used. 61595284 avail Mem
#    
#      PID USER      PR  NI    VIRT    RES    SHR S  %CPU %MEM     TIME+ COMMAND
#    19720 be2389    20   0  157988   2548   1556 R   0.7  0.0   0:00.18 top
#      561 root      20   0       0      0      0 S   0.3  0.0  42:58.96 xfsaild/dm-0
#     8205 root      20   0       0      0      0 S   0.3  0.0   0:49.35 kworker/4:0
#    16103 be2354    20   0  147984   2452   1116 S   0.3  0.0   0:00.41 sshd
#    19741 be2354    20   0  151796   5928   2792 S   0.3  0.0   0:00.07 vim
#        1 root      20   0  194444   7592   3988 S   0.0  0.0  29:22.26 systemd
#        2 root      20   0       0      0      0 S   0.0  0.0   0:25.61 kthreadd
#        3 root      20   0       0      0      0 S   0.0  0.0 360:10.19 ksoftirqd/0
#        8 root      rt   0       0      0      0 S   0.0  0.0   0:04.45 migration/0
#        9 root      20   0       0      0      0 S   0.0  0.0   0:00.00 rcu_bh
#       10 root      20   0       0      0      0 S   0.0  0.0 327:45.38 rcu_sched
#       11 root      rt   0       0      0      0 S   0.0  0.0   1:07.02 watchdog/0
#       12 root      rt   0       0      0      0 S   0.0  0.0   1:05.97 watchdog/1
#       13 root      rt   0       0      0      0 S   0.0  0.0   0:13.35 migration/1
#       14 root      20   0       0      0      0 S   0.0  0.0 260:50.17 ksoftirqd/1
#       16 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kworker/1:0H
#       17 root      rt   0       0      0      0 S   0.0  0.0   1:00.27 watchdog/2
#       18 root      rt   0       0      0      0 S   0.0  0.0   0:08.14 migration/2
#       19 root      20   0       0      0      0 S   0.0  0.0 200:43.36 ksoftirqd/2
#       21 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kworker/2:0H
#       22 root      rt   0       0      0      0 S   0.0  0.0   0:59.24 watchdog/3
#       23 root      rt   0       0      0      0 S   0.0  0.0   0:06.01 migration/3
#       24 root      20   0       0      0      0 S   0.0  0.0 167:21.16 ksoftirqd/3
#    [3]+  Stopped                 top
#


# Q29) kill
#
# Description:
#    It terminates a Process.
# Command:
#    kill 19940
#
# Output:
#    No output, it only killed the process.
#


# Q30) history
#
# Description:
#    It displays a list of previously executed commands.
# Command:
#    history
#
# Output:
#    38  ssh-keygen -t ed2389
#    39  ssh-keygen -t ed25519
#    40  clear
#    41  cat ~/ .ssh/id_ed25519.pub
#    42  cat ~/ .ssh/id_rsa.pub
#    43  cat ~/ .ssh/software.pub
#    44  cat ~/ .ssh/id_ed25519/software.pub
#    45  cat ~/ .ssh/software.pub
#    46  cd ..
#    47  ls
#    48  type id_ed25519
#    49  ssh-keygen -t ed25519
#    50  cd ..
#    51  ls
#    52  clear
#    53  ssh-keygen -t ed25519
#    54  cat ~/.ssh/id_ed25519.pub
#    .....................
#    998  ls
#    999  gcc gbn_receiver.c
#   1000  ./a.out
#   1001  ps
#   1002  chmod 777 file1
#   1003  cd ..
#   1004  ls
#   1005  cd be2391
#   1006  cd be2389
#   1007  ls
#   1008  clear
#   1009  chmod 777 file1
#   1010  ls
#   1011  nano intro.txt
#   1012  chmod 777 intro
#   1013  ls
#   1014  chmod 777 intro.txt
#   1015  grep
#   1016  grep "i" intro.txt
#   1017  mkdir OS
#   1018  cd OS
#   1019  touch new.txt
#   1020  ls
#   1021  more
#   1022  more -d
#   1023  nano os_poem.txt
#   1024  more os_poem.txt
#   1025  less os_poem.txt
#   1026  more os_poem.txt
#   1027  clear
#   1028  less os_poem.txt
#   1029  clear
#   1030  head os_poem.txt
#   1031  tail os_poem.txt
#   1032  top
#   1033  kill
#   1034  top
#   1035  kill 19294
#   1036  kill 19940
#   1037  history
#


# Q31) du
#
# Description:
#    It estimates file space usage (of a file or directory).
# Command:
#    du
#
# Output:
#    4
#


# Q32) ping
#
# Description:
#    It tests network connectivity to a host.
# Command:
#    ping 172.16.4.112
#
# Output:
#    PING 172.16.4.112 (172.16.4.112) 56(84) bytes of data.
#    64 bytes from 172.16.4.112: icmp_seq=1 ttl=64 time=0.082 ms
#    64 bytes from 172.16.4.112: icmp_seq=2 ttl=64 time=0.038 ms
#    64 bytes from 172.16.4.112: icmp_seq=3 ttl=64 time=0.038 ms
#    64 bytes from 172.16.4.112: icmp_seq=4 ttl=64 time=0.036 ms
#    64 bytes from 172.16.4.112: icmp_seq=5 ttl=64 time=0.036 ms
#    64 bytes from 172.16.4.112: icmp_seq=6 ttl=64 time=0.035 ms
#    64 bytes from 172.16.4.112: icmp_seq=7 ttl=64 time=0.764 ms
#    ^Z
#    [7]+  Stopped                 ping 172.16.4.112
#


# Q33) wc
# 
# Description:
#    It counts lines, words, and characters in a file.
#
# Command:
#    wc newText.txt
# 
# Output:
#    11  53 289 newText.txt
#


# Q34) >/>>
# 
# Description:
#    It redirects the standard output of a command to a file, overwriting the file if it exists. 
#
# Command:
#    ll > txtfile2.txt
#    cat txtfile2.txt
# 
# Output:
#    total 4
#    -rw-r--r--. 1 be2373 ugyr23 289 Jul 23 13:41 newText.txt
#    -rw-r--r--. 1 be2373 ugyr23   0 Jul 23 13:58 txtfile2.txt
#


# Q35) |
# 
# Description:
#    It takes the standard output of one command and uses it as the standard input for another command.
#
# Command:
#     ll -l | wc -l
# 
# Output:
#    3
#
