#include <iostream>
using namespace std;

struct Node {
    string name;
    Node *next;
    Node(string n) : name(n), next(nullptr) {}
};

// made with name Nodelist for my ease
class NodeList{
    Node *head;
    public:
        NodeList(){
            head = nullptr;
        }

        void reserveTicket(string name){
            Node *newNode = new Node(name);

            if(head == nullptr || name < head->name){
                newNode->next = head;
                head = newNode;
                cout<<"Seat reserved"<<endl;
                return;
            }

            Node *ptr = head;
            while(ptr->next != nullptr && ptr->next->name < name) ptr = ptr->next;

            if(ptr->next != nullptr && ptr->next->name == name){
                cout<<"Ticket reserved already"<<endl;
                delete newNode;
                return;
            }

            newNode->next = ptr->next;
            ptr->next = newNode;
            cout<<"Seat reserved"<<endl;
        }

        void cancelTicket(string name) {
            if(head == nullptr){
                cout<<"Epmty"<<endl;
                return;
            }

            if(head->name == name){
                Node *temp = head;
                head = head->next;
                delete temp;
                cout<<"Reservation cancelled"<<endl;
                return;
            }

            Node *ptr = head;
            while(ptr->next != nullptr){
                if(ptr->next->name == name){
                    Node *temp = ptr->next;
                    ptr->next = temp->next;
                    delete temp;
                    cout<<"Reservation cancelled"<<endl;
                    return;
                }
                ptr = ptr->next;
            }
            cout<<"No reservation exist"<<endl;
        }

        void checkTicket(string name){
            Node *ptr = head;
            while(ptr != nullptr){
                if(ptr->name == name){
                    cout<<name<<" has reservation"<<endl;
                    return;
                }
                ptr = ptr->next;
            }
            cout<<name<<" does not have reservation"<<endl;
        }

        void display(){
            Node *ptr = head;
            cout<<"Passenger List:"<<endl;
            while(ptr != nullptr){
                cout<<ptr->name<<" -> ";
                ptr = ptr->next;
            }
            cout<<"NULL"<<endl;
        }
};


int main(){
    NodeList n;
    int choice;
    string name;

    cout<<"\n--- Airline Ticket Reservation ---\n";
    cout<<"1. Reserve a Ticket"<<endl;
    cout<<"2. Cancel a Reservation"<<endl;
    cout<<"3. Check a Reservation"<<endl;
    cout<<"4. Display Passengers"<<endl;
    cout<<"5. Exit"<<endl;

    do{
        cout<<"Enter Choice: ";
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"Enter name: ";
            cin>>name;
            n.reserveTicket(name);
            break;
        case 2:
            cout<<"Enter name: ";
            cin>>name;
            n.cancelTicket(name);
            break;
        case 3:
            cout<<"Enter name: ";
            cin>>name;
            n.checkTicket(name);
            break;
        case 4:
            n.display();
            break;
        case 5:
            cout<<"Exiting.. ";
            break;
        
        default:
            cout<<"Invalid choice";
        }
    }while (choice != 5);
    
}