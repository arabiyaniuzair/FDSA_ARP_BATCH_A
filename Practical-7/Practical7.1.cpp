#include <iostream>
using namespace std;

int main(){
int n;
cout<<"Enter queue size: ";
cin>>n;
int queue[100];
int front=0, rear=-1,count=0;
int operations;
cout<<"Enter number of operations: ";
cin>>operations;


while(operations--){
cout<<"1. Join 2. Serve"<<endl;
int choice;
cout<<"Enter choice: ";
cin>>choice;

if(choice==1){
        int token;
        cout<<"Enter token number:";
        cin>>token;
        if(count==n){
            cout<<"Queue is full"<<endl;
        }
        else{
            rear=(rear+1)%n;
            queue[rear]=token;
            count++;
            cout<<"Token is joined"<<endl;

        }
}
else if(choice==2){
    if(count==0){
        cout<<"Queue is empty"<<endl;
    }else{
    cout<<"Token is served"<<endl;
    front=(front+1)%n;
    count--;
    }
}
else{
    cout<<"Invalid Choice"<<endl;
}
if(count>0) cout<<"Current Front: "<<queue[front]<<endl;
else cout<<"Current Front: Empty"<<endl;
}
return 0;
}
