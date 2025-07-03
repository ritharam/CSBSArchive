#include<iostream>
using namespace std;

class ObjectCounter{
	public :
		static int count;
	ObjectCounter()
	{
		count++;
		cout << "Object created." << "Count : " << count << endl;
	}
	~ObjectCounter()
	{
		count--;
		cout << "Object destroyed." << "Count : " << count << endl;
	}
};

int ObjectCounter::count = 0;

int main()
{
	ObjectCounter obj1;
{
	ObjectCounter obj2;
}
	ObjectCounter obj3;
	return 0;
}