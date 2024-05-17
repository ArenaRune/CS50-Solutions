#include <stdio.h>
#include <math.h>
#include <cs50.h>
int main(void)
{
    float dollar;
    int quarters,dimes,nickles,pennies,cents,change,x;
// Loop to find the change
    do
    {
        dollar = get_float("change owed: ");
        cents = round(dollar * 100);
        quarters = cents / 25;
        cents = cents % 25;
        dimes = cents / 10;
        cents = cents % 10;
        nickles = cents / 5;
        cents = cents % 5;
        pennies = cents;
  // Total amount of change
        change = quarters + dimes + nickles + pennies;
    }
    while ( dollar < 0 );
    printf("%d\n",change);
}
