#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
#include "data.h"
void doctor::getdocdata(vector<doctor>& docvec,int &counter2)
{

    ifstream inData;
    inData.open("Doctors.txt");
    inData>>counter2;

    for(int i=0;i<counter2;i++)
    {
        inData>>docvec[i].doctorId>>docvec[i].docusername
        >>docvec[i].docpassword>>docvec[i].docname>>
        docvec[i].docphone>>docvec[i].skill;
    }
    inData.close();
}

void doctor::viewdocs(vector<doctor> docvec,int counter2)
{
    for(int i=0;i<counter2;i++)
    {
        if(docvec[i].doctorId!=0)
        {
            cout<<"Doctor ID:"<<docvec[i].doctorId<<endl;
            cout<<"Username:"<<docvec[i].docusername<<endl;
            cout<<"Password:"<<docvec[i].docpassword<<endl;
            cout<<"Name:"<<docvec[i].docname<<endl;
            cout<<"Phone Number:"<<docvec[i].docphone<<endl;
            cout<<"Specialty:"<<docvec[i].skill<<endl<<endl;
        }

    }

}
void doctor::updatedocs(vector<doctor>& docvec,int counter2)
{
    int ID,option=0;
    string temp1="";
    cout<<"Input doctor's ID of the doctor you want to update:"<<endl;
    cin>>ID;
    for(int i=0;i<counter2;i++)
    {
        if(ID==docvec[i].doctorId)
        {
            cout<<"Choose which info you want to change by number."<<endl;
            cout<<"1.username 2.password 3.doctor's phone 4.doctor's specialty"<<endl;
            cin>>option;
            switch(option)
            {
                case 1 :
                    cout<<"Update username:"<<endl;
                    cin>>temp1;
                    docvec[i].docusername=temp1;
                    break;
                case 2 :
                    cout<<"Update password:"<<endl;
                    cin>>temp1;
                    docvec[i].docpassword=temp1;
                    break;
                case 3 :
                    cout<<"Update doctor's phone:"<<endl;
                    cin>>temp1;
                    docvec[i].docphone=temp1;
                    //cout<<docvec[i].docphone<<endl;
                    break;
                case 4 :
                    cout<<"Update doctor's specialty"<<endl;
                    cin>>temp1;
                    docvec[i].skill=temp1;
                    break;
            }
        }
    }
}
void doctor::searchdocs(vector<doctor> docvec,int counter2)
{
    string name="";

    cout<<"input doctor's name to search:"<<endl;

    cin>>name;
    for(int i=0;i<counter2;i++)
    {
        if(name==docvec[i].docname)
        {
            cout<<"Doctor ID:"<<docvec[i].doctorId<<endl;
            cout<<"Username:"<<docvec[i].docusername<<endl;
            cout<<"Password:"<<docvec[i].docpassword<<endl;
            cout<<"Name:"<<docvec[i].docname<<endl;
            cout<<"Phone Number:"<<docvec[i].docphone<<endl;
            cout<<"Specialty:"<<docvec[i].skill<<endl<<endl;
        }

    }

}
void doctor::deletedocs(vector<doctor>& docvec,int &counter2,vector<appointment> appvec)
{
     //bool jump=false;
     int ID=0;
    cout<<"Input doctor's ID you want to delete:"<<endl;
    cin>>ID;
    for(int i=0;i<counter2;i++)
    {
        for(int j=0;j<appvec.size();j++)
        {
            if(ID!=appvec[j].getdoctorId())
            {
                if(ID==docvec[i].doctorId)
                docvec.erase(docvec.begin()+i);
                cout<<"doctor has been deleted sucessfully"<<endl;
             i = counter2;
               break;
            }
            else
            {
                cout<<"This doctor have appointment, pls delete appointment first"<<endl;
               i = counter2;
               break;
            }
        }
    }
    counter2--;

   // cout<<counter2<<endl;
   // cout<<docvec[0].doctorId<<endl;
}
