#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
#include "data.h"
void patient::getpatientdata(vector<patient>& patientvec,int &counter1)
{

    ifstream inData;
    inData.open("Patients.txt");
    inData>>counter1;
    for(int i=0;i<counter1;i++)
    {
       inData>>patientvec[i].patientId>>patientvec[i].doctorid>>
       patientvec[i].recordid>>patientvec[i].patientname>>patientvec[i].patientphone
       >>patientvec[i].gender>>patientvec[i].patientemail>>patientvec[i].bloodtype;
    }
    inData.close();
}
void patient::addpatient(vector<patient>& patientvec,int &counter1)
{
    int temp1, temp2, temp3=0;
    string temp4,temp5, temp6, temp7="";
    char temp8=' ';
    cout<<"If you want to add a new patient, please input patient ID"<<endl;
    cin>>temp1;
    cout<<"please input doctor Id:"<<endl;
    cin>>temp2;
    cout<<"please input record Id:"<<endl;
    cin>>temp3;
    cout<<"please input patient name:"<<endl;
    cin>>temp5;
    cout<<"please input patient phone number:"<<endl;
    cin>>temp4;
    cout<<"please input patient gender:"<<endl;
    cin>>temp8;
    cout<<"please input patient email:"<<endl;
    cin>>temp6;
    cout<<"please input patient blood type:"<<endl;
    cin>>temp7;
    patientvec[counter1+1].patientId=temp1;
    patientvec[counter1+1].doctorid=temp2;
    patientvec[counter1+1].recordid=temp3;
    patientvec[counter1+1].patientname=temp5;
    patientvec[counter1+1].patientphone=temp4;
    patientvec[counter1+1].gender=temp8;
    patientvec[counter1+1].patientemail=temp6;
    patientvec[counter1+1].bloodtype=temp7;
    counter1++;
   // cout<<patientvec[counter1].patientId<<endl;
   // cout<<patientvec[counter1].patientemail<<endl;
}
void patient::updatepatientinfo(vector<patient>& patientvec,int& counter1)
{
    int ID,option=0;
    string temp1="";
    int temp2=0;
    char temp3=' ';
    cout<<"Input patient's ID of the patient you want to update:"<<endl;
    cin>>ID;
     for(int i=0;i<counter1;i++)
    {
        if(ID == patientvec[i].patientId)
        {
            cout<<"Choose which info you want to change by number."<<endl;
            cout<<"1.patient Id 2.doctor Id 3.record Id 4.patient name 5. patient phone 6.patient gender 7. patient email 8. blood type"<<endl;
            cin>>option;
            switch(option)
            {
                case 1 :
                    cout<<"Update patient Id:"<<endl;
                    cin>>temp2;
                    patientvec[i].patientId=temp2;
                    break;
                case 2 :
                    cout<<"Update doctor Id:"<<endl;
                    cin>>temp1;
                    patientvec[i].doctorid=temp2;
                    break;
                case 3 :
                    cout<<"Update record Id:"<<endl;
                    cin>>temp1;
                    patientvec[i].recordid=temp2;
                    break;
                case 4 :
                    cout<<"Update patient name"<<endl;
                    cin>>temp1;
                    patientvec[i].patientname=temp1;
                    cout<<patientvec[i].patientname<<endl;
                    break;
                case 5:
                    cout<<"Update patient phone"<<endl;
                    patientvec[i].patientphone=temp1;
                    break;
                case 6:
                    cout<<"Update patient gender"<<endl;
                    patientvec[i].gender=temp3;
                    break;
                case 7:
                    cout<<"Update patient email"<<endl;
                    patientvec[i].patientemail=temp1;
                    break;
                case 8:
                    cout<<"Update blood type"<<endl;
                    patientvec[i].bloodtype=temp1;
                    break;
            }

        }
    }
}
void patient::deletepatient(vector<patient>& patientvec,int &counter1)
{
    int ID=0;
    cout<<"Input patient's ID you want to delete:"<<endl;
    cin>>ID;
    for(int i=0;i<counter1;i++)
    {
        if(ID==patientvec[i].patientId)
            patientvec.erase(patientvec.begin()+i);

    }
    counter1--;
    for(int i=0;i<counter1;i++)
    {
        cout<<patientvec[i].patientId<<endl;
    }

}
void patient::viewpatbydocname(vector<patient> patientvec,int counter1,vector<doctor> doctorvec,int counter2)
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
    for(int i=0;i<counter1;i++)
    {
       if(temp==patientvec[i].doctorid)
       {
            cout<<"patient Id:"<<patientvec[i].patientId<<endl;
            cout<<"doctor Id:"<<patientvec[i].doctorid<<endl;
            cout<<"record Id:"<<patientvec[i].recordid<<endl;
            cout<<"patient name:"<<patientvec[i].patientname<<endl;
            cout<<"patient phone:"<<patientvec[i].patientphone<<endl;
            cout<<"patient gender:"<<patientvec[i].gender<<endl;
            cout<<"patient email:"<<patientvec[i].patientemail<<endl;
            cout<<"patient blood type:"<<patientvec[i].bloodtype<<endl;
            cout<<"------------------------------------------------"<<endl;
       }
    }
}
void patient::printallpatient(vector<patient> patientvec,int counter1,vector<doctor> doctorvec,vector<record> recordvec)
{
    string temp,temp1="";
    //int temp1=0;
    for(int i=0;i<counter1;i++)
    {
       for(int j=0;j<doctorvec.size();j++)
       {
           if(patientvec[i].doctorid==doctorvec[j].getdoctorId())
                temp=doctorvec[j].getdocname();
       }
       for(int k=0;k<recordvec.size();k++)
       {
            if(patientvec[i].recordid==recordvec[k].getrecordId())
                temp1=recordvec[k].getnotes();
       }
        cout<<"patient Id:"<<patientvec[i].patientId<<endl;
        cout<<"doctor Id:"<<patientvec[i].doctorid<<endl;
        cout<<"doctor name: "<<temp<<endl;
        cout<<"record notes: "<<temp1<<endl;
        cout<<"record Id:"<<patientvec[i].recordid<<endl;
        cout<<"patient name:"<<patientvec[i].patientname<<endl;
        cout<<"patient phone:"<<patientvec[i].patientphone<<endl;
        cout<<"patient gender:"<<patientvec[i].gender<<endl;
        cout<<"patient email:"<<patientvec[i].patientemail<<endl;
        cout<<"patient blood type:"<<patientvec[i].bloodtype<<endl;
        cout<<"------------------------------------------------"<<endl;

    }

}
void patient::searchpatient(vector<patient> patientvec,int counter1,vector<doctor> doctorvec,vector<record> recordvec)
{
    string input="";
    string temp,temp1="";
    cout<<"Input a patient name or email you want to search: "<<endl;
    cin>>input;
    for(int i=0;i<counter1;i++)
    {
        for(int j=0;j<doctorvec.size();j++)
       {
           if(patientvec[i].doctorid==doctorvec[j].getdoctorId())
                temp=doctorvec[j].getdocname();
       }
       for(int k=0;k<recordvec.size();k++)
       {
            if(patientvec[i].recordid==recordvec[k].getrecordId())
                temp1=recordvec[k].getnotes();
               // cout<<"temp1:"<<temp1<<endl;
                //cout<<"-------------"<<endl;
       }
        if(input==patientvec[i].patientname||input==patientvec[i].patientemail)
        {
            cout<<"patient Id:"<<patientvec[i].patientId<<endl;
            cout<<"doctor Id:"<<patientvec[i].doctorid<<endl;
            cout<<"doctor name: "<<temp<<endl;
            cout<<"record notes: "<<temp1<<endl;
            cout<<"record Id:"<<patientvec[i].recordid<<endl;
            cout<<"patient name:"<<patientvec[i].patientname<<endl;
            cout<<"patient phone:"<<patientvec[i].patientphone<<endl;
            cout<<"patient gender:"<<patientvec[i].gender<<endl;
            cout<<"patient email:"<<patientvec[i].patientemail<<endl;
            cout<<"patient blood type:"<<patientvec[i].bloodtype<<endl;
            cout<<"------------------------------------------------"<<endl;
        }
    }
}
void patient::viewpatbytime(vector<patient> patientvec,int counter1,vector<datetime> datevec,int counter4,vector<slot> slotvec,int counter3,vector<appointment> appointmentvec)
{
    char c,apm1,apm2=' ';
    int year1,year2,month1,month2,day1,day2,hour1,hour2,minute1,minute2;
    long long int begindate,enddate,entrydate=0;
    vector<int>temp;
    vector<int>temp2;
    vector<int>temp3;
    cout<<"Input the beginning of time you want to search:(format is: year:month:day:am_pm(a or p):hour:minute)"<<endl;
    cin>>year1>>c>>month1>>c>>day1>>c>>apm1>>c>>hour1>>c>>minute1;
    cout<<"Input the ending of time you want to search:(format is: year:month:day:am_pm:hour:minute)"<<endl;
    cin>>year2>>c>>month2>>c>>day2>>c>>apm2>>c>>hour2>>c>>minute2;
    if(apm1=='p')
        begindate =year1*60*24*30*12+month1*60*24*30+day1*60*24+(hour1+12)*60+minute1;
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
                  // cout<<entrydate<<endl;

       if(entrydate>=begindate&&entrydate<=enddate)
            temp.push_back(datevec[i].getdateId());
     }

    for(int i=0;i<counter3;i++)
    {
        for(int j=0;j<temp.size();j++)
        {
            if(temp[j]==slotvec[i].getdateId())
             temp2.push_back(slotvec[i].getslotId());

        }
    }
    for(int i=0;i<appointmentvec.size();i++)
    {
        for(int j=0;j<temp2.size();j++)
        {
            if(temp2[j]==appointmentvec[i].getslotId())
                temp3.push_back(appointmentvec[i].getpatientId());
        }
    }
    for(int i=0;i<counter1;i++)
    {
        for(int j=0;j<temp3.size();j++)
        {
            if(patientvec[i].patientId==temp3[j])
            {
                cout<<"patient Id:"<<patientvec[i].patientId<<endl;
                cout<<"doctor Id:"<<patientvec[i].doctorid<<endl;
                cout<<"record Id:"<<patientvec[i].recordid<<endl;
                cout<<"patient name:"<<patientvec[i].patientname<<endl;
                cout<<"patient phone:"<<patientvec[i].patientphone<<endl;
                cout<<"patient gender:"<<patientvec[i].gender<<endl;
                cout<<"patient email:"<<patientvec[i].patientemail<<endl;
                cout<<"patient blood type:"<<patientvec[i].bloodtype<<endl;
                cout<<"------------------------------------------------"<<endl;
            }

        }
    }
}

