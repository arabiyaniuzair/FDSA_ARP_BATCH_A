#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
    Node* head;

public:
    Queue() {
        head = nullptr;
    }

    void insertFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
    }

    void insertAtPosition(int value, int position) {
        if (position == 1) {
            insertFront(value);
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1 && temp != nullptr; i++)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value, position;

    while (true) {
        cout << "\n1. Insert at Front";
        cout << "\n2. Insert at End";
        cout << "\n3. Insert at Position";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter patient token: ";
            cin >> value;
            q.insertFront(value);
            q.display();
            break;

        case 2:
            cout << "Enter patient token: ";
            cin >> value;
            q.insertEnd(value);
            q.display();
            break;

        case 3:
            cout << "Enter patient token: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> position;

            q.insertAtPosition(value, position);
            q.display();
            break;

        case 4:
            q.display();
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice!" << endl;
        }
    }
}
