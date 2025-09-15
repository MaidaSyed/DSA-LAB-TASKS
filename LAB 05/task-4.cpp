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
		
		bool search(Node *ptr, int target){
			if(ptr == nullptr) return false;
			
			return (ptr->data == target) || search(ptr->next, target);
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
	int find = n.search(n.getHead(), 2);
	if(find == 1) cout<<"True";
	else cout<<"False";
}