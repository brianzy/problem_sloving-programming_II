#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;
//create struct to store atudent answer
struct StuAnswer
{
    string classname ;
    vector<int> StudentId ;
    vector<string> LastName;
    vector<string> FirstName;
    vector<string> StudentAnswer;
    StuAnswer(): StudentId(5000,0),LastName(5000,""), FirstName(5000,""),StudentAnswer(5000,"") {}



    void GenStudentId();
    void GenLastName();
    void GenFirstName();
    void GenStudentAnswer();
    void GetFirstAnswer();
    void DisplayStuAnswer();

};
//generate studentID
void StuAnswer::GenStudentId()
{
    bool check =true;
        int temp =0;
    for (int i=0; i<5000;i++)
    {

        do{
            check = true;
            temp=(rand()%99999 +10000);
            for(int j=0; j<i;j++)
            {
                if(temp==StudentId[j])
                {
                    check=false;
                }
            }

        }while(!check);
    StudentId[i] = temp;

    }

}

void StuAnswer::GenFirstName()
{
    for (int i =0;i<5000;i++)
           for(int j =0; j < (rand()%10+3); j++)
           {
               FirstName[i]+=(rand()%26+65);
           }
}
void StuAnswer::GenLastName()
{
    for (int i =0;i<5000;i++)

           for(int j =0; j < (rand()%10+3); j++)
           {
                LastName[i]+=(rand()%26+65);
           }
}
void StuAnswer::GenStudentAnswer()
{
    for (int i =1;i<5000;i++)
    {
        for(int j =0; j < 100; j++)
        {

        if(rand()%100==1)
            StudentAnswer[i]+=' ';
        else if(j==4||j==9||j==14||j==24)
            StudentAnswer[i]+= (rand()%2+65);
        else
            StudentAnswer[i]+= (rand()%3+65);
        }
    }
}
void StuAnswer::GetFirstAnswer()
{
    ifstream inData;
    inData.open("firstStudentAnswersEntry.txt");
    inData >> StudentAnswer[0];
    inData.close();

}
void StuAnswer::DisplayStuAnswer()
{
    ofstream outfile;
    outfile.open ("studentsAnswer.txt");
    for(int i = 0; i < 5000; i++)
    {
        outfile<<classname<<" "<<","<<StudentId[i]<<" "<<","<<LastName[i]<<" "
        <<","<<FirstName[i]<<" "<<","<<StudentAnswer[i]<<endl;
    }
    outfile.close();

}
int main()
{
    StuAnswer MyStruct;
    MyStruct.classname= "CS-250";
    MyStruct.GenStudentId();
    MyStruct.GenFirstName();
    MyStruct.GenLastName();
    MyStruct.GenStudentAnswer();
    MyStruct.GetFirstAnswer();
    MyStruct.DisplayStuAnswer();
    return 0;
}
