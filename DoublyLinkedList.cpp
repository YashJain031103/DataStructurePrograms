#include<iostream>
using namespace std;
struct Node{
    struct Node* prev;
    int info;
    struct Node* next;
};
struct Node* head=NULL;
void operation();
void choice_for_ins();
void choice_for_del();
void choice_for_traverse();
void choice_for_ins_pos();
void choice_for_del_pos();
void ins_at_begin();
void ins_after();
void ins_before();
void ins_at_end();
void del_from_begin();
void del_after();
void del_before();
void del_from_end();
void travrs_frward();
void travrs_rvrs();
void operation(){
    char x;
    cout<<"for insertion press i , for deletion press d"<<endl;
    cout<<"for traversing press t , to exit press e"<<endl;
    cin>>x;
    switch(x){
        case 'i':
        choice_for_ins();
        break;
        case 'd':
        choice_for_del();
        break;
        case 't':
        choice_for_traverse();
        break;
        case 'e':
        exit(0);
        default:
        cout<<"enter valid command!! Re-enter the command:-"<<endl;
        operation();
    }
}
void choice_for_ins(){
    int p;
    cout<<"for insertion at beginning press 1 , for insertion at any specific position press 2"<<endl;
    cout<<"for insertion at end press 3 , for going back press 4 : "<<endl;
    cin>>p;
    switch(p){
        case 1:
        ins_at_begin();
        break;
        case 2:
        choice_for_ins_pos();
        break;
        case 3:
        ins_at_end();
        break;
        case 4:
        operation();
        break;
        default:
        cout<<"invalid command!! kindly Re-enter your choice"<<endl;
        choice_for_ins();
    }
}
void choice_for_del(){
    int q;
     cout<<"for deletion from beginning press 1 , for deletion from any specific position press 2"<<endl;
     cout<<"for deletion from end press 3 , for going back press 4 : "<<endl;
     cin>>q;
     switch(q){
        case 1:
        del_from_begin();
        break;
        case 2:
        choice_for_del_pos();
        break;
        case 3:
        del_from_end();
        break;
        case 4:
        operation();
        break;
        default:
        cout<<"invalid command!! Re-enter your choice"<<endl;
        choice_for_del();
    }
}
void choice_for_ins_pos(){
    int s;
    cout<<"for insertion after a position press 1 , for insertion before a position press 2"<<endl;
    cout<<"for previous options press 3: "<<endl;
    cin>>s;
    switch(s){
        case 1:
        ins_after();
        break;
        case 2:
        ins_before();
        break;
        case 3:
        choice_for_ins();
        break;
        default:
        cout<<"enter a valid command!! kindly re-enter it"<<endl;
        choice_for_ins_pos();
    }
}
void choice_for_del_pos(){
    int r;
    cout<<"for deletion after a position press 1 , for deletion before a position press 2"<<endl;
    cout<<"for previous options press 3: "<<endl;
    cin>>r;
    switch(r){
        case 1:
        del_after();
        break;
        case 2:
        del_before();
        break;
        case 3:
        choice_for_del();
        break;
        default:
        cout<<"enter a valid command!! kindly re-enter it"<<endl;
        choice_for_del_pos();
    }
}
void choice_for_traverse(){
    int t;
    cout<<"for traversing forwardly press 1 , for traversing reverse press 2"<<endl;
    cout<<"for previous options press 3: "<<endl;
    cin>>t;
    switch(t){
        case 1:
        travrs_frward();
        break;
        case 2:
        travrs_rvrs();
        break;
        case 3:
        operation();
        break;
        default:
        cout<<"enter a valid command!! kindly re-enter it"<<endl;
        choice_for_traverse();
    }
}
void ins_at_begin(){
    int data;
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    cout<<"enter data in the Node: "; cin>>data;
    if(head==NULL){
        new_node->info=data;
        new_node->prev=NULL;
        new_node->next=NULL;
        head=new_node;
    }
    else{
        new_node->info=data;
        new_node->next=head;
        head->prev=new_node;
        new_node->prev=NULL;
        head=new_node;
    }
    cout<<"Element inserted successfully!!"<<endl;
    choice_for_ins();
}
void ins_at_end(){
    int data;
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    cout<<"enter data in the Node: "; cin>>data;
   if(head==NULL){
     new_node->info=data;
     new_node->prev=NULL;
     new_node->next=NULL;
     head=new_node;
   }
   else{
       new_node->info=data;
       struct Node* ptr=head;
       while(ptr->next!=NULL){
           ptr=ptr->next;
       }
    new_node->prev=ptr;
       ptr->next=new_node;
       new_node->next=NULL;
   }
   cout<<"Element inserted successfully!!"<<endl;
    choice_for_ins();
}
void ins_after(){
    if(head==NULL){
        cout<<"invalid operation!! Linked list is empty"<<endl;
        choice_for_ins();
    }
    else{
    int pos;
    int count=1;
        struct Node* ptr=head;
        while(ptr->next!=NULL){
          count++;
          ptr=ptr->next;
        }
    cout<<"enter the position after which you want to insert an element: "; cin>>pos;
    if(pos<1){
        cout<<"enter a valid position!!"<<endl;
        ins_after();
    }
    else if(pos==count){
        ins_at_end();
    }
         else if (pos>count){
            cout<<"position you entered is greater than the size of linked list"<<endl;
            choice_for_ins();
        }
        else {
            int data;
            struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
            struct Node* temp=head;
            struct Node* temp1;
            for(int i=1;i<=pos;i++){
                if(i==pos){
                 cout<<"enter the value in the node: "; cin>>data;
                 new_node->info=data;   
                 temp1=temp->next;   
                 new_node->next=temp->next;
                 new_node->prev=temp;
                 temp->next=new_node;
                 temp1->prev=new_node;
                }
                temp=temp->next;
            }
            cout<<"Element inserted successfully!!"<<endl;
            choice_for_ins();
        }
    }
    }
void ins_before(){
   if(head==NULL){
        cout<<"invalid operation!! Linked list is empty"<<endl;
        choice_for_ins();
    } 
    else{
        int pos;
       int count=1;
        struct Node* ptr=head;
        while(ptr->next!=NULL){
          count++;
          ptr=ptr->next;
        }
         cout<<"enter the position before which you want to insert an element: "; cin>>pos;
         if(pos<1){
        cout<<"enter a valid position!!"<<endl;
        ins_before();
        }
       else if(pos==1){
        ins_at_begin();
       }
       else if(pos>count){
           cout<<"the position you entered is greater than the size of list!! kindly re-enter the position"<<endl;
           ins_before();
       }
       else{
           int data;
           struct Node* temp;
           struct Node* temp1;
           temp=head;
           struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
           for(int i=1;i<=pos;i++){
               if(i==pos){
                cout<<"enter data in the Node: "; cin>>data;
                new_node->info=data;
                temp1=temp->prev;
                new_node->next=temp;
                new_node->prev=temp->prev;
                temp->prev=new_node;
                temp1->next=new_node;
               }
               temp=temp->next;
           }
           cout<<"data inserted successfully!!"<<endl;
           choice_for_ins();
       }
    }
}
void del_from_begin(){
    if(head==NULL){
        cout<<"your linked list is empty!! can't perform this operation!!"<<endl;
        operation();
    }
    else if(head->next==NULL && head->prev==NULL){
        head=NULL;
        cout<<"element deleted successfully!!!"<<endl;
        cout<<"now your linked list is empty!!"<<endl;
        operation();
    }
    else{
        struct Node* ptr;
        ptr=head->next;
        ptr->prev=NULL;
        head=ptr;
        cout<<"element deleted Successfully!!"<<endl;
        choice_for_del();
    }
}
void del_after(){
    if(head==NULL){
        cout<<"your Linked List is empty!! can't perform this operation"<<endl;
        operation();
    }
    else if(head->next==NULL){
        cout<<"You have only one element in the list!!"<<endl;
        cout<<"kindly insert some more elements in the list to enjoy this feature!!"<<endl;
        operation();
    }
    else{
       int pos;
       int count=1;
       struct Node* ptr=head;
       while(ptr->next!=NULL){
          count++;
          ptr=ptr->next;
        }
        cout<<"enter the position after which the element to be deleted: "; cin>>pos;
        if(pos<1){
            cout<<"Kindly enter a Valid position!! Re-enter the position"<<endl;
            del_after();
        }
        else if (pos==(count-1)){
            del_from_end();
        }
        else if(pos>=count){
            cout<<"position you entered is greater than or equal to size of list!!"<<endl;
            cout<<"enter a valid position"<<endl;
            del_after();
        }
        else{
            struct Node* temp=head;
            struct Node* temp1;
            for(int i=1;i<=pos;i++){
                if(i==pos){
                 temp1=temp->next;
                 temp->next=temp1->next;
                 temp1=temp1->next;
                 temp1->prev=temp;
                }
                temp=temp->next;
            }
            cout<<"element deleted successfully!!"<<endl;
            choice_for_del();
        }
    }
}
void del_before(){
    if(head==NULL){
        cout<<"your Linked List is empty!! can't perform this operation"<<endl;
        operation();
    }
    else if(head->next==NULL){
        cout<<"You have only one element in the list!!"<<endl;
        cout<<"kindly insert some more elements in the list to enjoy this feature!!"<<endl;
        operation();
    }
    else{
         int pos;
       int count=1;
       struct Node* ptr=head;
       while(ptr->next!=NULL){
          count++;
          ptr=ptr->next;
        }
        cout<<"enter the position before which the element to be deleted: "; cin>>pos;
        if(pos==1){
           cout<<"No Element present Before this Position!!"<<endl;
           cout<<"kindly Re-enter the position...."<<endl;
           del_before();
        }
        else if(pos<1){
            cout<<"Invalid Position!! kindly re-enter the position"<<endl;
            del_before();
        }
        else if(pos>count){
            cout<<"You entred a postion greater than the size of List!!"<<endl;
            cout<<"kindly Re-enter the position...."<<endl;
            del_before();
        }
        else if(pos==2){
            del_from_begin();
        }
        else{
            struct Node* temp=head;
            struct Node* temp1;
            for(int i=1;i<=pos;i++){
                if(i==pos){
                 temp1=temp->prev;
                 temp->prev=temp1->prev;
                 temp1=temp1->prev;
                 temp1->next=temp;
                }
                temp=temp->next;
            }
             cout<<"element deleted successfully!!"<<endl;
            choice_for_del();
        }
    }
}
void del_from_end(){
     if(head==NULL){
        cout<<"your linked list is empty!! can't perform this operation!!"<<endl;
        operation();
    }
    else if(head->next==NULL && head->prev==NULL){
        head=NULL;
        cout<<"element deleted successfully!!!"<<endl;
        cout<<"now your linked list is empty!!"<<endl;
        operation();
    }
    else{
        struct Node* ptr;
        struct Node* temp;
        ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
       temp=ptr->prev;
       temp->next=NULL;
       cout<<"element deleted Successfully!!"<<endl;
       choice_for_del();
    }
}
void travrs_frward(){
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
void travrs_rvrs(){
    if(head==NULL){
        cout<<"This is an empty linked list"<<endl;
    }
    else{
    struct Node* ptr =head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    cout<<"your reverse Linked list is: {";
    while(ptr!=NULL){
        cout<<ptr->info<<" ";
        ptr=ptr->prev;
    }
    cout<<"}"<<endl;
    }
    operation();
}
int main(){
    operation();
    return 0;
}
