#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long x = get_long("x: ");
    long y = get_long("y: ");

    float z = (float)x / (float)y;
    printf("%.2f\n", z);
}