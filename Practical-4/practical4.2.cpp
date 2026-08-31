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
    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Patient deleted." << endl;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr &&
               temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Patient not found!" << endl;
            return;
        }

        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;
        delete deleteNode;

        cout << "Patient deleted." << endl;
    }

    void displayForward() {
        Node* temp = head;

        if (temp == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Front to Back: ";

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void displayReverse(Node* temp) {
        if (temp == nullptr)
            return;

        displayReverse(temp->next);
        cout << temp->data << " ";
    }

    void reversePrint() {
        if (head == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Back to Front: ";
        displayReverse(head);
        cout << endl;
    }
};

int main() {
    Queue q;

    int choice, value, position;

    while (true) {
        cout << "1. Insert at Front\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete by Value\n";
        cout << "5. Display Front to Back\n";
        cout << "6. Display Back to Front\n";
        cout << "7. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter patient token: ";
            cin >> value;
            q.insertFront(value);
            q.displayForward();
            break;

        case 2:
            cout << "Enter patient token: ";
            cin >> value;
            q.insertEnd(value);
            q.displayForward();
            break;

        case 3:
            cout << "Enter patient token: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> position;

            q.insertAtPosition(value, position);
            q.displayForward();
            break;

        case 4:
            cout << "Enter token to delete: ";
            cin >> value;

            q.deleteByValue(value);
            q.displayForward();
            break;

        case 5:
            q.displayForward();
            break;

        case 6:
            q.reversePrint();
            break;

        case 7:
            cout << "Program ended." << endl;
            return 0;

        default:
            cout << "Invalid choice!" << endl;
        }
    }
}
