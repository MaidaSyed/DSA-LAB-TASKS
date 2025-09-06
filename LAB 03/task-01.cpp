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
		
		void insertAtEnd(int val){
			Node* newNode = new Node(val);
			if(tail == nullptr){
				head = newNode;
				tail = newNode;
			}else{
				tail->next = newNode;
				newNode->next = nullptr;
				tail = newNode;
			}
		}
		
		void insertAtPos(int val, int pos){
            if(pos == 0){
                insertAtHead(val);
                return;
            }
			int count = 0;
			Node *ptr = head;
			while(ptr != nullptr && count < pos-1){
				ptr = ptr->next;
				count++;
			}
            if(ptr == nullptr){
                cout<<"Invalid pos"<<endl;
                return;
            }
			Node* newNode = new Node(val);
			newNode->next = ptr->next;
			ptr->next = newNode;
		}
		
		void deleteVal(int val){
			Node* ptr = head;
			Node* prev = nullptr;
			while(ptr != nullptr){
                if(ptr->data == val){
                    if(ptr==head){
                        Node* temp = head;
                        head = head->next;
					    delete temp;
                        ptr = head;
                    }else{
					    prev->next = ptr->next;
                        if(ptr == tail) tail = prev;
                        Node* temp = ptr;
                        ptr = prev->next;
					    delete temp;
                    }
                }
                else{
                    prev = ptr;
				    ptr = ptr->next;
				}
			}
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
    int arr[] = {3, 1, 2, 5, 8};
    cout<<"Displayin Array: ";
    for(int i=0; i<5; i++) {
        cout<<arr[i]<<" ";
        //inserting in linked list;
        n.insertAtEnd(arr[i]);
    }
    cout<<endl;
    n.insertAtEnd(9);
    n.insertAtPos(11, 3);
    n.insertAtHead(4);
    n.deleteVal(1);
    n.deleteVal(2);
    n.deleteVal(5);

    cout<<"Printing linked List after changes: ";
    n.display();
}
