#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &hand);

// Sends to output stream a Card's value as: Rank of Suit
// i.e., Ace of Spades
ostream & operator<<(ostream &, const vector<Card> &);

int main() {
	srand(2222);

    Deck deck;

    string saveOutput;
    cout << "Do you want to output all hands to a file?(Yes/No) ";
    cin >> saveOutput;

    string outputFileName = "";
    ofstream outputFileStream;
    if (saveOutput == "Yes")
    {
        cout << "Enter name of output file: ";
        cin >> outputFileName;

        outputFileStream.open(outputFileName.c_str());
    }

    int numberOfCardsPerHand = 0;
    cout << "Enter number of cards per hand: ";
    cin >> numberOfCardsPerHand;

    int numberOfDeals = 0;
    cout << "Enter number of deals (simulations): ";
    cin >> numberOfDeals;

    int numberOfPairInHand = 0;

    vector<Card> hand;
    bool hasPairInHand = false;

    for (int i = 0; i < numberOfDeals; i++)
    {
        hand.clear();

        deck.shuffleDeck();

        for (int j = 0; j < numberOfCardsPerHand; j++)
        {
            hand.push_back(deck.dealCard());
        }

        hasPairInHand = hasPair(hand);

        if (hasPairInHand)
        {
            numberOfPairInHand++;
        }

        if (saveOutput == "Yes" && outputFileStream)
        {
            if (hasPairInHand)
            {
                outputFileStream << "Found Pair!! ";
            }
            else
            {
                outputFileStream << "             ";
            }

            outputFileStream << hand;
            outputFileStream << endl;
        }
    }

    double chanceOfReceivingAPairInAHand = 100.0 * (double)numberOfPairInHand / (double)numberOfDeals;

    cout << "Chances of receiving a pair in a hand of " << numberOfCardsPerHand << " cards is: " << chanceOfReceivingAPairInAHand << "%" << endl;

	return 0;
}

bool hasPair(const vector<Card> &hand)
{
    unsigned size = hand.size();
    if (size > 1)
    {
        for (unsigned i = 0; i <= size - 2; i++)
        {
            for (unsigned j = i + 1; j <= size - 1; j++)
            {
                if (hand[i].rank() == hand[j].rank())
                {
                    return true;
                }
            }
        } 
    }

    return false; 
}

ostream & operator<<(ostream & out, const vector<Card> & cards)
{
    unsigned size = cards.size();
    for (unsigned i = 0; i < size; ++i)
    {
        out << cards[i];
        if (i != size - 1)
        {
            out << ", ";
        }
    }

    return out;
}
