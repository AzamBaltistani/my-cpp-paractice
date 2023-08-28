#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <windows.h>

// Function to change the working directory
void run_cd(char **cmd)
{
    if (cmd[1] == NULL)
    {
        printf("cd: [directory missing]\n");
        return;
    }
    if (SetCurrentDirectory(cmd[1]) == TRUE) // the directory set successful
    {
        printf("> %s\n", cmd[1]);
    }
    else
    {
        printf("cd: no such file or directory: %s\n", cmd[1]); // printing error
    }
}
// Function to show to list of directory
void run_ls(char **cmd)
{

    WIN32_FIND_DATA my_FIND_DATA; // Windows API that is used to store information about a file or directory
    HANDLE my_FILE_HANDLE;        // Windows API that represents a handle to a resource that can be accessed by a process

    if (cmd[1] == NULL)
    {
        // if no directory was given by user
        // then find element in current current directory
        my_FILE_HANDLE = FindFirstFile("*", &my_FIND_DATA);
    }
    else
    {
        // find the first file at the given directory and store in my_FIND_DATA
        strcat(cmd[1], "*"); // put * at end of directory
        my_FILE_HANDLE = FindFirstFile(cmd[1], &my_FIND_DATA);
    }

    // print all files (name) on screen
    do
    {
        printf("- %s\n", my_FIND_DATA.cFileName); // printing file name of my_FIND_DATA

        // next file will store in my_FIND_DATA and if there no next file then the loop will stop
    } while (FindNextFile(my_FILE_HANDLE, &my_FIND_DATA) != 0);
}

// Function to make a new directory
void run_mkdir(char **cmd)
{
    if (cmd[1] == NULL) // if no command was given by user
    {
        printf("mkdir: [Destinition missing]\n");
        return;
    }
    if (CreateDirectory(cmd[1], NULL) == TRUE)
    {
        // if dirctory created succesully then print success message
        printf("Directory created: %s\n", cmd[1]);
    }
    else
    {
        // and if directory not created successfully then print error message
        printf("mkdir: cannot create directory '%s': File exists\n", cmd[1]);
    }
}
// Function to remove directory
void run_rmdir(char **cmd)
{
    if (cmd[1] == NULL)
    {
        // if no directory is given then print error  message
        printf("rmdir: missing operand\n");
        return;
    }
    if (RemoveDirectory(cmd[1]) == TRUE)
    {
        // if directory removed successfully then print success message
        printf("Deleted successfully:%s\n", cmd[1]);
    }
    else
    {
        // and if directory not removed successfully then print error message
        printf("rmdir: failed to remove '%s': No such file or directory\n", cmd[1]);
    }
}
// Function to show the help menu
void run_help()
{
    // print all commands along with their funcitons
    printf("Command\tFunction\n");
    printf("cd\tchanges a directory and it is used to change current working directory. \n");
    printf("ls\tlists the names of files in the current working directory.\n\tIf you type the ls command with a particular directory, the command displays\n\tthe files listed in the particular directory\n");
    printf("mkdir\tallows users to create or make new directories e.g. mkdir c:\\New Folder\n");
    printf("rmdir\tallows users to create or make new directories e.g. rmdir c:\\New Folder\n");
}

int main()
{
    char commandLine[1000];
    char *cmd_token[2];

    while (TRUE)
    {
        printf("WShell> ");
        fgets(commandLine, sizeof(commandLine), stdin); // taking command from user

        cmd_token[0] = strtok(commandLine, " \n"); // spliting first word and saving in cmd_cmd_token[2]
        cmd_token[1] = strtok(NULL, " \n");        // spliting second word and saving in cmd_token[1]
        // printf("0: %s\n1: %s\n", cmd_token[0], cmd_token[1]); // for check what values they have

        // checking
        if (cmd_token[0] == NULL)
        {
            // if no command given
            printf("No command. Enter 'help' for help menu :)\n");
        }
        else if (strcmp(cmd_token[0], "cd") == 0)
        {
            // compare given command with "cd", if true the call the run_cd() function
            run_cd(cmd_token);
        }
        else if (strcmp(cmd_token[0], "ls") == 0)
        {
            // if above codition if false then compare given command with "ls"
            // if this is true the call the run_ls() function
            run_ls(cmd_token);
        }
        else if (strcmp(cmd_token[0], "mkdir") == 0)
        {
            // again, if above codition if false then compare given command with "mkdir"
            // if this is true the call the run_mkdir() function
            run_mkdir(cmd_token);
        }
        else if (strcmp(cmd_token[0], "rmdir") == 0)
        {
            // again, if above codition if false then compare given command with "rmdir"
            // if this is true the call the run_rmdir() function
            run_rmdir(cmd_token);
        }
        else if (strcmp(cmd_token[0], "exit()") == 0)
        {
            // again, if above codition if false then compare given command with "exit()"
            // if this is true then print the below message and the program will stop in main function by codition of loop
            printf("WShell terminated\n");
            break;
        }
        else if (strcmp(cmd_token[0], "help") == 0)
        {
            // again, if above codition if false then compare given command with "help"
            // if this is true the call the run_help() function to help the user
            run_help();
        }
        else
        {
            // if all condition is false, then print error message
            printf("Invalid command... %s\nEnter 'help' for help menu :) \n", cmd_token[0]);
        }
    }

    return 0;
}