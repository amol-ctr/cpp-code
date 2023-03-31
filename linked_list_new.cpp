#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
	Node(int data){
	    this->data = data;
        this->next = NULL;
	}
};

/*Node* insertNode(Node *head, int i, int data) {
    if(head==NULL){
        return head;
    }
    if(i==0){
        Node* newnode=new Node(data);
        newnode->next=head;
        head=newnode;
        return head;
    }
    Node* newnode=insertNode(head->next,i-1,data);
    head->next=newnode;
    return head;
}

Node *deleteNodeRec(Node *head, int pos) {
	//Write your code here
    if(head==NULL){
        return head;
    }
    if(pos==0){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    Node* node=deleteNodeRec(head->next,pos-1);
    head->next=node;
    return head;
}

int findNode(Node *head, int n){
    // Write your code here.
    static int index=0;
    if(head==NULL){
        return -1;
    }
    if(head->data==n){
        return index;
    }
    index++;
    return findNode(head->next,n);
}

Node *appendLastNToFirst(Node *head, int n)
{
    
    int c=-n;
    if(head==NULL)
        return head;
    Node *temp=head;
    Node *tail=head;

    while(temp->next!=NULL)
    {
        if(c>=0)
        {
            tail=tail->next;
        }

        temp=temp->next;
        c++;
    }
    //connect 

    temp->next=head;
    head=tail->next;
    tail->next=NULL;
    return head;
    
}

Node* helper(Node* temp1,Node* temp2){
	if(temp1==NULL){
        return temp1;
    }
    
    if(temp2==NULL){
        return temp1;
    }
    else{
    	if(temp1->data==temp2->data){
        	Node* temp3=temp2->next;
            temp1->next=temp3;
            temp2->next=NULL;
            delete temp2;
			helper(temp1,temp3);
    	}    
        else{
            Node* temp=temp1;
            temp1=temp2;
            temp2=temp2->next;
            Node* node=helper(temp1,temp2);
            temp->next=node;
            return temp;
        }
    }
      
}

Node *removeDuplicates(Node *head)
{
    
    if(head==NULL){
        return head;
    }
    helper(head,head->next);
    
}

void printReverse(Node *head)
{
    //Write your code here
	if(head==NULL){
        return;
    }
    
    printReverse(head->next);
    
    cout<<head->data<<" ";
}

int length(Node* head){
    static int count=0;
    if(head==NULL){
        return count;
    }
    Node* temp=head;
	while(temp!=NULL){
		temp=temp->next;
        count++;
    }    
    return count;
}

Node *midPoint(Node *head)
{
    if(head==NULL || head->next==NULL){
        return head;
    } 
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
   }
   return slow;
}

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    Node* fhead=NULL;
    Node* ftail=NULL;
    while(head1!=NULL && head2!=NULL){
        if(head1->data<=head2->data){
            if(fhead==NULL){
                fhead=head1;
                ftail=head1;
                head1=head1->next;
            }
            else{
            	ftail->next=head1;
                ftail=ftail->next;
            	head1=head1->next;    
            }
        }
        else{
            if(fhead==NULL){
            	 fhead=head2;
                 ftail=head2;
                 head2=head2->next;
            }
            else{
            	ftail->next=head2;
                ftail=ftail->next;
            	head2=head2->next;    
            }
        }
    }
    if(head1==NULL){
    	ftail->next=head2;   
    }
    else{
        ftail->next=head1;
    }
    return fhead;
}

Node *mergeSort(Node *head)
{
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* head1=head;
    Node* head2=midPoint(head)->next;
    midPoint(head)->next=NULL;
    Node* fhead1=mergeSort(head1);
    Node* fhead2=mergeSort(head2);
    Node* fhead=mergeTwoSortedLinkedLists(fhead1,fhead2);
    return fhead;
    
}

class Pair{

    public:
    Node* head;
    Node* tail;
};

Pair reverse_LL(Node* head){
    if(head==NULL || head->next==NULL){
        Pair ans;
        ans.head=head;
        ans.tail=head;
        return ans;
    }
    Pair smallans=reverse_LL(head->next);
    smallans.tail->next=head;
    head->next=NULL;
    smallans.tail=head;
    return smallans;
}

Node *reverseLinkedListRec(Node *head)
{
    //Write your code here
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* temp=reverseLinkedListRec(head->next);
    (head->next)->next=head;
    head->next=NULL;
    return temp;
}

// REVERSING LINKED LIST ITERATIVELY
Node *reverseLinkedList(Node *head) {
    // Write your code here
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* prev=NULL;
    Node* current=head;
    Node* next1=head->next;
    while(current!=NULL){
        current->next=prev;
        prev=current;
        current=next1;
        if(current!=NULL){
        	next1=current->next;    
        }
        
    }
    return prev;
}

int findNodeRec(Node *head, int n)
{
	//Write your code here
    static int i=0;
    if(head==NULL){
        return -1;
    }
    if(head->data==n){
        return i;
    }
    i++;
    findNodeRec(head->next,n);
}

Node *evenAfterOdd(Node *head)
{
	//write your code here
    if(head==NULL || head->next==NULL){
        return head;
    }
    queue<Node*> pendingnodes;
    
    Node* temp=head;
    
    while(head!=NULL && (head->data)%2==0){
        head=head->next;
    }
    
    if(head==NULL){    // CASE WHEN ALL NO.'S ARE EVEN
        return temp;
    }
    
    while(temp!=head){
    	pendingnodes.push(temp);
        temp=temp->next;
    }
    
    Node* prev=head;
    while(temp!=NULL){
    	if((temp->data)%2==0){
        	pendingnodes.push(temp);
            prev->next=temp->next;    
            
        }    
        if((temp->data)%2!=0){
        	prev=temp;   
        }
        temp=temp->next;
    }
    
    
    while(pendingnodes.empty()==0){
        prev->next=pendingnodes.front();
        pendingnodes.pop();
        prev=prev->next;
    }
    prev->next=NULL;
    return head;
}

Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here
    if(head==NULL || (M==0 && N>0) || M<0 || N<0){
        return NULL;
    }
    if(head->next==NULL && M!=0){
        return head;
    }
    
    Node* temp=head;
    // Node* next=head->next;
    for(int i=0;i<(M-1);i++){
        if(temp->next==NULL){
            return head;
        }
        temp=temp->next;
    }
    Node* temp2=temp;
    for(int i=0;i<=N;i++){
        if(temp->next==NULL){
            temp2->next=NULL;
            return head;
        }
        temp=temp->next;
        temp2->next=temp;
    }
    
    temp2=temp;
    Node* smallans=skipMdeleteN(temp2,M,N);
    temp2->next=smallans->next;
    return head;
}

int length(Node* head){
    static int count=0;
    Node* temp=head;
    while(temp!=NULL){
    	temp=temp->next;
        count++;
    }
    return count;
}


Node *swapNodes(Node *head, int i, int j)
{
	int l1=length(head);//Write your code here
    if(head==NULL || i<0 || j<0 || i>=l1 || j>=l1 || i==j){
        return head;
    }
    Node* prev=NULL;
    Node* prev1=NULL;
    Node* prev2=NULL;
    Node* temp1=head;
    Node* temp2=head;
    Node* temp=head;
    for(int k=0;k<l1;k++){
        if(k==i){
            temp1=temp;
            prev1=prev;
        }
        if(k==j){
            temp2=temp;
            prev2=prev;
        }
        if(prev==NULL){
            prev=head;
        }
        else{
            prev=prev->next;
        }
        temp=temp->next;
    }
    
    if(prev1==NULL){
        head=temp2;
    }
    
    if(temp1==prev2){
    	if(prev1!=NULL){
            prev1->next=temp2; 
            prev2=temp2->next;
            temp2->next=temp1;
            temp1->next=prev2;
        }
        else{
            prev2=temp2->next;
            temp1->next=prev2;
            temp2->next=temp1;
            return temp2;
        }
        

        return head;
    }
    
    if(prev1!=NULL){
		prev1->next=temp2; 
    }

    if(prev2!=NULL){
        prev2->next=temp1;       
    }
    Node* temp3=temp1->next;
    temp1->next=temp2->next;
    temp2->next=temp3;
    
    return head;
}

Node *kReverse(Node *head, int k)
{
	
    if(head==NULL || head->next==NULL|| k<=1){
        return head;
    }
	
    
    Node* head1=head;
    Node* tail1=head;
    int count=1;
    while(count!=k && tail1->next!=NULL){
        tail1=tail1->next;
        count++;
    }
    Node* head2=tail1->next;
    tail1->next=NULL;
    Node* smallans=reverseLinkedListRec(head1);
    
    Node* smallans2=kReverse(head2,k);
    head1->next=smallans2;
    
    return smallans;
    
}
*/

Node *bubbleSort(Node *head)
{
	// Write your code here
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* temp=head;
    Node* prev=NULL;
    while(temp->next!=NULL){
        if(temp->data>temp->next->data){
            if(prev==NULL){
                head=temp->next;
                Node* temp1=temp->next->next;
                temp->next->next=temp;
                temp->next=temp1;
                prev=head;
            }
            else{
            	prev->next=temp->next; 
                Node* temp2=temp;
                Node* temp1=temp->next->next;
                temp->next->next=temp;
                temp->next=temp1;
                prev=temp2;
            }
        }
        else{
            prev=temp;
        	temp=temp->next;    
        }
        
    }
    prev->next=NULL;
    Node* smallans=bubbleSort(head);
    prev->next=temp;
    return smallans;
}

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

int main(){

    Node* head=take_input();
    print_node(head);
    head=bubbleSort(head);
    print_node(head);

    return 0;
}