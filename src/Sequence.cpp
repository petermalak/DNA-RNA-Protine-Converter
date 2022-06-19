#include "Sequence.h"
#include "DNA.h"
Sequence::Sequence()
{
    seq = new char[100]();
}

Sequence::Sequence(int length)
{
    seq=new char[length]();
}

Sequence::Sequence(Sequence& rhs)
{
//    if(100<strlen(rhs.seq))
//    {
//            delete [] seq;
//    seq = new char [strlen(rhs.seq)]();
//
//    }
//    for (int i=0; i<strlen(rhs.seq); i++)
//    {
//        seq[i] = rhs.seq[i];
//        seq[i+1]='/0';
//    }
}

Sequence::~Sequence()
{
    //delete []seq;
}
Sequence* Align(Sequence * s1, Sequence * s2)
{
    Sequence *temp=new DNA;
    int x=strlen(s1->seq);
    int y=strlen(s2->seq);
    if(x>=y)
    {
    //temp->seq=new char[y];
    //((DNA*)temp)->setseq(s2->seq);
            for(int i=0;i<y;i++)
            {
                if(s1->seq[i]==s2->seq[i])
                ((DNA*)temp)->setseq(s2->seq[i],i);
            }
    }
    else
    {
    //temp->seq=new char[x];
            for(int i=0;i<x;i++)
            {
                if(s1->seq[i]==s2->seq[i])
                ((DNA*)temp)->setseq(s1->seq[i],i);//]=s1->seq[i];
            }
    }
    cout<<"The Align Sequence : "<<temp->seq<<endl;
     return temp;
}
