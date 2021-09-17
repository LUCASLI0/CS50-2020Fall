#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string key = argv[1];
        for (int i = 0; i < strlen(key); i++)
        {
            if (strlen(key) != 26)
            {
                printf("Key must contain 26 characters.\n");
                return 1;
            }
            else if (isalpha(key[i]) == 0)
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
            else
            {
                // used nested loop to compare each char in the Key to other chars, besides itself when key[i] = key[j] since they will always be same
                for (int j = 0; j < strlen(key); j++)
                {
                    if (i != j && key[i] == key[j])
                    {
                        printf("Usage: ./substitution key\n");
                        return 1;
                    }
                }
            }
        }
        printf("%s\n", key);

        // get plaintext
        string plaintext = get_string("plaintext: ");
        for (int i = 0; i < strlen(plaintext); i++)
        {
            // first calculate each plaintext char's distance from a (-97) or A (-65), so that we can know its location in the Alphabet
            // then we use this location to get the replaced value from the Key
            // since the key is not case-sensitive where VCHPRZGJNTLSKFBDQWAXEUYMOI == vchprzgjntlskfbdqwaxeuymoi  == VcHpRzGjNtLsKfBdQwAxEuYmOi
            // then we need to lower or upper the ciphertext char accordingly
            if (islower(plaintext[i]))
            {
                int location = plaintext[i] - 97;
                plaintext[i] = tolower(key[location]);
            }
            else if (isupper(plaintext[i]))
            {
                int location = plaintext[i] - 65;
                plaintext[i] = toupper(key[location]);
            }
        }
        printf("ciphertext: %s\n", plaintext);
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}
