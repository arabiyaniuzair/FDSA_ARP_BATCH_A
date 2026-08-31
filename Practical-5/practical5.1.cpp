#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int value){
        data=value;
        next=nullptr;
        prev=nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertFront(int value) {
        Node* newNode = new Node(value);

        if (head != nullptr) {
            newNode->next = head;
            head->prev = newNode;
        }

        head = newNode;
    }

    void deleteFront(){
        if (head==nullptr)
            return;

        Node* temp=head;
        head=head->next;
        if (head != nullptr)
            head->prev = nullptr;

        delete temp;
    }

    void display(){
        Node* current=head;

        while(current!=nullptr){
            cout<<current->data<<" ";
            current=current->next;
        }

        cout<<endl;
    }
};

int main() {
    DoublyLinkedList list;

    list.insertFront(30);
    list.insertFront(20);
    list.insertFront(10);

    cout << "Before deletion: ";
    list.display();

    list.deleteFront();

    cout << "After deletion: ";
    list.display();

    return 0;
}
