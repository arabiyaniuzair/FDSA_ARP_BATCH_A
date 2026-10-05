#include <iostream>
using namespace std;

int main() {
    int table[10];
    for (int i = 0; i < 10; i++)
        table[i] = -1;

    int n;
    cout<<"Enter number of student IDs: ";
    cin>>n;

    for(int i=0;i<n;i++){
        int id;
        cout<<"Enter student ID: ";
        cin>>id;

        int h1=id%10;
        int h2=7-(id % 7);
        int pos=h1;

        for(int j=0;j<10;j++){
            pos=(h1+j*h2)%10;

            if (table[pos]==-1){
                table[pos]=id;
                break;
            }
        }
    }

    cout<<"\nFinal Hash Table:"<<endl;

    for(int i=0;i<10;i++){
        cout<<"Slot "<<i<<": ";

        if(table[i]==-1)
            cout<<"Empty";
        else
            cout<<table[i];

        cout<<endl;
    }

return 0;
}
