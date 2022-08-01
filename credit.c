#include <cs50.h>
#include <stdio.h>

//Function call
long verifier(long credit, long decimal, long result, long resulttotal);

int main(void)
{
    //Get card number
    long card = get_long("Card: ");

    //Calculate number of digits of card
    long digits = 0;
    long i = card;

    //Number of digits consist in dividing a number per 10 until it gets decimal
    for (; i > 0; i = i / 10)
    {
        digits = digits + 1;
    }

    //Calculate algarisms

    long decimal = 10;
    long result = 0;
    long counter = digits;
    long resulttotal = 0;
    long validity = 0;
    long factor = 0;
    long factora = 0;
    long factorb = 0;

    while (counter > 0)
    {
        result = verifier(card, decimal, result, resulttotal);
        counter--;
        resulttotal = resulttotal + result;
        factor = result * 10 / decimal;
        {
            //Odd and even events need to be treated differently
            //Both counter and digit number events will change based on odd/even
            if (digits % 2 == 0)
            {
                if (counter % 2 == 0)
                {
                    if (factor >= 5)
                    {
                        factora = (2 * factor) % 10;
                        validity = validity + factora + 1;
                    }
                    validity = validity + (2 * factor);
                }
                else
                {
                    validity = validity + (result * 10 / decimal);
                }
            }
            else
            {
                if (counter % 2 == 0)
                {
                    validity = validity + (result * 10 / decimal);
                }
                else
                {
                    if (factor >= 5)
                    {
                        factora = (2 * factor) % 10;
                        validity = validity + factora + 1;
                    }
                    else
                    {
                        validity = validity + (2 * factor);
                    }
                }
                factor = 0;
            }
        }
        decimal = decimal * 10;
    }

    //Validation
    if (validity % 10 == 0)
    {
        //None of the cards has less than 13 digits
        if (digits < 13)
        {
            printf("INVALID\n");
        }
        else
        {
            if (digits == 13)
            {
                printf("VISA\n");
            }
            if (digits > 16)
            {
                printf("INVALID\n");
            }
            //Limit cards by the start number
            if ((digits == 15 && resulttotal < 350000000000000 && resulttotal > 340000000000000) || (digits == 15
                    && resulttotal < 380000000000000 && resulttotal > 370000000000000))
            {
                printf("AMEX\n");
            }
            if ((digits == 15 && resulttotal > 350000000000000 && resulttotal < 370000000000000) || (digits == 15
                    && resulttotal > 380000000000000) || (digits == 15 && resulttotal < 340000000000000))
            {
                printf("INVALID\n");
            }
            if (digits == 16 && resulttotal < 5000000000000000)
            {
                printf("VISA\n");
            }
            if (digits == 16 && resulttotal > 5000000000000000 && resulttotal < 5600000000000000)
            {
                printf("MASTERCARD\n");
            }
            if (digits == 16 && resulttotal > 5600000000000000)
            {
                printf("INVALID\n");
            }
        }
    }
    else
    {
        {
            printf("INVALID\n");
        }
    }

}

//Function to get result
long verifier(long credit, long decimal, long result, long resulttotal)
{
    return credit % decimal - resulttotal;

}
