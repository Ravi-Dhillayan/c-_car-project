#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<conio.h>
 #include"truckhaderfile.h";
using namespace std;
int total1=0,car=1;
class vicale{
	struct fun{
		char nm[20],dnm[20],t[10],s[12],fl[12],bl[12];
	};
	struct fun o;
	public: 
		void car(){
//		
               cout<<"Enter the CAR driver Name : "<<endl;
               cin>>o.dnm;
				cout<<"Enter the  CAR Name : "<<endl;
				cin>>o.nm;
			cout<<"Enter the your car tires : "<<endl;
			cin>>o.t;
			cout<<"Enter the YOur car seat : "<<endl;
			cin>>o.s;
			cout<<"Enter the your car front Light : "<<endl;
			cin>>o.fl;
			cout<<"Enter the your car back Light : "<<endl;
			cin>>o.bl;
//		}
		}
		void display(){
			cout<<"---------------*********Your Information*************--------"<<endl;
			cout<<"Car Driver Name : "<<o.dnm<<endl;
			cout<<"Your car tires : "<<o.t;
			cout<<endl<<"Your car seat : "<<o.s<<endl;
			cout<<"your ca front Light : "<<o.fl<<endl;
			cout<<"Your car back Light : "<<o.bl<<endl;
		}
		public:
		template <class T,class S>
		void bus(){
			T *a,n;
			S nm,bt,bs,fl,bl;
			cout<<"How many Enter the buses record "<<endl;
			cin>>n;
			a=new T[n];
			for(int i=1;i<=n;i++){
//		/		cout<<a[i];
//               cin>>a[i];
				cout<<"Enter the "<<i<<"  Bus Name : "<<endl;
				cin>>nm;
				cout<<"Enter the "<<i<< " bus tires "<<endl;
				cin>>bt;
				
				cout<<"Enter the "<<i<<" bus seat : "<<endl;
				cin>>bs;
				cout<<"Enter the "<<i<<" bus  front Light "<<endl;
				cin>>fl;
				cout<<"Enter the "<<i<<"  bus Back Light "<<endl;
				cin>>bl;
				cout<<"your "<<i <<"  bus Name "<<nm<<endl;
				cout<<" Your "<<i<<"  Bus tires "<<bt<<endl;
				cout<<"Your "<<i<<" Bus seats "<<bs<<endl;
				cout<<"Your "<<i<<" Bus front Light "<<fl<<endl;
				cout<<"Your "<<i<<" Bus  Back Light "<<bl<<endl;
			}
		}
		
		void carenter();
		void showcar();
		void update();
		void delet();
		void search();
};
vicale vo;
void vicale::carenter(){
	ofstream ofa;
	ofa.open("cardata.dat",ios::in |ios::app );
	 int choice;
 cout<<"\nHow many Truck's record do you want to enter  :  ";
 cin>>choice;
 if(total1==0 ){
 	total1=total1+choice;
 	for(int i=0;i<choice ;i++){
 		
 		
 		vo.car();
 		ofa.write((char*)&vo,sizeof(vo));
	 }
	 ofa.close();
 }
 else
 {
 	for(int i=total1;i<choice;i++){
 		vo.car();
 		ofa.write((char*)&vo,sizeof(vo));
	 }
	 total1=total1+choice;
	  ofa.close();
 }

}
void vicale::showcar(){
	ifstream ofb;
	ofb.open("cardata.dat",ios::in | ios::app | ios::out);
	while(ofb.read((char*)&vo,sizeof(vo))){
		vo.display();
		getch();
	}
	getch();
	cout<<endl<<"NO MORE RECORDS !!!!"<<endl;
	ofb.close();
	
}
void vicale::search()
{
		struct fun o;
	int ch;
	char drnm[20];
	char nam[20];
	cout<<"ENTER YOUR CHOICE !! "<<endl;
	cout<<"Press 1 to search by driver name : "<<endl;
	cout<<" Press 0 to search by bicale Name : "<<endl;
	cin>>ch;
	ifstream ofb;
	ofb.open("caredate.dat",ios::in | ios::app | ios::out);
	int x=0;
	if(ch==1)
	{
		cout<<"\n Enter the Driver name you wants to search : ";
		scanf("\n");
		gets(drnm);
		while(ofb.read((char*)&vo,sizeof(vo)))
		{
			//cout<<;
	if(!strcmp(o.dnm,drnm)){
				
			}			
		}
	}
}
int main(){
	Trucks truckobj;
//	EnterTruck(truckobj);
	ShowTrucks();
	
//		truckobj.truck();
// truckenter(truckobj);
//	truckobj.truckdisplay();
//	 ShowTrucks(truckobj);
     
	vicale tobj;
//	tobj.car();
//	tobj.carenter();
	tobj.showcar();
//	tobj.display();
//	vicale obj;
//	obj.carenter();
//  obj.showdata();
//	obj.car();
//	obj.display();
//	obj.bus<int,string>();
//	obj.truck<int ,string>();
}
