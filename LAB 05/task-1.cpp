#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
	Node(int val) {
		data = val;
		next = nullptr;
	}
};

class ListNode{
	Node *head;
	Node *tail;
	public:
		ListNode(){
			head = nullptr;
			tail = nullptr;
		}
		
		insertAtEnd(int val){
			Node *newNode = new Node(val);
			
			if(head == nullptr){
				head = newNode;
				tail = newNode;
			}else{
				tail->next = newNode;
				newNode->next = nullptr;
				tail = newNode;
			}	
		}
		
		void displayReverse(Node* ptr){
		    if(ptr == nullptr) return;
		    displayReverse(ptr->next);
		    cout<<ptr->data<<" -> ";
		}
		
		Node* getHead(){
			return head;
		}
};

int main(){
	ListNode n;
	n.insertAtEnd(5);
	n.insertAtEnd(6);
	n.insertAtEnd(2);	
	n.displayReverse(n.getHead());
}