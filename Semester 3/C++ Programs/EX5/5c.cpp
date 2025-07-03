#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    int inches;

public:
    Distance() : feet(0), inches(0) {}  // Constructor to initialize to zero

    void getDistance() {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    void showDistance() const {
        cout << feet << " feet " << inches << " inches";
    }

    static Distance avgDistance(Distance distances[], int count) {
        Distance average;
        int totalFeet = 0;
        int totalInches = 0;

        for (int i = 0; i < count; i++) {
            totalFeet += distances[i].feet;
            totalInches += distances[i].inches;
        }

        // Convert excess inches to feet if needed
        totalFeet += totalInches / 12;
        totalInches %= 12;

        average.feet = totalFeet / count;
        average.inches = totalInches / count;

        return average;
    }
};

int main() {
    Distance distances[10];
    int numDistances;
    cout << "Enter the number of distances (up to 10): ";
    cin >> numDistances;

    for (int i = 0; i < numDistances; i++) {
        cout << "Enter Distance " << i + 1 << ":" << endl;
        distances[i].getDistance();
    }

    Distance average = Distance::avgDistance(distances, numDistances);
    cout << "Average Distance: ";
    average.showDistance();
    cout << endl;
    return 0;
}
