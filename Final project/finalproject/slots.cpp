#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
#include "data.h"

void slot::getslotdata(vector<slot>& slotvec,int& counter3)
{

    ifstream inData;
    inData.open("Slots.txt");
    inData>>counter3;
    for(int i=0;i<counter3;i++)
    {
        inData>>slotvec[i].slotId>>slotvec[i].dateId>>
        slotvec[i].doctorId>>slotvec[i].avaliable;

    }
        inData.close();
}
void slot::updateslot(vector<slot>& slotvec,int counter3)
{
        int ID,option,temp=0;
        string temp1="";
        cout<<"Input slot ID of the slot you want to update:"<<endl;
        cin>>ID;
        for(int i=0;i<counter3;i++)
        {
            if(ID==slotvec[i].slotId)
            {
                cout<<"Choose which info you want to change by number."<<endl;
                cout<<"1.slot ID 2.date ID 3.doctor's ID 4.avaliablity"<<endl;
                cin>>option;
                switch(option)
                    {
                        case 1:
                            cout<<"Update slot ID:"<<endl;
                            cin>>temp;
                            slotvec[i].slotId=temp;
                            break;

                        case 2:
                            cout<<"Update date ID:"<<endl;
                            cin>>temp;
                            slotvec[i].dateId=temp;
                            //cout<<slotvec[i].dateId<<endl;
                            break;
                        case 3:
                            cout<<"Update doctor's ID:"<<endl;
                            cin>>temp;
                            slotvec[i].doctorId=temp;
                            break;
                        case 4:
                            cout<<"Update avaliablity:"<<endl;
                            cin>>temp1;
                            slotvec[i].avaliable=temp1;
                            break;
                    }
                break;
            }
        }
}
void slot::viewallslots(vector<slot> slotvec,int counter3)
{
    for(int i=0;i<counter3;i++)
    {
        cout<<"Slot ID:"<<slotvec[i].slotId<<endl;
        cout<<"Date ID:"<<setfill('0') << setw(3)<<slotvec[i].dateId<<endl;
        cout<<"Doctor's ID:"<<slotvec[i].doctorId<<endl;
        cout<<"avaliability:"<<slotvec[i].avaliable<<endl;
        cout<<"-----------------------------------------"<<endl;
    }
}
void slot::viewallavailableslots(vector<slot> slotvec,int counter3)
{
    for(int i=0;i<counter3;i++)
    {
        if(slotvec[i].avaliable=="available")
        {
            cout<<"Slot ID:"<<slotvec[i].slotId<<endl;
            cout<<"Date ID:"<<setfill('0') << setw(3)<<slotvec[i].dateId<<endl;
            cout<<"Doctor's ID:"<<slotvec[i].doctorId<<endl;
            cout<<"avaliability:"<<slotvec[i].avaliable<<endl;
            cout<<"-----------------------------------------"<<endl;
        }
    }
}
void slot::viewallunavailableslots(vector<slot> slotvec,int counter3)
{
    for(int i=0;i<counter3;i++)
    {
        if(slotvec[i].avaliable=="unavailable")
        {
            cout<<"Slot ID:"<<slotvec[i].slotId<<endl;
            cout<<"Date ID:"<<setfill('0') << setw(3)<<slotvec[i].dateId<<endl;
            cout<<"Doctor's ID:"<<slotvec[i].doctorId<<endl;
            cout<<"avaliability:"<<slotvec[i].avaliable<<endl;
            cout<<"-----------------------------------------"<<endl;
        }
    }
}
void slot::deleteslot(vector<slot>& slotvec,int& counter3)
{
    int ID=0;
    cout<<"Input slot ID you want to delete:"<<endl;
    cin>>ID;
    for(int i=0;i<counter3;i++)
    {
        if(ID==slotvec[i].slotId)
            slotvec.erase(slotvec.begin()+i);

    }
    counter3--;
    //cout<<slotvec[1].slotId<<endl;
}
void slot::searchslotbydocname(vector<slot> slotvec,int counter3,vector<doctor> doctorvec,int counter2)
{
    string doctorname="";
    int temp=0;
    cout<<"input doctor's name you want to search"<<endl;
    cin>>doctorname;
    for(int i=0;i<counter2;i++)
    {
       if(doctorname==doctorvec[i].getdocname())
            temp=doctorvec[i].getdoctorId();
    }
    for(int i=0;i<counter3;i++)
    {
       if(temp==slotvec[i].doctorId)
       {
            cout<<"slot Id:"<<slotvec[i].slotId<<endl;
            cout<<"date Id:"<<slotvec[i].dateId<<endl;
            cout<<"Doctor's ID:"<<slotvec[i].doctorId<<endl;
            cout<<"avaliability:"<<slotvec[i].avaliable<<endl;
            cout<<"------------------------------------------------"<<endl;
       }
    }
}
void slot::viewslotsbytime(vector<datetime> datevec, int counter4,vector<slot> slotvec, int counter3)
{
   // cout<<datevec[0].getapm()<<endl;
    char c,apm1,apm2=' ';
    int year1,year2,month1,month2,day1,day2,hour1,hour2,minute1,minute2=0;
    long long int begindate = 0,enddate= 0,entrydate=0;
    vector<int>temp;
    cout<<"Input the beginning of time you want to search:(format is:year : month : day : am_pm(a or p) : hour : minute)"<<endl;
    cin>>year1>>c>>month1>>c>>day1>>c>>apm1>>c>>hour1>>c>>minute1;
    cout<<"Input the ending of time you want to search:(format is: year:month:day:am_pm:hour:minute)"<<endl;
    cin>>year2>>c>>month2>>c>>day2>>c>>apm2>>c>>hour2>>c>>minute2;
    if(apm1=='p')
    {
       // cout << begindate << endl;
        begindate +=year1*60*24*30*12;
        //cout << begindate << endl;
        begindate +=month1*60*24*30;
        //cout << begindate << endl;
        begindate +=day1*60*24;
        //cout << begindate << endl;
        begindate +=(hour1+12)*60;
       // cout << begindate << endl;
        begindate +=minute1;
       // cout << begindate << endl;
    }


    if(apm1=='a')
        begindate =year1*60*24*30*12+month1*60*24*30+day1*60*24+hour1*60+minute1;
    if(apm2=='p')
        enddate =year2*60*24*30*12+month2*60*24*30+day2*60*24+(hour2+12)*60+minute2;
    if(apm2=='a')
        enddate =year2*60*24*30*12+month2*60*24*30+day2*60*24+hour2*60+minute2;
        //cout<<begindate<<endl;
        //cout<<enddate<<endl;

        for(int i=0;i<counter4;i++)
     {
        if(datevec[i].getapm()=='p')
            entrydate =datevec[i].getyear()*60*24*30*12+datevec[i].getmonth()*60*24*30+datevec[i].getday()*60*24+(datevec[i].gethours()+12)*60+datevec[i].getminutes();
        if(datevec[i].getapm()=='a')
            entrydate =datevec[i].getyear()*60*24*30*12+datevec[i].getmonth()*60*24*30+datevec[i].getday()*60*24+datevec[i].gethours()*60+datevec[i].getminutes();
            //cout<<entrydate<<endl;
       if(entrydate>=begindate&&entrydate<=enddate)
            temp.push_back(datevec[i].getdateId());
     }
       for(int j=0;j<temp.size();j++)
    {
        for(int i=0;i<counter3;i++)
        {
            if(temp[j]==slotvec[i].dateId)
            {
                cout<<"slot Id:"<<slotvec[i].slotId<<endl;
                cout<<"date Id:"<<slotvec[i].dateId<<endl;
                cout<<"Doctor's ID:"<<slotvec[i].doctorId<<endl;
                cout<<"avaliability:"<<slotvec[i].avaliable<<endl;
                cout<<"------------------------------------------------"<<endl;
            }


        }
    }

}
