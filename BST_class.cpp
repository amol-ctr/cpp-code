#include<iostream>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;
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

class BST{
    BinaryTreeNode<int>* root;
    
    public:

    BST(){
        root=NULL;
    }

    ~BST(){
        delete root;
    }
    private:
    bool hasdatahelper(int data,BinaryTreeNode<int>* node){
        if(node==NULL){
            return false;
        }
        if(node->data==data){
            return true;
        }
        if(node->data>data){
            return hasdatahelper(data,node->left);
        }
        else{
            return hasdatahelper(data,node->right);
        }
        return false;
    }

    public:
    bool hasdata(int data){
        hasdatahelper(data,root);
    }

    private:
    BinaryTreeNode<int>* insertdatahelper(int data,BinaryTreeNode<int>* node){
        if(node==NULL){
            BinaryTreeNode<int>* newnode=new BinaryTreeNode<int>(data);
            return newnode;
        }
        if(data<node->data){
            node->left=insertdatahelper(data,node->left);
            return node;
        }
        if(data>=node->data){
            node->right=insertdatahelper(data,node->right);
            return node;
        }
    }

    public:
    void insertdata(int data){
        this->root=insertdatahelper(data,this->root);
    }

    private:
    BinaryTreeNode<int>* deletedatahelper(int data,BinaryTreeNode<int>* node){
        if(node==NULL){
            return NULL;
        }
        if(data<node->data){
            node->left=deletedatahelper(data,node->left);
            return node;
        }
        if(data>node->data){
            node->right=deletedatahelper(data,node->right);
            return node;
        }
        if(data==node->data){
            if(node->left==NULL && node->right==NULL){
                delete node;
                return NULL;
            }
            else if(node->left==NULL && node->right!=NULL){
                BinaryTreeNode<int>* temp=node;
                node->right=NULL;
                delete node;
                return temp;
            }
             else if(node->left!=NULL && node->right==NULL){
                BinaryTreeNode<int>* temp=node;
                node->left=NULL;
                delete node;
                return temp;
            }
            else{
                BinaryTreeNode<int>* temp=node->right;
                while(temp->left!=NULL){
                    temp=temp->left;
                }
                int rightmin=temp->data;
                node->data=rightmin;
                node->right=deletedatahelper(rightmin,node->right);
                return node;
            }
        }
    }

    public:
    void deletedata(int data){
        root=deletedatahelper(data,root);
    }

    private:
    void printreehelper(BinaryTreeNode<int>* node){
        if(node==NULL){
            return;
        }
        cout<<node->data<<":";
        if(node->left!=NULL){
            cout<<"L:"<<node->left->data<<",";
        }
        if(node->right!=NULL){
            cout<<"R:"<<node->right->data;
        }
        cout<<endl;
        printreehelper(node->left);
        printreehelper(node->right);
    }

    public:
    void printree(){
        printreehelper(root);
    }
    private:
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

    void pairSum(BinaryTreeNode<int> *node, int sum) {
        // Write your code here
        if(node==NULL){
            return;
        }
        static int* arr;
        static int i=0;
        arr[i++]=node->data;
        pairSum(node->left,sum);
        pairSum(node->right,sum);
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
    public:
    void pairsum(int sum){
        pairSum(this->root,sum);
    }

};

int main(){
    BST b1;
    b1.insertdata(5);
    b1.insertdata(12);
    b1.insertdata(7);
    b1.insertdata(4);
    b1.insertdata(2);
    b1.printree();
    b1.deletedata(5);
    b1.printree();
    cout<<b1.hasdata(4);
    b1.pairsum(9);
    return 0;
}