#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
// creating a structure which will hold all the student records.
struct StudentRecord {
string firstName;
string lastName;
int oduUin;
string dateOfBirth;
double gpa;
StudentRecord *next;
StudentRecord *prev;
StudentRecord() {next = 0;prev = 0;}
};
StudentRecord *head = NULL;

void free_list()
{
     // We will create a current node and assign head to it, then we will iterate the node through the linked list and delete all the records stored in the linked list
StudentRecord *current = head;
while(current!=NULL) // as I am considering tail->next = NULL
{
    head = current->next;

    current->next = NULL;
    current->prev = NULL;
    free(current);
    current = head;
}
head = NULL;

}


void display_data()
{
cout << endl << endl << "Listing all student records: " << endl;
cout << "---------------------------" << endl;
// We will create a node named start and will iterate it through the whole linked list and display the data
StudentRecord *start = head;
if (!start) {
cout << "No Data!" << endl;
return;
}
while(start) {
cout << start -> firstName << endl;
cout << start -> lastName << endl;
cout << start -> oduUin << endl;
cout << start -> dateOfBirth << endl;
cout << start -> gpa << endl << endl;
start = start -> next;
}
}



StudentRecord *get_data()
{
     //creating a temporary node in which we will store all the student records and return the temporary node in the end of the function
StudentRecord *rec = new StudentRecord;
cout << endl;
cout << "You chose option #2." << endl;
cout << "What is the student's first name?: ";
cin >> rec->firstName;
cout << "What is the student's last name?: ";
cin >> rec->lastName;
cout << "What is the student's uin?: ";
cin >> rec->oduUin;
cout << "What is the student's date of birth?: ";
cin >> rec->dateOfBirth;
cout << "What is the student's GPA?: ";
cin >> rec->gpa;

//rec->next = head;
return rec;
}

void add_data(StudentRecord *current)
{
// We will store the address of the present head node in the next field of the current node and later we will make the current node as head node
current->next=head;  // store the address of the pointer head(second field)
if(head==NULL)
    head=current;
if(head!=NULL)
head->prev=current;
head = current;

}
void search(double key)
{
     // We will iterate the head through the linked list until it finds the required variable or until the end of linked list
    while (head != NULL)
    {
        if (head->oduUin == key)
        {
            cout<<"key found"<<endl;
           // cout<<head->uin<<endl;
            cout<<"first name = "<<head->firstName<<endl;
            cout<<"last name = "<<head->lastName<<endl;
            cout<<"date of birth = "<<head->dateOfBirth<<endl;
            cout<<"gpa = "<<head->gpa<<endl;
            return;
        }
        head = head->next;
    }
    cout<<"Key not found"<<endl;
}
void insertdata(int pos)
{
    int tempos=1;
    StudentRecord *current = new StudentRecord;
    StudentRecord *rec = new StudentRecord;
    cout << endl;
    cout << "You chose option #1." << endl;
    cout << "What is the student's first name?: ";
    cin >> rec->firstName;
    cout << "What is the student's last name?: ";
    cin >> rec->lastName;
    cout << "What is the student's uin?: ";
    cin >> rec->oduUin;
    cout << "What is the student's date of birth?: ";
    cin >> rec->dateOfBirth;
    cout << "What is the student's GPA?: ";
    cin >> rec->gpa;
    if(pos==0)
    {
        rec->prev=NULL;
        rec->next=head;
        head=rec;
    }
    else
    {
        current=head;
        while(tempos!=pos)
        {
            current=current->next;
            tempos++;
        }
        tempos--;
        current=current->prev;
        rec->next=current->next;
        rec->prev=current;
        if(current->next!=NULL)
            current->next->prev=rec;
        current->next=rec;
        cout<<"added successfully!"<<endl;
    }

}
void processMenu()
{
      // creating current node for StudentRecord struct
StudentRecord *current = NULL;
int ser;
char choice = 0;
while(true) {
cout << endl <<"What would you like to do?" << endl;
cout << "1.Insert a student record at a particular position" << endl;
cout << "2. Enter a student record. " << endl;
cout << "3. List all student records. " << endl;
cout << "4. Exit program. " <<endl;
cout << "5. Search. " << endl;

cin >> choice;
while(cin.get() != '\n');
if(choice == '2'){
current = get_data();
add_data(current);
}
else if(choice == '3'){
display_data();
}
else if (choice == '4'){
free_list();
return;
}
else if (choice == '5'){
    cout<<"Enter student uin to search for records"<<endl;
    cin>>ser;
search(ser);
}
else if (choice == '1'){
    cout <<"Enter the position at which you want to insert your record:"<<endl;
    cin >>ser;
    insertdata(ser);


}
else {
cout << "Allowed Selections are 1, 2, and 3!" << endl;
}
}
}

int main()
{
     // Program starts execution from main block
cout << "Student Record Program." << endl << endl;
processMenu();
// calling process function which inturn calls create and display functions
system("pause");
return 0;
}
