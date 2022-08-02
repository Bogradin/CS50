#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main(int argc, string argv[])
{
    string key = argv[1];

    //check if key is valid
    if (argc != 2 || strlen(key) > 26 || strlen(key) < 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int soma = 0;
    int somaexp = 0;
    int product = 1;
    int productexp = 1;
    for (int i = 0; i < 26; i++)
    {
        somaexp = somaexp + alphabet[i];
        productexp = productexp * alphabet[i];
        if (isdigit(key[i]) || isspace(key[i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        alphabet[i] = tolower(key[i]);
        soma = soma + alphabet[i];
        product = product * alphabet[i];
    }
    if (soma != somaexp)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (product != productexp)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //ask user for plain text and remember if is lower/uppercase
    string plain = get_string("plaintext:");
    int n = strlen(plain);
    int cipher[n];
    int upper[n];
    char answer[n];

    printf("ciphertext: ");
    for (int i = 0; i < n; i++)
    {
        if (isalpha(plain[i]))
        {
            if (islower(plain[i]))
            {
                cipher[i] = plain[i] - 96;
            }
            else
            {
                cipher[i] = plain[i] - 64;
                upper[i] = 1;
            }
            int k = cipher[i];
            answer[i] = alphabet[k - 1];
            if (upper[i] == 1)
            {
                answer[i] = toupper(answer[i]);
            }
        }
        else
        {
            answer[i] = plain[i];
        }
        printf("%c", answer[i]);
    }
    printf("\n");
    return 0;
}
