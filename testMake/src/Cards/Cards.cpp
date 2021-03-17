#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "../include/Cards.h"

using namespace std;

char suites[] = {'H', 'D', 'C', 'S'};
int ranges[] = {1, 13};

void createDeck(vector<Card> *deck)
{
    for (int j = 0; j < 4; j++)
    {
        for (int i = ranges[0]; i <= ranges[1]; i++)
        {
            Card card{};
            card.value = i;
            card.suite = suites[j];
            deck->push_back(card);
        }
    }
}

void printCard(Card *card)
{
    cout << card->value << " " << card->suite << endl;
}

void printDeck(vector<Card> *deck)
{
    for (int i = 0; i < deck->size(); i++)
    {
        Card card = deck->at(i);
        printCard(&card);
    }
}

void shuffleDeck(vector<Card> *deck)
{
    random_device rd;
    default_random_engine rng(rd());
    shuffle(deck->begin(), deck->end(), rng);
}