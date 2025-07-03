#include<iostream>
using namespace std;

class Time{
	public:
    		int hrs;
    		int mins;
    		int secs;
		void getTime(int h, int m, int s)
		{
			hrs = h;	
			mins = m;
			secs = s;
		} 
		void showTime()  
		{
 		       cout << hrs << ":" << mins << ":" << secs << endl;
    		}
		Time addTime(Time t1, Time t2) 
		{
		        Time add;
        		add.secs = t1.secs + t2.secs;
        		add.mins = t1.mins + t2.mins + (add.secs / 60);
        		add.hrs = t1.hrs + t2.hrs + (add.mins / 60);
			add.secs %= 60;
        		add.mins %= 60;
			return add;
    		}
};

int main() 
{
	Time t1,t2,t3;
	t1.getTime(2, 30, 45);
	t2.getTime(1, 15, 20);
	t3 = t3.addTime(t1, t2);
	cout << "Time1: ";
    	t1.showTime();
    	cout << "Time2: ";
    	t2.showTime();
    	cout << "Time3 (Sum of Time1 and Time2): ";
    	t3.showTime();

    return 0;
}
