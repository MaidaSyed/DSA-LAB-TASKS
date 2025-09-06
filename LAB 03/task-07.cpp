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
                newNode->next = head;
			}else{
				newNode->next = head;
				head = newNode;
                tail->next = head;
			}
		}
		
		void insertAtEnd(int val){
			Node* newNode = new Node(val);
			if(tail == nullptr){
				head = newNode;
				tail = newNode;
                newNode->next = head;
			}else{
				tail->next = newNode;
				newNode->next = head;
				tail = newNode;
			}
		}
		
		void insertAtPos(int val, int pos){
            if(pos < 0) return;
            if(pos == 0){
                insertAtHead(val);
                return;
            }
			int count = 0;
			Node *ptr = head;
			while(ptr->next != head && count < pos-1){
				ptr = ptr->next;
				count++;
			}

            if(count != pos-1){
                cout<<"Invalid pos"<<endl;
                return;
            }
			Node* newNode = new Node(val);
			newNode->next = ptr->next;
			ptr->next = newNode;
		}
		
		void deleteVal(int val){
            if(head == nullptr) return;
			Node* ptr = head;
			Node* prev = nullptr;
			do{
                if(ptr->data == val){
                    if(ptr==head){
                        if(head == tail){
                            delete head;
                            head = nullptr;
                            tail = nullptr;
                            return;
                        }
                        head = head->next;
                        tail->next = head;
					    delete ptr;
                        return;
                    }else{
					    prev->next = ptr->next;
                        if(ptr == tail) tail = prev;                        
					    delete ptr;
                        return;
                    }
                }
                else{
                    prev = ptr;
				    ptr = ptr->next;
				}
			}while(ptr != head);
		}
		
		void display(){
			Node* temp = head;
            if(head == nullptr) {
                cout<<"Empty List"<<endl;
                return;
            }

			do{
				cout<<temp->data<<" -> ";
				temp = temp->next;
			}while(temp != head);
		}
};

int main(){
    NodeList n;
    int arr[] = {3, 1, 2, 5, 8};
    for(int i=0; i<5; i++) {
        n.insertAtEnd(arr[i]);
    }
    cout<<"Displaying Linked List before changes: ";
    n.display();
    n.insertAtEnd(9);
    n.insertAtPos(11, 3);
    n.insertAtHead(4);
    n.deleteVal(1);
    n.deleteVal(2);
    n.deleteVal(5);

    cout<<endl<<"Displaying Linked List after changes: ";
    n.display();
}
