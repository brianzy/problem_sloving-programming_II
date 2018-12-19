#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
#include "data.h"
void printmain();
void printappointmentmenu();
void printslotsmenu();
void printdocmenu();
void printpatientmenu();
void printrecordmenu();

void printmain()
{
    cout<<"Welcome to HMS. Please choose an action:"<<endl<<endl;
    cout<<"Main Menu:"<<endl<<endl;
    cout<<"1. Manage Appointments"<<endl;
    cout<<"2. Manage Slots"<<endl;
    cout<<"3. Manage Doctors"<<endl;
    cout<<"4. Manage Patients"<<endl;
    cout<<"5. Manage Patients’ records"<<endl;
    cout<<"6. Manage labs"<<endl;
    cout<<"7. Exit"<<endl;
}
void printappointmentmenu()
{
    cout<<"1. Schedule new appointment"<<endl;
    cout<<"2. Modify an existing appointment"<<endl;
    cout<<"3. Delete an appointment"<<endl;
    cout<<"4. Search for appointment by patient's info"<<endl;
    cout<<"5. Search for appointments by doctor's name"<<endl;
    cout<<"6. Go Back"<<endl;
}
void printslotsmenu()
{
    cout<<"1. Update slot info"<<endl;
    cout<<"2. delete a slot"<<endl;
    cout<<"3. view all slots"<<endl;
    cout<<"4. view all available slots"<<endl;
    cout<<"5. view all unavailable slots"<<endl;
    cout<<"6. Search for available slots by doctor's name"<<endl;
    cout<<"7. show available slots by time range "<<endl;
    cout<<"8. Go Back"<<endl;
}
void printdocmenu()
{
    cout<<"1. view all doctors"<<endl;
    cout<<"2. Update doctor's info"<<endl;
    cout<<"3. Delete a doctor"<<endl;
    cout<<"4. search doctor by name"<<endl;
    cout<<"5. Go Back"<<endl;
}
void printpatientmenu()
{
    cout<<"1. Add Patient"<<endl;
    cout<<"2. Update patient's info"<<endl;
    cout<<"3. Delete patient"<<endl;
    cout<<"4. View all patients"<<endl;
    cout<<"5. Search for patient"<<endl;
    cout<<"6. Search for patient by doctor's name"<<endl;
     cout<<"7. Show patient's appointments by time range"<<endl;
     cout<<"8. Go Back"<<endl;
}
void printrecordmenu()
{
    cout<<"1. Update a patient's record"<<endl;
    cout<<"2. Update a patient's diagnosis"<<endl;
    cout<<"3. Go Back"<<endl;
}
void printlabmenu()
{
    cout<<"1.create appointment for lab"<<endl;
    cout<<"2.delete lab appointment"<<endl;
    cout<<"3.show all lab appointment"<<endl;

}
int main()
{
    vector<patient> mypatient(50);
    vector<doctor> mydoctor(50);
    vector<slot> myslot(50);
    vector<datetime> mydate(50);
    vector<diagnosis> mydiagnosis(50);
    vector<appointment> myappointment(50);
    vector<record> myrecord(50);
    vector<labappointment> mylab(50);
    patient patientaccess;
    doctor doctoteraccess;
    slot slotaccess;
    datetime dateaccess;
    diagnosis diagnosisaccess;
    appointment appointmentaccess;
    record recordaccess;
    labappointment labaccess;
    bool loop = true;
    int option=0;
    int counter1,counter2,counter3,counter4, counter5 = 0;
    patientaccess.getpatientdata(mypatient,counter1);
    doctoteraccess.getdocdata(mydoctor,counter2);
    slotaccess.getslotdata(myslot,counter3);
    dateaccess.getdatedata(mydate,counter4);
    diagnosisaccess.getdiagnosisdata(mydiagnosis,counter5);

    do
    {
        printmain();
    cin>>option;
    switch(option)
    {
        case 1 :
            printappointmentmenu();
            cin>>option;
            switch(option)
                {
                    case 1:
                        appointmentaccess.addappointment(myappointment);
                        appointmentaccess.updaterecord(myappointment,mypatient,counter1,myrecord);
                        appointmentaccess.updateslot(myappointment,myslot,counter3);
                        break;
                    case 2:
                        appointmentaccess.updateappointment(myappointment);
                        break;
                    case 3:
                        appointmentaccess.cancelappointment(myappointment,myslot,counter3);
                        break;
                    case 4:
                        appointmentaccess.viewappointbypatient(myappointment,mypatient,counter1);
                        break;
                    case 5:
                        appointmentaccess.viewappointbydocname(myappointment,mydoctor,counter2);
                        break;
                    case 6:
                        break;

                }
            break;
        case 2 :
            printslotsmenu();
            cin>>option;
            switch(option)
            {
                case 1:
                    slotaccess.updateslot(myslot,counter3);
                    break;
                case 2:
                    slotaccess.deleteslot(myslot,counter3);
                    break;
                case 3:
                    slotaccess.viewallslots(myslot,counter3);
                    break;
                case 4:
                    slotaccess.viewallavailableslots(myslot,counter3);
                    break;
                case 5:
                    slotaccess.viewallunavailableslots(myslot,counter3);
                    break;
                case 6:
                    slotaccess.searchslotbydocname(myslot,counter3,mydoctor,counter2);
                    break;
                case 7:
                    slotaccess.viewslotsbytime(mydate,counter4,myslot,counter3);
                    break;
                case 8:
                    break;
            }
            break;
        case 3 :
            printdocmenu();
            cin>>option;
            switch(option)
            {
                case 1 :
                    doctoteraccess.viewdocs(mydoctor,counter2);
                    break;
                case 2 :
                    doctoteraccess.updatedocs(mydoctor,counter2);
                    break;
                case 3 :
                    doctoteraccess.deletedocs(mydoctor,counter2,myappointment);
                    break;
                case 4 :
                    doctoteraccess.searchdocs(mydoctor,counter2);
                    break;
                case 5 :
                    break;
            }
            break;
        case 4 :
            printpatientmenu();
            cin>>option;
            switch(option)
            {
                case 1:
                    patientaccess.addpatient(mypatient,counter1);
                    break;
                case 2:
                    patientaccess.updatepatientinfo(mypatient,counter1);
                    break;
                case 3:
                    patientaccess.deletepatient(mypatient,counter1);
                    break;
                case 4:
                    patientaccess.printallpatient(mypatient,counter1,mydoctor,myrecord);
                    break;
                case 5:
                    patientaccess.searchpatient(mypatient,counter1,mydoctor,myrecord);
                    break;
                case 6:
                    patientaccess.viewpatbydocname(mypatient,counter1,mydoctor,counter2);
                    break;
                case 7:
                    patientaccess.viewpatbytime(mypatient,counter1,mydate,counter4,myslot,counter3,myappointment);
                    break;
                case 8:
                    break;
            }
            break;
        case 5 :
            printrecordmenu();
            cin>>option;
            switch(option)
                {
                    case 1:
                        recordaccess.updaterecord(myrecord);
                        break;
                    case 2:
                        diagnosisaccess.updatediag(mydiagnosis,counter5);
                        break;
                }
            break;
        case 6 :
            printlabmenu();
            cin>>option;
            switch(option)
                {
                    case 1:
                        labaccess.addlab(mylab,myslot,counter3,mydate,counter4);
                        break;
                    case 2:
                        labaccess.deletelab(mylab);
                        break;
                    case 3:
                        labaccess.viewalllab(mylab);
                        break;
                }
            break;
        case 7 :
            loop=false;
            break;

    }
    }while(loop);


    return 0;
}
