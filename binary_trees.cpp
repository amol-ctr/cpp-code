#include<iostream>
using namespace std;
#include<queue>
#include<vector>
#include<utility>
// #include "binary_tree_node.h"
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
BinaryTreeNode<int>* take_input(){
    int rootdata;
    cout<<"enter the data: ";
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootdata);
    BinaryTreeNode<int>* leftchild=take_input();
    BinaryTreeNode<int>* rightchild=take_input();
    root->left=leftchild;
    root->right=rightchild;
    return root;
}
void printtree(BinaryTreeNode<int>* root){
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
    printtree(root->left);
    printtree(root->right);
}

BinaryTreeNode<int>* take_input_level_wise(){
    int rootdata;
    cout<<"enter the root data: ";
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int> *> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0){
        BinaryTreeNode<int>* front=pendingnodes.front();
        pendingnodes.pop();
        int leftchilddata;
        cout<<"enter the data of left child of "<<front->data<<": ";
        cin>>leftchilddata;
        if(leftchilddata!=-1){
            BinaryTreeNode<int>* child=new BinaryTreeNode<int>(leftchilddata);    
            front->left=child;
            pendingnodes.push(child);
        }
        int rightchilddata;
        cout<<"enter the data of right child of "<<front->data<<": ";
        cin>>rightchilddata;
        if(rightchilddata!=-1){
            BinaryTreeNode<int>* child2=new BinaryTreeNode<int>(rightchilddata);    
            front->right=child2;
            pendingnodes.push(child2);
        }
    }
    return root;
}

#include<utility>
#include<algorithm>
#include<climits>
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
    pair<int,int> p;
    if(root==NULL){
        p.first=INT_MAX;
        p.second=INT_MIN;
        return p;
    }
    pair<int,int> leftans=getMinAndMax(root->left);
    pair<int,int> rightans=getMinAndMax(root->right);
    int lmin=leftans.first;
    int lmax=leftans.second;
    int rmin=rightans.first;
    int rmax=rightans.second;
    
    int min1=min(min(lmin,rmin),root->data);
    int max1=max(max(lmax,rmax),root->data);
    p.first=min1;
    p.second=max1;
    return p;
}

void printtreelevelwise(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int>*>pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0){
        BinaryTreeNode<int>* front=pendingnodes.front();
        pendingnodes.pop();
        cout<<front->data<<": ";
        if(front->left!=NULL){
            cout<<"L "<<front->left->data;
            pendingnodes.push(front->left);
        }

        if(front->right!=NULL){
            cout<<" R "<<front->right->data;
            pendingnodes.push(front->right);
        }
        cout<<endl;
    }
}

int countnodes(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return 1+countnodes(root->left)+countnodes(root->right);
} 

void print_inorder(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    print_inorder(root->left);
    cout<<root->data<<" ";
    print_inorder(root->right);
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
    return NULL;
}

int height(BinaryTreeNode<int>* root){
    if(root== NULL){
        return 0;
    }
    return 1+ max(height(root->left),height(root->right));
}
// HERE ACCORDING TO OUR ASSUMPTION,FIRST WILL BE HEIGHT AND SECOND WILL BE DIAMETER 
pair<int,int> height_and_diameter(BinaryTreeNode<int>* root){
    if(root==NULL){
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int> leftans=height_and_diameter(root->left);
    pair<int,int> rightans=height_and_diameter(root->right);
    int lh=leftans.first;
    int ld=leftans.second;
    int rh=rightans.first;
    int rd=rightans.second;

    int height=1+max(lh,rh);
    int diameter=max(lh+rh,max(ld,rd));
    pair<int,int> p1;
    p1.first=height;
    p1.second=diameter;
    return p1;
}   

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(){
   /* BinaryTreeNode<int>* root=new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1=new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2=new BinaryTreeNode<int>(3);
    root->left=node1;
    root->right=node2; */
    BinaryTreeNode<int>* root=take_input_level_wise();
    printtreelevelwise(root);
    // print_inorder(root);
    //cout<<height(root);
    // cout<<countnodes(root);
    pair<int,int> p=height_and_diameter(root);
    cout<<"HEIGHT: "<<p.first<<endl;
    cout<<"DIAMETER: "<<p.second<<endl;
    return 0;
}