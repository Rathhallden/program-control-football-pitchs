#include <iostream>
#include <string.h>
#include <iomanip>
#include <conio.h>
using namespace std;
	class pitch{
		protected: 
			char t1[20],t2[20];
			int hour;
		public:
			void input(){
				cout<<"===========input team's name========"<<endl;
				cout<<"team1 name: "; cin.getline(t1,20);
				cout<<"team2 name: "; cin.getline(t2,20);
				cout<<"how many hours : "; cin>>hour;
			//	cout<<"how many water bet: "; cin>>bet;
			}
			char *gett1(){
				return t1;
			}
			char *gett2(){
				return t2;
			}
	//		void output(); //output 
	};
	class team1: public pitch{
		protected:
			int water,pocari;
		public: 
			void input1(){
				cout<<"===========team1========="<<endl;
				cout<<"how many water out : "; cin>>water;
				cout<<"how many pocariswat: "; cin>>pocari;
		//	void output1();
	}
	};
	class team2: public team1{
		protected:
			int water1,pocari1;
		public: 
			void input2(){
					cout<<"===========team2========="<<endl;
			 cout<<"how many water out : "; cin>>water1; 
			 cout<<"how many pocariswat : "; cin>>pocari1;
		}
	};
	class output: public team2{
		protected: 
			char name[20];
			int bet,w,w1,r=0,r1=0,l=0,l1=0;
			long total;
		public: 
			void input3(){
					cout<<"=================find winner============="<<endl;
				cin.ignore();
				cout<<"which team winner(team1 or team2): "; cin.getline(name,20);
				cout<<"how many water bet : "; cin>>bet;
			}
			void condi(){
					if(strcmp(name,"team1")==0){
					w=water-bet;
					r=bet;
					l1=bet;
					w1=water1+bet;
				}
				else 	if(strcmp(name,"team2")==0){
					w1=water1-bet;
					r1=bet;
                	l=bet;
					w=water+bet;
				}
			}
			void out1(){
			  int b;
				b=hour/2;
				total=(b*40000+w*1000+pocari*2000);
				cout<<left<<setw(10)<<"hour"<<setw(10)<<b<<setw(10)<<"40000R"<<endl;
				cout<<left<<setw(10)<<"water"<<setw(10)<<water<<setw(10)<<"1000R"<<endl;
				cout<<left<<setw(10)<<"pocari"<<setw(10)<<pocari<<setw(10)<<"2000R"<<endl;
				cout<<"-------------------------"<<endl;
				cout<<left<<setw(10)<<"--> win water : "<<r<<endl;
				cout<<left<<setw(10)<<"--> lose water : "<<l<<endl;
				cout<<"-------------------------"<<endl;
				cout<<left<<"-->total ="<<total<<"R"<<endl;
				cout<<"-------------------------"<<endl;
			//	cout<<left<<setw(10)<<"total= "<<total<<endl;
			}
			void out2(){
			
				int a;
				a=hour/2;
				total=(a*40000+w1*1000+pocari1*2000);
				cout<<left<<setw(10)<<"hour"<<setw(10)<<a<<setw(10)<<"40000R"<<endl;
				cout<<left<<setw(10)<<"water"<<setw(10)<<water1<<setw(10)<<"1000R"<<endl;
				cout<<left<<setw(10)<<"pocari"<<setw(10)<<pocari1<<setw(10)<<"2000R"<<endl;
				cout<<"-------------------------"<<endl;
				cout<<left<<setw(10)<<"--> win water : "<<r1<<endl;
				cout<<left<<setw(10)<<"--> lose water : "<<l1<<endl;
				cout<<"------------------------"<<endl;
				cout<<left<<"==>total="<<total<<"R"<<endl;
					cout<<"------------------------"<<endl;
			//	total=a*40000+water*1000+pocari*2000;
				//cout<<left<<setw(10)<<hour<<setw(10)<<"1h=10$"<<setw(10)<<water1<<setw(10)<<"1=1000R"<<setw(10)<<pocari1<<endl;
			}
	};
	void header(){
		string rath(35,'-');
		cout<<rath<<endl;
		cout<<left<<setw(10)<<"item"<<setw(10)<<"qty"<<setw(10)<<"price"<<setw(10)<<endl;
		cout<<rath<<endl;
	}
	void menu(){
		cout<<"-------------welcome to our NR sport-------------"<<endl;
		cout<<"[a/A] input Team's Name"<<endl;
		cout<<"[b/B] input Item Team1"<<endl;
		cout<<"[c/C] input Item Team2"<<endl;
		cout<<"[d/D] find winner"<<endl;
		cout<<"[e/E] report team1"<<endl;
		cout<<"[f/F] report team2"<<endl;
		cout<<"[g/G] report both team"<<endl;
		cout<<"[q/Q] Exit"<<endl;
		cout<<"-------------------------------------------------"<<endl;
	}
	int main(){
		output obj;
		int v=1;
		char ch;
		A:system("cls");
		menu();
		switch(getch()){
			case 'a':case 'A': system("cls"); obj.input();cout<<"<--press any key go to back-->"; getch(); break;
			case 'b': case 'B': system("cls");	obj.input1();cout<<"<--press any key go to back-->"; getch(); break;
			case 'c': case 'C': system("cls");	obj.input2();cout<<"<--press any key go to back-->"; getch();break;
			case 'd': case 'D': system("cls");	obj.input3();	obj.condi();cout<<"<--press any key go to back-->"; getch();break;
			case 'e': case 'E':	system("cls");	cout<<"===================output team1================="<<endl; 
			 cout<<"-> team name : "<<obj.gett1()<<endl; header();obj.out1(); cout<<"<--press any key go to back-->"; getch();break;
			case 'f': case 'F':	system("cls"); cout<<"===================output team2================="<<endl;
			cout<<"-> team name : "<<obj.gett2()<<endl; header();obj.out2();cout<<"<--press any key go to back-->"; getch();break;
			case 'g': case 'G': system("cls");	cout<<"==============team1============"<<endl;
													header();obj.out1();
													cout<<"==============team2============"<<endl;
													header();obj.out2();
													cout<<"<--press any key go to back-->"; getch();break;
			case 'q': case 'Q': exit(0);break;		
			default : cout<<"!...you're wrong type"<<endl;getch();
		}
			goto A;
		return 0;
	}
