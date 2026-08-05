
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >>n;

    int arr[n];

    for (int  i=0;i<n;i++) {
        cin>>arr[i];
    }

    for (int i=0; i<n; i++) {
        int count=1;


        bool visited=false;
        for (int k =0;k<i;k++) {
            if (arr[i]==arr[k]) {
                visited=true;
                break;
            }
        }

        if (visited)
            continue;


        for (int j=i+1;j<n;j++) {
            if (arr[i]==arr[j]) {
                count++;
            }
        }

        if (count > 1) {
            cout <<arr[i]<<" is repeated "<<count<<" times"<<endl;
        }
    }

    return 0;
}
