#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
#include "data.h"
//get data from files
void getdata(manager &ManagerList, salesman SalesmanList[])
{
    ifstream inData;
    inData.open("input.txt");
    string x="";
    double y=0.0;
    int z=0;
    inData>>x;
    ManagerList.setManagerId(x);
    inData>>x;
    ManagerList.setManagerFirstName(x);
    inData>>x;
    ManagerList.setManagerLastName(x);
    inData>>y;
    ManagerList.setManagerSalary(y);

    for(int i=0;i<5;i++)
    {

        inData>>x;
        SalesmanList[i].setSalesmanId(x);
        inData>>x;
        SalesmanList[i].setSalesmanFirstName(x);
        inData>>x;
        SalesmanList[i].setSalesmanLastName(x);
        inData>>x;
        SalesmanList[i].setSalesmanGender(x);
        inData>>z;
        SalesmanList[i].setCustomerNo(z);
        for(int j=0;j<SalesmanList[i].getCustomerNo();j++)
        {
            inData>>x;
            SalesmanList[i].Customer[j].setCustomerFirstName(x);
            inData>>x;
            SalesmanList[i].Customer[j].setCustomerLastName(x);
            inData>>y;
            SalesmanList[i].Customer[j].setCustomerSpend(y);
        }
    }

    inData.close();
}
//calculate total score
double salesman::caltotal()
{
    for(int i=0;i<CustomerNo;i++)
    {
        totalsales=totalsales+Customer[i].getCustomerSpend();
    }
    return totalsales;
}
//sorting the total sales bubble the least sales salesman to the last of the array.
void salesman::sortSalesData(salesman SalesmanList[],int &i)
{

        if(SalesmanList[i].totalsales<SalesmanList[i+1].totalsales)
            swap(SalesmanList[i],SalesmanList[i+1]);


}
//distrube the fired salesman's customer to other salesman
void distributeCus(salesman SalesmanList[])
{
    int j =0;
    int k =0;
    for(int i=0;i<4;i++)
    {
        double z =0.0;

            if(j>=SalesmanList[4].getCustomerNo())
            {
                break;
            }
            k=i;
            SalesmanList[i].Customer[SalesmanList[i].getCustomerNo()] = (SalesmanList[4].Customer[j]);
            z=SalesmanList[i].gettotalsales();
            z=z+SalesmanList[4].Customer[j].getCustomerSpend();
            SalesmanList[i].settotalsales(z);

           //add the given customers sales to total

            j++;

    }
    for(int i=0;i<k+1;i++)
    {
        int z =0;
        z=SalesmanList[i].getCustomerNo();
        z++;
        SalesmanList[i].setCustomerNo(z);
    }


}
//print the previous data which before fired a salesman
void printdata1(manager &ManagerList, salesman SalesmanList[])
{
    cout<<"Manager:"<<setw(7)<<ManagerList.getManagerId()<<setw(7) <<ManagerList.getManagerFirstName()
    <<setw(7)<<ManagerList.getManagerLastName()<<setw(7)<<ManagerList.getManagerSalary()<<endl;

    for(int i=0;i<5;i++)
    {
        cout<<"______________________________________________________"<<endl;
        cout<<"\t"<<"Salesperson:"<<setw(10)<<left<< SalesmanList[i].getSalesmanFirstName()<<setw(7)<<SalesmanList[i].getSalesmanLastName()
        <<setw(10)<<SalesmanList[i].getSalesmanId()<<setw(7)<<SalesmanList[i].gettotalsales()<<endl;
        cout<<"__________________________________________________________"<<endl;
        for(int j=0;j<SalesmanList[i].getCustomerNo();j++)
        {
            cout<<"\t"<<"\t"<<"Customer:"<<setw(10)<<left<<SalesmanList[i].Customer[j].getCustomerFirstName()
            <<setw(10)<<SalesmanList[i].Customer[j].getCustomerLastName()<<setw(7)<<SalesmanList[i].Customer[j].getCustomerSpend()<<endl;

        }
    }


}
//print the final results
void printdata2(manager &ManagerList, salesman SalesmanList[])
{
    cout<<"========================================================================="<<endl;
    cout<<"Manager:"<<setw(7)<<ManagerList.getManagerId()<<setw(7)<<ManagerList.getManagerFirstName()
    <<setw(7)<<ManagerList.getManagerLastName()<<setw(7)<<ManagerList.getManagerSalary()<<endl;

    for(int i=0;i<4;i++)
    {
        cout<<"______________________________________________________"<<endl;
        cout<<"\t"<<"Salesperson:"<<setw(10)<<left<< SalesmanList[i].getSalesmanFirstName()<<setw(7)<<SalesmanList[i].getSalesmanLastName()
        <<setw(10)<<SalesmanList[i].getSalesmanId()<<setw(7)<<SalesmanList[i].gettotalsales()<<endl;
        cout<<"__________________________________________________________"<<endl;
        for(int j=0;j<SalesmanList[i].getCustomerNo();j++)
        {
            cout<<"\t"<<"\t"<<"Customer:"<<setw(10)<<left<<SalesmanList[i].Customer[j].getCustomerFirstName()
            <<setw(10)<<SalesmanList[i].Customer[j].getCustomerLastName()<<setw(7)<<SalesmanList[i].Customer[j].getCustomerSpend()<<endl;


        }
    }

}
