#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
 /*
 create class manager,arrary of class salesman and struct of customer
 */
class customer
    {
       string CustomerFirstName;
       string CustomerLastName;
       double CustomerSpend;
    public:
        customer()

        {
            CustomerFirstName="";
            CustomerLastName="";
            CustomerSpend=0.0;
        }
    string getCustomerFirstName(){
        return CustomerFirstName;
    }
    void setCustomerFirstName(string x){
        CustomerFirstName=x;
    }
    string getCustomerLastName(){
        return CustomerLastName;
    }
    void setCustomerLastName(string x){
        CustomerLastName=x;
    }
    double getCustomerSpend(){
        return CustomerSpend;
    }
    void setCustomerSpend(double x){
        CustomerSpend=x;
    }
    };
class manager
{
    string ManagerId;
    string ManagerFirstName;
    string ManagerLastName;
    double ManagerSalary;
    public:
    manager()
    {
        ManagerId="";
        ManagerFirstName="";
        ManagerLastName="";
        ManagerSalary=0.0;
    }
    string getManagerId(){
        return ManagerId;
    }
    void setManagerId(string x){
        ManagerId=x;
    }
    string getManagerFirstName(){
        return ManagerFirstName;
    }
    void setManagerFirstName(string x){
        ManagerFirstName=x;
    }
    string getManagerLastName(){
        return ManagerLastName;
    }
    void setManagerLastName(string x){
        ManagerLastName=x;
    }
    double getManagerSalary(){
        return ManagerSalary;
    }
    void setManagerSalary(double x){
        ManagerSalary=x;
    }
};

class salesman
{


    string SalesmanId;
    string SalesmanFirstName;
    string SalesmanLastName;
    int CustomerNo;
    double totalsales;
    string SalesmanGender;
    public:
    customer temp;//use temp struct to initialize the vector
    vector<customer> Customer;//create vector of customers
    salesman():Customer(5,temp)
    {
        SalesmanId="";
        CustomerNo=0;
        totalsales=0.0;
        SalesmanFirstName="";
        SalesmanLastName="";
        SalesmanGender="";
    }

    double caltotal();
    void sortSalesData(salesman SalesmanList[],int &i);



    string getSalesmanId(){
        return SalesmanId;
    }
    void setSalesmanId(string x){
        SalesmanId=x;
    }
    string getSalesmanFirstName(){
        return SalesmanFirstName;
    }
    void setSalesmanFirstName(string x){
        SalesmanFirstName=x;
    }
    string getSalesmanLastName(){
        return SalesmanLastName;
    }
    void setSalesmanLastName(string x){
        SalesmanLastName=x;
    }
    int getCustomerNo(){
        return CustomerNo;
    }
    void setCustomerNo(int x){
        CustomerNo=x;
    }
    double gettotalsales(){
        return totalsales;
    }
    void settotalsales(double x){
        totalsales=x;
    }
    string getSalesmanGender(){
        return SalesmanGender;
    }
    void setSalesmanGender(string x){
        SalesmanGender=x;
    }

};
void getdata(manager &ManagerList, salesman SalesmanList[]);
void printdata1(manager &ManagerList, salesman SalesmanList[]);

void distributeCus(salesman SalesmanList[]);
void printdata2(manager &ManagerList, salesman SalesmanList[]);


#endif // DATA_H_INCLUDED
