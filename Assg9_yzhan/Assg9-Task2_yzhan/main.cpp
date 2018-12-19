#include <iostream>
#include <iomanip>
#include "fractionType.h"

using namespace std;

int main()
{
    fractionType totaltomato(3,1);
    fractionType totalgarlic(1,1);
    fractionType totalonions(2,1);
    fractionType totalbutter(1,1);
    fractionType totalbeef(2,1);
    fractionType totalbeans(2,1);
    fractionType tomato1(1,2);
    fractionType garlic1(3,4);
    fractionType onion1(1,4);
    fractionType butter1(1,8);
    fractionType beef1(1,2);
    fractionType beans1(2,3);
    fractionType tomato2(3,5);
    fractionType garlic2(1,5);
    fractionType onion2(2,5);
    fractionType butter2(1,5);
    fractionType beef2(7,10);
    fractionType beans2(9,10);
    cout<<"The tomato left is :"<<totaltomato-tomato1-tomato2<<endl;
    cout<<"The garlic left is :"<<totalgarlic-garlic1-garlic2<<endl;
    cout<<"The onion left is :"<<totalonions-onion1-onion2<<endl;
    cout<<"The butter bar left is :"<<totalbutter-butter1-butter2<<endl;
    cout<<"The ground beef left is :"<<totalbeef-beef1-beef2<<endl;
    cout<<"The beans left is :"<<totalbeans-beans1-beans2<<endl;
    if(beef1+beans1<beef2+beans2)
        cout<<"dish 1 weight less than dish2"<<endl<<endl;
    else
        cout<<"dish 1 weight more than dish2"<<endl;

    return 0;
}
