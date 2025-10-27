
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Combatant {
public:
    string name;
    int health;
    int attack;

    Combatant(string n = "", int h = 0, int a = 0)
        : name(n), health(h), attack(a) {}
};

class Node {
public:
    Combatant c;
    Node* left;
    Node* right;

    Node(Combatant combatant) {
        c = combatant;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() { root = NULL; }

    Node* insert(Node* root, Combatant c) {
        if (root == NULL)
            return new Node(c);
        if (c.name < root->c.name)
            root->left = insert(root->left, c);
        else
            root->right = insert(root->right, c);
        return root;
    }

    void insert(Combatant c) {
        root = insert(root, c);
    }

    Node* findMin(Node* node) {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    Node* remove(Node* root, string name) {
        if (root == NULL) return root;

        if (name < root->c.name)
            root->left = remove(root->left, name);
        else if (name > root->c.name)
            root->right = remove(root->right, name);
        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = findMin(root->right);
            root->c = temp->c;
            root->right = remove(root->right, temp->c.name);
        }
        return root;
    }

    void remove(string name) {
        root = remove(root, name);
    }

    bool isEmpty() {
        return (root == nullptr);
    }

    Node* getFrontline() {
        Node* ptr = root;
        while(ptr->left != nullptr) ptr = ptr->left;
        return ptr;
    }

    void display(Node* node) {
       cout<<"Name: "<<node->c.name<<endl;
       cout<<"Health: "<<node->c.health<<endl;
       cout<<"Attack: "<<node->c.attack<<endl;
    }
    
    void inOrder(Node* n){
        if(n == nullptr) return;
        inOrder(n->left);
        display(n);
        inOrder(n->right);
	}
		
    void displayTeam() {
        Node* ptr = root;
        inOrder(ptr);
    }
};

class Battle_quesuest {
private:
    BST playerTeam;
    BST enemyTeam;

public:
    Battle_quesuest() {
        srand(time(0));
//        initializeTeams();
    }

    void initialize_teams() {
        
    }

    void displayTeams() {
       
       
    }

    void attack(Node* attacker, Node* defender, BST& defenderTeam) {
       
    }

    void start_battle() {
        
        
    }
};


int main() {
//    BattleQuest game;
//    game.start_battle(); 
    return 0;
}