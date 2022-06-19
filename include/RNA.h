#ifndef RNA_H
#define RNA_H
#include "DNA.h"
#include "Sequence.h"
#include "Protein.h"
#include "CodonsTable.h"
class DNA;
class CodonsTable;
enum RNA_Type {mRNA, tRNA, rRNA,noRNA};

class RNA :public Sequence
{
 	private:
       	RNA_Type type;
 	public:
		// constructors and destructor
       	RNA();
       	RNA(char* s, RNA_Type atype);
       	RNA(RNA& rhs);
       	~RNA();

       	//Setter and Getter For Sequence
        void setseq(char* seq1);
       	void setseq (char,int);
        char* getseq ();
        int getlen ();

        //Setter and Getter For Type
        void settype (RNA_Type t);
        RNA_Type gettype ();


        //Load and Save From File
        void LoadSequenceFromFile(string);
        void SaveSequenceToFile(string);

		// function to be overridden to print all the RNA information
       	void Print();


		// function to convert the RNA sequence into protein sequence
        // using the codonsTable object
        Protein ConvertToProtein( CodonsTable table);

		// function to convert the RNA sequence back to DNA
       	DNA ConvertToDNA();

       	//Assignment and Operator Overload
        friend ostream&operator<<(ostream& out , RNA& a);
        friend istream&operator>>(istream& in , RNA& a);
        RNA operator = (const RNA& );
        RNA operator +(const RNA& );
        bool operator==(const RNA & );
        bool operator !=(const RNA & );

};


#endif // RNA_H
