#include <iostream>
#include <vector>
using namespace std;

int main(){
vector<int> shelf[10];
int n;
cout<<"Enter number of books: ";
cin>>n;
cout<<"Enter book codes:\n";
for(int i=0;i<n;i++) {
    int code;
    cin>>code;
    int shelfNo=code % 10;
    shelf[shelfNo].push_back(code);
}
cout<<"\nFinal shelves:"<<endl;
for(int i=0;i<10;i++){
        cout<<"Shelf "<<i<<": ";
        if(shelf[i].empty()){
        cout<<"Empty";
        }else{
            for(int code:shelf[i])
                cout<<code<<" ";
        }

        cout<<endl;
}

    return 0;
}
