#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
    Node* prev;
	Node(int val){
		data = val;
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
		
		void insertAtHead(int val){
			Node *newNode = new Node(val);
			if(head == nullptr){
				head = newNode;
				tail = newNode;
			}else{
				newNode->next = head;
                head->prev = newNode;
				head = newNode;
                head->prev = nullptr;
			}
		}
		
		void insertAtEnd(int val){
			Node* newNode = new Node(val);
			if(tail == nullptr){
				head = newNode;
				tail = newNode;
			}else{
				tail->next = newNode;
				newNode->next = nullptr;
                newNode->prev = tail;
				tail = newNode;
			}
		}

        static NodeList concatenate(NodeList &n1, NodeList &n2){
            NodeList n;

            if (n1.head == nullptr) return n2;
            if (n2.head == nullptr) return n1;

            n1.tail->next = n2.head;
            n2.head->prev = n1.tail;

            n.head = n1.head;
            n.tail = n2.tail;
            return n;
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
    NodeList n1;
    int arr1[] = {3, 1, 2, 5, 8};
    for(int x : arr1)  n1.insertAtEnd(x);
    cout<<"Linked List 1: ";
    n1.display();

    NodeList n2;
    int arr2[] = {2, 4, 6, 8, 1, 3, 5};
    for(int x : arr2) n2.insertAtEnd(x);
    cout<<endl<<"Linked List 2: ";
    n2.display();

    NodeList final = NodeList::concatenate(n1, n2);
    cout<<endl<<"Concatenated Linked List: ";
    final.display();
}
