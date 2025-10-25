#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int d){
		data = d;
		next = nullptr;
	}
};

class NodeList{
	Node* head;
	Node* tail;
	public:
		NodeList(){
			head = nullptr;
			tail = nullptr;
		}
		
		void insert(int val){
			Node* newN = new Node(val);
			if(head == nullptr){
				head = newN;
				tail = newN;
				newN->next = nullptr;
			}else{
				tail->next = newN;
				newN->next = nullptr;
				tail = newN;
			}
		}
		
		void display(){
			Node* ptr = head;
			while(ptr != nullptr){
				cout<<ptr->data<<" -> ";
				ptr = ptr->next;
			}
			cout<<"nullptr"<<endl;
		}
		
		void deleteFrontNode(){
			Node* temp = head;
			head = head->next;
			delete temp;
			cout<<"Front node deleted"<<endl;
		}
		
		void deleteLastNode(){
			Node* ptr = head;
			
			while(ptr->next->next != nullptr) ptr = ptr->next;
			Node* temp = ptr->next;
			ptr->next = nullptr;
			
			delete temp;
			cout<<"Last node deleted"<<endl;
		}
		
		void deleteAtAnyPos(int pos){
			Node* prev = nullptr;
			Node* ptr = head;
			for(int i=0; i<pos; i++) {
				prev = ptr;
				ptr = ptr->next;
			}
			prev->next = ptr->next;
			delete ptr;	
			cout<<"Required node deleted"<<endl;
		}
			
};

int main(){
	NodeList n;
	n.insert(5);
	n.insert(8);
	n.insert(2);
	n.insert(0);
	n.insert(9);
	n.insert(4);
	n.display();
	
	n.deleteFrontNode();
	n.display();
	
	n.deleteLastNode();
	n.display();
	
	n.deleteAtAnyPos(2);
	n.display();
}