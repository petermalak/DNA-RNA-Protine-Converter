#include "Protein.h"
#include "DNA.h"
#include <fstream>

Protein::Protein()
{
    type=noProtein;
    seq=new char[100]();
}
Protein::Protein(char* p)
{
    if(100<strlen(p))
    {
            delete [] seq;
    seq = new char [strlen(p)]();

    }

    type=noProtein;
    for(int i=0;i<strlen(p);i++)
    {
        this->seq[i]=p[i];
        this->seq[i+1]='\0';
    }
}

Protein::~Protein()
{
     //delete []seq;
}

void Protein::Print()
{
//    ofstream outFile;
//    outFile.open("Fileout.txt", ios::app);
    cout<<"The Protein Sequence : "<<seq<<endl;
    if(type==0)
    cout<<"The Type : Hormon"<<endl;
    else if(type==1)
    cout<<"The Type : Enzyme"<<endl;
    else if(type==2)
    cout<<"The Type : TF"<<endl;
    else if(type==3)
    cout<<"The Type : Celluar_Function"<<endl;
    else
    cout<<"The Type : noType"<<endl<<endl<<endl;
//    outFile.close();

}

void Protein::setseq ( int n)
{
    seq=new char[n]();
}
char* Protein::getseq ()
{
    return seq;
}
void Protein::setseq (char* seq1)
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
void Protein::setseq (char n,int x)
{
    seq[x]=n;
}
Protein Protein::operator = (const Protein& a)
{
    type = a.type;
    if(100<strlen(a.seq))
    {
            delete [] seq;
    seq = new char [strlen(a.seq)]();

    }
    for(unsigned int i=0; i<strlen(a.seq); i++)
    {
        seq[i]=a.seq[i];
        seq[i+1] = '\0';
    }
    return *this;
}
void Protein::LoadSequenceFromFile(string s)
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
void Protein::SaveSequenceToFile(string s)
{
       ofstream outFile;
    outFile.open("Fileout.txt", ios::app);
    //outFile.open(s.c_str(), ios::app);
    outFile<<endl<<endl<<"The Protein Sequence : "<<seq<<endl;
    if(type==0)
    outFile<<"The Type : Hormon"<<endl;
    else if(type==1)
    outFile<<"The Type : Enzyme"<<endl;
    else if(type==2)
    outFile<<"The Type : TF"<<endl;
    else if(type==3)
    outFile<<"The Type : Celluar_Function"<<endl;
    else
    outFile<<"The Type : noType"<<endl<<endl<<endl;
    outFile.close();

}
DNA* Protein::GetDNAStrandsEncodingMe(DNA bigDNA)
{
    int num=0;
    int counter=0;
    int Dna_len = bigDNA.getlen();
    int Protein_len = strlen(seq);
    int Temp_len = (Protein_len*3)+1;
    int Temp_num =((Dna_len/Temp_len)+(Dna_len-Temp_len))+1;
    CodonsTable m;
    bigDNA.BuildComplementaryStrand();
    DNA *result=new DNA[100];
    DNA Temp;
    //Temp.seq=new char[Temp_len];
    DNA dnaseq;
    //dnaseq.seq=new char[Temp_len];
    DNA compseq ;
    //compseq.seq=new char[Temp_len];
    //dnaseq.setseq(bigDNA.getseq());
    //compseq.setseq(bigDNA.getcomp());
    RNA dnaseq1;
    RNA compseq1;
    Protein dnaseq2;
    Protein compseq2;
    for(int i=0;i<Temp_num-1;i++)
    {
        int n=0;
        int n1=0;

            for(int h=i;h<Temp_len-1+i;h++)
            {

                Temp.setseq(bigDNA.getseq(h),n);
                Temp.setseq('\0',n+1);
                n++;
            }
            if((Temp.getlen())!=(Temp_len-1))
            {
                return result;
            }
            Temp.BuildComplementaryStrand();
            for(int h=i;h<Temp_len-1+i;h++)
            {

               compseq.setseq(Temp.getcomp(n1),n1);
                compseq.setseq('\0',n1+1);
                n1++;
            }
            if((compseq.getlen())!=(Temp_len-1))
            {
                return result;
            }
            Temp.BuildComplementaryStrand();
            dnaseq1=Temp.ConvertToRNA();
            dnaseq2=dnaseq1.ConvertToProtein(m);
            compseq.BuildComplementaryStrand();
            compseq1=compseq.ConvertToRNA();
            compseq2=compseq1.ConvertToProtein(m);
            if(*this==dnaseq2)
            {

                //cout<<counter<<endl;
                cout<<"h : "<<(Temp_len-1+i)<<endl;
                Temp.Print();
               result[num].setseq(dnaseq2.getseq());
                num++;
            }
            if(*this==compseq2)
            {
                counter++;
                //cout<<counter<<endl;
                cout<<"h : "<<(Temp_len-1+i)<<endl;
                compseq.Print();
                result[num].setseq(compseq2.getseq());
                num++;
            }

    }
    return result;
}
//DNA* Protein::GetDNAStrandsEncodingMe( DNA  bigDNA)
//{
//    int y=strlen(seq);
//    int z=y*3;
//    int counter=0;
//    CodonsTable m;
//    RNA x;
//    int n=0;
//    Protein f;
//    //DNA *seq1=new DNA[100];
//    //char **seq1=new char*[100];
//    char *seq1=new char[100];
//    char *seq2=new char[100];
//    char pseq[strlen(seq)];
//    strcpy(pseq,seq);
//    //m.LoadCodonsFromFile();
//    //bigDNA.BuildComplementaryStrand();
//    //x=bigDNA.ConvertToRNA();
//    //f=x.ConvertToProtein(m);
//    //char seq[strlen(bigDNA.seq)];
//    int s;//=0;
//    int h=0;
//    DNA temp;
//    int c=0;
////    for(int m=0;z==m;m+=z)
////    {
////
////    }
//
// DNA *fuii=new DNA;
//    for(int i=0;true;i+=z)
//    {
//        s=i;
//        for(int l=0;l<z;l++)
//        {
//            //temp.seq=new char[z];
//            temp.setseq(bigDNA.getseq(s),l);
//            s++;
//        }
//            temp.BuildComplementaryStrand();
//            x=temp.ConvertToRNA();
//            f=x.ConvertToProtein(m);
//
//        for(int k=0;k<=y;k++)
//        {
//            while(f.seq[k]==pseq[k])
//            {
//
//                counter++;
//                k++;
//            }
//                if(counter==y)
//                {
//                    //seq1->DNA[n].setseq(temp.seq);
//                    //seq1[i]=new char[x]
//                    if(h==0)
//                    {
//                        seq1=temp.getseq();
//                        cout<<seq1;
//                        //temp.Print();
//                        c++;
//                        h++;
//                        //break;
//                    }
//
//                    else if(h==1)
//                    {
//                        seq2=temp.getseq();
//                        cout<<seq2;
//                        //temp.Print();
//                        c++;
//                        //break;
//                    }
//                    //continue;
//                    //break;
//                    //n++;
//                }
//            if(h==0 || h==1)
//                break;
//                if(c==2)
//            return fuii;
//            //}
//            if(c==2)
//            return fuii;
//        }
//
//        if(c==2)
//            return fuii;
//        //counter=0;
////        if(h==1)
////            break;
//    }
//
//return fuii;
//}
istream&operator>>(istream& in , Protein& a)
{
    cout<<"Enter the Sequence : ";
    in>>a.seq;
}
ostream&operator<<(ostream& out , Protein& a)
{
    cout<<"The Sequence : ";
    out<<a.seq;
    cout<<endl;
    cout<<"The Type : ";
    out<<a.type;
    return out;
}
void Protein::settype (Protein_Type t)
{
     type=t;
}
Protein_Type Protein::gettype ()
{
    return type;
}
Protein Protein::operator +(const Protein & rhs)
{
    Protein f;
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
bool Protein::operator ==(const Protein & a)
{

    if(strlen(seq)!=strlen(a.seq))
        return true;
    else
    {
       int length=strlen(seq);
       int counter=0;
       int i=0;
       while(seq[i]==a.seq[i] && i<length )
       {
           counter++;
           i++;
       }
       if(counter==length)
        return true;
       else
        return false;
    }
}
bool Protein::operator !=(const Protein & a)
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
