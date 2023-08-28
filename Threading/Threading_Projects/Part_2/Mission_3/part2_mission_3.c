#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <utime.h>

// cat function - read data from file and prints the content
void cat(char **fileDirectory)
{
    // Check if file name is provided
    if (fileDirectory[1] == NULL)
    {
        printf("Usage: cat [file]\n");
        return;
    }

    // Open the file for reading
    FILE *file = fopen(fileDirectory[1], "r");

    // Check if file was successfully opened
    if (file == NULL)
    {
        printf("Error: Unable to open file %s\n", fileDirectory[1]);
        return;
    }

    // Read and print the content of the file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s\n", line);
    }

    // Close the file
    fclose(file);
}

// head function - displays the beginning of a text file (10 lines by default)
void head(char **fileDirectory)
{
    // Check if file name is provided
    if (fileDirectory[1] == NULL)
    {
        printf("Usage: head [file]\n");
        return;
    }

    // Set the default number of lines to print
    int printLine = 10;

    // If the number of lines to print is provided, use it instead of the default
    if (fileDirectory[2] != NULL)
    {
        printLine = atoi(fileDirectory[2]);
    }

    // Open the file for reading
    FILE *file = fopen(fileDirectory[1], "r");

    // Check if file was successfully opened
    if (file == NULL)
    {
        printf("Error: Unable to open file %s\n", fileDirectory[1]);
        return;
    }

    // Read and print the first 'printLine(either provided or default)' lines of the file
    char line[1024];
    for (int i = 0; i < printLine && fgets(line, sizeof(line), file) != NULL; i++)
    {
        printf("%s", line);
    }

    printf("\n");

    // Close the file
    fclose(file);
}

// tail function - displays the end of a text file (10 lines by default)
void tail(char **fileDirectory)
{
    // Check if file name is provided
    if (fileDirectory[1] == NULL)
    {
        printf("Usage: tail [file]\n");
        return;
    }

    // Set the default number of lines to print from tail
    int printLastLine = 10;

    // If the number of lines to print is provided, use it instead of the default
    if (fileDirectory[2] != NULL)
    {
        printLastLine = atoi(fileDirectory[2]);
    }

    // Open the file for reading
    FILE *file = fopen(fileDirectory[1], "r");

    // Check if file was successfully opened
    if (file == NULL)
    {
        printf("Error: Unable to open file %s\n", fileDirectory[1]);
        return;
    }

    // Count the number of lines in the file
    int num_lines = 0;
    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        num_lines++;
    }

    // Move the file pointer back to the beginning of the file
    rewind(file);

    // Calculate the starting line to print from
    int start_line = (num_lines > printLastLine) ? num_lines - printLastLine : 0;
    num_lines = 0; // reset the num_lines to 0

    // again go through the file and count the number of lines in the file
    while (fgets(line, sizeof(line), file) != NULL)
    {
        num_lines++;

        if (num_lines > start_line)
        {
            // as the line number reaches to the desired line start to print from their
            printf("%s", line);
        }
    }
    printf("\n");
    // close the file
    fclose(file);
}

// more function - views the content of a text file one screen at a time
void more(char **fileDirectory)
{
    // Check if file name is provided
    if (fileDirectory[1] == NULL)
    {
        printf("Usage: more [file]\n");
        return;
    }

    // Open the file for reading
    FILE *file = fopen(fileDirectory[1], "r");
    if (file == NULL)
    {
        printf("Error: Unable to open file %s\n", fileDirectory[1]);
        return;
    }
    // Set the default height of page by line numbers to print
    int screenHeightbyLine = 10;

    // If the height of page is provided, use it instead of the default
    if (fileDirectory[2] != NULL)
    {
        screenHeightbyLine = atoi(fileDirectory[2]); // convert string to int
    }

    char line[1024];
    int line_count = 0;

    // Read and print the first 'printLine(either provided or default)' lines of the file
    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
        line_count++;

        if (line_count % screenHeightbyLine == 0)
        {
            // as line exceeded, show an option of read more or not
            printf("--Read More --(Y/n): ");
            char c;
            scanf("%c", &c);
            if (c == 'N' || c == 'n')
            {
                // if option is 'n' or 'N' stop further display
                break;
            }
            printf("\033[A\r             \r"); // Erase the "--More--" message by move up and right
        }
    }
    printf("\n");
    // close the file
    fclose(file);
    getchar(); // to catch the trailing input
}

void help()
{
    // print all commands, syntax and their funcitons
    printf("Command\tSyntax\t-- Function\n");
    printf("cat\t [file directory] \t-- print all content\n");
    printf("head\t [file directory] [number of lines(optional)] \t-- print given line of content from head\n");
    printf("tail\t [file directory] [number of lines(optional)] \t-- print given line of content from tail\n");
    printf("more\t [file directory] [screen height by line (optional)] \t-- print given line of content from tail\n");
}

int main()
{
    char command[1000]; // to store given command by user
    char *cmd_token[3]; // to store all arguements seperately by tokonizing the command

    while (1)
    {
        printf("WShell> ");
        // take command from user
        fgets(command, sizeof(command), stdin);
        // tokanizing
        // main command e.g. head, cat, etc.
        cmd_token[0] = strtok(command, " \n");
        // file directory e.g. c:\one.txt
        cmd_token[1] = strtok(NULL, " \n");
        // line number, number of line to print (optional)
        cmd_token[2] = strtok(NULL, " \n");

        // compare main command with functions and call the corresponding function
        if (strcmp(cmd_token[0], "cat") == 0)
        {
            cat(cmd_token);
        }
        else if (strcmp(cmd_token[0], "head") == 0)
        {
            head(cmd_token);
        }
        else if (strcmp(cmd_token[0], "tail") == 0)
        {
            tail(cmd_token);
        }
        else if (strcmp(cmd_token[0], "more") == 0)
        {
            more(cmd_token);
        }
        else if (strcmp(cmd_token[0], "exit()") == 0)
        {
            // for exit, just break the loop
            printf("WShell closed\n");
            break;
        }
        else if (strcmp(cmd_token[0], "help") == 0)
        {
            help();
        }
        else
        {
            // show error message
            printf("Invalid command\n");
        }
    }

    return 0;
}