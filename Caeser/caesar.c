#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2) // limits the arguments of main to two
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int k = atoi(argv[1]); // k is initialised to the cipher word
    if (k <= 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else //the ciphertext is made 
    {
        char p[100];
        printf("plaintext: ");
        scanf("%[^\n]s",p);
        printf("ciphertext: ");
        for (int i = 0, l = strlen(p); i < l; i++)
        {
            int c = 0;
            if (isupper(p[i]))
            {
                c = (((int)p[i] - 65 + k) % 26) + 65;
                printf("%c",c);
            }
            else if (islower(p[i]))
            {
                c = (((int)p[i] - 97 + k) % 26) + 97;
                printf("%c",c);
            }
            else
            {
                printf("%c",p[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
