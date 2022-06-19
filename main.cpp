#include <iostream>
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "Protein.h"
#include "CodonsTable.h"
#include<windows.h>
using namespace std;

int main()
{
    cout<<"                           Welcome To Sequence Converter :) "<<endl<<endl;
    system("Color 8B");
    int choice=0;
    char x='n';
    char x1='n';
    char x2='n';
    int ch;
    do
    {
        cout<<"Enter the number of Sequence you need to Enter :"<<endl;
        cout<<"1-DNA \n2-RNA \n3-Protien "<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
        {
            Sequence *x=new DNA("ACGTTT",promoter);
            cout<<"\nHow to take the Sequence :"<<endl;
            cout<<"1-Enter the Sequence\n2-Load Sequence from file\n3-Set Random Sequence\n";
            cin>>ch;
            switch(ch)
            {

            case 1:
            {
                cout<<"The Sequence : ";
                char *d=new char[100];
                cin>>d;
                x->setseq(d);
                break;
            }
            case 2:
            {
                cout<<"Enter the File Name to Read Sequence From\n";
                string q;
                cin>>q;
                x->LoadSequenceFromFile(q.c_str());
                cout<<"The Sequence is Loaded. . . \n";
                //x->LoadSequenceFromFile("Ahmed");
                break;
            }
            case 3:
            {
                cout<<"Random Sequence is Setted\n";
                break;
            }
            default :
            {
                cout<<"Wrong input!!\nRandom Sequence is Setted\n";
                break;
            }

            }
            cout<<"\nEnter the Type of the Sequence\n";
            cout<<"1-promoter\n2-motif\n3-tail\n4-noncoding\n5-None\n";
            cin>>ch;
            switch(ch)
            {
            case 1:
            {
                ((DNA*)x)->settype(promoter);
                break;
            }
            case 2:
            {
                ((DNA*)x)->settype(motif);
                break;
            }
            case 3:
            {
                ((DNA*)x)->settype(tail);
                break;
            }
            case 4:
            {
                ((DNA*)x)->settype(noncoding);
                break;
            }
            case 5:
            {
                ((DNA*)x)->settype(noDNA);
                break;
            }
            default:
            {
                cout<<"Wrong input\nNoType is setted\n";
            }
            }
            do
            {
                cout<<"\nOperation on the Sequence?!\n";
                cout<<"1-Align to another sequence\n2-Add another Sequence to the Previous Sequence\n3-Compare Equality with another Sequence\n4-None\n";
                cin>>ch;
                switch(ch)
                {
                case 1:
                {
                    Sequence *r=new DNA;
                    cout<<"Enter the Sequence\n";
                    char *d=new char[100];
                    cin>>d;
                    r->setseq(d);
                    x->setseq(((DNA*)Align(x,r))->getseq());
                    break;
                }
                case 2:
                {
                    DNA r("A",promoter);
                    cout<<"Enter the Sequence\n";
                    char *d=new char[100];
                    cin>>d;
                    r.setseq(d);
                    DNA y("A",promoter);
                    y.setseq(((DNA*)x)->getseq());
                    y.settype(((DNA*)x)->gettype());
                    x->setseq((y+r).getseq());
                    break;
                }
                case 3:
                {
                    DNA r("A",promoter);
                    cout<<"Enter the Sequence\n";
                    char *d=new char[100];
                    cin>>d;
                    r.setseq(d);
                    DNA off;
                    off.setseq(((DNA*)x)->getseq());
                    if(off==r)
                        cout<<"They Are Equal\n";
                    else
                        cout<<"They Are Not Equal\n";
                    break;

                }
                case 4:
                {
                    break;
                }
                }
                if(ch==4)
                    break;
                cout<<"Another Operation (Y/N)\n";
                cin>>x1;
            }
            while(x1=='y' || x1=='Y');
            do
            {
                cout<<"\nEnter the num. of the operation you want to perform? "<<endl;
                cout<<"1-Build Complementary Strand \n2-Convert to RNA\n3-Convert to Protien\n4-None\n";
                int a=0;
                cin>>a;
                switch(a)
                {
                case 1:
                {
                    ((DNA*)x)->BuildComplementaryStrand();
                    break;
                }
                case 2:
                {
                    ((DNA*)x)->BuildComplementaryStrand();
                    ((DNA*)x)->ConvertToRNA();
                    break;
                }
                case 3:
                {
                    RNA Rna;
                    CodonsTable codon;
                    ((DNA*)x)->BuildComplementaryStrand();
                    Rna=((DNA*)x)->ConvertToRNA();
                    Rna.ConvertToProtein(codon);
                    break;


                }
                case 4: break;
                }
                if(a==4)
                    break;
                cout<<"Another Operation (Y/N)"<<endl;
                cin>>x1;

            }
            while(x1=='y' || x1=='Y');

            cout<<"Save The Results to a File\n";
            cout<<"1-Yes\n2-No"<<endl;
            int p=0;
            cin>>p;
            switch(p)
            {
            case 1:
            {
                cout<<"Enter the File Name to Save Sequence in it\n";
                string file;
                cin>>file;
                x->SaveSequenceToFile(file.c_str());
                cout<<"The Sequence Data is Saved. . . \n";
                break;
            }
            case 2:
            {
                break;
            }
            }

            break;
        }
        case 2:
        {
            Sequence *v=new RNA("ACGUUU",mRNA);
            cout<<"\nHow to take the Sequence :"<<endl;
            cout<<"1-Enter the Sequence\n2-Load Sequence from file\n3-Set Random Sequence\n";
            cin>>ch;
            switch(ch)
            {
            case 1:
            {

                cout<<"The Sequence : ";
                char *d=new char[100];
                cin>>d;
                v->setseq(d);
                break;
            }
            case 2:
            {
                cout<<"Enter the File Name to Read Sequence From\n";
                string q;
                cin>>q;
                v->LoadSequenceFromFile(q.c_str());
                cout<<"The Sequence is Loaded. . . \n";
                break;
            }
            case 3:
            {
                cout<<"Random Sequence is Setted\n";
                break;
            }

            default:
            {
                cout<<"Wrong input!!\nRandom Sequence is Setted\n";
                break;
            }
            }
            cout<<"\nEnter the Type of the Sequence\n";
            cout<<"1-mRNA\n2-tRNA\n3-rRNA\n4-None\n";
            cin>>ch;
            switch(ch)
            {
            case 1:
            {
                ((RNA*)v)->settype(mRNA);
                break;
            }
            case 2:
            {
                ((RNA*)v)->settype(tRNA);
                break;
            }
            case 3:
            {
                ((RNA*)v)->settype(rRNA);
                break;
            }
            case 4:
            {
                ((RNA*)v)->settype(noRNA);
                break;
            }
            default:
            {
                cout<<"Wrong input\nNoType is setted\n";
            }
            }
            do
            {
                cout<<"\nOperation on the Sequence?!\n";
                cout<<"1-Align to another sequence\n2-Add another Sequence to the Previous Sequence\n3-Compare Equality with another Sequence\n4-None\n";
                cin>>ch;
                switch(ch)
                {
                case 1:
                {
                    Sequence *r=new RNA;
                    cout<<"Enter the Sequence\n";
                    char *d=new char[100];
                    cin>>d;
                    r->setseq(d);
                    v->setseq(((RNA*)Align(v,r))->getseq());
                    break;
                }
                case 2:
                {
                    RNA r("A",mRNA);
                    cout<<"Enter the Sequence\n";
                    char *d=new char[100];
                    cin>>d;
                    r.setseq(d);
                    RNA y("A",mRNA);
                    y.setseq(((RNA*)v)->getseq());
                    y.settype(((RNA*)v)->gettype());
                    v->setseq((y+r).getseq());
                    break;
                }
                case 3:
                {
                    RNA r("A",mRNA);
                    cout<<"Enter the Sequence\n";
                    char *d=new char[100];
                    cin>>d;
                    r.setseq(d);
                    RNA of;
                    of.setseq(((RNA*)v)->getseq());
                    if(of==r)
                        cout<<"They Are Equal\n";
                    else
                        cout<<"They Are Not Equal\n";
                    break;
                }
                case 4:
                {
                    break;
                }
                }
                if(ch==4)
                    break;
                cout<<"Another Operation (Y/N)\n";
                cin>>x1;
            }
            while(x1=='y' || x1=='Y');
            do
            {
                cout<<"\nEnter the num. of the operation you want to perform? "<<endl;
                cout<<"1-Convert to Protien \n2-Convert to DNA\n3-None\n";
                int a=0;
                cin>>a;
                switch(a)
                {
                case 1:
                {
                    CodonsTable x;
                    ((RNA*)v)->ConvertToProtein(x);
                    break;
                }
                case 2:
                {
                    ((RNA*)v)->ConvertToDNA();

                    //((DNA*)x)->ConvertToRNA();
                    break;
                }
                case 3:
                    break;
                }
                if(a==3)
                    break;
                cout<<"Another Operation (Y/N)"<<endl;
                cin>>x1;

            }
            while(x1=='y' || x1=='Y');
            cout<<"Save The Results to a File\n";
            cout<<"1-Yes\n2-No\n";
            int p=0;
            cin>>p;
            switch(p)
            {
            case 1:
            {

                cout<<"Enter the File Name to Save Sequence in it\n";
                string file;
                cin>>file;
                v->SaveSequenceToFile(file.c_str());
                cout<<"The Sequence Data is Saved. . . \n";
                break;
            }
            case 2:
                break;
            }
            break;
        }
        case 3:
        {
            Sequence *an=new Protein;
            cout<<"\nHow to take the Sequence :"<<endl;
            cout<<"1-Enter the Sequence\n2-Load Sequence from file\n3-Set Random Sequence\n";
            cin>>ch;
            switch(ch)
            {
            case 1:
            {
                cout<<"The Sequence : ";
                char *d=new char[100];
                cin>>d;
                an->setseq(d);
                break;
            }
            case 2:
            {
                cout<<"Enter the File Name to Read Sequence From\n";
                string q;
                cin>>q;
                an->LoadSequenceFromFile(q.c_str());
                cout<<"The Sequence is Loaded. . . \n";
                break;
            }
            case 3:
            {
                cout<<"\nEnter the Type of the Sequence\n";
                cout<<"1-Hormon\n2-Enzyme\n3-TF\n4-Cellular Function\n5-None\n";
                cin>>ch;
                switch(ch)
                {
                case 1:
                {
                    ((Protein*)an)->settype(Hormon);
                    break;
                }
                case 2:
                {
                    ((Protein*)an)->settype(Enzyme);
                    break;
                }
                case 3:
                {
                    ((Protein*)an)->settype(TF);
                    break;
                }
                case 4:
                {
                    ((Protein*)an)->settype(Cellular_Function);
                    break;
                }
                case 5:
                {
                    ((Protein*)an)->settype(noProtein);
                    break;
                }
                default:
                {
                    cout<<"Wrong input\nNoType is setted\n";
                }
                }
                break;
            }

            }
            do
            {
                cout<<"\nOperation on the Sequence?!\n";
                cout<<"1-Align to another sequence\n2-Add another Sequence to the Previous Sequence\n3-Compare Equality with another Sequence\n4-None\n";
                cin>>ch;
                switch(ch)
                {
                case 1:
                {
                    Sequence *r=new Protein;
                    cout<<"Enter the Sequence\n";
                    char *d=new char[100];
                    cin>>d;
                    an->setseq(d);
                    an->setseq(((Protein*)Align(an,r))->getseq());
                    break;
                }
                case 2:
                {
                    Protein r("MA");
                    cout<<"Enter the Sequence\n";
                    char *d=new char[100];
                    cin>>d;
                    r.setseq(d);
                    Protein y("MA");
                    y.setseq(((Protein*)an)->getseq());
                    y.settype(((Protein*)an)->gettype());
                    an->setseq((y+r).getseq());
                    break;
                }
                case 3:
                {
                    Protein r("A");
                    cout<<"Enter the Sequence\n";
                    char *d=new char[100];
                    cin>>d;
                    r.setseq(d);
                    Protein offf;
                    offf.setseq(((Protein*)an)->getseq());
                    if(offf==r)
                        cout<<"They Are Equal\n";
                    else
                        cout<<"They Are Not Equal\n";
                    break;
                }
                case 4:
                {
                    break;
                }
                }
                if(ch==4)
                    break;
                cout<<"Another Operation (Y/N)\n";
                cin>>x1;
            }
            while(x1=='y' || x1=='Y');
            do
            {
                cout<<"\nEnter the num. of the operation you want to perform? "<<endl;
                cout<<"1-Get DNA Strands Encoding Me \n2-None\n";
                int a=0;
                cin>>a;
                switch(a)
                {
                case 1:
                {
                    DNA Dna("ATGGCCATGGCCCCCAGAACTGAGATC",promoter);
                    //cout<<"Enter the DNA Sequence\n";
                    //char *d=new char[100];
                    //cin>>d;
                    //d="ATGGCCATGGCCCCCAGAACTGAGATCAATAGTACCCGTATTAACGGGTGA";
                    //Dna.setseq(d);
                    Protein pro("MA");
                    //pro.setseq(((Protein*)an)->getseq());
                    //((Protein*)a)->GetDNAStrandsEncodingMe(Dna);
                    pro.GetDNAStrandsEncodingMe(Dna);
                    break;
                }
                case 2:
                {
                    break;
                }
                }
                if(a==2)
                break;
                cout<<"Another Operation (Y/N)"<<endl;
                cin>>x1;

            }
            while(x1=='y' || x1=='Y');

            cout<<"Save The Results to a File\n";
            cout<<"1-Yes\n2-No"<<endl;
            int p=0;
            cin>>p;
            switch(p)
            {
            case 1:
            {
                cout<<"Enter the File Name to Save Sequence in it\n";
                string file;
                cin>>file;
                an->SaveSequenceToFile(file.c_str());
                cout<<"The Sequence Data is Saved. . . \n";
                break;
            }
            case 2:
            {
                break;
            }
            }
            break;
        }
        default :
            cout<<"Wrong Input!!\n";
            break;
        }
        cout<<"Enter Another Sequence Operation (Y/N)"<<endl;
        cin>>x;
    }
    while(x=='y' || x=='Y');

    return 0;
}
