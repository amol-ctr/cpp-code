#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }

};

Node* insert_node(){
    int data;
    cin>>data;
    Node* head=NULL;
    Node* tail=NULL;
    while(data!=-1){
        Node* newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}

void print_Node(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* delete_node(Node* head,int element){
    if(head==NULL){
        return NULL;
    }
    Node* temp=head;
    if(temp->data==element){
        head=temp->next;
        return head;
    }

    Node* smallans=delete_node(temp->next,element);
    head->next=smallans;
    return head;

}

int main(){
    Node* head=insert_node();
    print_Node(head);
    head=delete_node(head,1);
    print_Node(head);
    return 0;
}