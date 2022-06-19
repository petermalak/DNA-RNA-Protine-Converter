#ifndef PROTEIN_H
#define PROTEIN_H
#include "DNA.h"
#include "Sequence.h"
class DNA;
enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function, noProtein};

class Protein :public Sequence
{
 	private:
       	Protein_Type type;
 	public:

		// constructors and destructor
		Protein();
		Protein(char* p);
		~Protein();
        void setseq (int n);
        void setseq (char* );
       	void setseq (char n,int x);
        char* getseq ();
        void settype (Protein_Type t);
        Protein_Type gettype ();

        void LoadSequenceFromFile(string);
        void SaveSequenceToFile(string);

		// return an array of DNA sequences that can possibly generate
        // that protein sequence
        DNA* GetDNAStrandsEncodingMe(DNA bigDNA);

        void Print();

        //Assignment and cout overload
        friend ostream&operator<<(ostream& out , Protein& a);
        friend istream&operator>>(istream& in , Protein& a);
        Protein operator = (const Protein& rhs);
        Protein operator +(const Protein & );
        bool operator==(const Protein & );
        bool operator !=(const Protein & );

};


#endif // PROTEIN_H
