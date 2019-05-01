#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf ("use: crack <hash>\n");
        return 1;
    }
    int letter = 53;
    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string hash = argv[1];
    char salt[3];
    memcpy (salt, hash, 2);
    salt [2] = '\0';

    char password [6] = "\0\0\0\0\0\0";
    for (int five = 0; five <letter; five++)
    {
        for (int four = 0; four < letter; four++)
        {
            for (int three = 0; three < letter; three++)
            {
                for (int two = 0; two < letter; two++)
                {
                    for (int one = 0; one < letter; one++)
                    {
                        password [0] = letters[one];
                        password [1] = letters[two];
                        password [2] = letters[three];
                        password [3] = letters[four];
                        password [4] = letters[five];

                        if (strcmp (crypt(password, salt), hash) == 0)
                        {
                            printf("%s\n", password);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    printf("Password can't be cracked!");
    return 2;
}