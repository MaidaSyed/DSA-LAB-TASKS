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
		
		bool deleteVal(int val){
			bool check = false;
			Node* ptr = head;
			Node* prev = nullptr;
			while(ptr != nullptr){
                if(ptr->data == val){
                    if(ptr==head){
                        Node* temp = head;
                        head = head->next;
					    delete temp;
                        ptr = head;
						check = true;
                    }else{
					    prev->next = ptr->next;
                        if(ptr == tail) tail = prev;
                        Node* temp = ptr;
                        ptr = prev->next;
					    delete temp;
                        ptr = head;
						check = true;
                    }
                }
                else{
                    prev = ptr;
				    ptr = ptr->next;
				}
			}
            return check;
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
    int arr[] = {2, 4, 6, 8, 1, 3, 5, 6};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<size; i++) n.insertAtHead(arr[i]);

    cout<<"Linked List before deleting: ";
    n.display();

    int count;
    cout<<"enter how many values you want to delete: ";
    cin>>count;

    for(int i=0; i<count; i++){
        int val;
        cout<<"Enter value "<<i+1<<": ";
        cin>>val;
        if(n.deleteVal(val)){
            cout<<"After deleting "<<val<<": ";
            n.display();
        }else{
            cout<<"Invalid value";
        }
        cout<<endl;
    }
}
