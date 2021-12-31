
#ifndef DSSTRING_H
#define DSSTRING_H


class DSstring {
private:
    char* n;
    int stringSize;
    int count;
public:
    DSstring();
    DSstring(int size);

    DSstring (const char* d);
    DSstring& operator=(const char* c);
    DSstring operator+(DSstring& obj);
    DSstring (const DSstring *sample);




    bool operator==(DSstring obj);
    char operator[](int i);
    bool isEmpty();
    void empty();
    int getStringSize();
    void setAt(char c,int i);
    void makeUpper();
    void makeLower();
    void insert(char c,int i);
    void print();
    void setCount();
};

#endif


