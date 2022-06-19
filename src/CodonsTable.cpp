#include "CodonsTable.h"
#include <iostream>
#include <fstream>
using namespace std;
CodonsTable::CodonsTable()
{
    //ctor
    codonsFileName="File.txt";
}

CodonsTable::~CodonsTable()
{
    //dtor
}
void CodonsTable::setfname(std::string s)
{
    codonsFileName=s;
}
void CodonsTable::LoadCodonsFromFile(std::string codonsFileName)
{
    int num[64];
    ifstream inFile;
    inFile.open(codonsFileName.c_str());
    //inFile.open("File.txt");
    for(int i=0;i<64;i++)
    {
        inFile>>num[i]>>codons[i].value[0]>>codons[i].value[1]>>codons[i].value[2]>>codons[i].AminoAcid;
        codons[i].value[3]='\0';
    }
    inFile.close();

}
Codon CodonsTable::getAminoAcid(char * value)
{

    for(int i=0;i<65;i++)
    {

        if(codons[i].value[0]==value[0] && codons[i].value[1]==value[1] && codons[i].value[2]==value[2])
            {
                if (codons[i].AminoAcid=='X')
                {
                    cout<<"No AminoAcid Matches";
                    break;
                }
                cout<<"The Amino Acid -> "<<codons[i].AminoAcid;

                return codons[i];
            }

    }
    cout<<"No AminoAcid Matches!! ";

}
void CodonsTable::setCodon(char * value, char AminoAcid, int index)
{
    codons[index].value[0]=value[0];
    codons[index].value[1]=value[1];
    codons[index].value[2]=value[2];
    codons[index].value[3]='\0';
    codons[index].AminoAcid=AminoAcid;
}
char* CodonsTable::getaa(char* p)
{
    int length=((strlen(p))/3)+1;
    char *x=new char[length]();
    int n=0;

        for(int j=0;j<strlen(p);j+=3)
        {
            for(int i=0;i<65;i++)
            {
                if(codons[i].value[0]==p[j] && codons[i].value[1]==p[j+1] && codons[i].value[2]==p[j+2])
                {
                    if (codons[i].AminoAcid=='X')
                    {
                        return x;
                    }
                    else
                    {
                        x[n]=codons[i].AminoAcid;
                        x[n+1]='\0';
                        n++;
//                      if(n>=length)
//                      return x;
                        break;
                    }
                }
            }
        }

    return x;
}
