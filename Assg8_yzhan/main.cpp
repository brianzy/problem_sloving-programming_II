#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
class List1
{
    public:
    vector <int> myint1;
    List1():myint1(5000,0){}


};
class List2
{
    public:
    vector <int> myint2;
    List2():myint2(5000,0){}

};
void GenInt(List1 &list1,List2 &list2);
void sortlist1(List1 &list1);
void sortlist2(List2 &list2);

void GenInt(List1 &list1,List2 &list2)
{
    int temp =0;
    for (int i=0; i<5000;i++)
    {
        temp=(rand()%99999 +10000);
        list1.myint1[i]=temp;

        list2.myint2[i]=temp;

        //cout<<list2.myint2[i];
    }
}
void sortlist1(List1 &list1)
{

    int counter1, counter2=0;
    for(int i=1;i<5000;i++)
    {
        counter1++;
        for (int j=0;j<4999-i;j++)
        {
        if(list1.myint1[j]>list1.myint1[j+1])
            swap(list1.myint1[j],list1.myint1[j+1]);
            counter2+=3;
        }
    }
    cout<<"Number of comparisions"<<endl;
    cout<<counter1<<endl;
    cout<<"Number of item assignments"<<endl;
    cout<<counter2<<endl;
}
void sortlist2(List2 &list2)
{
    //int temp;
    int counter1, counter2=0;
    for(int i=0;i<4999;i++)
    {
        int minvalue=i;
        for (int j = i+1; j < 5000; j++)
        {
            ++counter1;
            if (list2.myint2[minvalue] > list2.myint2[j])
                {
                minvalue = j;
                }


            if (minvalue != i)
                {
                //temp=list2.myint2[i];
                //list2.myint2[i]=list2.myint2[minvalue];
                //list2.myint2[minvalue]=temp;

                swap(list2.myint2[i], list2.myint2[minvalue]);
                counter2+=3;
                }

        }
    }
    cout<<"Number of comparisions"<<endl;
    cout<<counter1<<endl;
    cout<<"Number of item assignments"<<endl;
    cout<<counter2<<endl;
}
int main()
{
    List1 mylist1;
    List2 mylist2;
    GenInt(mylist1,mylist2);
     cout<<"---------------------"<<endl;
    cout<<"bubble sort"<<endl;
    sortlist1(mylist1);
    cout<<"---------------------"<<endl;
    cout<<"selection sort"<<endl;
    sortlist2(mylist2);

    return 0;
}
