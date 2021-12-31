#include <iomanip>
#include "readFile.h"


readFile::readFile(){

}
void readFile::readData(std::ifstream &fin) { //reads in the tweets from file and creates review objects to store each tweet and sentiment
    if(!fin.is_open()) throw std::runtime_error("Could not open file");


    char firstline = 'x'; //removes header line
    while (firstline != '\n') {
        fin >> std::noskipws >> firstline;

    }
    for(int h = 0; h<20000; h++) {  //loops 20,000 times removing ID, date, query and username and storing the tweet and sentiment
    Review obj;
    int tweetSentiment = 0;
    fin >> tweetSentiment;
    char removeComma = 'x';
    fin >> removeComma;
    char removeID = 'x';
    while (removeID != ',')
        fin >> removeID;
    char removeDate = 'x';
        while (removeDate != ',')
            fin >> removeDate;
        char removeQuery = 'x';
        while (removeQuery != ',')
            fin >> removeQuery;
        char removeUser = 'x';
        while (removeUser != ',')
            fin >> removeUser;

    char test1 = 'x';
    DSstring object;
    int i = 0;
    fin >> test1;
    if(test1 == '@'){  //skips any @usernames at the beginning of tweet
        while(test1 != ' ')
            fin >> test1;
    }
    else {
        object.insert(test1, i);
        i++;
    }
    while (test1 != '\n') {
        fin >> test1;
        object.insert(test1, i);
        i++;
    }

        if(tweetSentiment == 4)
            obj.setPositiveOrNegative(1);
    if(tweetSentiment == 0)
        obj.setPositiveOrNegative(-1);



object.insert('\0', object.getStringSize()); //adds null character to end of string






    obj.setReviewText(object); //sets the tweet text for the review object
    data.push_back(obj); //stores tweet and sentiment in a vector of review objects
    reviewText.push_back(object); //stores tweet in a seperate vector containing only tweet text


    }

}
void readFile::getWords() { //takes each tweet and seperates all the different words and stores them in a positive or negative word vector

    int counter = 0;
    int j;
    int q = 0;

    for (int d = 0; d < reviewText.size(); d++) {
        j = 0;

        while (reviewText[counter].operator[](j) != '\0') {
            q = 0;
            DSstring object1;

            while ((reviewText[counter].operator[](j) != ' ' ) && (reviewText[counter].operator[](j) != '\0') ) {
                if (isalpha(reviewText[counter].operator[](j))) { //makes sure only letters are stored and not other symbols

                    object1.insert(reviewText[counter].operator[](j), q);
                    j++;
                    q++;
                }
                else {
                    j++;
                }
            }
            while(reviewText[counter].operator[](j) == ' ') {
                j++;

            }
            object1.makeLower(); //makes all letters lowercase
            word object2;
            object2.setWord(object1);

        if(data[counter].getPositiveOrNegative() == 1) { //checks sentiment of the tweet each individual word came from and stores them into positive/negative word vectors
            int temp = 0;
            if (wordsPositive.empty() && (object1.getStringSize() > 3) ) {
                object2.setSentimentValue(1);
                wordsPositive.push_back(object2);
            }
            else {
                for (int i = 0; i < wordsPositive.size(); ++i) { //makes sure no duplicate words are added
                    if (object1.operator==(wordsPositive[i].getWord())) {
                        wordsPositive[i].setSentimentValue(1);
                        temp++;
                    }
                }
                    if((temp == 0) && (object1.getStringSize() > 3)) {
                        object2.setSentimentValue(1);
                        wordsPositive.push_back(object2);
                    }
                }

        }

        if(data[counter].getPositiveOrNegative() == -1) {
                int temp = 0;
                if (wordsNegative.empty() && (object1.getStringSize() > 3) ) {
                    object2.setSentimentValue(-1);
                    wordsNegative.push_back(object2);
                }
                else {
                    for (int i = 0; i < wordsNegative.size(); ++i) {
                        if (object1.operator==(wordsNegative[i].getWord())) {
                            wordsNegative[i].setSentimentValue(-1);
                            temp++;
                        }
                    }
                    if((temp == 0) && (object1.getStringSize() > 3)) {
                        object2.setSentimentValue(-1);
                        wordsNegative.push_back(object2);
                    }
                }

        }

        }
        counter++;

}

std::vector<Review>().swap(data); //clears vector of review objects and tweet text now that we have vectors of positive and negative words
    std::vector<DSstring>().swap(reviewText);
}
void readFile::readTestData(std::ifstream &fin)  { //same process as the readData function but for the testing data set

    if(!fin.is_open()) throw std::runtime_error("Could not open file");


    char firstline = 'x';
    while (firstline != '\n') {
        fin >> std::noskipws >> firstline;

    }
    for(int h = 0; h<10000; h++) {
        Review obj;
        char removeID = 'x';
        while (removeID != ',')
            fin >> removeID;
        char removeDate = 'x';
        while (removeDate != ',')
            fin >> removeDate;
        char removeQuery = 'x';
        while (removeQuery != ',')
            fin >> removeQuery;
        char removeUser = 'x';
        while (removeUser != ',')
            fin >> removeUser;

        char test1 = 'x';
        DSstring object;
        int i = 0;
        fin >> test1;
        if(test1 == '@'){
            while(test1 != ' ')
                fin >> test1;
        }
        else {
            object.insert(test1, i);
            i++;
        }
        while (test1 != '\n') {
            fin >> test1;
            object.insert(test1, i);
            i++;
        }


        object.insert('\0', object.getStringSize());






        obj.setReviewText(object);
        testData.push_back(obj);
        testReviewText.push_back(object);


    }

}
void readFile::assignTestSentiment(std::ifstream &fin){ //reads sentiment values from sentiment dataset and stores them in the testData vector
    if(!fin.is_open()) throw std::runtime_error("Could not open file");
    char firstLine = 'x';
    while (firstLine != '\n') {
        fin >> std::noskipws >> firstLine;

    }
    for (int i = 0; i < testData.size(); ++i) {
        int tweetPosOrNeg = 0;
        fin >> tweetPosOrNeg;
        if(tweetPosOrNeg == 4)
            testData[i].reviewPosOrNeg = 1;
        if(tweetPosOrNeg == 0)
            testData[i].reviewPosOrNeg = -1;

        char removeComma = 'x';
        fin >> removeComma;
        char getId = 'x';
        DSstring IdNumber;
        int j = 0;
        while (getId != '\n') {
            fin >> getId;
            IdNumber.insert(getId,j);
            j++;
        }
        testData[i].setIdNumber(IdNumber);


    }
}

void readFile::getTestWords() {  //seperates words from test data set and assigns my positive or negative "guess"
    int counter = 0;
    testData[counter].myPositiveOrNegative = 0;
    int j;
    int q = 0;

    for (int d = 0; d < testReviewText.size(); d++) {
        j = 0;

        while (testReviewText[counter].operator[](j) != '\0') {
            q = 0;
            DSstring object1;

            while ((testReviewText[counter].operator[](j) != ' ' ) && (testReviewText[counter].operator[](j) != '\0') ) {
                if (isalpha(testReviewText[counter].operator[](j))) {

                    object1.insert(testReviewText[counter].operator[](j), q);
                    j++;
                    q++;
                }
                else {
                    j++;
                }
            }
            while(testReviewText[counter].operator[](j) == ' ') {
                j++;

            }
            object1.makeLower();
            for (int i = 0; i < wordsPositive.size() ; ++i) { //if the word is found in the postive words vector it assigns a value of one to the whole tweet
                if (object1 == wordsPositive[i].getWord())
                    testData[counter].setMyPositiveOrNegativeGuess(wordsPositive[i].getSentimentValue());
            }
            for (int k = 0; k < wordsNegative.size() ; ++k) { //if the word is found in the negative words vector it assigns a value of negative one to the whole tweet, it does this for each word in the tweet and the positive or negative guess is added. So if a tweet contains 10 words found only in the negative words vector it will have a final value of -10.  If the word is found in both positive and negative word vectors they will cancel out
                if (object1 == wordsNegative[k].getWord())
                    testData[counter].setMyPositiveOrNegativeGuess(wordsNegative[k].getSentimentValue());
            }


        }

        if(testData[counter].myPositiveOrNegative > 0)
            testData[counter].myPositiveOrNegative = 1;
        if(testData[counter].myPositiveOrNegative < 0)
            testData[counter].myPositiveOrNegative = -1;
        if(testData[counter].myPositiveOrNegative == 0){
            testData[counter].myPositiveOrNegative = 1;
        }
        counter++;
        testData[counter].myPositiveOrNegative = 0;
    }
   
}
void readFile::getAccuracy(std::ofstream &out) { //checks my assigned sentiment against the actual sentiment and calculates accuracy
    if(!out.is_open()) throw std::runtime_error("Could not open file");
    float correct = 0;
    float total = testData.size();
    std::vector<DSstring> rowNum;
    for (int i = 0; i < testData.size() ; ++i) {  //writes row numbers of tweets that were assigned incorrectly to txt file
        if(testData[i].myPositiveOrNegative == testData[i].reviewPosOrNeg)
            correct++;
        else {

            rowNum.push_back(testData[i].IdNumber);
        }
    }
    std::vector<Review>().swap(testData);
    std::vector<word>().swap(wordsPositive);
    std::vector<word>().swap(wordsNegative);
    std::vector<DSstring>().swap(testReviewText);
    float accuracy;
    accuracy = correct / total;
    out << correct << std::endl;
    out << std::setprecision(3) << accuracy << std::endl;
    for (int j = 0; j < rowNum.size() ; ++j) {
       int k = 0;
       while(rowNum[j].operator[](k) != '\0') {
           out << rowNum[j].operator[](k);
            k++;
       }

    }

out.close();
}