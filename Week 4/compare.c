#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    //int i = get_int("i: ");
    //int j = get_int("j: ");
    string s = get_string("s: ");
    string t = get_string("t: ");

    //if (i == j)
    if (strcmp(s, t) ==0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}