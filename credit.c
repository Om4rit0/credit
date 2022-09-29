#include <cs50.h>
#include <stdio.h>

long card_num();
long luhn(long card);


int main(void)
{
   card_num();
}

long card_num()
{
    long card;
    
    do
    {
        card = get_long("Card #:");
    }
    while (card < 1);
    
    return card;
}

long luhn(long card)
{
    
}
