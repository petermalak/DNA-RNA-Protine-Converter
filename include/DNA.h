#ifndef DNA_H
#define DNA_H
#include "Sequence.h"
#include "RNA.h"

class RNA;

enum DNA_Type {promoter, motif, tail, noncoding,noDNA};

class DNA :public Sequence
{
private:
    DNA_Type type;
    DNA*  complementary_strand;
    int startChar;
    int endChar;

public:
    // constructors and destructor
    DNA();
    DNA(int n);
    DNA(char* s, DNA_Type atype);
    DNA(DNA& rhs);
    ~DNA();

    //Setter and Getters for Sequence
    void setseq (char* seq1);
    void setseq (char,int);
    char* getseq ();
    char getseq (int);
    int getlen ();
    char* getcomp(){return complementary_strand->seq; }
    char getcomp(int f){return complementary_strand->seq[f];}

    //Start and End Setters and Getters
    void setstart (int sc);
    void setend (int ec);
    int getstart ();
    int getend ();

    // function printing DNA sequence information to user
    void Print();

    // function to build the second strand/pair of DNA sequence
    void BuildComplementaryStrand();

    //DNA Type setter and getters
    void settype (DNA_Type t);
    DNA_Type gettype ();

    // function to convert the DNA sequence to RNA sequence
    RNA ConvertToRNA();

    //Save and Load From File
    void LoadSequenceFromFile(string);
    void SaveSequenceToFile(string);

    //Operators Overload
    friend ostream&operator<<(ostream& out , DNA& a);
    friend istream&operator>>(istream& in , DNA& a);
    DNA operator =(const DNA & );
    DNA operator +(const DNA & );
    bool operator==(const DNA & );
    bool operator !=(const DNA & );



};


#endif // DNA_H
