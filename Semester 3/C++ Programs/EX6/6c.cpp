#include <iostream>
#include <cstring>
using namespace std;

class Details 
{
        private:
                char name[100];
                char area[100];
                char phone_no[15];
                char area_code[5];

        public:
                void setDetails() 
                {
                        cout << "Enter Name : ";
                        cin >> name;
                        cout << "Enter Area : ";
                        cin >> area ;
                        cout << "Enter Phone no : ";
                        cin >> phone_no;
                        cout << "Enter Area Code : ";
                        cin >> area_code;
                }
                void displayDetails() 
                {
                        cout << "Name: " << name << endl;
                        cout << "Area: " << area << endl;
                        cout << "Phone Number and Area Code: " << strcat(phone_no, area_code);
                }
};

int main() 
{
        int n;
        Details dets[10];
        cout << "Enter number of details : ";
        cin >> n;
        for (int i=1;i<=n;i++)
        {
                dets[i].setDetails();
        }
        for (int i=1;i<=n;i++)
        {
                dets[i].displayDetails();
        }
        return 0;
}
