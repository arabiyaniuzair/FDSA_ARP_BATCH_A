#include<iostream>

using namespace std;

int main(){
int packeting[10];
for (int i=0;i<10;i++){
    packeting[i]=-1;
}
int n;
cout<<"Enter number of vehicles: ";
cin>>n;
cout<<"Enter vehicle registration numbers:"<<endl;

for(int i=0;i<n;i++){
    int reg;
    cin>>reg;
    int slot=reg%10;
    int start=slot;
    while(packeting[i]!=-1){
        slot=(slot+1)%10;
        if(slot==start){
            cout<<"Full"<<endl;
            break;
        }
    }
    if(packeting[slot]==-1){
        packeting[slot]=reg;
    }

}
cout<<"\nFinal packeting lot:"<<endl;
    for(int i=0;i<10;i++){
        cout<<"Slot "<<i<<": ";
        if (packeting[i]==-1)
            cout<<"Empty";
        else
            cout<<packeting[i];
        cout<<endl;
    }
    return 0;
}
