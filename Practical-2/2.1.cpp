#include<iostream>
using namespace std;
int findIndex(string name[],int n,string part,int i){
if(i==n){
    return -1;
}
if(name[i]==part){
    return i;
}
return findIndex(name,n,part,i+1);
}
int main(){
int n;
cout<<"Enter the size:"<<endl;
cin>>n;
cout<<"Enter the id:"<<endl;
string name[n];
for(int i=0;i<n;i++){
    cin>>name[i];
}
string part;
cout<<"Enter the target plate number which you wan to find:"<<endl;
cin>>part;

cout<<"Found at index:"<<findIndex(name,n,part,0);
}
