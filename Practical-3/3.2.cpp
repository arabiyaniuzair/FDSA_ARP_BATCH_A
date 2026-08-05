#include<iostream>
#include<vector>
using namespace std;

void arrange_color(vector<int>& arr){
int n=arr.size();
int low=0,mid=0,high=n-1;
while(mid<=high){
    if(arr[mid]==0){
        swap(arr[low],arr[mid]);
        low++;
        mid++;
    }else if(arr[mid]==1){
    mid++;
    }else if(arr[mid]==2){
    swap(arr[mid],arr[high]);
    high--;
    }
}
}
int main() {
    int n;
    cout<<"Enter the size of the vector: ";
    cin>>n;
    vector<int> arr(n);
   cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    arrange_color(arr);
    cout<<"After arranging array elements: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
