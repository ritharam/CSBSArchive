#include<iostream>
using namespace std;

class CarPart
{	public :
		int CarID;
		int Charge;
		float Time;
	void GetData()
	{
    		cout << "Enter the CarID : ";
    		cin >> CarID;
    		cout << "Enter the charge : ";
    		cin >> Charge;
    		cout << "Enter the Time :";
    		cin >> Time;
	}
	void PutData()
	{
		cout << "Car ID  : " << CarID << endl;
            	cout << "Charge : " << Charge << endl;
            	cout << "Time : " << Time << endl;
	}
	int SearchID(int sid)
	{
		if (CarID == sid)
		{
			PutData();
			return 1;
		}
		return 0;	
	}

};

int main()
{
	int n,res,ch,sid;
	float tm;
	cout << "Enter number of CarParts : ";
	cin >> n;
	CarPart cp[n];
	for(int i=0;i<n;i++)
     		cp[i].GetData();
	cout << "1.Search \n2.Exit\n";
  	cin >> ch;
	if (ch==1)
	{
  		cout << "Enter the CarID to search : ";
  		cin >> sid;
  		for(int i=0;i<n;i++)
		{
			res = cp[i].SearchID(sid);
			if(res==1)
			{
				break;
			} 
		}
  	}
  	if(res==0)
	{
   	 cout<<"No Car ID found.";
   	}
	return 0;
	
}