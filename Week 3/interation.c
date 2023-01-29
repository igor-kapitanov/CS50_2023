#include <cs50.h>
#include <stdio.h>

void draw(int n);
int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}

void draw(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int g = 0; g < i+1; g++)
        {
            printf("#");
        }
        printf("\n");
    }
}