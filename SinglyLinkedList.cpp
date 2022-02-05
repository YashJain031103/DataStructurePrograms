#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node{
    int info;
    struct Node* next;
};
void operation();
void get_choiceForIns();
void get_choiceFordelt();
void insert_at_begin();
void insert_at_pos();
void insert_at_end();
void delete_from_begin();
void delete_from_pos();
void delete_from_end();
struct Node* head=NULL;
int p;
   void get_choiceForIns(){
   cout<<"for insertion at beginning press 1 , for insertion at any specific position press 2"<<endl;
   cout<<"for insertion at end press 3 , for going back press 4 : "<<endl;
   cin>>p;
    switch(p){
        case 1:
        insert_at_begin();
        break;
        case 2:
        insert_at_pos();
        break;
        case 3:
        insert_at_end();
        break;
        case 4:
        operation();
        break;
        default:
        cout<<"invalid command!! Re-enter your choice"<<endl;
        get_choiceForIns();
    }
    }
void insert_at_begin(){
    int data;
    cout<<"enter the data in node: ";
    cin>>data;
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->info=data;
    new_node->next=head;
    head=new_node;
    cout<<"data inserted successfully"<<endl;
    get_choiceForIns();
}
void insert_at_pos(){
    int pos,data;
    struct Node* ptr=head;
    if(head==NULL){
        cout<<"operation is invalid in empty linked list"<<endl;
    }
    else{
        int count=1;
        while(ptr->next!=NULL){
          count++;
          ptr=ptr->next;
        }
    struct Node* temp;
    temp=head;
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    cout<<"enter the position at which you want to insert the element: ";
    cin>>pos;
    if(pos==1){
        insert_at_begin();
    }
    else if(pos==(count+1)){
      insert_at_end();
    }
    else if(pos>(count+1)){
        cout<<"position you entered is more than size of list!! Kindly re-enter position"<<endl;
        insert_at_pos();
    }
    else{
    for(int i=1;i<pos;i++){
        if(i==(pos-1)){
         cout<<"enter the data in node: ";
         cin>>data;
         new_node->next=temp->next;
         temp->next=new_node;
         new_node->info=data;
        }
     temp=temp->next;
    }
    cout<<"data inserted successfully"<<endl;
    get_choiceForIns();
    }
}
}

void insert_at_end(){
    int data;
    struct Node* ptr;
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    cout<<"enter the data in node: ";
    cin>>data;
    if(head==NULL){
        new_node->info=data;
        new_node->next=NULL;
        head=new_node;
    }
    else{
       ptr=head;
       while(ptr->next!=NULL){
           ptr=ptr->next;
       }
       ptr->next=new_node;
       new_node->info=data;
       new_node->next=NULL;
    }
    cout<<"data inserted successfully"<<endl;
    get_choiceForIns();
}
  int q;
void get_choiceFordelt()
    {
   cout<<"for deletion from beginning press 1 , for deletion from any specific position press 2"<<endl;
   cout<<"for deletion from end press 3 , for going back press 4 : "<<endl;
   cin>>q;
    switch(q){
        case 1:
        delete_from_begin();
        break;
        case 2:
        delete_from_pos();
        break;
        case 3:
        delete_from_end();
        break;
        case 4:
        operation();
        break;
        default:
        cout<<"invalid command!! Re-enter your choice"<<endl;
        get_choiceFordelt();
    }
    }
void delete_from_begin(){
    struct Node* ptr;
 if(head==NULL){
     cout<<"Can't Remove!! list is Empty."<<endl;
 }
 else{
     ptr=head;
     if(ptr->next==NULL){
         head=NULL;
     cout<<"element deleted successfully!! Now your List is empty"<<endl;
     }
     else {
           head=head->next;
           cout<<"element deleted successfully"<<endl;
     }
 }
  get_choiceFordelt();
}
void delete_from_pos(){
int pos;
struct Node* ptr;
struct Node* temp;
if(head==NULL){
    cout<<"Empty Linked List!! can't perform this operation"<<endl;
}
else {
    ptr=head;
    cout<<"enter the position from which you want to delete the element: ";
    cin>>pos;
    if(pos<1){
        cout<<"enter a valid position!! Re-enter the position"<<endl;
        delete_from_pos();
    }
    else{
        if(pos==1){
            delete_from_begin();
        }
        else{
            int count=1;
            while(ptr->next!=NULL){
                ptr=ptr->next;
                count++;
            }
            if(pos>count){
                cout<<"your entered position is greater than the size of list!! Re-enter the position"<<endl;
                delete_from_pos();
            }
            else{  
                if(pos==count){
                    delete_from_end();
                } 
             else{  
                 if(pos<count){
                     ptr=head;   
                     for(int i=1;i<pos;i++){
                     if(i==(pos-1)){
                     temp=ptr->next;
                     ptr->next=temp->next;
                     free(temp);
                    }
                    ptr=ptr->next;
                }
             }
            }
        }
     }
     cout<<"Element has been deleted successfully!!"<<endl;
    }
}
get_choiceFordelt();
}
void delete_from_end(){
struct Node* ptr;
struct Node* temp;
if(head==NULL){
    cout<<"This Linked list is Empty!! operation invalid"<<endl;
}
else{
if(head->next==NULL){
    head=NULL;
    cout<<"now your list is empty after this deletion!!"<<endl;
}
else{
    ptr=head;
    while(ptr->next!=NULL){
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=NULL;
    cout<<"element has been deleted successfully!!"<<endl;
}
}
get_choiceFordelt();
}
void  traverse(){
    if(head==NULL){
        cout<<"This is an empty linked list"<<endl;
    }
    else{
    struct Node* ptr;
    ptr=head;
    cout<<"your Linked list is: {";
    while(ptr!=NULL){
        cout<<ptr->info<<" ";
        ptr=ptr->next;
    }
    cout<<"}"<<endl;
    }
    operation();
}

void operation(){
char ch;
int n;
cout<<"for insertion press i , for deletion press d "<<endl;
cout<<"for traversing press t , to exit press e : "<<endl;
cin>>ch;
switch(ch){
    case 'i':
    n=1;
    break;
    case 'd':
    n=2;
    break;
    case 't':
    n=3;
    break;
    case 'e':
    exit(0);
    break;
    default:
    cout<<"invalid command!!, Please Re-Enter the valid command"<<endl;
    operation();
}
switch(n){
    case 1:
    get_choiceForIns();
    break;
    case 2:
    get_choiceFordelt();
    break;
    case 3:
    traverse();
    break;
    default:
    exit(0);
}
}
int main(){
    operation();
    return 0;
}
