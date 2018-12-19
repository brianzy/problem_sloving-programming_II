#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
/**
create time, sizes, orders and shipments struct. create constructor of each
struct and initialize these constructors. create compare member functions
for orders and shipments.
**/
struct time
{
  int month;
  int day;
  int year;
  time()
  {
    month = 0;
    day = 0;
    year = 0;
  }
};
struct sizes
{
    int length;
    int width;
    int height;
    sizes ()
    {
    length =0;
    width =0;
    height = 0;
    }
};
struct orders
{
   string CusName;
   string FoodItem;
   int BoxNum;
   float cost;
   time OrderDate;
   orders ()
   {
   CusName = "";
   FoodItem = "";
   BoxNum = 0;
   cost = 0.0;
   }
   bool CompareOrders (orders A);
};
struct shipments
{
    string FoodItem;
    time ExpDate;

    sizes BoxSize;
    float BoxWeight;
    char StorageMethod;
    time DateRece;
    double ItemPrice;
    shipments ()
    {
    FoodItem = "";
    BoxWeight = 0.0;
    ItemPrice = 0.0;
    StorageMethod = ' ';
    }
    bool CompareShipment(shipments B);
};
/**
declear two sorting functions for sorting orders and shipments.
**/
void sortorders(orders *orderlist, int ordercounter );
void sortshipments(shipments *shiplist, int ShipCounter );





#endif // DATA_H_INCLUDED
