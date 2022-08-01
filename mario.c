#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Questionar Height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //Fazer escada
    for (int layer = 0; layer < height; layer++)
    {
        //Esquerda
        int n = height - layer;
        for (int i = 1; i < n; i++)
        {
            printf(" ");
        }

        for (int i = 0; i <= layer; i++)
        {
            printf("#");
        }

        //Buraco
        for (int i = 0; i < 2; i++)
        {
            printf(" ");
        }

        //Direita
        for (int i = 0; i <= layer; i++)
        {
            printf("#");
        }

        //Quebra de linha
        printf("\n");
    }
}
