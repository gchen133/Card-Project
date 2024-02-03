#include <algorithm>
#include "Deck.h"

using namespace std;

Deck::Deck()
{
    for (int r = 13; r >= 1; r--)
    {
        Card card('s', r);
        theDeck.push_back(card);
    }

    for (int r = 13; r >= 1; r--)
    {
        Card card('h', r);
        theDeck.push_back(card);
    }

    for (int r = 13; r >= 1; r--)
    {
        Card card('d', r);
        theDeck.push_back(card);
    }

    for (int r = 13; r >= 1; r--)
    {
        Card card('c', r);
        theDeck.push_back(card);
    }
}

Card Deck::dealCard()
{    
    Card card = theDeck.back();
    dealtCards.push_back(card);

    theDeck.pop_back();
    return card;
}

// THE FOLLOWING shuffleDeck() IMPLEMENTATION IS GIVEN TO YOU. 
// DO NOT CHANGE!!

/* Places all cards back into theDeck and shuffles them into random order.
   Uses random_shuffle function from algorithm library.
*/
void Deck::shuffleDeck() {
	for (unsigned i = 0; i < dealtCards.size(); ++i) {
		theDeck.push_back(dealtCards.at(i));
	}
	dealtCards.clear();
	random_shuffle(theDeck.begin(), theDeck.end());
}

unsigned Deck::deckSize() const
{
    return theDeck.size();
}