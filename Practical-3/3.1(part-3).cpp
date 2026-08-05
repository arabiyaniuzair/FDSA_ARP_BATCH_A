#include<iostream>
using namespace std;

void insertionsort(int arr[],int n){
for(int i=1;i<=n;i++){
    int j=i;
    while(arr[j-1]>arr[j] && j>=1){
        int temp=arr[j-1];
        arr[j-1]=arr[j];
        arr[j]=temp;
        j--;
    }
}
}
int main(){
int n;
cout<<"Enter the size of the array:"<<endl;
cin>>n;
int arr[n];
cout<<"Enter the array elemnet:"<<endl;
for(int i=0;i<n;i++){
    cin>>arr[i];
}
insertionsort(arr,n);
cout<<"After sorting array elemnt:"<<endl;
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
return 0;
}
