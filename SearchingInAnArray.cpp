#include<iostream>
using namespace std;
int main(){
    int arr[10],n,elmnt;
    cout<<"enter the number of elements will be entering in the array: ";cin>>n;
    cout<<"enter elements in the array: ";
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"your array is: {";
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"}"<<endl;
    cout<<"enter the element you want to search in your entered array: ";
    cin>>elmnt;
    int check=0;
    for(int i=0;i<n;i++){
        if(arr[i]==elmnt){
            cout<<elmnt<<" is at "<<i+1<<" position in the array";
            check=1;
        }
    }
    if(check==0){
        cout<<"element not present in your array.";
    }
}
