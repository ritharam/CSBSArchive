#include <iostream>
#include<cstring>
using namespace std;

class Student
{

private:
    char Name[20];
    int RollNo;
    int PhoneNo;

public :
    void getData()
{
        cout << "Enter Name : ";
cin >> Name;
cout << "Enter Roll Number : ";
cin >> RollNo ;
cout << "Enter Phone no : ";
cin >> PhoneNo;
    }

void putData()
{
        cout << "Name : " << Name << endl;
        cout << "Roll Number : " << RollNo << endl;
        cout << "Phone Number : " << PhoneNo << endl;
    }

void checkName(const char* checkName)
{
if (strcmp(Name,checkName) == 0)
{
cout << "Details of the student : \n";
putData();
}
if (strcmp(Name,checkName) != 0)
cout << "Name not Found";
}
};

int main()
{
int n;
char chkName[20];
Student mystud[10];

cout << "Enter number of student details : ";
cin >> n;
for (int i=1;i<=n;i++)
{
mystud[i].getData();
}
cout << "Enter the name to check : ";
cin >> chkName;

for (int i=1;i<=n;i++)
{
mystud[i].checkName(chkName);
}
return 0;
}