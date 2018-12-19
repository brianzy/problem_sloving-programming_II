#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
class doctor;
class appointment;
class record;
class slot;
class datetime;
//create patient ADT
class patient
{
  int patientId;
  int doctorid;
  int recordid;
  string patientname;
  string patientphone;
  char gender;
  string patientemail;
  string bloodtype;

public:
    patient()
    {
      patientId=0;
      doctorid=0;
      recordid=0;
      patientname="";
      patientphone="";
      gender=' ';
      patientemail="";
      bloodtype="";
    }
    void getpatientdata(vector<patient>& patientvec,int &counter1);
    void addpatient(vector<patient>& patientvec,int &counter1);
    void updatepatientinfo(vector<patient>& patientvec,int &counter1);
    void deletepatient(vector<patient>& patientvec,int &counter1);
    void printallpatient(vector<patient> patientvec,int counter1,vector<doctor> doctorvec,vector<record> recordvec);//also print doc name and note for record;
    void searchpatient(vector<patient> patientvec,int counter1,vector<doctor> doctorvec,vector<record> recordvec);
    void viewpatbydocname(vector<patient> patientvec,int counter1,vector<doctor> doctorvec,int counter2);
    void viewpatbytime(vector<patient> patientvec,int counter1,vector<datetime> datevec,int counter4,vector<slot> slotvec,int counter3,vector<appointment> appointmentvec);
    int getpatientId(){
        return patientId;
    }
    int getrecordId(){
        return recordid;
    }
    string getpatientname(){
        return patientname;
        }
    string getpatientemail(){return patientemail;}

};
//create doctor ADT
class doctor
{
    int doctorId;
    string docusername;
    string docpassword;
    string docname;
    string docphone;
    string skill;
public:
    doctor()
    {
        doctorId=0;
        docusername="";
        docpassword="";
        docname="";
        docphone="";
        skill="";
    }
    void getdocdata(vector<doctor>& docvec,int &counter2);
    void viewdocs(vector<doctor> docvec,int counter2);
    void searchdocs(vector<doctor> docvec,int counter2);
    void updatedocs(vector<doctor>& docvec,int counter2);
    void deletedocs(vector<doctor>& docvec,int &counter2,vector<appointment> appvec);
    int getdoctorId(){
        return doctorId;
    }
    string getdocname(){
        return docname;
    }
};
//create slot ADT
class slot
{
    int slotId;
    int dateId;
    int doctorId;
    string avaliable;
public:
    slot()
    {
        slotId=0;
        dateId=0;
        doctorId=0;
        string avaliable="";
    }
    void getslotdata(vector<slot>& slotvec,int& counter3);
    void updateslot(vector<slot>& slotvec,int counter3);
    void viewallslots(vector<slot> slotvec,int counter3);
    void viewallavailableslots(vector<slot> slotvec,int counter3);
    void viewallunavailableslots(vector<slot> slotvec,int counter3);
    void deleteslot(vector<slot>& slotvec,int& counter3);
    void searchslotbydocname(vector<slot> slotvec,int counter3,vector<doctor> doctorvec,int counter2);
    void viewslotsbytime(vector<datetime> datevec, int counter4,vector<slot> slotvec, int counter3);

    int getslotId(){
    return slotId;
    }
    int getdateId(){
    return dateId;
    }
    string getavaliable(){
    return avaliable;
    }
    void setavaliable(string x){
        avaliable=x;
    }
};
//create datetime ADT
class datetime
{
    int dateId;
    int day;
    int month;
    int year;
    int hours;
    int minutes;
    char am_pm;
public:
    datetime(){
        dateId=0;
        day=0;
        month=0;
        year=0;
        hours=0;
        minutes=0;
        am_pm=' ';
    }
    void getdatedata(vector<datetime>& datevec,int& counter4);
    int getdateId(){
    return dateId;
    }
    int getday(){
    return day;
    }
    int getmonth(){
    return month;
    }
    int getyear(){
    return year;
    }
    int gethours(){
    return hours;
    }
    int getminutes(){
    return minutes;
    }
    char getapm(){
    return am_pm;
    }
};
//create record ADT
class record
{
    int recordId;
    int patientId;
    string notes;
public:
    record(){
        recordId=0;
        patientId=0;
        notes="";
    }

    void updaterecord(vector<record>& recordvec);
    int getrecordId(){
    return recordId;
    }
    void setrecordId(int x){
    recordId=x;
    }
    int getpatientId(){
    return patientId;
    }
    void setpatientId(int x){
    patientId=x;
    }
    string getnotes(){
    return notes;
    }
    void setnotes(string x){
     notes=x;
    }
};
//create diagnosis ADT
class diagnosis
{
    int diagnosisId;
    string diseasename;
public:
    diagnosis(){
        diagnosisId=0;
        diseasename="";
    }
    void getdiagnosisdata(vector<diagnosis>& diagnosisvec,int& counter5);
    void updatediag(vector<diagnosis>& diagnosisvec,int counter5);
};
//Create appointment ADT
class appointment
{
    int appointmentId;//should be auto increment
    int doctorId;
    int patientId;
    int slotId;
    string reason;
    int diagnosisId;
    string medication;
public:
    appointment(){
        appointmentId=0;
        doctorId=0;
        patientId=0;
        slotId=0;
        reason="";
        diagnosisId=0;
        medication="";
    }
    void updateappointment(vector<appointment>& appointmentvec);
    void viewappointbydocname(vector<appointment> appointmentvec,vector<doctor> doctorvec,int counter2);
    void viewappointbypatient(vector<appointment> appointmentvec,vector<patient> patientvec,int counter1);
    void cancelappointment(vector<appointment>& appointmentvec,vector<slot>& slotvec,int counter3);
    void addappointment(vector<appointment>& appointmentvec);
    void updaterecord(vector<appointment> appointmentvec,vector<patient> patientvec,int counter1,vector<record>& recordvec);
    void updateslot(vector<appointment> appointmentvec,vector<slot>& slotvec,int counter3);
    int getdoctorId(){
        return doctorId;
    }
    int getslotId(){
     return slotId;
    }
    int getpatientId(){
    return patientId;
    }
};
//Create lab ADT
class labappointment
{
    int appointmentId;
    int doctorId;
    int patientId;
    int slotId;
    string reason;
    int diagnosisId;
    string medication;
public:
    labappointment(){
        appointmentId=0;
        doctorId=0;
        patientId=0;
        slotId=0;
        reason="";
        diagnosisId=0;
        medication="";
    }
    void addlab(vector<labappointment>& labvec,vector<slot>& slotvec,int counter3,vector<datetime> datevec, int counter4);
    void deletelab(vector<labappointment>& labvec);
    void viewalllab(vector<labappointment> labvec);
};
#endif // DATA_H_INCLUDED
