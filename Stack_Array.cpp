#include<iostream>
using namespace std;
#define n 10
int arr[n],top;
void choicef(){
    int y;
    cout<<"press 1 for Push operation"<<endl;
    cout<<"press 2 for Pop operation"<<endl;
    cout<<"press 3 to Display stack"<<endl;
    cout<<"press 4 to access Top element"<<endl;
    cout<<"press 5 to exit"<<endl;
    cin>>y;
    switch(y){
        case 1:
         if (top==n-1){
        cout<<"stack is full!!"<<endl;
    }
    else{
    int data;
    cout<<"enter the data: "; cin>>data;
    top=top+1;
    arr[top]=data;
    cout<<"data inserted successfully!!"<<endl;
    }
        choicef();
        break;
        case 2:
        if(top==-1){
        cout<<"stack is empty!!"<<endl;
    }
    else{
        top=top-1;
        cout<<"data deleted successfully!!"<<endl;
    }
        choicef();
        break;
        case 3:
        if(top==-1){
        cout<<"your stack is empty!!"<<endl;
    }
    else{
        cout<<"your stack is: {";
        for(int i=top;i>=0;i--){
          cout<<arr[i]<<" ";
        }
        cout<<"}"<<endl;
    }
        choicef();
        break;
        case 4:
        if(top==-1){
            cout<<"your stack is underflow!!"<<endl;
            choicef();
        }
        else{
        cout<<"Your Top most element is: "<<arr[top]<<endl;
        choicef();
        }
        break;
        case 5:
        exit(0);
        default:
        cout<<"invalid operation!!"<<endl;
        choicef();
    }
}
int main(){
    top=-1;
    choicef();
    return 0;
}
