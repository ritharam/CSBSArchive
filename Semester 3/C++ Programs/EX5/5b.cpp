#include<iostream>
#include<iomanip>
using namespace std;

class Employee 
{
	public :
		char EName[20];
		long int Eno ;
	void GetData()
	{	
		cout << "Enter Employee Name : "; 
		cin >> EName;
		cout << "Enter Employee Number ; ";
		cin >> Eno;
 	}
	void PutData()
	{
		cout << setw(5) << "Name : " << EName << endl;
		cout << setw(5) << "Number : " << Eno;
	}
	
};

int main()
{
	Employee emp[10];

	for(int i=0;i<10;i++)
     		emp[i].GetData();
	cout << "Employee Data : " << endl;
    	for (int i = 0; i < 10; i++) 
	{
        	emp[i].PutData();
       		cout << endl;
    	}

    return 0;
	
}