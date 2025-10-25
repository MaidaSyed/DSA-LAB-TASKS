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
        
        void bubbleSort(){
            Node* last = nullptr;
            bool swapped;

            do{
                swapped = false;
                Node* ptr = head;

                while(ptr->next != last){
                    if(ptr->data > ptr->next->data){
                        int temp = ptr->data;
                        ptr->data = ptr->next->data;
                        ptr->next->data = temp;
                        swapped = true;
                    }
                    ptr = ptr->next;
                }
                last = ptr;
            }while(swapped);
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

	cout << "Before sorting:\n";
    n.display();

    n.bubbleSort();

    cout << "\nAfter sorting:\n";
    n.display();

}