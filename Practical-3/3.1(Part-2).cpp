#include<iostream>
using namespace std;
void selectionsort(int arr[],int n){
for(int i=0;i<n;i++){
    int min_idx=i;
    for(int j=i;j<=n-1;j++){
        if(arr[j]<arr[min_idx]) min_idx=j;
    }
    int temp=arr[min_idx];
    arr[min_idx]=arr[i];
    arr[i]=temp;
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
selectionsort(arr,n);
cout<<"After sorting array elemnt:"<<endl;
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
return 0;
}
