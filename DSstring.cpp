#include "DSstring.h"
#include <iostream>
#include <cstring>



DSstring::DSstring() //creates DSstring object with size 0
{
    stringSize = 0;
    n = nullptr;
}

DSstring::DSstring(int sz) //creates DSstring object with any size
{
    stringSize = sz;
    n = new char[stringSize];
}

void DSstring::print(){ //prints DSstring to console
    for (int i = 0; i < stringSize; ++i) {

            std::cout << n[i];

    }
std::cout << std::endl;
}
DSstring DSstring::operator+(DSstring& obj) //combines two DSstrings together
{
    int newsz = stringSize + obj.stringSize;
    DSstring out(newsz);
    for(int i = 0 ; i < stringSize;i++)
        out.n[i] = n[i];
    for(int i = stringSize;i<newsz;i++)
        out.n[i] = obj.n[i-stringSize];
    return out;
}

char DSstring::operator[](int i) //accesses individual char of DSstring object
{
    return n[i];
}

int DSstring::getStringSize() //returns size of DSstring object
{
    return stringSize;
}

bool DSstring::operator==(DSstring obj) //checks to see if two DSstrings are equivalent
{
    if(stringSize != obj.stringSize)
        return false;
    for(int i = 0 ; i <  stringSize;  i++)
        if(n[i] != obj.n[i]) return false;
    return true;
}

bool DSstring::isEmpty()
{
    return stringSize == 0;
}

void DSstring::empty()
{
    stringSize = 0;
}

void DSstring::setAt(char c,int i)
{
    n[i] = c;
}

void DSstring::makeUpper()
{
    for(int i = 0 ; i <  stringSize;  i++)
        if(n[i] >= 'a' && n[i] <= 'z')
            n[i] = n[i] + 'A' - 'a';
}
void DSstring::makeLower()
{
    for(int i = 0 ; i <  stringSize;  i++)
        if(n[i] >= 'A' && n[i] <= 'Z')
            n[i] = n[i] + 'a' - 'A';
}

void DSstring::insert(char c,int i)  //inserts character into char array and allows array to expand as needed
{
    if(n == nullptr){
        //std::cout << "In insert - if" << std::endl;
        n = new char[1];
        n[0] = c;
        stringSize = 1;
    }
    else {

        stringSize = stringSize + 1;
        //std::cout << "In insert -- else" << std::endl;
        char *temp = n;
        n = new char[stringSize + 1];
        for(int j = 0; j < stringSize; j++){
            n[j] = temp[j];
        }

        n[i] = c;
        n[stringSize] = '\0';
    }
}
void DSstring::setCount() {
     count = 0;
    while(n[count]!=',' )
      count++;

}


DSstring::DSstring(const DSstring *sample){
    if(sample->n != nullptr) {
        n = sample->n;

        n[strlen(sample->n)] = '\0';
    }
}

DSstring& DSstring::operator=(const char* c){
    char* temp = n;
    n = new char[strlen(c)+1];
     strcpy(n,c);
     n[strlen(c) +1] = '\0';
     delete[] temp;
     return *this;

}
