#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
#include "data.h"

void datetime::getdatedata(vector<datetime>& datevec,int& counter4)
{
    ifstream inData;
    inData.open("Date_Time.txt");
    inData>>counter4;
    for(int i=0;i<counter4;i++)
    {
        inData>>datevec[i].dateId>>datevec[i].day>>datevec[i].month
        >>datevec[i].year>>datevec[i].hours>>datevec[i].minutes>>datevec[i].am_pm;
    }
        inData.close();
}
