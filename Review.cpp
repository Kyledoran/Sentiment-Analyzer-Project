#include "Review.h"
Review::Review(){

}

void Review::setReviewText(DSstring x) {
    reviewText = x;
}
DSstring Review::getReviewText() {
    return reviewText;
}
void Review::setPositiveOrNegative(int x) {
    reviewPosOrNeg = x;
}
int Review::getPositiveOrNegative() {
    return reviewPosOrNeg;
}
void Review::setMyPositiveOrNegativeGuess(int x) {
    myPositiveOrNegative =  myPositiveOrNegative + x;
}
int Review::getMyPositiveOrNegativeGuess() {
    return myPositiveOrNegative;
}
void Review::setIdNumber(DSstring x)  {
    IdNumber = x;
}
DSstring Review::getIdNumber() {
    return IdNumber;
}