#include<iostream>
using namespace std;
int findbook(int arr[],int low,int n,int high,int target){
while(low<=high){
    int mid=low+(high-low)/2;
    if(arr[mid]==target) return mid;
    else if(arr[mid]>target) high=mid-1;
    else low=mid+1;
}
return -1;
}
int main(){
int n;
cout<<"Enter the no.of Elements"<<endl;
cin>>n;
int arr[n];
cout<<"Enter the array:";
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int target;
cout<<"Enter the target"<<endl;
cin>>target;
cout<<"Your target at index:"<<findbook(arr,0,n,n-1,target);
return 0;
}
