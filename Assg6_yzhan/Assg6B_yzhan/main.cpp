#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <istream>
using namespace std;
//struct StuAnswer;
//create struct to store answerkey
struct answerkey
{
    string AnswerKey;
    string markingschema;
    answerkey()
    {
        AnswerKey="";
        markingschema="";
    }
    void readAnswer();

};
//create struct to store student answers
struct StuAnswer
{
    string classname ;
    int StudentId ;
    string LastName;
    string FirstName;
    string StudentAnswer;
    int totalStudentPoints;
    int numberOfCorrectAnswers;
    int numberOfFalseAnswers;
    int numberOfBlanks;
    char grade;
    StuAnswer()
    {
        classname=" ";
        StudentId=0;
        LastName="";
        FirstName="";
        totalStudentPoints=70;
        numberOfCorrectAnswers=0;
        numberOfFalseAnswers=0;
        numberOfBlanks=0;
        grade=' ';
    }


    void points(answerkey MyStruct2);
    void getgrade( answerkey MyStruct2);
    void getStatistics(int& numberofstu,int& numberofAstu,int& numberofBstu,int& numberofCstu,int& numberofDstu,int& numberofFstu);
    void printresult(ofstream& outfile);
};
void readData(StuAnswer MyStruct[]);
void printheader(ofstream& outfile);
void printstatistic(ofstream& outfile,int& numberofstu,int& numberofAstu,int& numberofBstu,int& numberofCstu,int& numberofDstu,int& numberofFstu);


void readData(StuAnswer MyStruct[])
{
    ifstream inData;
    inData.open("studentsAnswer.txt");
    char c;
    for(int i=0;i<5000;i++)
    {
        inData>>MyStruct[i].classname;
        inData>>c;
        inData>>MyStruct[i].StudentId;
        inData>>c;
        inData>>MyStruct[i].LastName;
        inData>>c;
        inData>>MyStruct[i].FirstName;
        inData>>c;
        getline(inData,MyStruct[i].StudentAnswer);


    }
    inData.close();
}
void answerkey::readAnswer()
{
    ifstream inData;
    inData.open("answerKey.txt");
    getline(inData,AnswerKey);
    inData>>markingschema;
    inData.close();

}
void StuAnswer::points(answerkey MyStruct2)
{
    double maximumPossiblePoints =270.00;
    //MyStruct2.readAnswer();

        for(int j=0;j<100;j++)
        {
            if (StudentAnswer[j]==' ')
            {
               numberOfBlanks+=1;
               totalStudentPoints=totalStudentPoints;
            }

            else if(StudentAnswer[j]==MyStruct2.AnswerKey[j])
            {
                totalStudentPoints=totalStudentPoints+2;
                numberOfCorrectAnswers+=1;
            }

            else if(StudentAnswer[j]!=MyStruct2.AnswerKey[j])
            {
                totalStudentPoints=totalStudentPoints-1;
                numberOfFalseAnswers+=1;
            }


        }
        if(numberOfBlanks>=5)
            totalStudentPoints=totalStudentPoints-2;

        totalStudentPoints = (totalStudentPoints/ maximumPossiblePoints) * 100;

}
void StuAnswer::getStatistics(int& numberofstu,int& numberofAstu,int& numberofBstu,int& numberofCstu,int& numberofDstu,int& numberofFstu)
{


        if(grade=='A')
        numberofAstu+=1;
        if(grade=='B')
        numberofBstu+=1;
        if(grade=='C')
        numberofCstu+=1;
        if(grade=='D')
        numberofDstu+=1;
        if(grade=='F')
        numberofFstu+=1;


    numberofstu=numberofAstu+numberofBstu+numberofCstu+numberofDstu+numberofFstu;
}
void printheader(ofstream& outfile)
{
    char c=',';
    outfile<<"class-name"<<c<<"studentsID"<<c<< "lastName"<<c<<"firstName"<<c<<
    "answers"<<c<<"letterGrade"<<c<<"numberOfCorrectAnswers"<<c<<"numberOfFalseAnswers"<<
    c<<"numberOfBlanks"<<c<<"totalPoints"<<endl;
}
void StuAnswer::printresult(ofstream& outfile)

{

    char c =',';

        outfile<<classname<<c<<StudentId<<c<<LastName<<c<<FirstName<<c;

        outfile<<StudentAnswer;

        outfile<<c<<grade<<c<<numberOfCorrectAnswers<<c<<numberOfFalseAnswers
        <<c<<numberOfBlanks<<c<<totalStudentPoints<<endl;


   // outfile.close();
}
void printstatistic(ofstream& outfile,int& numberofstu,int& numberofAstu,int& numberofBstu,int& numberofCstu,int& numberofDstu,int& numberofFstu)
{
    outfile<<"Number students attended the exam:"<<numberofstu<<endl;
    outfile<<"Number students received A:"<<numberofAstu<<endl;
    outfile<<"Number students received B:"<<numberofBstu<<endl;
    outfile<<"Number students received C:"<<numberofCstu<<endl;
    outfile<<"Number students received D:"<<numberofDstu<<endl;
    outfile<<"Number students received F:"<<numberofFstu<<endl;
}
void StuAnswer::getgrade( answerkey MyStruct2)
{


        if(MyStruct2.markingschema=="hard")
        {
            if(totalStudentPoints>=95)
                grade='A';
            else if(totalStudentPoints<95&&totalStudentPoints>=85)
                grade='B';
            else if(totalStudentPoints<85&&totalStudentPoints>=75)
                grade='C';
            else if(totalStudentPoints<75&&totalStudentPoints>=65)
                grade='D';
            else
                grade='F';
        }
        if(MyStruct2.markingschema=="medium")
        {
            if(totalStudentPoints>=90)
                grade='A';
            else if(totalStudentPoints<90&&totalStudentPoints>=80)
               grade='B';
            else if(totalStudentPoints<80&&totalStudentPoints>=70)
               grade='C';
            else if(totalStudentPoints<70&&totalStudentPoints>=60)
                grade='D';
            else
               grade='F';
        }
        if(MyStruct2.markingschema=="easy")
        {
            if(totalStudentPoints>=90)
               grade='A';
            else if(totalStudentPoints<90&&totalStudentPoints>=80)
                grade='B';
            else if(totalStudentPoints<80&&totalStudentPoints>=70)
                grade='C';
            else if(totalStudentPoints<70&&totalStudentPoints>=60)
                grade='D';
            else
                grade='F';
        }

}
int main()
{
    int numberofstu=0;
    int numberofAstu=0;
    int numberofBstu=0;
    int numberofCstu=0;
    int numberofDstu=0;
    int numberofFstu=0;
    StuAnswer MyStruct[5000];
    answerkey MyStruct2;
    MyStruct2.readAnswer();
    readData(MyStruct);
    ofstream outfile;
    outfile.open ("results.txt");
    printheader(outfile);
    for (int i=0;i<5000;i++)
    {
        MyStruct[i].points(MyStruct2);
        MyStruct[i].getgrade(MyStruct2);
        MyStruct[i].getStatistics(numberofstu, numberofAstu, numberofBstu, numberofCstu, numberofDstu, numberofFstu);
        MyStruct[i].printresult(outfile);
    }
    printstatistic(outfile,numberofstu,numberofAstu,numberofBstu,numberofCstu,numberofDstu,numberofFstu);
    outfile.close();
    return 0;
}
