#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //int n = 50;
    //printf("%i\n", n);
    //printf("%p\n", &n); //shows the address of 50
    //int *p = &n;
    //printf("%p\n", p);
    //printf("%i\n", *p); //print int which located in "p"
    //string s = "HI!";
    char *s = "HI!";
    //printf("%s\n", s);
    //printf("%p\n", s);
    //printf("%p\n", &s[0]);
    //printf("%p\n", &s[1]);
    //printf("%p\n", &s[2]);
    //printf("%p\n", &s[3]);
    printf("%c\n", *s);
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+2));
}