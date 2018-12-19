#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
#include "data.h"
void record::updaterecord(vector<record>& recordvec)
{
        int ID,option,temp=0;
        string temp1="";
        cout<<"Input record ID of the record you want to update:"<<endl;
        cin>>ID;
        for(int i=0;i<recordvec.size();i++)
        {
            //cout<<recordvec.size()<<endl;
            if(ID==recordvec[i].recordId)
            {
                cout<<"Choose which info you want to change by number."<<endl;
                cout<<"1.record ID 2.patient ID 3.doctor's notes"<<endl;
                cin>>option;
                switch(option)
                    {
                        case 1:
                            cout<<"Update record ID:"<<endl;
                            cin>>temp;
                            recordvec[i].recordId=temp;
                            break;
                        case 2:
                            cout<<"Update patient ID:"<<endl;
                            cin>>temp;
                            recordvec[i].patientId=temp;
                            //cout<<recordvec[i].patientId<<endl;
                            break;
                        case 3:
                            cout<<"Update doctor's notes:"<<endl;
                            cin>>temp1;
                            recordvec[i].notes=temp1;
                            break;
                    }
            }
            break;
        }
}
