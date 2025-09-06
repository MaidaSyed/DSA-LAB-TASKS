#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int val){
		data = val;
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
		
		void insertAtHead(int val){
			Node *newNode = new Node(val);
			if(head == nullptr){
				head = newNode;
				tail = newNode;
			}else{
				newNode->next = head;
				head = newNode;
			}
		}
		
		void rotate(){
            if(head == nullptr || head->next == nullptr) return;
			Node* temp = head;
            head = head->next;
            tail->next = temp;
            tail = temp;
            tail->next = nullptr;
		}
		
		void display(){
			Node* temp = head;
			while(temp != nullptr){
				cout<<temp->data<<" -> ";
				temp = temp->next;
			}
            cout<<"NULL"<<endl;
		}
};

int main(){
    NodeList n;
    int arr[] = {2, 4, 6, 8, 1, 3, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<size; i++) n.insertAtHead(arr[i]);

    cout<<"Linked List: ";
    n.display();

    int count;
    cout<<endl<<"Enter how many nodes to rotate: ";
    cin>>count;

    for(int i=0; i<count; i++) n.rotate();

    cout<<"After rotating: ";
    n.display(); 
}
