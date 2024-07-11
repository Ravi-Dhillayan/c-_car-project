#include<iostream>
#include<fstream>
#include<conio.h>

using namespace std;

int total1 = 0, car = 1;

class vicale {
public:
    struct fun {
        char nm[20], dnm[20], t[10], s[12], fl[12], bl[12];
    };
    struct fun o;

    void carInput() {
        cout << "Enter the CAR driver Name: ";
        cin >> o.dnm;
        cout << "Enter the CAR Name: ";
        cin >> o.nm;
        cout << "Enter your car tires: ";
        cin >> o.t;
        cout << "Enter Your car seat: ";
        cin >> o.s;
        cout << "Enter your car front Light: ";
        cin >> o.fl;
        cout << "Enter your car back Light: ";
        cin >> o.bl;
    }

    void displayCar() {
        cout << "---------------*********Your Information*************--------" << endl;
        cout << "Car Driver Name: " << o.dnm << endl;
        cout << "Your car tires: " << o.t << endl;
        cout << "Your car seat: " << o.s << endl;
        cout << "Your car front Light: " << o.fl << endl;
        cout << "Your car back Light: " << o.bl << endl;
    }

    template <class T, class S>
    void bus() {
        T* a;
        S nm, bt, bs, fl, bl;
        int n;
        cout << "How many Enter the buses record: ";
        cin >> n;
        a = new T[n];
        for (int i = 1; i <= n; i++) {
            cout << "Enter the " << i << " Bus Name: ";
            cin >> nm;
            cout << "Enter the " << i << " bus tires: ";
            cin >> bt;
            cout << "Enter the " << i << " bus seat: ";
            cin >> bs;
            cout << "Enter the " << i << " bus front Light: ";
            cin >> fl;
            cout << "Enter the " << i << " bus Back Light: ";
            cin >> bl;
            cout << "Your " << i << " bus Name " << nm << endl;
            cout << "Your " << i << " Bus tires " << bt << endl;
            cout << "Your " << i << " Bus seats " << bs << endl;
            cout << "Your " << i << " Bus front Light " << fl << endl;
            cout << "Your " << i << " Bus Back Light " << bl << endl;
        }
        delete[] a;
    }

    void carEnter() {
        ofstream ofa;
        ofa.open("cardata.dat", ios::in | ios::app);
        int choice;
        cout << "\nHow many Car's record do you want to enter: ";
        cin >> choice;

        if (total1 == 0) {
            total1 = choice;
            for (int i = 0; i < choice; i++) {
                carInput();
                ofa.write((char*)&o, sizeof(o));
            }
            ofa.close();
        } else {
            for (int i = total1; i < total1 + choice; i++) {
                carInput();
                ofa.write((char*)&o, sizeof(o));
            }
            total1 += choice;
            ofa.close();
        }
    }

    void showCar() {
        ifstream ofb;
        ofb.open("cardata.dat", ios::in | ios::app | ios::out);
        while (ofb.read((char*)&o, sizeof(o))) {
            displayCar();
            getch();
        }
        getch();
        cout << endl << "NO MORE RECORDS !!!!" << endl;
        ofb.close();
    }

    void search() {
        int ch;
        char drnm[20];
        cout << "ENTER YOUR CHOICE!!" << endl;
        cout << "Press 1 to search by driver name" << endl;
        cout << "Press 0 to search by vehicle Name" << endl;
        cin >> ch;

        ifstream ofb;
        ofb.open("cardata.dat", ios::in | ios::app | ios::out);
        int x = 0;

        if (ch == 1) {
            cout << "\nEnter the Driver name you want to search: ";
            cin >> drnm;
            while (ofb.read((char*)&o, sizeof(o))) {
                if (!strcmp(o.dnm, drnm)) {
                    // Display or perform actions for the matched record
                    displayCar();
                    x = 1;
                }
            }
        } else if (ch == 0) {
            // Add code for searching by vehicle Name if needed
        }

        if (x == 0) {
            cout << "Record not found!" << endl;
        }
        ofb.close();
    }
};

int main() {
    vicale tobj;
    tobj.carEnter();
    tobj.showCar();
    tobj.search();

    return 0;
}

