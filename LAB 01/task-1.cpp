#include <iostream>
using namespace std;

class BankAccount{
	double* balance;
	public:
		BankAccount(){
			balance = new double(0);
		}
		BankAccount(int b){
			balance = new double(b);
		}
		
		BankAccount(const BankAccount& BA){
			balance = new double(*BA.balance); // deep copy
		}
		
		double getBalance(){
			 return *balance;
		}
		
		void deduct(double amount) {
			*balance -= amount;
		}
		
		~BankAccount(){
			delete balance;
		}
};


int main() {
    BankAccount account1;
    cout<<"accout-1 balance from default constructor: "<<account1.getBalance()<<endl;
    
    BankAccount account2(1000);
    cout<<"accout-2 balance from paramaterized constructor: "<<account2.getBalance()<<endl;
    
    BankAccount account3 = account2;
	cout<<"accout-3 balance from copy constructor: "<<account3.getBalance()<<endl;
    account3.deduct(200);
    cout<<"accout-3 balance after withdraw: "<<account3.getBalance()<<endl;
    
    cout<<"accout-2 balance no affect from account-3: "<<account2.getBalance()<<endl;
}