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
		
		int findLength(Node *ptr, int count = 0){
			if(ptr == nullptr) return count;
			return findLength(ptr->next, count+1);
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
	cout<<"Length of Linked List: "<<n.findLength(n.getHead())<<endl;
	
	n.insertAtEnd(5);
	n.insertAtEnd(6);
	n.insertAtEnd(2);	
	cout<<"Length of Linked List: "<<n.findLength(n.getHead());
}