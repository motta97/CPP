#include<iostream>
using namespace std;
class linkeList{
public:
    int data;
    linkeList *next;
}*first=NULL;
void create(int arr[],int n){
    //we want to create a linked list having the data as the array
    first = new linkeList;
    first->data=arr[0];
    linkeList *q=first;

    for(int i =1; i<n;i++){

        q->next=new linkeList;
        q=q->next;
        q->data=arr[i];
        q->next=NULL;


    }
    


}
void displayLL(linkeList *l){
linkeList *tmp = l;
while(tmp){
    cout<<tmp->data<<endl;
    tmp=tmp->next;
}


}
void displayRecursive(linkeList * p){
    if(p==NULL){
        return;
    }
    cout<<p->data<<endl;
    displayRecursive(p->next);
}
void displayRecusiveA(linkeList * p){
    if(p){
        cout<<p->data<<endl;
        displayRecusiveA(p->next);
    }
}

int main(){
int arr[]={5,4,3,2,1};
create(arr,5);
displayLL(first);

displayRecursive(first);

}
