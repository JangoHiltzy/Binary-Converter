#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CONVERTS A NUMBER TO ITS BINARY REPRESENTATION
void ConvertToBinary()
{
    int number;
    char binary[33]; // TO STORE THE BINARY REPRESENTATION (32 BITS + '\0')
    int index = 0;

    // ASK USER TO ENTER A NUMBER TO CONVERT TO BINARY
    printf("Enter a number to convert to binary:\n");

    // VERIFY IF THE USER ENTERED A VALID INTEGER
    if (scanf("%d", &number) == 1)
    {
        // HANDLE CASE IF THE NUMBER IS 0 (ITS BINARY IS JUST "0")
        if (number == 0)
        {
            printf("Binary representation: 0\n");
            return; // EXIT EARLY FOR NUMBER 0
        }

        // MANUAL CONVERSION OF INTEGER TO BINARY
        while (number > 0)
        {
            binary[index++] = (number % 2) + '0'; // APPEND REMAINDER (0 OR 1)
            number /= 2;                          // DIVIDE THE NUMBER BY 2 FOR NEXT BIT
        }
        binary[index] = '\0'; // NULL TERMINATE THE STRING

        // REVERSE THE STRING TO OBTAIN THE CORRECT BINARY ORDER
        for (int i = 0; i < index / 2; i++)
        {
            char temp = binary[i];
            binary[i] = binary[index - i - 1];
            binary[index - i - 1] = temp;
        }

        // PRINT FINAL BINARY REPRESENTATION
        printf("Binary representation: %s\n", binary);
    }
    else
    {
        // IF USER ENTERS AN INVALID INPUT, SHOW ERROR MESSAGE
        printf("Invalid input. Please enter a valid number.\n");
        while (getchar() != '\n') // CLEAR INVALID CHARACTERS
            ;
    }
}

// CONVERTS A BINARY STRING TO ITS NUMBER EQUIVALENT
void ConvertToNumber()
{
    char binary[33]; // TO STORE THE BINARY STRING
    int number;

    // ASK USER TO ENTER A BINARY STRING TO CONVERT
    printf("Enter a binary to convert to a number:\n");

    // GET USER INPUT FOR BINARY STRING
    if (scanf("%s", binary) == 1)
    {
        // CHECK IF THE BINARY STRING ONLY CONTAINS '0' AND '1'
        for (int i = 0; binary[i] != '\0'; i++)
        {
            if (binary[i] != '0' && binary[i] != '1')
            {
                printf("Invalid binary input. Only '0' or '1' allowed.\n");
                return; // EXIT IF BINARY INPUT IS INVALID
            }
        }

        // USE strtol() TO CONVERT BINARY STRING TO INTEGER
        number = strtol(binary, NULL, 2);
        printf("Number representation: %d\n", number);
    }
    else
    {
        // IF USER ENTERS AN INVALID INPUT, SHOW ERROR MESSAGE
        printf("Invalid input. Please enter a valid binary number.\n");
        while (getchar() != '\n') // CLEAR INVALID INPUT
            ;
    }
}

// MAIN FUNCTION TO LET USER CHOOSE CONVERSION TYPE
int main()
{
    int choice;

    while (1)
    {
        // MENU OPTIONS FOR THE USER
        printf("\nBinary Converter\n");
        printf("0. Convert number to binary\n");
        printf("1. Convert binary to number\n");
        printf("2. Exit\n");

        // GET USER CHOICE
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a valid choice.\n");
            while (getchar() != '\n')
                ; // CLEAR INVALID INPUT
            continue;
        }

        // HANDLE CHOICE SELECTION
        switch (choice)
        {
        case 0:
            ConvertToBinary();
            break;
        case 1:
            ConvertToNumber();
            break;
        case 2:
            printf("Exiting program\n");
            return 0;
        default:
            printf("Invalid choice. Please enter 0, 1, or 2.\n");
        }
    }

    return 0;
}
