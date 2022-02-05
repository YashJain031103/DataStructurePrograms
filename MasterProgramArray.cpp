#include<iostream>
using namespace std;
class oprarray{
    public:
    int n;
    int arr[20];
    void getdata();
    int display();
    int insert();
    int dlt();
    int select();
};
void oprarray::getdata(){
    cout<<"enter the number of elements in the array: ";
    cin>>n;
    cout<<"enter the elements"<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<" element: "; cin>>arr[i];
    }
    select();
}
int oprarray::display(){
    cout<<"your array is: {";
    for(int i=0;i<n;i++){ 
        cout<<arr[i]<<" ";
    }
    cout<<"}"<<endl;
    select();
}
int oprarray::insert(){
     int k,val;
        cout<<"at which position in array you want to insert an element: ";
        cin>>k;
        cout<<"enter the value you want to insert at "<<k<<"th position: ";
        cin>>val;
        for (int i=n;i>k-2;i--){
            arr[i+1]=arr[i];
        }
        arr[k-1]=val;
        n=n+1;
        select();
}
int oprarray::dlt(){
          int delElmt;
          int check=5;
          cout<<"which element you want to delete in array: ";
          cin>>delElmt;
          for(int i=0;i<n;i++){
              if(arr[i]==delElmt){
                  for(int j=i;j<n;j++){
                      arr[j]=arr[j+1];
                      check=5;
                  }
              }
              else{
                  check=0;
              }
          }
           n=n-1;
            if(check==0){
                cout<<"element does not exist in your array";
            } 
            select();       
}
int oprarray::select(){
        char ch;
        int p;
        cout<<"To display array press \"d\", for Inserting press \"i\" "<<endl;
        cout<<"for Deleting press \"l\" ,to exit press \"e\": ";
        cin>>ch;
        if(ch=='d') p=1;
        else if(ch=='i') p=2;
        else if(ch=='l') p=3;
        else if(ch=='e') p=4;
        else cout<<"invalid command";
        switch(p){
            case 1:
               display();
               break;
            case 2:
               insert();
               break;
            case 3:
               dlt();
               break;  
            case 4:
                exit(0);
        }

}
int main(){
    oprarray arr1;
    arr1.getdata();
    return 0;
}

