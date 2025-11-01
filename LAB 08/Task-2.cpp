#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Combatant
{
public:
    string name;
    int health;
    int attack;

    Combatant(string n = "", int h = 0, int a = 0)
        : name(n), health(h), attack(a) {}
};

class Node
{
public:
    Combatant c;
    Node *left;
    Node *right;

    Node(Combatant combatant)
    {
        c = combatant;
        left = right = NULL;
    }
};

class BST
{
public:
    Node *root;

    BST() { root = NULL; }

    Node *insert(Node *root, Combatant c)
    {
        if (root == NULL)
            return new Node(c);
        if (c.name < root->c.name)
            root->left = insert(root->left, c);
        else
            root->right = insert(root->right, c);
        return root;
    }

    void insert(Combatant c)
    {
        root = insert(root, c);
    }

    Node *findMin(Node *node)
    {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    Node *remove(Node *root, string name)
    {
        if (root == NULL)
            return root;

        if (name < root->c.name)
            root->left = remove(root->left, name);
        else if (name > root->c.name)
            root->right = remove(root->right, name);
        else
        {
            if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            Node *temp = findMin(root->right);
            root->c = temp->c;
            root->right = remove(root->right, temp->c.name);
        }
        return root;
    }

    void remove(string name)
    {
        root = remove(root, name);
    }

    bool isEmpty()
    {
        return (root == nullptr);
    }

    Node *getFrontline()
    {
        Node *ptr = root;
        while (ptr->left != nullptr)
            ptr = ptr->left;
        return ptr;
    }

    void display(Node *node)
    {
        cout << "Name: " << node->c.name << " , Health: " << node->c.health << " , Attack: " << node->c.attack << endl;
    }

    void inOrder(Node *n)
    {
        if (n == nullptr)
            return;
        inOrder(n->left);
        display(n);
        inOrder(n->right);
    }

    void displayTeam()
    {
        Node *ptr = root;
        inOrder(ptr);
    }
};

class BattleQuest
{
private:
    BST playerTeam;
    BST enemyTeam;

public:
    BattleQuest()
    {
        srand(time(0));
        //        initializeTeams();
    }

    void initialize_teams()
    {
        Combatant heroes[5] = {
            Combatant("Maida", 40, 9),
            Combatant("Aila", 35, 10),
            Combatant("Kiran", 45, 8),
            Combatant("Neama", 38, 11),
            Combatant("Batool", 42, 7)};

        // Enemy team
        Combatant enemies[5] = {
            Combatant("Rafay", 43, 9),
            Combatant("Usman", 39, 10),
            Combatant("Zayan", 37, 8),
            Combatant("Taimoor", 41, 9),
            Combatant("Hammad", 40, 10)};

        for (int i = 0; i < 5; i++)
        {
            playerTeam.insert(heroes[i]);
            enemyTeam.insert(enemies[i]);
        }
        cout << "Teams initialize succesfully" << endl;
    }

    void displayTeams()
    {
        cout << "Displaying Hero Team:" << endl;
        playerTeam.displayTeam();
        cout << "Displaying Enemy Team:" << endl;
        enemyTeam.displayTeam();
    }

    void attack(Node *attacker, Node *defender, BST &defenderTeam)
    {
        if (!attacker || !defender)
            return;

        int damage = attacker->c.attack + rand() % 5; // base attack + random 0-4
        cout << attacker->c.name << " attacks " << defender->c.name
             << " for " << damage << " damage!" << endl;

        defender->c.health -= damage;

        if (defender->c.health <= 0)
        {
            cout << defender->c.name << " has been defeated!\n";
            defenderTeam.remove(defender->c.name); // remove from BST
        }
        else
        {
            cout << defender->c.name << " now has " << defender->c.health << " HP remaining.\n";
        }
    }

    Node *getFrontLine()
    {
        Node *heroTeam = playerTeam.getFrontline();
        Node *enemyT = enemyTeam.getFrontline();

        // less health attack first
        return (heroTeam->c.health < enemyT->c.health) ? heroTeam : enemyT;
    }

    void start_battle()
    {
        initialize_teams();
        int round = 1;
        bool playerTurn = true;

        // At start, player’s frontline attacks first
        Node *heroFront = playerTeam.getFrontline();
        Node *enemyFront = enemyTeam.getFrontline();

        if (!heroFront || !enemyFront)
            return;

        cout << "\n===== Battle Start =====\n";

        cout << "\nInitial Hero Team:\n";
        playerTeam.displayTeam();
        cout << "\nInitial Enemy Team:\n";
        enemyTeam.displayTeam();

        cout << "\nHero " << heroFront->c.name << " attacks first!\n";

        // Player attacks first
        attack(heroFront, enemyFront, enemyTeam);
        playerTurn = false; // next turn is enemy

        // Battle loop
        while (!playerTeam.isEmpty() && !enemyTeam.isEmpty())
        {
            round++;
            cout << "\n===== Round " << round << " =====\n";

            // // Display current teams
            // cout << "\nHero Team:\n";
            // playerTeam.displayTeam();
            // cout << "\nEnemy Team:\n";
            // enemyTeam.displayTeam();

            // Update frontline nodes
            heroFront = playerTeam.getFrontline();
            enemyFront = enemyTeam.getFrontline();

            if (playerTurn)
            {
                cout << "\nHero " << heroFront->c.name << " attacks!\n";
                attack(heroFront, enemyFront, enemyTeam);
            }
            else
            {
                cout << "\nEnemy " << enemyFront->c.name << " attacks!\n";
                attack(enemyFront, heroFront, playerTeam);
            }

            // Alternate turns
            playerTurn = !playerTurn;
        }

        // Display final result
        cout << "\n===== Battle Over =====\n";
        if (playerTeam.isEmpty())
            cout << "Enemies win the battle!\n";
        else
            cout << "Heroes win the battle!\n";
    }
};

int main()
{
    BattleQuest game;
    game.start_battle();
    return 0;
}