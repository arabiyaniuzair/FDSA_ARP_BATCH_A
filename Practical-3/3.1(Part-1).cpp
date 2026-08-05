#include<iostream>
using namespace std;
void bubblesort(int arr[],int n){
for(int i=n-1;i>=1;i--){
    bool swape=true;
    for(int j=0;j<=i-1;j++){
        if(arr[j]>arr[j+1]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            swape=false;
        }
    }
    if(swape==true) break;
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
bubblesort(arr,n);
cout<<"After sorting array elemnt:"<<endl;
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
return 0;
}

