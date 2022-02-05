#include<iostream>
using namespace std;
int main(){
    int n;
    int arr[20];
    cout<<"number of elements you want to take in array: ";
    cin>>n;
    cout<<"enter the elements in the array"<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<" element: ";cin>>arr[i];
    }
    cout<<"your array is: {";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"}"<<endl;
    int max=0;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    cout<<"Greatest number out of your given array is: "<<max;

}
