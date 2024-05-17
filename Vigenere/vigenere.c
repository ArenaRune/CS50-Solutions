#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    if (argc != 2) //limits the arguments of main to 2
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    int len = strlen(argv[1]);
    char k[len];
    int key[len];
    for (int i = 0; i < len; i++)
    {
        k[i] = argv[1][i];//initialises k in cipher form
        if (isalpha(k[i]) == false) //initialises key in ascii
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }
        else
        {
            if (isupper(k[i]))
            {
                key[i] = (int)k - 65;
            }
            else
            {
                key[i] = (int)k[i] - 97;
            }
        }
    }
    char p[150];
    printf("plaintext: ");
    scanf("%[^\n]s",p);
    printf("ciphertext: ");
    for (int i = 0, j = 0, l = strlen(p); i < l ; i++) // cipher is created
    {
        int c = 0;
        j = j%len;
        if (isupper(p[i]))
            {
                c = (((int)p[i] - 65 + key[j]) % 26) + 65;
                printf("%c",c);
                j++;
            }
        else if (islower(p[i]))
            {
                c = (((int)p[i] - 97 + key[j]) % 26) + 97;
                printf("%c",c);
                j++;
            }
        else
            {
                printf("%c",p[i]);
            }
    }
    printf("\n");
    return 0;
}
