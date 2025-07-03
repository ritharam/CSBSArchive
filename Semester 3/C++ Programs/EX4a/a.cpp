#include <iostream>
#include<cstring>
using namespace std;

class Part
{

public:
    char partName[20];
    int partNumber;
    int cost;

    void setPart(const char* name, int number, int c)
{
        strcpy(partName,name);
        partNumber = number;
        cost = c;
    }

void showPart()
{
        cout << "Part Name : " << partName << endl;
        cout << "Part Number : " << partNumber << endl;
        cout << "Cost : " << cost << endl;
    }
};

int main()
{
Part myPart;
myPart.setPart("Mobile", 123, 30000);
cout << "Part Details : " << endl;
        myPart.showPart();
return 0;
}