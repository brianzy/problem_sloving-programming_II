#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "data.h"
using namespace std;
/**
use bool function to create compare  function.compare order date from year to day.
return true when it is bigger. when the date is same, need to compare the cost. return true when the cost is smaller.
we need to create A and B two incident for orders struct. Because it is not the member function, we cannot use A.function(B)
to compare anymore.
**/
bool CompareOrders (orders B, orders A)
{
    if (B.OrderDate.year < A.OrderDate.year)
            return true;
    if (B.OrderDate.year == A.OrderDate.year && B.OrderDate.month < A.OrderDate.month)
            return true;
    if (B.OrderDate.year == A.OrderDate.year && B.OrderDate.month == A.OrderDate.month && B.OrderDate.day < A.OrderDate.day)
            return true;
    if (B.OrderDate.year == A.OrderDate.year && B.OrderDate.month == A.OrderDate.month && B.OrderDate.day == A.OrderDate.day)
            {
                if (B.cost > A.cost)
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
           if (CompareOrders(orderlist[i],orderlist[j]))
                {
                    temp = orderlist[i] ;
                    orderlist[i] = orderlist[j];
                    orderlist[j]=temp;
                }

       }
}
/**
compare the received date from year to day, when the received date is same.
we need to compare expiration date.we need to create A and B two incident for shipments struct.
Because it is not the member function, we cannot use A.function(B)
to compare anymore.
**/
bool CompareShipment(shipments B, shipments A)
{
    if(A.DateRece.year < B.DateRece.year)
        return true;
    if(A.DateRece.year == B.DateRece.year &&  A.DateRece.month < B.DateRece.month)
        return true;
    if(A.DateRece.year == B.DateRece.year &&  A.DateRece.month == B.DateRece.month&& A.DateRece.day <B.DateRece.day )
        return true;
    if (A.DateRece.year == B.DateRece.year &&  A.DateRece.month == B.DateRece.month&& A.DateRece.day == B.DateRece.day)
        {
            if (A.ExpDate.year < B.ExpDate.year)
                return true;
            if (A.ExpDate.year == B.ExpDate.year &&  A.ExpDate.month < B.ExpDate.month)
                return true;
            if (A.ExpDate.year == B.ExpDate.year &&  A.ExpDate.month == B.ExpDate.month&& A.ExpDate.day < B.ExpDate.day)
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
            if (CompareShipment(shiplist[j],shiplist[i]))
                {
                temp = shiplist[i] ;
                shiplist[i] = shiplist[j];
                shiplist[j]=temp;
                }

        }

}

