#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;


struct time
{
  int month;
  int day;
  int year;
};
struct sizes
{
    int length;
    int width;
    int height;
};

struct shipments
{
    string FoodItem;
    time ExpDate;

    sizes BoxSize;
    int BoxWeight;
    char StorageMethod;
    time DateRece;
    double ItemPrice;
};


struct customers
{
   string CusName;
   string Location;
   int Distance;

};

struct orders
{
   string CusName;
   string FoodItem;
   int BoxNum;
   double cost;
   time OrderDate;

};
shipments* readShipments (shipments *shiparray, int &shipcounter); // function to read shipment file
customers* readCustomers (customers *custarray, int &custcounter); // function to read customer file
orders* readOrders (orders *orderarray, int &ordercounter);//function to read orders file
void printShip (shipments *shiparray, int ShipCounter); //function to print shipment file
void printCust (customers *custarray, int custcounter);//function to print customer file
void printOrders (orders *orderarray, int ordercounter);//function to print orders file
bool search_shipments(shipments *shiparray, int &shipcounter);//function to search shipment file

int main()
{
    shipments *Temp1Ptr = NULL;//setup pointer temp1ptr and make it to null value
    int ShipCounter = 0;
    shipments* ShipArr = readShipments (Temp1Ptr, ShipCounter);//pass temp1ptr to function and give it to pointer ShipArr

     printShip (ShipArr, ShipCounter);//pass pointer ShipArr to print function and call print function to get result



    customers *Temp2Ptr = NULL;
    int CustCounter = 0;
    customers* CustArr = readCustomers(Temp2Ptr, CustCounter);
    printCust(CustArr, CustCounter);  //set up temp2prt and custarr pass the array in the readcustomers function to pointer
                                        //call print function to get result

    orders *Temp3Ptr = NULL;
    int ordercounter = 0;
    orders* OrderArr = readOrders(Temp3Ptr, ordercounter);
    printOrders(OrderArr, ordercounter); //call print order function to get result

    search_shipments(ShipArr, ShipCounter);//call search function to search item in shipments
    return 0;
}


shipments* readShipments (shipments *shiparray, int &ShipCounter)
{
    char c;
    ifstream inDate;
    inDate.open("Shipments.txt");
    inDate >> ShipCounter;//read the first number which indicate rows in shipment struct
    shiparray = new shipments[ShipCounter];
    for (int i = 0; i < ShipCounter; i ++) //use loop to read all the file data
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

customers* readCustomers (customers *custarray, int &custcounter)//read data in customers file
{
   ifstream inDate;
    inDate.open("Customers.txt");
    inDate >> custcounter;
    custarray = new customers[custcounter] ;
    for (int i = 0; i < custcounter; i ++)
    {
      inDate >>  custarray[i].CusName >> custarray[i].Location >> custarray[i].Distance;
    }
    inDate.close();
    return custarray;
}

orders* readOrders (orders *orderarray, int &ordercounter)//read data in orders file
{
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

void printShip (shipments *shiparray, int ShipCounter)
{
    for(int i=0; i< 76; i++)//print 76 times of ====
    {
        cout << "=" ;
    }
    cout << endl;
    cout <<setw(38)<< "shipments"<< endl;
    for(int i=0; i< 76; i++)
    {
        cout << "=" ;
    }
    cout << endl;
    cout << left<<setw(12)<< "Food Item" <<"|" << setw(12)<< "Expiry Date"  << "|"<< setw(10)<<"Box size"
    << "|"<<setw(5)<<"Weight"<< "|"<<setw(5)<<"Storage"<< "|"<< setw(10)<<"Received Date"<< "|"<< setw(5)<<"Price"<< endl;
    for(int i=0; i< 76; i++)
    {
        cout << "-" ;
    }
    cout << endl;



    for(int i=0; i< ShipCounter; i++)//print data from shipments file
    {
    cout <<fixed<<showpoint<<setprecision(2)<< left<<setw(12)<< shiparray[i].FoodItem<<setw(2) << shiparray[i].ExpDate.month
        <<  ":" << shiparray[i].ExpDate.day << ":"<<right<<setw(3) << shiparray[i].ExpDate.year<< setw(8)
        << shiparray[i].BoxSize.length << ":"<< shiparray[i].BoxSize.width
        << ":"<< shiparray[i].BoxSize.height <<setw(5)<< shiparray[i].BoxWeight<< setw(5)
        << shiparray[i].StorageMethod << setw(8) <<shiparray[i].DateRece.month
        << ":" << shiparray[i].DateRece.day << ":" << shiparray[i].DateRece.year
        << setw(10) <<shiparray[i].ItemPrice << endl;
    }
}

void printCust (customers *custarray, int custcounter)//print data from customers file
{
    for(int i=0; i< 76; i++)
    {
        cout << "=" ;
    }
    cout << endl;
    cout <<setw(38)<< "customers"<< endl;
    for(int i=0; i< 76; i++)
    {
        cout << "=" ;
    }
    cout << endl;
    cout << setw(15)<< "customer name" <<"|" << setw(8)<< "city"  << "|"<< setw(15)<<"distance"
    << "|"<< endl;
    for(int i=0; i< 76; i++)
    {
        cout << "-" ;
    }
    cout << endl;
    for(int i=0; i< custcounter; i++)
    {
    cout <<left<< setw(15) << custarray[i].CusName<< setw(15) << custarray[i].Location
        <<setw(15)<<custarray[i].Distance <<endl;
    }
}


void printOrders (orders *orderarray, int ordercounter)// print data from orders file
{
for(int i=0; i< 76; i++)
    {
        cout << "=" ;
    }
    cout << endl;
    cout <<setw(38)<< "Orders"<< endl;
    for(int i=0; i< 76; i++)
    {
        cout << "=" ;
    }
    cout << endl;
    cout << setw(15)<< "customer name" <<"|" << setw(15)<< "item name"  << "|"<< setw(8)<<"#boxes"
    << "|"<<setw(8)<<"Costs"<< "|"<<setw(15)<<"Order Date"<< "|"<< endl;
    for(int i=0; i< ordercounter; i++)
    {
    string c = ":";
    cout<<fixed<<showpoint<<setprecision(2)<<left << setw(18) << orderarray[i].CusName<< setw(15) << orderarray[i].FoodItem
        << setw(10)<<orderarray[i].BoxNum<< setw(10) <<orderarray[i].cost<<right<<orderarray[i].OrderDate.month
        << c << orderarray[i].OrderDate.day << c << orderarray[i].OrderDate.year<< endl;
    }
}

bool search_shipments(shipments *shiparray, int &shipcounter)//search the item which you input
{
    int option;
    string item;
    cout << "Do you want to search in shipment?"<< endl;
    cout << "1. Yes"<<endl;
    cout << "2. No"<<endl<<endl;
    cout << "Enter Option (1-2):";
    cin >> option;
    if(option == 1)
    {
        cout << "Enter the Item to search:"<< endl;
    }
    else if (option == 2)
        return -1;
    else
    {
        cout << "You input option is invaild."<< endl;
        return -1;
    }
    cin >> item ;
    cout<< endl;
    cout << "Searching for food item:"<< item<< endl;
    for(int i=0; i< 76; i++)
    {
        cout << "=" ;
    }
    cout << endl;
    cout <<setw(38)<< "search result"<< endl;
    for(int i=0; i< 76; i++)
    {
        cout << "=" ;
    }
    cout << endl;
      cout << left<<setw(12)<< "Food Item" <<"|" << setw(12)<< "Expiry Date"  << "|"<< setw(10)<<"Box size"
    << "|"<<setw(5)<<"Weight"<< "|"<<setw(5)<<"Storage"<< "|"<< setw(10)<<"Received Date"<< "|"
    << setw(5)<<"Price"<< endl;
    for(int i=0; i< shipcounter; i++ )//use loop to find match of the input item
    {
    if (item == shiparray[i].FoodItem)
        {
        string c = ":";
        cout <<fixed<<showpoint<<setprecision(2)<< setw(8) << shiparray[i].FoodItem<<right<< setw(6) << shiparray[i].ExpDate.month
        << c << shiparray[i].ExpDate.day << c << shiparray[i].ExpDate.year<< setw(6)
        << shiparray[i].BoxSize.length << c << shiparray[i].BoxSize.width
        << c << shiparray[i].BoxSize.height <<setw(8)<< shiparray[i].BoxWeight<< setw(5)
        << shiparray[i].StorageMethod << setw(9) <<shiparray[i].DateRece.month
        << c << shiparray[i].DateRece.day << c << shiparray[i].DateRece.year
        << setw(7) <<shiparray[i].ItemPrice << endl;
        }

    }
}
