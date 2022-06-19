#include "DNA.h"
#include "RNA.h"
#include "string.h"
#include <fstream>

DNA::DNA()
{
    type=noDNA;
    complementary_strand=new DNA(0);
    seq=new char[100]();
    int startChar=0;
    int endChar=100;
}
DNA::DNA(int n)
{
    complementary_strand=nullptr;
    type=noDNA;
    seq=new char[100]();
}
DNA::DNA(char* s, DNA_Type atype)
{
    if(100<strlen(s))
    {
            delete [] seq;
    seq = new char [strlen(s)]();

    }
    type= atype;
    complementary_strand=new DNA(0);
    for(int i=0; i<strlen(s); i++)
    {
        this->seq[i]=s[i];
        this->seq[i+1]='\0';
    }
}
DNA::DNA(DNA& rhs)
{
     if(100<strlen(rhs.seq))
    {
            delete [] seq;
    seq = new char [strlen(rhs.seq)]();

    }
    complementary_strand=rhs.complementary_strand;
    type=rhs.type;
    for(int i=0; i<strlen(rhs.seq); i++)
    {
        this->seq[i]=rhs.seq[i];
        this->seq[i+1]='\0';
    }
}
DNA::~DNA()
{
   // if(complementary_strand!=nullptr)
   // delete []complementary_strand;
    delete []seq;
}
void DNA::setseq (char* seq1)
{
        if(100<strlen(seq1))
    {
            delete [] seq;
    seq = new char [strlen(seq1)]();

    }
    for (int i =0 ; i<strlen(seq1) ; i++)
    {
        this->seq[i]=seq1[i];
        this->seq[i+1] = '\0';
    }

}
char* DNA::getseq ()
{
    return seq;
}
int DNA::getlen ()
{
    int y=strlen(seq);return y;
}
void DNA::setseq (char x,int n)
{
    seq[n]=x;
}
char DNA::getseq (int l)
{
    return seq[l];
}
void DNA::setstart (int sc)
{
    startChar=sc;
}
void DNA::setend (int ec)
{
    endChar=ec;
}
int DNA::getstart ()
{
    return startChar;
}
int DNA::getend ()
{
    return endChar;
}

void DNA::Print()
{
    cout<<"The DNA Sequence : "<<seq<<endl;
    cout<<"The Complementary Strand : "<<complementary_strand->seq<<endl;
    if(type==0)
    cout<<"The Type : promoter"<<endl;
    else if(type==1)
    cout<<"The Type : motif"<<endl;
    else if(type==2)
    cout<<"The Type : tail"<<endl;
    else if(type==3)
    cout<<"The Type : noncoding"<<endl;
    else
    cout<<"The Type : noType"<<endl;
}
void DNA::BuildComplementaryStrand()
{
    int y=strlen(seq)+1;
    DNA d;
    d.complementary_strand->seq=new char[y];

    for(int i=0; i<y-1; i++)
    {

        if (seq[i]=='A' || seq[i]=='a')
            d.complementary_strand->seq[i]='T';

        else if (seq[i]=='G' || seq[i]=='g')
           d.complementary_strand->seq[i]='C';

        else if (seq[i]=='T' || seq[i]=='t')
            d.complementary_strand->seq[i]='A';

        else if (seq[i]=='C' || seq[i]=='c')
            d.complementary_strand->seq[i]='G';

    }
    int n=2;
    d.complementary_strand->seq[y-1]='\0';
    for(int i=0; i<y+1; i++)
    {
        complementary_strand->seq[i]=d.complementary_strand->seq[y-n];
        n++;
    }
    complementary_strand->seq[y-1]='\0';
//    cout<<endl;
//    cout<<"The Complementary Strand of the Sequence : ";
//    cout<<complementary_strand->seq;
//    cout<<endl;
}
void DNA::settype (DNA_Type t)
{
    type=t;
}
DNA_Type DNA::gettype ()
{
    return type;
}

RNA DNA::ConvertToRNA()
{
    RNA r1;
    int y=strlen(seq)+1;

    for(int i=0; i<y; i++)
    {
        if(complementary_strand->seq[i]=='T')
           {

            r1.setseq('U',i);
            r1.setseq('\0',i+1);

           }
        else
            {
            r1.setseq(complementary_strand->seq[i],i);
            }
    }
//    cout<<endl;
//    r1.Print();

    return r1;
}
DNA DNA::operator =(const DNA & a)
{
        if(100<strlen(a.seq))
    {
            delete [] seq;
    seq = new char [strlen(a.seq)]();

    }
        for (unsigned int i = 0 ; i <strlen(a.seq); i++)
        {
            seq[i] = a.seq[i];
            seq[i+1] = '\0';
            complementary_strand->seq[i] = a.complementary_strand->seq[i];
            complementary_strand->seq[i+1]='\0';
        }
        type= a.type;
        startChar= a.startChar;
        endChar= a.endChar;
        return *this;
}
void DNA::LoadSequenceFromFile(string s)
{
    int i=0;
    ifstream FromFile;
    FromFile.open("File1.txt");
    //FromFile.open(s.c_str());
    while(!FromFile.eof())
    {
        FromFile>>seq[i];
        //seq[i+1]='\0';
        i++;
    }
}
void DNA::SaveSequenceToFile(string s)
{
     ofstream outFile;
    outFile.open("Fileout.txt", ios::app);
    //outFile.open(s.c_str(), ios::app);

    outFile<<endl<<"The DNA Sequence : "<<seq<<endl;
    outFile<<"The Complementary Strand : "<<complementary_strand->seq<<endl;
    if(type==0)
    outFile<<"The Type : promoter"<<endl;
    else if(type==1)
    outFile<<"The Type : motif"<<endl;
    else if(type==2)
    outFile<<"The Type : tail"<<endl;
    else if(type==3)
    outFile<<"The Type : noncoding"<<endl;
    else
    outFile<<"The Type : noDNA"<<endl<<endl<<endl;

    outFile.close();

}
ostream&operator<<(ostream& out , DNA& a)
{
    cout<<"The Sequence : ";
    out<<a.seq;
    cout<<endl;
    cout<<"The Complementary Sequence : ";
    out<<a.complementary_strand;
    cout<<endl;
    cout<<"The Type : ";
    out<<a.type;
    return out;
}
istream&operator>>(istream& in , DNA& a)
{
    cout<<"Enter the Sequence : ";
    in>>a.seq;
}
DNA DNA::operator +(const DNA & rhs)
{
    DNA f;
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
    f.BuildComplementaryStrand();
    f.Print();
    cout<<endl;
    return f;
}
bool DNA::operator ==(const DNA & a)
{

    if(strlen(seq)!=strlen(a.seq))
        return 0;
    else
    {
       int length=strlen(seq);
       int counter=0;
       int i=0;
       while(seq[i]==a.seq[i] && i<length)
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
bool DNA::operator !=(const DNA & a)
{
     if(strlen(seq)!=strlen(a.seq))
        return 1;
    else
    {
       int length=strlen(seq);
       int counter=0;
       int i=0;
       while(seq[i]==a.seq[i] && i<length)
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

