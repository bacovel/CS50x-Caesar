#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string argument);
char encrypt(char ch, int key);

int main(int argc, string argv[])
{
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);
    string plain = get_string("plaintext:  ");

    printf("ciphertext: ");
    // Going through "plain" and for each ch we call the encrypt function
    for (int i = 0, len = strlen(plain); i < len; i++)
    {
        printf("%c", encrypt(plain[i], key));
    }
    printf("\n");
}

bool only_digits(string argument)
{
    for (int i = 0, len = strlen(argument); i < len; i++)
    {
        char ch = argument[i];
        if (!isdigit(ch))
        {
            return false;
        }
    }
    return true;
}

char encrypt(char ch, int key)
{
    if (!isalpha(ch))
    {
        return ch;
    }
    else if (isupper(ch))
    {
        int new_ch = ((int) ch - 'A') + key;
        if (new_ch > 25)
        {
            ch = (new_ch % 26) + 'A';
            return ch;
        }
        ch = new_ch + 'A';
        return ch;
    }
    else
    {
        int new_ch = ((int) ch - 'a') + key;
        if (new_ch > 25)
        {
            ch = (new_ch % 26) + 'a';
            return ch;
        }
        ch = new_ch + 'a';
        return ch;
    }
}