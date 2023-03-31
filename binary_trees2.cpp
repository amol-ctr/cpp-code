#include<iostream>
#include<queue>
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

BinaryTreeNode<int>* take_input(){
    int rootdata;
    cout<<"enter the data: ";
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootdata); 
    BinaryTreeNode<int>* left_child=take_input();
    BinaryTreeNode<int>* right_child=take_input();
    root->left=left_child;
    root->right=right_child;
    return root;
}

void print(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<": ";
    if(root->left!=NULL){
        cout<<"L "<<root->left->data;
    }
    if(root->right!=NULL){
        cout<<" R "<<root->right->data;
    }
    cout<<endl;
    print(root->left);
    print(root->right);
}

BinaryTreeNode<int>* take_input_level_wise(){
    int rootdata;
    cout<<"enter the root data: ";
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int>*> pending_nodes;
    pending_nodes.push(root);
    while (pending_nodes.size()!=0)
    {
        BinaryTreeNode<int>* node=pending_nodes.front();
        pending_nodes.pop();
        
        int leftchilddata,rightchilddata;
        cout<<"enter the data of left child of "<<node->data<<": ";
        cin>>leftchilddata;
        if(leftchilddata!=-1){
            BinaryTreeNode<int>* leftchild=new BinaryTreeNode<int>(leftchilddata);
            node->left=leftchild;
            pending_nodes.push(leftchild);
        }

        cout<<"enter the data of right child of "<<node->data<<": ";
        cin>>rightchilddata;
        if(rightchilddata!=-1){
            BinaryTreeNode<int>* rightchild=new BinaryTreeNode<int>(rightchilddata);
            node->right=rightchild;
            pending_nodes.push(rightchild);
        }
    }

    return root;
}

void print_tree_level_wise(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> pending_nodes;
    pending_nodes.push(root);
    while(pending_nodes.size()!=0){
        BinaryTreeNode<int>* node=pending_nodes.front();
        pending_nodes.pop();
        cout<<node->data<<": ";
        if(node->left!=NULL){
            pending_nodes.push(node->left);
            cout<<"L "<<node->left->data<<" ";
        }
        if(node->right!=NULL){
            pending_nodes.push(node->right);
            cout<<"R "<<node->right->data;
        }

        cout<<endl;
    }
}

int count_nodes(BinaryTreeNode<int>* root){
    static int count =1;
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return count;
    }
    if(root->left!=NULL){
        count++;
        count_nodes(root->left);
    }
    if(root->right!=NULL){
        count++;
        count_nodes(root->right);
    }
    return count; 
}

int height_of_tree(BinaryTreeNode<int>* root){
    int count =1;
    if(root==NULL){
        return 0;
    }
    int count1=height_of_tree(root->left);
    int count2=height_of_tree(root->right);
    return 1+((count1>count2)?(count1):(count2)); 
}

void preorder(BinaryTreeNode<int>* root){
    cout<<root->data<<" ";
    if(root->left!=NULL){
        preorder(root->left);
    }
    if(root->right!=NULL){
        preorder(root->right);
    }
}

BinaryTreeNode<int>* buildtree(int* pre,int* in,int plength,int inlength){
    if(plength==0 || inlength==0){
        return NULL;
    }
    
}
int main(){
    BinaryTreeNode<int>* root=take_input_level_wise();
    //print_tree_level_wise(root);
    //cout<<height_of_tree(root);
    preorder(root);
    return 0;
}