#include<iostream>
using namespace std;
int main(){
    int n,arr[10];
    cout<<"how many elements to be entered in array: ";cin>>n;
    cout<<"enter the elements in the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"your array is: {";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"}";
    return 0;
    
}
