#include<stdio.h>
void mountain(int n);
int main(void)
{
    int x;
    // Prompt user to enter Height
    do
    {
        printf("Height:\n");
        scanf("%d",&x);
        if(1 <= x && x <= 8)
        {
            mountain(x);
        }
    }while(1 >= x || x >= 8);
}
// Function to print the height
void mountain(int n)
{
    for(int i=0; i<n; i++)
    {
        int a = i;
        for(int i=(n-1); i>a; i--)
        {
          printf(" ");
        }
        for(int i=0; i<=a; i++)
        {
          printf("#");
        }
        printf("\n");
    }
}
