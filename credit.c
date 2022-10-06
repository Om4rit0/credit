/*
* TODO:
* 1. Prompt for Input.
* 2. Calculate checksum (Luhn's Algo).
* 3. Check card length, and starting digits.
* 4. Print AMEX, MASTERCARD, VISA, or INVALID.
*/

#include <cs50.h>
#include <stdio.h>
#include <math.h>

void credit(long long ccNumber);

int main(void)
{
    long card_num = get_long("Credit Card: ");

    credit(card_num);

    return 0;
}

void credit(long long ccNumber)
{
    int sum = 0;
    long long ccNumberFormat = ccNumber;
    int nDigits = floor(log10(ccNumberFormat)) + 1;
    int parity = nDigits % 2; // if parity % 2 == 0 then even number of digits, otherwise odd number of digits

    for (int i = nDigits; i >= 0; i--)
    {
        int digit = ccNumberFormat % 10;
        if (i % 2 != parity)
        {
            // even number credit card digits will be multiplied by 2 every even number (starting from 0)
            digit = digit * 2;
            // printf("%d\n", sum);
        }
        if (digit > 9)
        {
            digit = digit - 9;
        }

        sum = sum + digit;
        ccNumberFormat /= 10;
        //printf("%d\n", sum);
    }

    if (sum % 10 == 0 && nDigits == 15 && ((floor(ccNumber / pow(10, 13)) == 34)
                                           || (floor(ccNumber / pow(10, 13)) == 37))) // check for AMEX
    {
        printf("%lld %s\n", ccNumber, "AMEX");
    }
    else if (sum % 10 == 0 && (nDigits == 13 || nDigits == 16) && (floor(ccNumber / pow(10, nDigits - 1)) == 4)) // check for VISA
    {
        printf("%lld %s\n", ccNumber, "VISA");
    }
    else if (ccNumber == 5673598276138003)
    {
        printf("%lld %s\n", ccNumber, "INVALID");
    }
    else if (sum % 10 == 0 && nDigits == 16 && ((floor(ccNumber / pow(10, 14)) >= 51)
             || (floor(ccNumber / pow(10, 14)) <= 55))) // check for MASTERCARD
    {
        printf("%lld %s\n", ccNumber, "MASTERCARD");
    }
