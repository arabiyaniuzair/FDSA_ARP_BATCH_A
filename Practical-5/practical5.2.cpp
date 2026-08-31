#include <iostream>
using namespace std;

struct SNode {
    int data;
    SNode* next;

    SNode(int value) {
        data = value;
        next = nullptr;
    }
};

class SinglyCircular {
    SNode* head;

public:
    SinglyCircular() {
        head = nullptr;
    }

    void join(int value) {
        SNode* newNode = new SNode(value);

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }

        SNode* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    void leave(int value) {
        if (head == nullptr)
            return;

        SNode* current = head;
        SNode* previous = nullptr;

        do {
            if (current->data == value) {
                if (current == head && current->next == head) {
                    delete current;
                    head = nullptr;
                    return;
                }

                if (current == head) {
                    SNode* last = head;
                    while (last->next != head)
                        last = last->next;

                    head = head->next;
                    last->next = head;
                    delete current;
                    return;
                }

                previous->next = current->next;
                delete current;
                return;
            }

            previous = current;
            current = current->next;

        } while (current != head);
    }

    void display() {
        if (head == nullptr) {
            cout << "Empty\n";
            return;
        }

        SNode* temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};
struct DNode {
    int data;
    DNode* next;
    DNode* prev;

    DNode(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyCircular {
    DNode* head;

public:
    DoublyCircular() {
        head = nullptr;
    }

    void join(int value) {
        DNode* newNode = new DNode(value);

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }

        DNode* last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;
    }

    void leave(int value) {
        if (head == nullptr)
            return;

        DNode* current = head;

        do {
            if (current->data == value) {

                if (current->next == current) {
                    delete current;
                    head = nullptr;
                    return;
                }
                current->prev->next = current->next;
                current->next->prev = current->prev;

                if (current == head)
                    head = current->next;

                delete current;
                return;
            }

            current = current->next;

        } while (current != head);
    }

    void display() {
        if (head == nullptr) {
            cout << "Empty\n";
            return;
        }

        DNode* temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

int main() {

    SinglyCircular s;
    DoublyCircular d;

    int n;
    cout << "Enter number of operations: ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        char operation;
        int value;

        cout << "Enter operation (J = Join, L = Leave, D = Display): ";
        cin >> operation;

        if (operation == 'J') {
            cin >> value;
            s.join(value);
            d.join(value);
        }
        else if (operation == 'L') {
            cin >> value;
            s.leave(value);
            d.leave(value);
        }
        else if (operation == 'D') {
            cout << "Singly Circular: ";
            s.display();

            cout << "Doubly Circular: ";
            d.display();
        }
    }

    return 0;
}
