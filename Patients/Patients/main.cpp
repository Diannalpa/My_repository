#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
 
using namespace std;
 
class PacientInfo {
public:
    PacientInfo(string name, bool dispensary, int visits, string diagnosis, double medicine_cost) {
        this->name = name;
        this->dispensary = dispensary;
        this->visits = visits;
        this->diagnosis = diagnosis;
        this->medicine_cost = medicine_cost;
    }
 
    void printInfo() const {
        cout << "Name: " << name << "\n";
        cout << "Dispensary: " << (dispensary ? "True" : "False") << "\n";
        cout << "Visits: " << visits << "\n";
        cout << "Diagnosis: " << diagnosis << "\n";
        cout << "Medicine Cost: " << medicine_cost << "\n";
    }
 
    static void divide_entries1(const list<PacientInfo>& pacients,
                                list<PacientInfo>& lessThan100,
                                list<PacientInfo>& greaterThanOrEqual100) {
 
        for (const auto& pacient : pacients) {
            if (pacient.getMedicineCost() < 100)
                lessThan100.push_back(pacient);
            else
                greaterThanOrEqual100.push_back(pacient);
        }
    }
 
    static list<PacientInfo> divide_entries2(list<PacientInfo>& pacients) {
 
        list<PacientInfo> greaterThanOrEqual100;
 
        auto it = pacients.begin();
        while (it != pacients.end()) {
            if (it->getMedicineCost() >= 100) {
                greaterThanOrEqual100.push_back(*it);
                it = pacients.erase(it);
            } else ++it;
        }
        return greaterThanOrEqual100;
    }
 
    string getName() const {
        return name;
    }
 
    bool getDispensary() const {
        return dispensary;
    }
 
    int getVisits() const {
        return visits;
    }
 
    string getDiagnosis() const {
        return diagnosis;
    }
 
    double getMedicineCost() const {
        return medicine_cost;
    }
 
    void setName(string name) {
        this->name = name;
    }
 
    void setDispensary(bool dispensary) {
        this->dispensary = dispensary;
    }
 
    void setVisits(int visits) {
        this->visits = visits;
    }
 
    void setDiagnosis(string diagnosis) {
        this->diagnosis = diagnosis;
    }
 
    void setMedicineCost(double medicine_cost) {
        this->medicine_cost = medicine_cost;
    }
 
private:
    string name;
    bool dispensary;
    int visits;
    string diagnosis;
    double medicine_cost;
};
 
PacientInfo create_patient(list<PacientInfo>& pacients) {
    string name, diagnosis;
    bool dispensary;
    int visits;
    double medicine_cost;
    cout << "Enter patient name: ";
    cin >> name;
    cout << "Enter patient diagnosis: ";
    cin >> diagnosis;
    cout << "Is the patient in the dispensary? 1 - yes, 0 - no: ";
    cin >> dispensary;
    cout << "How many visits does the patient have: ";
    cin >> visits;
    cout << "Cost of medicine for patient: ";
    cin >> medicine_cost;
    cout << "New patient created. \n";
 
    return PacientInfo(name, dispensary, visits, diagnosis, medicine_cost);
}
 
bool validateDiagnosis(const string& diagnosis) {
    return !diagnosis.empty();
}
 
void sortPacientsBySickness(list<PacientInfo>& pacients) {
    pacients.sort([](const PacientInfo& a, const PacientInfo& b) {
        return a.getDiagnosis() < b.getDiagnosis();
    });
    cout << "Patients sorted based on diagnosis. \n";
}
 
void printMinMaxVisits(const list<PacientInfo>& pacients) {
    if (pacients.empty()) {
        cout << "No patients available.\n";
        return;
    }
    int maxVisits = pacients.front().getVisits();
    int minVisits = pacients.front().getVisits();
    string maxVisitsName = pacients.front().getName();
    string minVisitsName = pacients.front().getName();
 
    for (const auto& pacient : pacients) {
        if (pacient.getVisits() > maxVisits) {
            maxVisits = pacient.getVisits();
            maxVisitsName = pacient.getName();
        }
        if (pacient.getVisits() < minVisits) {
            minVisits = pacient.getVisits();
            minVisitsName = pacient.getName();
        }
    }
 
    cout << "Patient with most visits: " << maxVisitsName << " (" << maxVisits << " visits)" << endl;
    cout << "Patient with least visits: " << minVisitsName << " (" << minVisits << " visits)" << endl;
}
 
void printDispensaryPatients(const list<PacientInfo>& pacients) {
    cout << "Patients that are in the dispensary: \n";
    for (const auto& pacient : pacients) {
        if (pacient.getDispensary())
            cout << pacient.getName() << "\n";
    }
}
 
void dividePatients1(const list<PacientInfo>& pacients,
                     list<PacientInfo>& lessThan100,
                     list<PacientInfo>& greaterThanOrEqual100) {
    PacientInfo::divide_entries1(pacients, lessThan100, greaterThanOrEqual100);
    cout << "Patients divided based on medicine cost.\n";
}
 
list<PacientInfo> dividePatients2(list<PacientInfo>& pacients) {
    return PacientInfo::divide_entries2(pacients);
}
 
void displayMenu() {
    cout << "1. Create new patient\n";
    cout << "2. Read all patients\n";
    cout << "3. Sort patients by diagnosis\n";
    cout << "4. Print patient with most and least visits\n";
    cout << "5. Print patients in the dispensary\n";
    cout << "6. Divide patients 1 (based on medicine cost)\n";
    cout << "7. Divide patients 2 (based on medicine cost)\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
}
 
int main() {
    list<PacientInfo> pacients;
 
    pacients.push_back(PacientInfo("John Doe", true, 3, "Flu", 50.0));
    pacients.push_back(PacientInfo("Jane Smith", false, 2, "Fever", 150.0));
    pacients.push_back(PacientInfo("Alice Johnson", true, 4, "Cold", 80.0));
    pacients.push_back(PacientInfo("Bob Brown", false, 1, "Headache", 120.0));
    pacients.push_back(PacientInfo("Emma Davis", true, 5, "Flu", 90.0));
    pacients.push_back(PacientInfo("Michael Wilson", false, 3, "Fever", 110.0));
    pacients.push_back(PacientInfo("Sophia Martinez", true, 2, "Cold", 70.0));
    pacients.push_back(PacientInfo("William Taylor", false, 6, "Headache", 130.0));
    pacients.push_back(PacientInfo("Olivia Anderson", true, 4, "Flu", 80.0));
    pacients.push_back(PacientInfo("Daniel Thomas", false, 2, "Fever", 150.0));
    pacients.push_back(PacientInfo("Ava Garcia", true, 3, "Cold", 60.0));
    pacients.push_back(PacientInfo("Matthew Hernandez", false, 1, "Headache", 100.0));
    pacients.push_back(PacientInfo("Emily Wilson", true, 4, "Flu", 70.0));
    pacients.push_back(PacientInfo("Ethan Lee", false, 2, "Fever", 140.0));
    pacients.push_back(PacientInfo("Isabella Nguyen", true, 3, "Cold", 85.0));
    pacients.push_back(PacientInfo("James Smith", false, 1, "Headache", 125.0));
    pacients.push_back(PacientInfo("Sophia Brown", true, 5, "Flu", 95.0));
    pacients.push_back(PacientInfo("Alexander Davis", false, 3, "Fever", 115.0));
    pacients.push_back(PacientInfo("Mia Garcia", true, 2, "Cold", 75.0));
    pacients.push_back(PacientInfo("Charlotte Wilson", false, 4, "Headache", 135.0));
 
    int choice;
    do {
        displayMenu();
        cin >> choice;
 
        switch(choice) {
            case 1:
                pacients.push_back(create_patient(pacients));
                break;
            case 2:
                cout << "\n--- All Patients ---\n";
                for (const auto& pacient : pacients) {
                    pacient.printInfo();
                    cout << endl;
                }
                break;
            case 3:
                sortPacientsBySickness(pacients);
                break;
            case 4:
                printMinMaxVisits(pacients);
                break;
            case 5:
                printDispensaryPatients(pacients);
                break;
            case 6:
                {
                    list<PacientInfo> lessThan100, greaterThanOrEqual100;
                    dividePatients1(pacients, lessThan100, greaterThanOrEqual100);
                    cout << "\nPatients with medicine cost less than 100:\n";
                    for (const auto& patient : lessThan100)
                        patient.printInfo();
                    cout << "\nPatients with medicine cost greater than or equal to 100:\n";
                    for (const auto& patient : greaterThanOrEqual100)
                        patient.printInfo();
                    break;
                }
            case 7:
                {
                    list<PacientInfo> greaterThanOrEqual100 = dividePatients2(pacients);
                    cout << "\nPatients with medicine cost greater than or equal to 100:\n";
                    for (const auto& patient : greaterThanOrEqual100)
                        patient.printInfo();
                    break;
                }
            case 8:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 8);
 
    return 0;
}
