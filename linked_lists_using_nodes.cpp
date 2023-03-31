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

Node* take_input(){         // making a linked list by taking input from user
    int data;
    cin>>data;
    Node* head=NULL;
    Node* tail=NULL;
    while(data!=-1){
        Node* N1=new Node(data);
        if(head==NULL){
            head=N1;
            tail=N1;
        }
        else{
            tail->next=N1;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}
    
void print_node(Node* head){        // printing entire list
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int length(Node* head){         // printing length of the linked list
    Node* temp=head;
    static int count=0;
    while(temp!=NULL){
        count+=1;
        temp=temp->next;
    }
    return count;
}

void printIthNode(Node *head, int i)   // printing element at i th index of linked list
{
    Node* temp=head;
    static int count=0;
    while(temp!=NULL){
        if(i==count){
            cout<<temp->data;
        }
        count++;
        temp=temp->next;        
    }
}

Node* insert_node(Node* head,int i,int data){    // inserting element at i th index
    Node* newnode=new Node(data);
    Node* temp=head;
    static int count=0;
    if(i==0){
        newnode->next=head;
        head=newnode;
        return head;
    }
    while(temp!=NULL){
        if(count==i-1){
            newnode->next=temp->next;
            temp->next=newnode;
            break;
        }
        temp=temp->next;
        count++;
    }
    
    return head;
}

Node* delete_node(Node* head,int i){
    Node* temp=head;
    static int count=0; 
    int size=length(head);
    if(i==0){
        head=head->next;
        delete temp;
        return head;
    }
    while(temp!=NULL){
        if(i>size-1){
            break;
        }
        if(count==i-1){
            Node* a=temp->next;
            temp->next=a->next;
            delete a;
            break;
        }
        temp=temp->next;
        count++;
    }
    size=length(head);
    return head;
}
int main(){
    Node* head= take_input();
    print_node(head);
    // cout<<length(head);
    int i,data;
    cin>>i;
    // head=insert_node(head,i,data);
    head=delete_node(head,i);
    print_node(head);
    return 0;
}