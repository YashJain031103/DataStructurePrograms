#include<iostream>
#include<stdlib.h>
int n;
using namespace std;
struct Node{
    int info;
    struct Node* next;
};
struct Node *head;  
void opr();
void Push();  
void pop();  
void peek();
void display();
void push(){
    int data;
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    if(head==NULL){
        cout<<"enter the data: "; cin>>data;
        new_node->info=data;
        new_node->next=NULL;
        head=new_node;
        cout<<"Element inserted successfully!!"<<endl;
    }
    else{
        struct Node* ptr=head;
        int count=1;
        while(ptr->next!=NULL){
          count++;
          ptr=ptr->next;
        }
      if(n==count){
        cout<<"stack overflow"<<endl;
        opr();
    }
    else{  
     cout<<"enter the data: "; cin>>data;
     new_node->info=data;
     new_node->next=head;
     head=new_node;
     cout<<"Element inserted successfully!!"<<endl;
    }
    }      
}
void pop(){
    if(head==NULL){
        cout<<"stack Underflow"<<endl;
    }
    else{
        head=head->next;
        cout<<"Node deleted successfully!!"<<endl;
    }
}
void peek(){
    cout<<"your Top most element is: "<<head->info<<endl;
}
void display(){
    struct Node* ptr;
    if(head==NULL){
        cout<<"your stack is empty!!"<<endl;
    }
    else{
    ptr=head;
    cout<<"your stack is: {";
    while(ptr->next!=NULL){
        cout<<ptr->info<<" ";
        ptr=ptr->next;
     };
     cout<<ptr->info;
    cout<<"}"<<endl;
    }
}
void opr(){
    int x;
    cout<<"press 1 for push operation ; press 2 for pop operation"<<endl;
    cout<<"press 3 for peek operation ; press 4 to display"<<endl;
    cout<<"press 5 to exit: "<<endl;
    cin>>x;
    switch(x){
        case 1:
        push();
        opr();
        break;
        case 2:
        pop();
        opr();
        break;
        case 3:
        peek();
        opr();
        break;
        case 4:
        display();
        opr();
        break;
        case 5:
        exit(0);
        default:
        cout<<"Invalid command!! please Re-enter the command"<<endl;
        opr();
    }
}
int main(){
    cout<<"enter the size of stack: ";
    cin>>n;
    opr();
    return 0;
}
