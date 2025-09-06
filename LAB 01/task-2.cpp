#include <iostream>
using namespace std;
#include <cstring>

class Exam{
	char *name;
	char *date;
	double *score;
	public:
		Exam(string n, string d, double s){
			name = new char[n.size()+1];
			strcpy(name, n.c_str());
			
			date = new char[d.size()+1];
			strcpy(date, d.c_str());
			
			score = new double(s);
		}
		
		void display(){
			cout<<"Name: "<<name<<endl;
			cout<<"Date:"<<date<<endl;
			cout<<"Score: "<<*score<<endl;
		}
		
		~Exam(){
			delete[] name;
			delete[] date;
			delete score;
		}
		
		//changin name to show same memory address
		void newName(string n){
			strcpy(name, n.c_str());
		}
		
};

int main(){
	Exam ex1("batool", "20-8-2024", 99.9);
	ex1.display();
	cout<<endl;
	
	Exam ex2 = ex1; // shallow copy
	cout<<"shallow copy from above"<<endl;
	ex2.display();
	cout<<endl;
	
	ex1.newName("maida");
	cout<<"after updating both affecting"<<endl;
	ex1.display();
	cout<<endl;
	ex2.display();
}