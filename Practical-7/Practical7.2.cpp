#include <iostream>
using namespace std;

struct Node{
    int patient;
    Node* next;
};

int main(){
Node* front=nullptr;
Node* rear=nullptr;
int operations;
cout<<"Enter number of operations: ";
cin>>operations;
while(operations--){
    int choice;
    cout<<"Enter your choice: ";
    cin>>choice;
    if(choice==1){
        int patient;
        cout<<"Enter the patient: ";
        cin>>patient;
        Node* newnode=new Node();
        newnode->patient=patient;
        newnode->next=nullptr;
        if(rear==nullptr){
            front=rear=newnode;
        }else{
        rear->next=newnode;
        rear=newnode;
        }
        cout<<"Patient is added"<<endl;
    }
    else if(choice==2){
        if(front==nullptr){
            cout<<"No patient is available"<<endl;
        }
        else{
            Node* temp=front;
             cout<<"Patient attended: "<<front->patient<<endl;
            front = front->next;
            if(front==nullptr){
                rear=nullptr;
            }
            delete temp;
        }

    }
    else{
        cout<<"Invalid choice"<<endl;
    }

}
if(front!=nullptr){
    cout<<"Current Front Patient: "<<front->patient<<endl;
}
else{
     cout<<"Current Front Patient: Empty"<<endl;
}
return 0;
}
