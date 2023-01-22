#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // string s = "HI!";
    // string t = "BYE!";
    string words[2];

    words[0] = "HI!";
    words[1] = "BYE!";

    // printf("%c%c%c\n", s[0], s[1], s[2]);
    // printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);
    // printf("%s\n", s);
    // printf("%s\n", t);
    printf("%s\n", words[0]);
    printf("%s\n", words[1]);
}