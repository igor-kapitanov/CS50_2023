#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    //int numbers[] = {20, 500, 10, 5, 100, 1, 50};
    string str[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    //int n = get_int("Number: ");
    string s = get_string("String: ");
    for (int i = 0; i < 6; i++)
    {
        //if (numbers[i] == n)
        if (strcmp(str[i], s) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}