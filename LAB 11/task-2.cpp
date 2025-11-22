#include <iostream>
using namespace std;

struct Node{
    string key;
    string val;
    Node* next;
    Node(string k, string v){
        val = v;
        key = k;
        next = nullptr;
    }
};

class HashTable{
    static const int size = 100;
    Node* table[size];

    int hashFunc(string s){
        int sum = 0;
        for(char c : s) sum += int(c);
        return sum % size;
    }

    public:
    HashTable(){
        for(int i=0; i<size; i++) table[i] = nullptr;
    }

    void insert(string key, string val){
        int index = hashFunc(key);
        Node* newN = new Node(key, val);

        newN->next = table[index];
        table[index] = newN;
    }

    void wordSearch(string s){
        for(int i=0; i<size; i++){
            Node* temp = table[i];
            while(temp != nullptr){
                if(temp->val == s) {
                    cout<<s<<" is found"<<endl;
                    return;
                }
                temp = temp->next;
            } 
        }
        cout<<s<<" is not found"<<endl;
    }

    void deleteWord(string key, string val){
        int index = hashFunc(key);
        Node* prev = nullptr;
        Node* temp = table[index];

        while(temp != nullptr){
            if(temp->val == val){
                prev->next = temp->next;
                cout<<val<<" is deleted"<<endl;
                return;
            }
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        cout<<"value doesn't exist"<<endl;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Bucket " << i << ": ";
            Node* temp = table[i];
            while (temp != NULL) {
                cout << "[" << temp->key << " : " << temp->val << "] -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main(){
    HashTable myhash;

    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.insert("A", "zzzzz");

    myhash.display();

    myhash.wordSearch("aaaaa");   
    myhash.wordSearch("FASTNU");  

    myhash.deleteWord("A", "aaaaa"); 
    myhash.display();  
}