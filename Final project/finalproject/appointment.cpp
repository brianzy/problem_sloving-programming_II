#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
#include "data.h"
void appointment::updateappointment(vector<appointment>& appointmentvec)
{
    int ID,option,temp=0;
        string temp1="";
        cout<<"Input appointment ID of the appointment you want to update:"<<endl;
        cin>>ID;
        for(int i=0;i<appointmentvec.size();i++)
        {
            //cout<<recordvec.size()<<endl;
            if(ID==appointmentvec[i].appointmentId)
            {
                cout<<"Choose which info you want to change by number."<<endl;
                cout<<"1.appointment ID 2.doctor ID 3.patient ID 4.slot ID 5.reason for visit"<<endl;
                cout<<"6.diagnosis ID 7.medication"<<endl;
                cin>>option;
                switch(option)
                    {
                        case 1:
                            cout<<"Update appointment ID:"<<endl;
                            cin>>temp;
                            appointmentvec[i].appointmentId=temp;
                            break;
                        case 2:
                            cout<<"Update doctor ID:"<<endl;
                            cin>>temp;
                            appointmentvec[i].doctorId=temp;
                            //cout<<recordvec[i].patientId<<endl;
                            break;
                        case 3:
                            cout<<"Update patient ID:"<<endl;
                            cin>>temp;
                            appointmentvec[i].patientId=temp;
                            break;
                        case 4:
                            cout<<"Update slot ID:"<<endl;
                            cin>>temp;
                            appointmentvec[i].slotId=temp;
                            break;
                        case 5:
                            cout<<"Update reason for visit:"<<endl;
                            cin>>temp1;
                            appointmentvec[i].reason=temp1;
                            break;
                        case 6:
                            cout<<"Update diagnosis ID:"<<endl;
                            cin>>temp;
                            appointmentvec[i].diagnosisId=temp;
                            break;
                        case 7:
                            cout<<"Update medication:"<<endl;
                            cin>>temp1;
                            appointmentvec[i].medication=temp1;
                            break;
                    }
                    break;
            }

        }
}
void appointment::viewappointbydocname(vector<appointment> appointmentvec,vector<doctor> doctorvec,int counter2)
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
    for(int i=0;i<appointmentvec.size();i++)
    {
       if(temp==appointmentvec[i].doctorId)
       {
            cout<<"appointment ID:"<<appointmentvec[i].appointmentId<<endl;
            cout<<"doctor ID:"<<appointmentvec[i].doctorId<<endl;
            cout<<"patient ID:"<<appointmentvec[i].patientId<<endl;
            cout<<"Update slot ID:"<<appointmentvec[i].slotId<<endl;
            cout<<"reason for visit:"<<appointmentvec[i].reason<<endl;
            cout<<"diagnosis ID:"<<appointmentvec[i].diagnosisId<<endl;
            cout<<"medication:"<<appointmentvec[i].medication<<endl;
            cout<<"------------------------------------------------"<<endl;
       }
    }
}
void appointment::viewappointbypatient(vector<appointment> appointmentvec,vector<patient> patientvec,int counter1)
{
    string input="";
    int temp=0;
    cout<<"Input a patient name or email you want to search: "<<endl;
    cin>>input;
    for(int i=0;i<appointmentvec.size();i++)
    {
        for(int j=0;j<counter1;j++)
        {
            if(input==patientvec[j].getpatientname()||input==patientvec[j].getpatientemail())
                temp=patientvec[j].getpatientId();
        }
            if(temp==appointmentvec[i].patientId)
            {
                cout<<"appointment ID:"<<appointmentvec[i].appointmentId<<endl;
                cout<<"doctor ID:"<<appointmentvec[i].doctorId<<endl;
                cout<<"patient ID:"<<appointmentvec[i].patientId<<endl;
                cout<<"Update slot ID:"<<appointmentvec[i].slotId<<endl;
                cout<<"reason for visit:"<<appointmentvec[i].reason<<endl;
                cout<<"diagnosis ID:"<<appointmentvec[i].diagnosisId<<endl;
                cout<<"medication:"<<appointmentvec[i].medication<<endl;
                cout<<"------------------------------------------------"<<endl;
            }
    }
}
void appointment::cancelappointment(vector<appointment>& appointmentvec,vector<slot>& slotvec,int counter3)
{
    int appid;
    cout<<"Input appointment ID you want to delete:"<<endl;
    cin>>appid;
    for(int i=0;i<appointmentvec.size();i++)
    {
        for(int j=0;j<counter3;j++)
         {
            if(appid==appointmentvec[i].appointmentId)
            {
                if(appointmentvec[i].slotId==slotvec[j].getslotId())
                {
                    string x="avaliable";
                    slotvec[j].setavaliable(x);

                    cout<<"The slot associated with the deleted appointment changed to available"<<endl;
                    appointmentvec.erase(appointmentvec.begin()+i);
                    j=counter3;
                    i=appointmentvec.size();
                    break;
                }

            }

         }

    }

}
void appointment::addappointment(vector<appointment>& appointmentvec)
{
    int doctorid, patientid, slotid, diagnosisid=0;
    string reasons, med="";
    cout<<"Input the doctor ID of your new appointment"<<endl;
    cin>>doctorid;
    cout<<"Input the patient ID of your new appointment"<<endl;
    cin>>patientid;
    cout<<"Input the slot ID of your new appointment"<<endl;
    cin>>slotid;
    cout<<"Input the reasons of your new appointment"<<endl;
    cin>>reasons;
    cout<<"Input the diagnosis ID of your new appointment"<<endl;
    cin>>diagnosisid;
    cout<<"Input the medication of your new appointment"<<endl;
    cin>>med;
    for(int i=0;i<appointmentvec.size();i++)
    {
        if(appointmentvec[i].doctorId==0)
        {
            appointmentvec[i].doctorId=doctorid;
            appointmentvec[i].patientId=patientid;
            appointmentvec[i].slotId=slotid;
            appointmentvec[i].reason=reasons;
            appointmentvec[i].diagnosisId=diagnosisid;
            appointmentvec[i].medication=med;
            appointmentvec[i].appointmentId=i;//atuomatically generate appointment ID;
/*
            cout<<appointmentvec[i].appointmentId<<endl;
            cout<<appointmentvec[i].doctorId<<endl;
            cout<<appointmentvec[i].patientId<<endl;
            cout<<appointmentvec[i].slotId<<endl;
            cout<<appointmentvec[i].reason<<endl;
            cout<<appointmentvec[i].diagnosisId<<endl;
            cout<<appointmentvec[i].medication<<endl;
*/
            cout<<"Finished adding appointment, appointment ID create automatically."<<endl;
            break;
        }

    }
}
void appointment::updaterecord(vector<appointment> appointmentvec,vector<patient> patientvec,int counter1,vector<record>& recordvec)
{

    for(int i=0;i<appointmentvec.size();i++)
    {
        for(int j=0;j<recordvec.size();j++)
        {
            for(int k=0;k<counter1;k++)
            {
                if(appointmentvec[i].patientId==patientvec[k].getpatientId())
                {
                    recordvec[j].setpatientId(appointmentvec[i].patientId);
                    recordvec[j].setrecordId(patientvec[k].getrecordId());//update record ID with record ID in patient
                    recordvec[j].setnotes(appointmentvec[i].medication);
                    //cout<<"notes:"<<recordvec[j].getnotes()<<endl;
                    j=recordvec.size();
                    i=appointmentvec.size();
                    break;
                }

            }

        }

    }

    cout<<"All the record updated at same time."<<endl;
}
void appointment::updateslot(vector<appointment> appointmentvec,vector<slot>& slotvec,int counter3)
{
    for(int i=0;i<appointmentvec.size();i++)
    {
        for(int j=0;j<counter3;j++)
        {
            if(appointmentvec[i].slotId==slotvec[j].getslotId())
            {
                string x="unavailable";
                slotvec[j].setavaliable(x);
                i=appointmentvec.size();
                j=counter3;
                break;
            }

        }

    }
    cout<<"All the slots availablity updated at same time."<<endl;
}
