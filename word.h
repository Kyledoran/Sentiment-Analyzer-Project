#include "DSstring.h"
#ifndef WORD_H
#define WORD_H


class word {

private:



public:
DSstring words;
int sentimentValue;
word();
void setWord(DSstring x);
DSstring getWord();
void setSentimentValue(int x);
int getSentimentValue();





};

#endif