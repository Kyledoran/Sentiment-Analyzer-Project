#include "DSstring.h"
#ifndef REVIEW_H
#define REVIEW_H


class Review {
private:

public:
Review();
DSstring reviewText;
int reviewPosOrNeg;
int myPositiveOrNegative;
DSstring IdNumber;
void setReviewText(DSstring x);
DSstring getReviewText();
void setPositiveOrNegative(int x);
int getPositiveOrNegative();
void setMyPositiveOrNegativeGuess(int x);
int getMyPositiveOrNegativeGuess();
void setIdNumber(DSstring x);
DSstring getIdNumber();

};

#endif

