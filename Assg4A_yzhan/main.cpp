#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "data.h"
using namespace std;
/**
declear read data functions and display functions
**/
orders* readOrders (int &ordercounter);
shipments* readShipments ( int &shipcounter);
void displayShipments(shipments *shiparray,int shipcounter);
void displayOrders(orders *orderarray, int ordercounter);

int main()
{

    int ordercounter = 0;
    int shipcounter = 0;
    orders *orderarray=readOrders(ordercounter);
    shipments *shiparray=readShipments(shipcounter);
    sortorders(orderarray, ordercounter );
    sortshipments(shiparray, shipcounter );
    displayOrders(orderarray, ordercounter);
    displayShipments(shiparray, shipcounter);
    return 0;
}

/**
read data from orders.txt . put all the orders data to orderarray.
**/
orders* readOrders (int &ordercounter)//read data in orders file
{
    orders * orderarray;
   char c;
   ifstream inDate;
    inDate.open("Orders.txt");
    inDate >> ordercounter;
    orderarray = new orders[ordercounter];
    for (int i = 0; i < ordercounter; i++)
    {
        inDate >> orderarray[i].CusName >> orderarray[i].FoodItem >> orderarray[i].BoxNum >> orderarray[i].cost
        >> orderarray[i].OrderDate.month>>c >> orderarray[i].OrderDate.day >>c>> orderarray[i].OrderDate.year;
    }
    inDate.close();
    return orderarray;

}
/**
Displaying the content from the orders struct array and output them to the file
**/
void displayOrders(orders *orderarray,int ordercounter)
{
    ofstream outfile;
    outfile.open ("SequencedOrders.txt");
    outfile << setw(10) << setfill(' ') << "Customer Name" << " | "
         << "Item Name" << "  | "
         << "#Boxes" << "  | "
         << "Cost" << "  | "
         << "Order Date" << endl;
    for(int i = 0; i < ordercounter; i++)
        {
        outfile <<fixed<<showpoint<<setprecision(2);
        outfile<< left << setw(10) << orderarray[i].CusName << "    | "
             << left << setw(10) << orderarray[i].FoodItem << " | "
             << right << setw(2) << setfill('0') << orderarray[i].BoxNum << "      | "
             << right << setw(4) << setfill('0') << orderarray[i].cost << " | "
             << right << setw(2) << setfill('0') << orderarray[i].OrderDate.month <<":" << setw(2) << setfill('0') << orderarray[i].OrderDate.day <<":" << setw(2) << setfill('0') << orderarray[i].OrderDate.year << " "
             << setfill(' ') << endl;
        }
    outfile.close();
}

/**
read data from shipments.txt . put all the orders data to shiparray.
**/
shipments* readShipments ( int &shipcounter)
{
    shipments *shiparray;
    char c;
    ifstream inDate;
    inDate.open("Shipments.txt");
    inDate >> shipcounter;//read the first number which indicate rows in shipment struct
    shiparray = new shipments[shipcounter];
    for (int i = 0; i < shipcounter; i ++) //use loop to read all the file data
    {
        inDate >> shiparray[i].FoodItem >> shiparray[i].ExpDate.month
        >> c >> shiparray[i].ExpDate.day >> c >> shiparray[i].ExpDate.year
        >> shiparray[i].BoxSize.length >> c >> shiparray[i].BoxSize.width
        >> c >> shiparray[i].BoxSize.height >> shiparray[i].BoxWeight
        >> shiparray[i].StorageMethod >> shiparray[i].DateRece.month
        >> c >> shiparray[i].DateRece.day >> c >> shiparray[i].DateRece.year
        >> shiparray[i].ItemPrice;
    }

         inDate.close();

    return shiparray;

}

/**
Displaying the content from the shipments struct array and output them to the file
**/
void displayShipments(shipments *shiparray, int shipcounter)
{
   ofstream outfile;
    outfile.open ("SequencedShipments.txt");
   outfile << setw(10) << "Food Item" << "  | "
        << "Exp Date " << "  | "
        << "Box Size" << "  | "
        << "Weight" << " | "
        << "Storage" << " | "
        << "Received date" << " | "
        << "Price" << endl;


    for(int i = 0; i < shipcounter; i++)
        {
        outfile <<fixed<<showpoint<<setprecision(2);
        outfile << left << setw(9) << shiparray[i].FoodItem << "   | "
             << right <<setw(2) << setfill('0') << shiparray[i].ExpDate.month <<":" << setw(2) << setfill('0') << shiparray[i].ExpDate.day <<":" << setw(2) << setfill('0') << shiparray[i].ExpDate.year << " | "
             << right <<setw(2) << setfill('0') << shiparray[i].BoxSize.length <<":"<< setw(2) << setfill('0') << shiparray[i].BoxSize.width << ":" << setw(2) << setfill('0') <<shiparray[i].BoxSize.height << "  | "
             << right <<setw(5) << shiparray[i].BoxWeight << "  | "
             << right <<shiparray[i].StorageMethod << "       | "
             << right <<setw(2) << setfill('0') << shiparray[i].DateRece.month <<":" << setw(2) << setfill('0') << shiparray[i].DateRece.day <<":" << setw(2) << setfill('0') << shiparray[i].DateRece.year << "    | "
             << right << fixed << setprecision(2) << setfill('0') << shiparray[i].ItemPrice << " "
             << setfill(' ') << endl;
        }
    outfile.close();
}

