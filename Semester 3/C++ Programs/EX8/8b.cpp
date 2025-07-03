/*Develop a C++ program for hospital management. The PATIENT class has details such as PatientId, PatientName, 
Age, Disease, Blood_Group and DoctorId. Include parameterized constructor to get the details for the data 
members. The DOCTOR class has details such as DoctorId, DoctorName and Specialization. Include parameterized 
constructor to take input for the data members. Create a class TREATMENT derived from PATIENT and DOCTOR 
classes. Include a member function search(int,int) in TREATMENT class, that takes the PatientId and DoctorId
as input and searches for a matching record in PATIENT objects. If found, then display the PatientId, patient
name, DoctorId and DoctorName. Overload the search() function to take the DoctorId as input and retrieve the 
details of the patients of that doctor. Include a friend function called search() that retrieves the details 
of DOCTOR object based on the patient name (PNAME) taken as user input. In main method, create an array of 
TREATMENT objects and demonstrate the function of the member functions and the friend function. Create a 
menu driven program to execute the above given scenario.*/

#include <iostream>
#include <string>

using namespace std;

class DOCTOR {
private:
    int DoctorId;
    string DoctorName;
    string Specialization;

public:
    DOCTOR(int id, const string& name, const string& specialization)
        : DoctorId(id), DoctorName(name), Specialization(specialization) {}

    friend class TREATMENT;
};

class PATIENT {
protected:
    int PatientId;
    string PatientName;
    int Age;
    string Disease;
    string Blood_Group;
    int DoctorId;

public:
    PATIENT(int id, const string& name, int age, const string& disease, const string& blood_group, int docId)
        : PatientId(id), PatientName(name), Age(age), Disease(disease), Blood_Group(blood_group), DoctorId(docId) {}
};

class TREATMENT : public PATIENT, public DOCTOR {
public:
    TREATMENT(int pId, const string& pName, int age, const string& disease, const string& blood_group, int docId,
              int docId2, const string& docName, const string& specialization)
        : PATIENT(pId, pName, age, disease, blood_group, docId), DOCTOR(docId2, docName, specialization) {}

    void search(int patientId, int doctorId) {
        if (PATIENT::PatientId == patientId && DOCTOR::DoctorId == doctorId) {
            cout << "Patient ID: " << PATIENT::PatientId << endl;
            cout << "Patient Name: " << PATIENT::PatientName << endl;
            cout << "Doctor ID: " << DOCTOR::DoctorId << endl;
            cout << "Doctor Name: " << DOCTOR::DoctorName << endl;
        } else {
            cout << "Record not found." << endl;
        }
    }

    void search(int doctorId) {
        if (DOCTOR::DoctorId == doctorId) {
            cout << "Patient ID: " << PATIENT::PatientId << endl;
            cout << "Patient Name: " << PATIENT::PatientName << endl;
            cout << "Doctor ID: " << DOCTOR::DoctorId << endl;
            cout << "Doctor Name: " << DOCTOR::DoctorName << endl;
        } else {
            cout << "Record not found." << endl;
        }
    }

    static void search(const string& patientName, TREATMENT* patients, int numPatients) {
        for (int i = 0; i < numPatients; i++) {
            if (patients[i].PATIENT::PatientName == patientName) {
                cout << "Doctor ID: " << patients[i].DOCTOR::DoctorId << endl;
                cout << "Doctor Name: " << patients[i].DOCTOR::DoctorName << endl;
                return;
            }
        }
        cout << "Patient not found." << endl;
    }
};

int main() {
    TREATMENT patients[3] = {
        TREATMENT(1, "Patient1", 30, "Fever", "A+", 101, 101, "Doctor1", "General Physician"),
        TREATMENT(2, "Patient2", 25, "Injury", "B-", 102, 101, "Doctor1", "General Physician"),
        TREATMENT(3, "Patient3", 40, "Cough", "O+", 103, 102, "Doctor2", "Cardiologist")
    };

    int choice;
    do {
        cout << "Hospital Management System" << endl;
        cout << "1. Search for a patient by ID and Doctor ID" << endl;
        cout << "2. Search for patients by Doctor ID" << endl;
        cout << "3. Search for Doctor by patient name" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int pId, dId;
                cout << "Enter Patient ID and Doctor ID: ";
                cin >> pId >> dId;
                for (int i = 0; i < 3; i++) {
                    patients[i].search(pId, dId);
                }
                break;

            case 2:
                int docId;
                cout << "Enter Doctor ID: ";
                cin >> docId;
                for (int i = 0; i < 3; i++) {
                    patients[i].search(docId);
                }
                break;

            case 3:
                {string pname;
                cout << "Enter Patient Name: ";
                cin.ignore();
                getline(cin, pname);
                TREATMENT::search(pname, patients, 3);
                break;}

            case 4: cout << "Exiting program. Goodbye!" << endl;
                    break;

            default: cout << "Invalid choice. Please try again." << endl;
                     break;
        }

    } while (choice != 4);

    return 0;
}
