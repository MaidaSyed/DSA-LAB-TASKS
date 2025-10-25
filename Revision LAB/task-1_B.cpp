#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node* prev;
	Node(int d){
		data = d;
		next = nullptr;
		prev = nullptr;
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
				newN->prev = nullptr;
			}else{
				tail->next = newN;
				newN->next = nullptr;
				newN->prev = tail;
				tail = newN;
			}
		}
		
		void display(Node* Head){
			Node* ptr = Head;
			while(ptr != nullptr){
				cout<<ptr->data<<" -> ";
				ptr = ptr->next;
			}
			cout<<"nullptr"<<endl;
		}

		Node* reverse(Node* cHead){
			if(cHead == nullptr) return nullptr;

			Node* temp = cHead->next;
			cHead->next = cHead->prev;
			cHead->prev = temp;

			if(cHead->prev == nullptr) return cHead;

			return reverse(cHead->prev);
		}
		
		// Node* reverse(Node* head){
		// 	Node* temp = nullptr;
		// 	Node* curr = head;
			
		// 	while(curr != nullptr){
		// 		temp = curr->prev;
		// 		curr->prev = curr->next;
		// 		curr->next = temp;
		// 		curr = curr->prev;
		// 	}
		
		// 	if(temp != nullptr) head = temp->prev;
			
		// 	return head;
		// }
		
		Node* getHead() {
			return head;
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
	n.display(n.getHead());
	
	Node* head = n.reverse(n.getHead());
	
	n.display(head);
}