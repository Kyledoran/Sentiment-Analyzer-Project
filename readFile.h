#include <vector>
#include <iostream>
#include <fstream>
#include "DSstring.h"
#include "Review.h"
#include "word.h"



#ifndef READFILE_H
#define READFILE_H
class readFile {
private:
    std::vector<Review> data;
    std::vector<DSstring> reviewText;
    std::vector<Review> testData;
    std::vector<DSstring> testReviewText;
    std::vector<word> wordsPositive;
    std::vector<word> wordsNegative;



public:

    readFile();

    void readData(std::ifstream &fin);

    void readTestData(std::ifstream &fin);
    void assignTestSentiment(std::ifstream &fin);

    void getWords();

    void getTestWords();
    void getAccuracy(std::ofstream &out);
};
#endif
