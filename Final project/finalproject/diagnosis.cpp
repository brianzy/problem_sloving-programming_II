#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
#include "data.h"

void diagnosis::getdiagnosisdata(vector<diagnosis>& diagnosisvec,int& counter5)
{
    string blank="";
    ifstream inData;
    inData.open("Diagnosis.txt");
    inData>>counter5;
    inData.ignore();
    for(int i=0;i<counter5;i++)
    {
       getline(inData,diagnosisvec[i].diseasename);
       getline(inData,blank);
       diagnosisvec[i].diagnosisId=i;//create diagnosis ID
       //cout<<blank<<endl;
      // cout<<diagnosisvec[i].diseasename<<endl;
    }
}
void diagnosis::updatediag(vector<diagnosis>& diagnosisvec,int counter5)
{
    int ID,option,temp=0;
        string temp1="";
        cout<<"Input diagnosis ID of the diagnosis you want to update:"<<endl;
        cin>>ID;
        for(int i=0;i<counter5;i++)
        {
            if(ID==diagnosisvec[i].diagnosisId)
            {
                cout<<"Choose which info you want to change by number."<<endl;
                cout<<"1.diagnosis ID 2.diease name"<<endl;
                cin>>option;
                switch(option)
                    {
                        case 1:
                            cout<<"Update diagnosis ID:"<<endl;
                            cin>>temp;
                            diagnosisvec[i].diagnosisId=temp;
                            break;
                        case 2:
                            cout<<"Update disease name:"<<endl;
                            cin>>temp1;
                            diagnosisvec[i].diseasename=temp1;
                            break;
                    }
            }
            break;
        }
        /*
    for(int i=0;i<counter5;i++)
    {
        cout<<diagnosisvec[i].diagnosisId<<endl;
        cout<<diagnosisvec[i].diseasename<<endl;
    }
    */
}
