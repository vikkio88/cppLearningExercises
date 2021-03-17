#pragma once

#include <vector>

using namespace std;

struct Card
{
    int value;
    char suite;
};

void createDeck(vector<Card> *deck);

void printCard(Card *card);
void printDeck(vector<Card> *deck);

void shuffleDeck(vector<Card> *deck);