#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    int bookID;
    string name;
    double price;
        void getData()
        {
            cout << "Enter Book ID : ";
            cin >> bookID;
            cout << "Enter Book Name : ";
            cin >> name ;
            cout << "Enter Book Price : ";
            cin >> price;
        }
        int searchBook(const Book bk[], int n, int searchID) 
        {
            for (int i = 0; i < n; ++i) {
                if (bk[i].bookID == searchID) {
                    return i;  
                }
            }
        return -1;  
        }
};

int main() 
{
    Book bk[3];
    int n=3;
    for (int i = 0; i < n; i++)
    {
        bk[i].getData();
    }
    cout << "Enter a book ID to search: ";
    int searchID;
    cin >> searchID;

    int bookIndex = bk[1].searchBook(bk, n, searchID);

    if (bookIndex != -1) 
    {
        cout << "Book Found!" << endl;
        cout << "ID: " << bk[bookIndex].bookID<< endl;
        cout << "Name: " << bk[bookIndex].name << endl;
        cout << "Price: $" << bk[bookIndex].price << endl;
    } 
    else 
    {
        cout << "Book not found." << endl;
    }

    return 0;
}
