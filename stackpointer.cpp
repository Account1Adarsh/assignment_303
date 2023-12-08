#include<iostream>
#include<vector>
using namespace std;

struct node{
    int data;
    node* next;

    node(int x){
        data=x;
        next=NULL;
    }
};

node* push(node* head,int x){
    node* temp=new node(x);
    if(head==NULL){
       return temp; 
    }
    else {
        temp->next=head;
        return temp;
    }
}
node* pop(node* head){
    if(head==NULL){
        cout<<"UNDERFLOW";
        return head;
    }
    node* temp=head;

    head=head->next;
    delete(temp);
    return head;
}
void show(node* head){
    node*temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return;
}
int main(){
    node* head=NULL;
    while(true){
        cout<<"Enter 1 for insertion "<<endl;
        cout<<"Enter 2 for deletion "<<endl;
        cout<<"Enter 3 for top "<<endl;
        cout<<"Enter 4 for show "<<endl;
        cout<<"Enter 5 for exit "<<endl;
        int a;
        cin>>a;
        if(a==1){
            cout<<"Enter the element ";
            int x;
            cin>>x;
            head=push(head,x);
            cout<<endl;
        }
        else if(a==2){
            head=pop(head);
            cout<<endl;
        }
        else if(a==3){
            if(head==NULL){
                cout<<"NULL";
            }
            else
            cout<<head->data<<endl;
        }
        else if(a==4){
            show(head);
        }
        else if(a==5){
            break;
        }
        else{
            cout<<"entered wrong!! retry"<<endl; 
            cout<<endl;
        }
    }
    
    return 0;
}