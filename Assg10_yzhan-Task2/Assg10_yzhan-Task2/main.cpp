#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
using namespace std;

struct contactlist
{
    string firstname;
    string lastname;
    string phone;
    contactlist()
    {
        phone="757";
        firstname="";
        lastname="";
    }
};
int main()
{
    list<int> integerlist;
    list<int>::iterator i_iterator;
    i_iterator=integerlist.begin();
    for(int i=0;i<6;i++)
    {
        integerlist.push_back(i);
    }

    list<string> stringlist;
     stringlist.push_back("A");
     stringlist.push_back("B");
    stringlist.push_back("C");
     stringlist.push_back("D");
     stringlist.push_back("E");
     stringlist.push_back("F");
     stringlist.push_back("G");


     list<float> elements (1000,78.15);
     list<float> ::iterator f_iterator;
     f_iterator=elements.begin();
     /*
     for(f_iterator=elements.begin();f_iterator!=elements.end();f_iterator++)
     {
        cout<<*f_iterator<<endl;
     }
        */
     integerlist.push_front(0);
     integerlist.push_back(15);
    list<string>::iterator i;
    i=stringlist.begin();
    for(int j=0;j<4;j++)
       i++;
    string temp="yuzhang";
     stringlist.insert(i,temp);
     integerlist.push_front(2);
     for(i_iterator=integerlist.begin();i_iterator!=integerlist.end();i_iterator++)
    {
        cout<<*i_iterator<<endl;
    }
     integerlist.back()=integerlist.back()-4;


    for(i=stringlist.begin();i!=stringlist.end();++i)
    {
        cout<<*i<<endl;
    }
    list<contactlist> contact;
    list<contactlist>::iterator it;
    it=contact.begin();
    string tempname="";

    for(int i=0;i<500;i++)
    {
        contactlist contact1;

        for(int j=0;j<rand()%10+3;j++)
        {
            contact1.firstname +=char(rand()%26+65);
        }
        for(int j=0;j<rand()%10+3;j++)
        {
            contact1.lastname+=char(rand()%26+65);
        }
        for(int j=0;j<7;j++)
        contact1.phone+=char(rand()%(57-49+1)+49);

        contact.push_back(contact1);
    }
    /*
    for(it=contact.begin();it!=contact.end();it++)
    {
        cout<<it->firstname<<endl;
        cout<<it->lastname<<endl;
        cout<<it->phone<<endl;
    }
        */
    integerlist.sort();
    for(i_iterator=integerlist.begin();i_iterator!=integerlist.end();i_iterator++)
    {
        cout<<*i_iterator<<endl;
    }

    integerlist.reverse();

    return 0;
}
