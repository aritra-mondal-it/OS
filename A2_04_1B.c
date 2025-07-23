/**********************************************************************************************************************************************************************
 * ASSIGNMENT 1 -> QUESTION B
 * Name :- Ansh Kumar Singh, Trisanjit Das, Aritra Mondal
 * Roll No. :- 002311001073, 002311001089, 002311001091
 * Sec. :- A2
 * Team No :- 04
 * Date :- 23/07/2025
 **********************************************************************************************************************************************************************
 * Program to get and set environment variables using system calls
 **********************************************************************************************************************************************************************
 * Problem Definition
 * Program to GET and SET the Environment variable and to know use of getenv and setenv system calls
 *
 * UNIX ENVIRONMENT VARIABLES
 * Variables are a way of passing information from the shell to programs when you run them. Programs look "in the environment" for particular * variables and if they are found will use the values stored. Some are set by the system, others by you, yet others by the shell, or any program that loads another program. Standard UNIX variables are split into two categories, environment variables and shell variables. In broad terms, shell variables apply only to the current instance of the shell and are used to set short-term working conditions; environment variables have a farther reaching significance, and those set at login are valid for the duration of the session. By convention, environment variables have UPPER CASE and shell variables have lower case names.
 *
 * Display the following  environment variables using getenv call:
 *  USER (your login name)
 *  HOME (the path name of your home directory)
 *  HOST (the name of the computer you are using)
 *  ARCH (the architecture of the computer's processor)
 *  DISPLAY (the name of the computer screen to display X windows)
 *  PRINTER (the default printer to send print jobs)
 *  PATH (the directories the shell should search to find a command)
 *
 * Syntax: Char *getenv( const char *name);
 * The getenv() function searches the environment list to find the Environment variable name, and returns a pointer to the corresponding value string.
 *
 * Now, Set two new environment variables and display them.
 *
 * Syntax: int setenv(const char * envname,const char * enval,int overwrite)
 * The setenv() function adds the variable name to the environment with the value value, if name does not already exist. If name does exist in the environment, then its value is changed to value if overwrite is nonzero; if overwrite is zero, then the value of name is not changed (and setenv() returns a success status).
 *
 **********************************************************************************************************************************************************************
 *
 * Assignment Details -
 * This is a program to GET and SET the ENVIRONMENT VARIABLES and to know the use of getenv and setenv system calls
 *
 * Input Description -
 * No input
 *
 * Output Description -
 * The required ENVIRONMENT VARIABLES are displayed at first. After that two new ENVIRONMENT VARIABLES are set and displayed
 *
 **********************************************************************************************************************************************************************
 *
 * File creation command - nano A2_04_1B.c
 * 
 * Compilation Command -  gcc A2_04_1B.c
 *
 * Execution Command -
 * ./a.out
 *
 **********************************************************************************************************************************************************************
 * Sample Input -
 * No input
 *
 * Sample Output -
 *
*Program to GET and SET Environment Variables
*
*Displaying environment variables by using getenv
*USER = be2391
*HOME = /home/usr/student/ug/yr23/be2391
*HOST is not set, empty
*ARCH is not set, empty
*DISPLAY is not set, empty
*PRINTER is not set, empty
*PATH = /usr/lib64/qt-3.3/bin:/usr/local/bin:/usr/bin:/usr/local/sbin:/usr/sbin:/home/usr/student/ug/yr23/be2391/.local/bin:/home/usr/student/*ug/yr23/be2391/bin
*
*
*Setting new Environment Variables by using setenv "NEW_USER" & "NEW_HOST"
*NEW_USER = User1
*NEW_HOST = User2
 **********************************************************************************************************************************************************************
 */

 #include <stdio.h>
 #include <stdlib.h>
 
 // Function to print environment variables
 void print_env_vars(const char *env_var_names[], int count)
 {
	int i; 
	for (i = 0; i < count; i++)
	 {
		 char *env_var = getenv(env_var_names[i]);
		 if (env_var != NULL)
			 printf("%s = %s\n", env_var_names[i], env_var);
		 else
			 printf("%s is not set, empty\n", env_var_names[i]);
	 }
 }
 
 int main()
 {
	 const char *env_var_names[] = {"USER", "HOME", "HOST", "ARCH", "DISPLAY", "PRINTER", "PATH"};
 
	 printf("\nProgram to GET and SET the Environment variable and to know use of getenv and setenv system calls\n\n");
 
	 printf("Displaying the environment variables using getenv call:\n");
	 int n = sizeof(env_var_names) / sizeof(env_var_names[0]);
	 print_env_vars(env_var_names, n);
 
	 printf("\n\nSetting two new environment variables and display them. \"NEW_USER\" & \"NEW_ARCH\"\n");
 
	 const char *new_env_var_names[] = {"NEW_USER", "NEW_ARCH"};
 
	 if (setenv(new_env_var_names[0], "User1", 1) < 0)
		 printf("Error setting new Environment Variable 1.\n");
	 if (setenv(new_env_var_names[1], "User2", 1) < 0)
		 printf("Error setting new Environment Variable 2.\n");
 
	 int nn = sizeof(new_env_var_names) / sizeof(new_env_var_names[0]);
	 print_env_vars(new_env_var_names, nn);
 
	 return 0;
 }
 
