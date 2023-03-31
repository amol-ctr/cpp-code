#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }  

    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

template <typename T>
class Node{
    public:
	T data;
    Node<T> *next;
    
	Node(T data) {
        this->data = data;
    	this->next = NULL;
	}
};

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	// Write your code here
    if(root==NULL){
        return;
    }
    if(root->data>k2){
        elementsInRangeK1K2(root->left,k1,k2);
    }
    else if(root->data<k1){
        elementsInRangeK1K2(root->right,k1,k2);
    }
    else if(root->data==k1){
        cout<<root->data<<" ";
     	elementsInRangeK1K2(root->right,k1+1,k2);   
    }
    else if(root->data==k2){
     	elementsInRangeK1K2(root->left,k1,k2-1);
     	cout<<root->data<<" ";   
    }
    else{
    	elementsInRangeK1K2(root->left,k1,k2); 
        cout<<root->data<<" ";
    	elementsInRangeK1K2(root->right,k1,k2);
    }
 	
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
	// Write your code here
    if(n==0){
        return NULL;
    }
    if(n==1){
        BinaryTreeNode<int>* root=new BinaryTreeNode<int>(input[n-1]);
        return root;
    }
    if(n%2!=0){
    	int mid=n/2+1;
        BinaryTreeNode<int>* root=new BinaryTreeNode<int>(input[mid-1]);
        root->left=constructTree(input,mid-1);
        root->right=constructTree(input+mid,mid-1);
        return root;
    }
    if(n%2==0){
    	int mid=n/2; 
        BinaryTreeNode<int>* root=new BinaryTreeNode<int>(input[mid-1]);
        root->left=constructTree(input,mid-1);
        root->right=constructTree(input+mid,mid);
        return root;
    }
       
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
    	Node<int>* head=new Node<int>(root->data);
        return head;
    }
    
    if(root->left==NULL && root->right!=NULL){
    	Node<int>* head=new Node<int>(root->data);
        head->next=constructLinkedList(root->right);
        return head;
    }
    
    if(root->left!=NULL && root->right==NULL){
    	Node<int>* Lhead=constructLinkedList(root->left);
        Node<int>* temp=Lhead;
        Node<int>* head=new Node<int>(root->data);
        if(temp->next==NULL){
        	Node<int>* tail=temp;		
            tail->next=head;
        }
        else{
            while(temp->next!=NULL){
                temp=temp->next;
            }
            Node<int>* tail=temp;
            tail->next=head;   
        }
        return Lhead;
    }
    Node<int>* Lhead=constructLinkedList(root->left);
    Node<int>* head=new Node<int>(root->data);
    Lhead->next=head;
    Node<int>* Rhead=constructLinkedList(root->right);
    head->next=Rhead;
    return Lhead;
}

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	// Write your code here
    if(root==NULL){
        return NULL;
    }
    if(root->data==data){
        vector<int>* output=new vector<int>();
        output->push_back(data);
        return output;
    }
    if(root->data>data){
        if(root->left!=NULL){
        	vector<int>* leftoutput=getPath(root->left,data);
            if(leftoutput!=NULL){
            	leftoutput->push_back(root->data);
            	return leftoutput;       
            } 
        }
        else{
            return NULL;
        }
    }
    if(root->data<data){
         if(root->right!=NULL){
             vector<int>* rightoutput=getPath(root->right,data);   
             if(rightoutput!=NULL){
             	rightoutput->push_back(root->data);
             	return rightoutput; 
             }
         }
		 else{
        	return NULL;
        }        
    }
    return NULL;
}

#include<utility>

pair<Node<int>*, Node<int>*> helper(BinaryTreeNode<int>* root) {
    if(root==NULL) {
        pair<Node<int>*, Node<int>*> p;
        p.first = NULL;
        p.second = NULL;
        return p;
    }
    
    pair<Node<int>*, Node<int>*> leftAns = helper(root->left);
    pair<Node<int>*, Node<int>*> rightAns = helper(root->right);
    Node<int>* newNode = new Node<int>(root->data);
    pair<Node<int>*, Node<int>*> ans;
    
    if(leftAns.second!=NULL)
        leftAns.second->next = newNode;
    
    newNode->next = rightAns.first;
    
    if(leftAns.first!=NULL)
        ans.first=leftAns.first;
    else
        ans.first=newNode;
    
    if(rightAns.second!=NULL)
        ans.second=rightAns.second;
    else
        ans.second=newNode;
    
    return ans;
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
    
    return helper(root).first;
}

void insertDuplicateNode(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL){
        return;
    }
    BinaryTreeNode<int>* newnode=new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int>* temp=root->left;
    root->left=newnode;
    newnode->left=temp;
    insertDuplicateNode(temp);
    insertDuplicateNode(root->right);
}

int partition(int input[],int start,int end){
    int count_smaller_elements=0;
    for(int i=start+1;i<=end;i++){
        if(input[start]>input[i]){
            count_smaller_elements++;
        }
    }
    int pivot_index=start+count_smaller_elements;
    int temp=input[start];
    input[start]=input[pivot_index];
    input[pivot_index]=temp;
    int j=start;
    int k=end;
    while(j<pivot_index && k>pivot_index){
        while(input[j]<=input[pivot_index]){
            j++;
        }
        while(input[k]>input[pivot_index]){
            k--;
        }
        if(input[j]>input[pivot_index] && input[k]<input[pivot_index]){
            int t=input[j];
            input[j]=input[k];
            input[k]=t;
        }
    }
    return pivot_index;
}

void quickSort(int input[], int start, int end)
{
    if(start>=end){
        return;
    }     
    int pivot_index=partition(input,start,end);
    quickSort(input,start,pivot_index-1);
    quickSort(input,pivot_index+1,end);
}
void quickSort(int input[], int size)
{
	quickSort(input, 0, size - 1);
}


void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    if(root==NULL){
        return;
    }
    int* arr;
    static int i=0;
    arr[i++]=root->data;
    pairSum(root->left,sum);
    pairSum(root->right,sum);
    int length=(sizeof(arr)/sizeof(arr[0]));
    quickSort(arr,length);
    int j=0;
    int k=length-1;
    while(j<k){
    	if(arr[j]+arr[k]<sum){
            j++;
        }
        if(arr[j]+arr[k]>sum){
            k--;
        }
        if(arr[j]+arr[k]==sum){
            cout<<arr[j]<<" "<<arr[k]<<endl;
            j++;
            k--;
        }
    }    
}

int main(){
    

    return 0;
}   