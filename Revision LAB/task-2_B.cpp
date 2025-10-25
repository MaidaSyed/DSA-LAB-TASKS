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
		
		void display(Node* head){
			Node* ptr = head;
			while(ptr != nullptr){
				cout<<ptr->data<<" -> ";
				ptr = ptr->next;
			}
			cout<<"nullptr"<<endl;
		}
        
        void join(NodeList &list2){
            Node* ptr1 = head;
            Node* ptr2 = list2.head;
            while(ptr1 != nullptr && ptr2 != nullptr){
                Node* next1 = ptr1->next;
                Node* next2 = ptr2->next;

                ptr1->next = ptr2;
                ptr2->next = next1;

                ptr1 = next1;
                ptr2 = next2;
            }
            list2.head = ptr2;
        }

        Node* getHead(){
            return head;
        }
};

int main(){
	NodeList list1, list2;

    list1.insert(1);
    list1.insert(2);
    list1.insert(3);

    list2.insert(4);
    list2.insert(5);
    list2.insert(6);
    list2.insert(7);
    list2.insert(8);

    cout << "Before merging:\n";
    cout << "List1: "; list1.display(list1.getHead());
    cout << "List2: "; list2.display(list2.getHead());

    list1.join(list2);

    cout << "\nAfter merging:\n";
    cout << "List1: "; list1.display(list1.getHead());
    cout << "List2: "; list2.display(list2.getHead());


}