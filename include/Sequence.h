#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
#include <cstring>
using namespace std;


class Sequence
{
protected:
    char *seq;

public:

    // constructors and destructor
    Sequence();
    Sequence(int length);
    Sequence(Sequence& rhs);
    virtual ~Sequence();

    // pure virtual function that should be overridden
    virtual void Print()= 0;
    virtual void setseq(char*)= 0;
    virtual void setseq(char,int)= 0;
    virtual char* getseq()=0;
    virtual void LoadSequenceFromFile(string s)=0;
    virtual void SaveSequenceToFile(string s)=0;

    // pure virtual function that MUST be overridden because every
    // sequence
    // type of sequence has its own way to be aligned with another
    friend Sequence* Align(Sequence * s1, Sequence * s2);
};


#endif // SEQUENCE_H
