#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Node {
    string name;
    int score;
    Node* next;
    Node(string n, int s) {
        name = n;
        score = s;
        next = nullptr;
    }
};

void addNode(Node** head, string name, int score) {
    Node* newNode = new Node(name, score);
    newNode->next = *head;
    *head = newNode;
}

int getMax(Node* head) {
    int mx = head->score;
    for (Node* temp = head; temp != nullptr; temp = temp->next)
        if (temp->score > mx)
            mx = temp->score;
    return mx;
}

void countSort(Node** head, int exp) {
    Node* output[10000];
    int count[10] = {0};
    Node* arr[10000];
    int n = 0;

    for (Node* temp = *head; temp != nullptr; temp = temp->next)
        arr[n++] = temp;

    for (int i = 0; i < n; i++)
        count[(arr[i]->score / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i]->score / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n - 1; i++)
        output[i]->next = output[i + 1];
    output[n - 1]->next = nullptr;
    *head = output[0];
}

void radixSort(Node** head) {
    int maxVal = getMax(*head);
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countSort(head, exp);
}

int binarySearch(Node* head, string name, int score) {
    Node* arr[10000];
    int n = 0;
    for (Node* temp = head; temp != nullptr; temp = temp->next)
        arr[n++] = temp;

    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid]->name == name && arr[mid]->score == score)
            return mid;
        else if (arr[mid]->score < score)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void deleteRecord(Node** head, string name, int score) {
    Node* temp = *head, *prev = nullptr;
    while (temp != nullptr) {
        if (temp->name == name && temp->score == score) {
            if (prev == nullptr)
                *head = temp->next;
            else
                prev->next = temp->next;
            delete temp;
            cout << "Record deleted.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Record not found.\n";
}

void display(Node* head) {
    for (Node* temp = head; temp != nullptr; temp = temp->next)
        cout << temp->name << " " << temp->score << endl;
}

int main() {
    Node* head = nullptr;

    addNode(&head, "Ayan", 90);
    addNode(&head, "Zameer", 60);
    addNode(&head, "Sara", 70);
    addNode(&head, "Sohail", 30);
    addNode(&head, "Ahmed", 20);

    radixSort(&head);
    display(head);

    string name;
    int score;
    cout << "\nEnter name and score to delete: ";
    cin >> name >> score;

    int idx = binarySearch(head, name, score);
    if (idx != -1)
        deleteRecord(&head, name, score);
    else
        cout << "Record not found.\n";

    cout << "\nUpdated List:\n";
    display(head);
}
