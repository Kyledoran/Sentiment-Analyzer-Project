#include "word.h"

word::word(){
    sentimentValue = 0;
}
void word::setWord(DSstring x) {
    words = x;
}
DSstring word::getWord() {
    return words;
}
void word::setSentimentValue(int x) {
    sentimentValue = sentimentValue + x;
}
int word::getSentimentValue() {
    return sentimentValue;
}