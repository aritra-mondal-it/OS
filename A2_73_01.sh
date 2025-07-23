#!/bin/bash

#######################################################################
# Name     : Ansh Kumar Singh
# Section  : A2
# Roll No  : 002311001073
# Team No  : 4
# Date     : 23/07/2025
#
# Assignment 1A: (6 Marks) [CO1]
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


# 10) rmdir
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


# 11) cat
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


# 12) cp
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


# 13) mv
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


# 14) rm
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


# 15) stat
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


