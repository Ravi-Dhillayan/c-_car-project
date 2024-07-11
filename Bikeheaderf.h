#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
int total2=0;
template <class T,class S>
struct fun2{
	T*a;
	int n;
	S bnm[200],bno[200],bt[200],bs[200],bfl[200],bbl[200];
};
class bikes{
	struct fun2<int ,char> o;
	public:
		void bike(){
			 cout<<"How many Enter the Bike's Record : "<<endl;
			 cin>>o.n;
			 o.a=new int[o.n];
			 for(int i=1;i<=o.n;i++){
			 	cout<<"--------*****Enter "<<i<<"Bike Data******------"<<endl;

	cout<<"Enter the "<<i<<" Bike Driver name : "<<endl;
	cin>>o.bnm[i];
	cout<<"Enter the "<<i<<" Bike Number : "<<endl;
	cin>>o.bno[i];
	cout<<"Enter the "<<i<<"Bike tires : "<<endl;
	cin>>o.bt[i];
	cout<<"Enter the "<<i<<"Bike seats : "<<endl;
	cin>>o.bs[i];
	cout<<"Enter the "<<i<<"Bike front Light : "<<endl;
	cin>>o.bfl[i];
	cout<<"Enter the "<<i<<"Bike back Light : "<<endl;
	cin>>o.bbl[i];
	
			 }
		}
		void bikedisplay(){
			cout << "----------------************YOUR INFORMATION***********--------------" << endl;
        for (int i = 0; i < o.n; i++) {
            cout << "-------------*****Your " << i + 1 << " Bike Data*****------" << endl;
            cout << "Your  Bike Driver Name : " << o.bnm[i] << endl;
            cout<<"Bike Number : "<<o.bno[i]<<endl;
            cout << "Your Bike tires : " << o.bt[i] << endl;
            cout << "Your Bike  seats " << o.bs[i] << endl;
            cout << "Your Bike front light : " << o.bfl[i] << endl;
            cout << "Your Bike back light : " << o.bbl[i] << endl;
        }
    }
		friend void bikeenter( bikes &ao);
		friend void bikeshow();
};
bikes bo;
void bikeenter(){
		ofstream ofa;
	ofa.write("cardata.dat",ios::app);
  if(total2==0){
  	
	bo.bike();
	ofa.write((char*)&bo,sizeof(bo));
	ofa.close();
  }
  else{
  	bo.bike();
  ofa.write((char*)&bo,sizeof(bo));
  	ofa.close();
  }
}
void bikeshow(){
		ifstream ofb;
	ofb.open("cardata.dat",ios::in | ios::app | ios::out);
	while(ofb.read((char*)&bo,sizeof(bo))){
		bo.bikedisplay();
		
	}
	getch();
	cout<<endl<<"NO MORE RECORDS !!!!"<<endl;
	ofb.close();
	

}




