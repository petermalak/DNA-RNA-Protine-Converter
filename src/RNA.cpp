#include "RNA.h"
#include "DNA.h"
#include "CodonsTable.h"
#include "Sequence.h"
#include "Protein.h"
#include <fstream>
class Protein;
RNA::RNA()
{
    type=noRNA;
    seq =new char[100]();
}
RNA::RNA(char* s, RNA_Type atype)
{
    if(100<strlen(s))
    {
            delete [] seq;
    seq = new char [strlen(s)]();

    }
    type=atype;
    for(int i=0;i<strlen(s);i++)
    {
        this->seq[i]=s[i];
        this->seq[i+1]='\0';
    }

}
RNA::RNA(RNA& rhs)
{
    if(100<strlen(rhs.seq))
    {
            delete [] seq;
    seq = new char [strlen(rhs.seq)]();

    }
    for(int i=0;i<strlen(rhs.seq);i++)
    {
        this->seq[i]=rhs.seq[i];
        this->seq[i+1]='\0';
    }
    type=rhs.type;

}
RNA::~RNA()
{
 delete []seq;
}

void RNA::Print()
{
//    ofstream outFile;
//    outFile.open("Fileout.txt", ios::app);
    cout<<"The RNA Sequence : "<<seq<<endl;
    if(type==0)
    cout<<"The Type : mRNA"<<endl;
    else if(type==1)
    cout<<"The Type : tRNA"<<endl;
    else if(type==2)
    cout<<"The Type : rRNA"<<endl;
    else
    cout<<"The Type : noType"<<endl;


//    outFile.close();

}
DNA RNA::ConvertToDNA()
{
    DNA *x=new DNA;
    int y=strlen(seq)+1;
    char seq1[y];
    char seq2[y];
    strcpy(seq1, seq);
    for(int i=0;i<y;i++)
    {
        if(seq[i]=='U')
        {
            //seq[i]->setseq('T',i);
            seq1[i]='T';
            seq1[i+1]='\0';
        }

            else
            {
//                x->setseq(seq[i],i);
                seq1[i]=seq[i];
                seq1[i+1]='\0';
            }


    }
    strcpy(seq2,seq1);
    for(int i=0;i<y;i++)
    {
        if(seq1[i]=='A')
            seq2[i]='T';
        if(seq1[i]=='T')
            seq2[i]='A';
        if(seq1[i]=='C')
            seq2[i]='G';
        if(seq1[i]=='G')
            seq2[i]='C';
    }
    int n=2;
    for(int i=0; i<y+1; i++)
    {
       seq1[i]=seq2[y-n];
        n++;
    }
    x->setseq(seq1);
    //x->complementary_strand->setseq(seq1);
    x->BuildComplementaryStrand();
    cout<<endl;
    x->Print();
    cout<<endl;
    return *x;

}
Protein RNA::ConvertToProtein(CodonsTable  table)
{
    Protein x;
    table.LoadCodonsFromFile("File.txt");
    x.setseq(seq);
    x.setseq(table.getaa(seq));
    //cout<<endl;
    //x.Print();
    return x;
}
void RNA::setseq(char* seq1)
{
    if(100<strlen(seq1))
    {
            delete [] seq;
    seq = new char [strlen(seq1)]();

    }
    for(int i=0;i<strlen(seq1);i++)
    {
        seq[i]=seq1[i];
        seq[i+1]='\0';
    }

}
char* RNA::getseq ()
{
    return seq;
}
void RNA::setseq (char s,int x)
{
    seq[x]=s;
}
int RNA::getlen ()
{
    int y;
    y=strlen(seq);
    return y;
}
RNA RNA::operator = (const RNA& a)
{
        if(100<strlen(a.seq))
    {
            delete [] seq;
    seq = new char [strlen(a.seq)]();

    }

    type = a.type;
//    delete [] seq;
//    seq = new char [strlen(a.seq)]();
    for(int i=0; i<strlen(a.seq); i++)
    {
        seq[i]=a.seq[i];
        seq[i+1] = '\0';
    }
    return *this;
}
void RNA::LoadSequenceFromFile(string s)
{
    int i=0;
    ifstream FromFile;
    FromFile.open("File1.txt");
    //FromFile.open(s.c_str());
    while(!FromFile.eof())
    {
        FromFile>>seq[i];
        i++;
    }
}
void RNA::SaveSequenceToFile(string s)
{
        ofstream outFile;
    outFile.open("Fileout.txt", ios::app);
    //outFile.open(s.c_str(), ios::app);
    outFile<<endl<<endl<<"The RNA Sequence : "<<seq<<endl;
    if(type==0)
    outFile<<"The Type : mRNA"<<endl;
    else if(type==1)
    outFile<<"The Type : tRNA"<<endl;
    else if(type==2)
    outFile<<"The Type : rRNA"<<endl;
    else
    outFile<<"The Type : noRNA"<<endl<<endl<<endl;

    outFile.close();

}
istream&operator>>(istream& in , RNA& a)
{
    cout<<"Enter the Sequence : ";
    in>>a.seq;
    return in;
}
ostream&operator<<(ostream& out , RNA& a)
{
    cout<<"The Sequence : ";
    out<<a.seq;
    cout<<endl;
    cout<<"The Type : ";
    out<<a.type;
    return out;
}
void RNA::settype (RNA_Type t)
{
    type=t;
}
RNA_Type RNA::gettype ()
{
    return type;
}
RNA RNA::operator +(const RNA & rhs)
{
    RNA f;
    f.type=type;
    int length=strlen(seq)+strlen(rhs.seq)+1;
    //delete []seq;
    f.seq=new char[length];
    for(int i=0;i<strlen(seq);i++)
    {
        f.seq[i]=seq[i];
    }
    int n=0;
    for(int i=strlen(seq);i<length;i++)
    {
        f.seq[i]=rhs.seq[n];
        f.seq[i+1]='\0';
        n++;
    }
    f.Print();
    cout<<endl;
    return f;
}
bool RNA::operator ==(const RNA & a)
{

    if(strlen(seq)!=strlen(a.seq))
        return 0;
    else
    {
       int length=strlen(seq);
       int counter=0;
       int i=0;
       while(seq[i]==a.seq[i]  && i<length)
       {
           counter++;
           i++;
       }
       if(counter==length)
        return 1;
       else
        return 0;
    }
}
bool RNA::operator !=(const RNA & a)
{
     if(strlen(seq)!=strlen(a.seq))
        return 1;
    else
    {
       int length=strlen(seq);
       int counter=0;
       int i=0;
       while(seq[i]==a.seq[i]  && i<length)
       {
           counter++;
           i++;
       }
       if(counter==length)
        return 0;
       else
        return 1;
    }
}
