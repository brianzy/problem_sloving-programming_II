#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
#include "data.h"



int main()
{
    manager Manager;//create manager object
    salesman Salesman[5];//create array of salesman
    getdata(Manager,Salesman);
    for(int i=0;i<5;i++)
    Salesman[i].caltotal();
    printdata1(Manager,Salesman);
    for(int i=0;i<5;i++)
    Salesman[i].sortSalesData(Salesman,i);
    distributeCus(Salesman);
    printdata2(Manager,Salesman);
    return 0;
}
