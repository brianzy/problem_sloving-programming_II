#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "data.h"
using namespace std;
/**
use bool function to create compare member function.compare order date from year to day.
return true when it is bigger. when the date is same, need to compare the cost. return true when the cost is smaller
**/
bool orders::CompareOrders (orders A)
{
    if (OrderDate.year < A.OrderDate.year)
            return true;
    if (OrderDate.year == A.OrderDate.year && OrderDate.month < A.OrderDate.month)
            return true;
    if (OrderDate.year == A.OrderDate.year && OrderDate.month == A.OrderDate.month && OrderDate.day < A.OrderDate.day)
            return true;
    if (OrderDate.year == A.OrderDate.year && OrderDate.month == A.OrderDate.month && OrderDate.day == A.OrderDate.day)
            {
                if (cost > A.cost)
                return true;
            }

    return false;
}
/**
call the compare function in the sorting function, if compare function is true. we need
to switch the position.
**/
void sortorders(orders *orderlist, int ordercounter )
{
    orders temp;
    for(int i=0;i< ordercounter;++i)
        for (int j = 0; j< ordercounter; ++j)
       {
           if (orderlist[i].CompareOrders(orderlist[j]))
                {
                    temp = orderlist[i] ;
                    orderlist[i] = orderlist[j];
                    orderlist[j]=temp;
                }

       }
}
/**
compare the received date from year to day, when the received date is same.
we need to compare expiration date.
**/
bool shipments::CompareShipment(shipments B)
{
    if(DateRece.year < B.DateRece.year)
        return true;
    if(DateRece.year == B.DateRece.year &&  DateRece.month < B.DateRece.month)
        return true;
    if(DateRece.year == B.DateRece.year &&  DateRece.month == B.DateRece.month&& DateRece.day <B.DateRece.day )
        return true;
    if (DateRece.year == B.DateRece.year && DateRece.month == B.DateRece.month&& DateRece.day == B.DateRece.day)
        {
            if (ExpDate.year < B.ExpDate.year)
                return true;
            if (ExpDate.year == B.ExpDate.year &&  ExpDate.month < B.ExpDate.month)
                return true;
            if (ExpDate.year == B.ExpDate.year &&  ExpDate.month == B.ExpDate.month&& ExpDate.day < B.ExpDate.day)
                return true;
        }

        return false;

}
/**
call the compare function in the sorting function, if compare function is true. we need
to switch the position.
**/
void sortshipments(shipments *shiplist, int ShipCounter )
{

    shipments temp;
    for(int i=0;i< ShipCounter;++i)
        for (int j = 0; j< ShipCounter; ++j)
        {
            if (shiplist[i].CompareShipment(shiplist[j]))
                {
                temp = shiplist[i] ;
                shiplist[i] = shiplist[j];
                shiplist[j]=temp;
                }

        }

}

