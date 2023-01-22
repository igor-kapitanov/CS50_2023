#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2) // if command line argument is not equal to 2
    {
        printf("Usage: ./substitution key\n"); // print error message "Usage ./substitution" is commnand is not equal to 2
        return 1;
    }

    int argv_length = strlen(argv[1]); // to get the lenth of argv[1], the second command after ./substitution on command line
    if (argv_length != 26)             // to make sure argv length must 26 characters
    {
        printf("Key must be up to 26\n"); // if argv length is not equal to 26 (print the error message )
        return 1;
    }
    for (int i = 0; i < argv_length; i++) // iterate over argv_length in order to get its character
    {
        if (!isalpha(argv[1][i])) // to check if argv[1] is not alphabethic
        {
            printf("All Key must be an Alphabeth\n"); // print this error message if all character in argv[1] is not an alphabeth
            return 1;
        }
        for (int j = i + 1; j < argv_length; j++) // declaring another iteration on argv_length to check for repeated alphabeth
        {
            if (argv[1][i] == argv[1][j]) // checking repeated alphabeth in argv[1]
            {
                printf("Key must not contain repeated alphabeth"); // if repeated alphabeth found, print the below error message
                return 1;
            }
        }
    }
    string plaintext = get_string("plaintext: "); // Getting user's input as plaintext
    printf("ciphertext: ");                       // to print the ciphertext
    int plaintext_length = strlen(plaintext);     // get the strlen of plaintext (user's input)
    for (int i = 0; i < plaintext_length; i++)    // iterate over the plaintext_Length
    {
        if (isupper(plaintext[i])) // check if plaintext character is uppercase
        {
            printf("%c", toupper(argv[1][plaintext[i] - 65])); // calculation to print the encipher text amd make sure it is Uppercase (case doesn't change)
        }
        else if (islower(plaintext[i])) // check if plaintext character is lowercase
        {
            printf("%c", tolower(argv[1][plaintext[i] - 97])); /// calculation to print the encipher text amd make sure it is lowercase(case doesn't change)
        }
        else // if plaintext is anything else, print it like that without changing
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n"); // print new line
}