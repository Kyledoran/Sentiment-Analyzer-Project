#include <iostream>
#include <fstream>



#include "Review.h"
#include "readFile.h"

int main(int argc, char **argv) {
    std::ifstream fin(argv[1]);
    std::ifstream fin1(argv[2]);
    std::ifstream fin2(argv[3]);
   std::ofstream out(argv[4]);
    readFile test;
   test.readData(fin);
   test.getWords();
   test.readTestData(fin1);
   test.assignTestSentiment(fin2);
   test.getTestWords();
   test.getAccuracy(out);

}