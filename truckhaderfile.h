//#include<iostream>
//#include<fstream>
//#include<conio.h>
//using namespace std;
//
//template <class T, class S>
//struct fun1 {
//    T *a;
//    int n;
//    S tnm[20], tt[20], ts[20], tfl[20], tbl[20];
//};
//
//class trucks {
//    struct fun1<int, char> o;
//
//public:
//    void truck() {
//        cout << "-------------*****This Enter Truck Data*****------" << endl;
//        cout << "Enter the truck Driver Name: " << endl;
//        cin >> o.tnm[o.n];
//        cout << "Enter the truck tires : " << endl;
//        cin >> o.tt[o.n];
//        cout << "Enter the truck seat : " << endl;
//        cin >> o.ts[o.n];
//        cout << "Enter the truck front Light : " << endl;
//        cin >> o.tfl[o.n];
//        cout << "Enter the truck back Light : " << endl;
//        cin >> o.tbl[o.n];
//        o.n++;
//    }
//
//    void truckdisplay() {
//        cout << "----------------************YOUR INFORMATION***********--------------" << endl;
//        for (int i = 0; i < o.n; i++) {
//            cout << "-------------*****Your " << i + 1 << " Truck Data*****------" << endl;
//            cout << "Your truck Name : " << o.tnm[i] << endl;
//            cout << "Your truck tires : " << o.tt[i] << endl;
//            cout << "Your truck seats " << o.ts[i] << endl;
//            cout << "Your truck front light : " << o.tfl[i] << endl;
//            cout << "Your truck back light : " << o.tbl[i] << endl;
//        }
//    }
//
//    friend void truckenter(trucks &o);
//    friend void truckshow(trucks &o);
//};
//
//trucks tro;
//
//void truckenter(trucks &o) {
//    ofstream ofa;
//    ofa.open("cardata.dat", ios::binary | ios::app);
//
//    int choice;
//    cout << "\n How many Truck's record do you want to enter : " << endl;
//    cin >> choice;
//
//    for (int i = 0; i < choice; i++) {
//        tro.truck();
//        ofa.write((char*)&tro, sizeof(tro));
//    }
//    ofa.close();
//}
//
//void truckshow(trucks &o) {
//    ifstream ofb;
//    ofb.open("cardata.dat", ios::binary);
//
//    while (ofb.read((char*)&tro, sizeof(tro))) {
//        tro.truckdisplay();
//    }
//
//    getch();
//    cout << endl << "NO MORE RECORDS !!!" << endl;
//    ofb.close();
//}
//
//int main() {
//    trucks truckobj;
//    truckenter(truckobj);
//    truckshow(truckobj);
//    return 0;
//}
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

struct TruckData {
    char tnm[20];
    char tt[20], ts[20], tfl[20], tbl[20];
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
    ofstream outFile("truckdata.dat", ios::binary | ios::app);

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
    ifstream inFile("truckdata.dat", ios::binary);

    Trucks truck;
    while (inFile.read(reinterpret_cast<char*>(&truck), sizeof(truck))) {
        truck.DisplayTruckData();
        getch();
    }

    getch();
    cout << endl << "NO MORE RECORDS !!!" << endl;

    inFile.close();
}

