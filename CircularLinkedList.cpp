#include<iostream>
using namespace std;
struct Node{
    int info;
    struct Node* next;
};
struct Node* head=NULL;
void operation();
void choice_for_inst();
void choice_for_delt();
void ins_at_begin();
void ins_at_pos();
void ins_at_end();
void delt_from_begin();
void delt_from_pos();
void delt_from_end();
void traverse();
void choice_for_inst(){
    int p;
    cout<<"for insertion at beginning press 1 , for insertion at any specific position press 2"<<endl;
   cout<<"for insertion at end press 3 , for going back press 4 : "<<endl;
   cin>>p;
    switch(p){
        case 1:
        ins_at_begin();
        break;
        case 2:
        ins_at_pos();
        break;
        case 3:
        ins_at_end();
        break;
        case 4:
        operation();
        break;
        default:
        cout<<"invalid command!! Re-enter your choice"<<endl;
        choice_for_inst();
    }
    }
 void ins_at_begin(){
     struct Node* new_node =(struct Node*)malloc(sizeof(struct Node));
    int data;
    cout<<"enter data in the node: ";
    cin>>data;
    if(head==NULL){
     new_node->info=data;
     new_node->next=new_node;
     head=new_node;
 }
 else {
     new_node->info=data;
     new_node->next=head;
     struct Node* ptr;
     ptr=head;
     while(ptr->next!=head){
         ptr=ptr->next;
     }
     ptr->next=new_node;
     head=new_node;
 }
  cout<<"data inserted successfully!!";
 choice_for_inst();
}
void ins_at_pos(){
    if(head==NULL){
        cout<<"operation is invalid in empty linked list"<<endl;
        choice_for_inst();
    }
    else{
        int pos,data;
        struct Node* ptr=head;
         int count=1;
        while(ptr->next!=head){
          count++;
          ptr=ptr->next;
        }
    cout<<"enter the position at which you want to insert the element: ";
    cin>>pos;
    if(pos==1){
        ins_at_begin();
    }
    else if(pos==(count+1)){
      ins_at_end();
    }
    else if(pos>(count+1)){
        cout<<"position you entered is more than size of list!! Kindly re-enter position"<<endl;
        ins_at_pos();
    }
    else{
         struct Node* temp;
         temp=head;
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        for(int i=1;i<pos;i++){
        if(i==(pos-1)){
         cout<<"enter the data in node: ";
         cin>>data;
         new_node->info=data;
         new_node->next=temp->next;
         temp->next=new_node;
        }
        temp=temp->next;
    }
    cout<<"data inserted successfully"<<endl;
    choice_for_inst();
    }
}   
}
void ins_at_end(){
    int data;
    struct Node* ptr;
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    cout<<"enter the data in node: ";
    cin>>data;
    if(head==NULL){
        new_node->info=data;
        new_node->next=new_node;
        head=new_node;
    }
    else{
        new_node->info=data;
        struct Node* ptr=head;
        while(ptr->next!=head){
            ptr=ptr->next;
        }
        ptr->next=new_node;
        new_node->next=head;
    }
    cout<<"data inserted successfully"<<endl;
    choice_for_inst();
}
void choice_for_delt()
    {
     int q;
     cout<<"for deletion from beginning press 1 , for deletion from any specific position press 2"<<endl;
     cout<<"for deletion from end press 3 , for going back press 4 : "<<endl;
     cin>>q;
     switch(q){
        case 1:
        delt_from_begin();
        break;
        case 2:
        delt_from_pos();
        break;
        case 3:
        delt_from_end();
        break;
        case 4:
        operation();
        break;
        default:
        cout<<"invalid command!! Re-enter your choice"<<endl;
       choice_for_delt();
    }
    }
void delt_from_begin(){
    struct Node* ptr;
 if(head==NULL){
     cout<<"Can't Remove!! list is Empty."<<endl;
 }
 else{
     ptr=head;
     if(ptr->next==head){
         head=NULL;
     cout<<"element deleted successfully!! Now your List is empty"<<endl;
     }
     else {
           head=head->next;
           cout<<"element deleted successfully"<<endl;
     }
 }
  choice_for_delt();
}
void delt_from_pos(){
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
        delt_from_pos();
    }
    else{
        if(pos==1){
            delt_from_begin();
        }
        else{
            int count=1;
            while(ptr->next!=NULL){
                ptr=ptr->next;
                count++;
            }
            if(pos>count){
                cout<<"your entered position is greater than the size of list!! Re-enter the position"<<endl;
                delt_from_pos();
            }
            else{  
                if(pos==count){
                    delt_from_end();
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
choice_for_delt();
}
void delt_from_end(){
struct Node* ptr;
struct Node* temp;
if(head==NULL){
    cout<<"This Linked list is Empty!! operation invalid"<<endl;
}
else{
if(head->next==head){
    head=NULL;
    cout<<"now your list is empty after this deletion!!"<<endl;
}
else{
    ptr=head;
    while(ptr->next!=head){
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=head;
    cout<<"element has been deleted successfully!!"<<endl;
}
}
choice_for_delt();
}
void traverse(){
    if(head==NULL){
        cout<<"This is an empty linked list"<<endl;
    }
    else{
    struct Node* ptr;
    ptr=head;
    cout<<"your Linked list is: {";
    while(ptr->next!=head){
        cout<<ptr->info<<" ";
        ptr=ptr->next;
    }
    cout<<ptr->info;
    cout<<"}"<<endl;
    }
    operation();
}   
void operation(){
    char x;
    cout<<"for insertion press i , for deletion press d"<<endl;
    cout<<"for traversing press t , to exit press e"<<endl;
    cin>>x;
    switch(x){
        case 'i':
        choice_for_inst();
        break;
        case 'd':
        choice_for_delt();
        break;
        case 't':
        traverse();
        break;
        case 'e':
        exit(0);
        default:
        cout<<"enter valid command!! Re-enter the command:-"<<endl;
        operation();
    }
}
int main(){
    operation();
    return 0;
}
