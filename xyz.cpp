#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

struct TruckData {
    char tnm[20];
    int tt, ts, tfl, tbl;
};

class Trucks {
    TruckData data;

public:
    void EnterTruckData() {
        cout << "-------------*****This Enter Truck Data*****------" << endl;
        cout << "Enter the truck Driver Name: ";
        cin >> data.tnm;
        cout << "Enter the truck tires: ";
        cin >> data.tt;
        cout << "Enter the truck seat: ";
        cin >> data.ts;
        cout << "Enter the truck front Light: ";
        cin >> data.tfl;
        cout << "Enter the truck back Light: ";
        cin >> data.tbl;
    }

    void DisplayTruckData() const {
        cout << "----------------************YOUR INFORMATION***********--------------" << endl;
        cout << "Your truck Name: " << data.tnm << endl;
        cout << "Your truck tires: " << data.tt << endl;
        cout << "Your truck seats: " << data.ts << endl;
        cout << "Your truck front light: " << data.tfl << endl;
        cout << "Your truck back light: " << data.tbl << endl;
    }

    friend void EnterTruck(Trucks &);
    friend void ShowTrucks();
};

void EnterTruck(Trucks &truck) {
    ofstream outFile("cardata.dat", ios::binary | ios::app);

    int choice;
    cout << "How many Truck's record do you want to enter: ";
    cin >> choice;

    for (int i = 0; i < choice; i++) {
        truck.EnterTruckData();
        outFile.write(reinterpret_cast<char*>(&truck), sizeof(truck));
    }

    outFile.close();
}

void ShowTrucks() {
    ifstream inFile("cardata.dat", ios::binary);

    Trucks truck;
    while (inFile.read(reinterpret_cast<char*>(&truck), sizeof(truck))) {
        truck.DisplayTruckData();
        getch();
    }

    getch();
    cout << endl << "NO MORE RECORDS !!!" << endl;

    inFile.close();
}

int main() {
    Trucks truckObj;
    EnterTruck(truckObj);
    ShowTrucks();
    return 0;
}

