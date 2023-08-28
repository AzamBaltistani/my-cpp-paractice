#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <utime.h>

// function to update timestamp or create new file
void touch(char *filename)
{
    struct stat st;
    time_t now;
    time(&now);
    if (stat(filename, &st) != 0)
    {
        // File doesn't exist, create an empty file
        FILE *file = fopen(filename, "w");
        fclose(file);
    }
    else
    {
        // File exists, update timestamp
        struct utimbuf newTime;
        newTime.actime = st.st_atime;
        newTime.modtime = now;
        utime(filename, &newTime);
    }
}

// function to copy file from source to destinition
void cp(char *source_file, char *target_file)
{
    FILE *source = fopen(source_file, "r"); // copy the source file
    if (source == NULL)
    {
        printf("Cannot open source file %s\n", source_file); // printing error message
        return;
    }
    FILE *target = fopen(target_file, "w"); // create file on destinition
    if (target == NULL)
    {
        printf("Cannot create target file %s\n", target_file); // printing error message
        fclose(source);
        return;
    }
    char buffer[1024];
    size_t nread;
    while ((nread = fread(buffer, 1, sizeof(buffer), source)) > 0)
    {
        fwrite(buffer, 1, nread, target); // pasting on destinition
    }
    fclose(source); // close source file
    fclose(target); // close destinition file
}

// function to move file from one directory to another or rename the file
void mv(char *source_file, char *target_file)
{
    if (rename(source_file, target_file) != 0)
    {
        printf("Cannot rename file %s to %s\n", source_file, target_file);
    }
}

// function to remove file from destiniton or directory
void rm(char *filename)
{
    struct stat st;
    if (stat(filename, &st) != 0)
    {
        printf("Cannot find file %s\n", filename);
        return;
    }
    if (S_ISDIR(st.st_mode))
    {
        // Directory
        char cmd[1024];
        snprintf(cmd, sizeof(cmd), "rm -r %s", filename);
        system(cmd);
    }
    else
    {
        // File
        if (remove(filename) != 0)
        {
            printf("Cannot remove file %s\n", filename);
        }
    }
}

void help()
{
    // print all commands, syntax and their funcitons
    printf("Command\tSyntax\t-- Function\n");
    printf("touch\t [file directory] \t-- Modify timestamp\n");
    printf("cp\t [source directory] [target directory] \t-- copy and paste\n");
    printf("mv\t [source directory] [any another directory] \t-- move \n");
    printf("mv\t [source directory] [source directory but name change]\t-- rename \n");
    printf("rm\t [file directory] \t-- remove/delete\n");
}

int main()
{
    char command[1000], command_type[10], file1[1000], file2[1000];

    while (1)
    {
        printf("WShell> ");
        fgets(command, sizeof(command), stdin);
        sscanf(command, "%s %s %s", command_type, file1, file2); // parse the user input into command and file names

        if (strcmp(command_type, "touch") == 0)
        {
            touch(file1);
        }
        else if (strcmp(command_type, "cp") == 0)
        {
            cp(file1, file2);
        }
        else if (strcmp(command_type, "rm") == 0)
        {
            rm(file1);
        }
        else if (strcmp(command_type, "mv") == 0)
        {
            mv(file1, file2);
        }
        else if (strcmp(command_type, "exit()") == 0)
        {
            printf("WShell closed");
            break;
        }
        else if (strcmp(command_type, "help") == 0)
        {
            help();
        }
        else
        {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
