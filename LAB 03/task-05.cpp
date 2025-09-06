#include <iostream>
using namespace std;

struct Node{
	char data;
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

        NodeList nodeCopy(){
            NodeList cpy;
            Node *temp = head;
            while(temp != nullptr){
                cpy.insertAtEnd(temp->data);
                temp = temp->next;
            }
            return cpy;
        }

        void reverseList(){
            Node* prev = NULL;
            Node* curr = head;
            Node* next = NULL;

            tail = head;

            while(curr != NULL){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            head = prev;
        }

        bool isPalindrome(){
            NodeList cpy = nodeCopy();
            cpy.reverseList();

            Node *p1 = head;
            Node *p2 = cpy.head;
            while(p1 != nullptr && p2 != nullptr){
                if(p1->data != p2->data) return false;
                p1 = p1->next;
                p2 = p2->next;
            }
            return true;
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
    NodeList list1;
    int arr1[] = {1, 0, 2, 1};
    for (int x : arr1) list1.insertAtEnd(x + '0'); // store as char

    cout << "List 1: ";
    list1.display();
    cout << (list1.isPalindrome() ? "Linked List is a Palindrome\n"
                                  : "Linked List is NOT a Palindrome\n");

    NodeList list2;
    string word = "BORROWORROB";
    for (char c : word) list2.insertAtEnd(c);

    cout << "\nList 2: ";
    list2.display();
    cout << (list2.isPalindrome() ? "Linked List is a Palindrome\n"
                                  : "Linked List is NOT a Palindrome\n");
}