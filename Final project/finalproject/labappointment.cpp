#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
#include "data.h"
void labappointment::addlab(vector<labappointment>& labvec,vector<slot>& slotvec,int counter3,vector<datetime> datevec, int counter4)
{
    bool jump=false;
    bool condition=false;
    long long int entrydate,comparedate=0;
    vector<int>temp;
    vector<int>temp2;

    int doctorid, patientid, slotid, diagnosisid=0;
    string reasons, med="";
    cout<<"Input the doctor ID of your new lab"<<endl;
    cin>>doctorid;
    cout<<"Input the patient ID of your new lab"<<endl;
    cin>>patientid;
    cout<<"Input the slot ID of your new lab"<<endl;
    cin>>slotid;
    cout<<"Input the reasons of your new lab"<<endl;
    cin>>reasons;
    cout<<"Input the diagnosis ID of your new lab"<<endl;
    cin>>diagnosisid;
    cout<<"Input the medication of your new lab"<<endl;
    cin>>med;
/*
    for(int k=0;k<counter4;k++)
            {
                    entrydate=datevec[k].getyear()*10000+datevec[k].getmonth()*100+datevec[k].getday();
                    temp.push_back(entrydate);
                   // cout<<temp[k]<<endl;
            }
*/
    for(int i=30;i<40;i++)
       {
            if(slotid==slotvec[i].getslotId()&&slotvec[i].getavaliable()=="unavailable")
            {
               condition=true;
               cout<<"A lab can only be used once a day. can not add other lab2."<<endl;
               break;
            }
       }
    for(int i=30;i<40;i++)
    {
        if(slotid%2==0)
        {
            if(slotid==slotvec[i].getslotId()&&slotvec[i-1].getavaliable()=="unavailable")
            {
                condition=true;
                cout<<"A lab can only be used once a day. can not add other lab2."<<endl;
                break;
            }

        }
        else
        {
            if(slotid==slotvec[i].getslotId()&&slotvec[i+1].getavaliable()=="unavailable")
            {

                    condition=true;
                    cout<<"A lab can only be used once a day. can not add other lab2."<<endl;
                    break;

            }
        }
    }


if(condition==false)
       {
            for(int j=30;j<40;j++)
            {
                if(slotid==slotvec[j].getslotId()&&slotvec[j].getavaliable()=="available")
                {
                        for(int i=0;i<labvec.size();i++)
                    {
                        if(labvec[i].doctorId==0)
                        {
                            labvec[i].doctorId=doctorid;
                            labvec[i].patientId=patientid;
                            labvec[i].slotId=slotid;
                            labvec[i].reason=reasons;
                            labvec[i].diagnosisId=diagnosisid;
                            labvec[i].medication=med;
                            labvec[i].appointmentId=i;
                            slotvec[j].setavaliable("unavailable");
                            //cout<<slotvec[j].getavaliable()<<endl;
                            cout<<"Finished adding lab appointment, labappointment ID create automatically."<<endl;
                            j=40;
                            break;
                        }
                    }
                }

            }

       }

}
void labappointment::deletelab(vector<labappointment>& labvec)
{
    int appid=0;
    cout<<"Input lab appointment ID you want to delete:"<<endl;
    cin>>appid;
    for(int i=0;i<labvec.size();i++)
    {
        if(appid==labvec[i].appointmentId)
        {
            labvec.erase(labvec.begin()+i);
            break;
        }
    }
}
void labappointment::viewalllab(vector<labappointment> labvec)
{
    for(int i=0;i<labvec.size();i++)
    {
        if(labvec[i].doctorId!=0)
        {
            cout<<"appointment ID:"<<labvec[i].appointmentId<<endl;
            cout<<"doctor ID:"<<labvec[i].doctorId<<endl;
            cout<<"patient ID:"<<labvec[i].patientId<<endl;
            cout<<"Update slot ID:"<<labvec[i].slotId<<endl;
            cout<<"reason for visit:"<<labvec[i].reason<<endl;
            cout<<"diagnosis ID:"<<labvec[i].diagnosisId<<endl;
            cout<<"medication:"<<labvec[i].medication<<endl;
            cout<<"------------------------------------------------"<<endl;
        }
    }
}
