#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node{
    int data;
    struct node*left;
    struct node*right;
// constructor
    node(int val){
        data=val;
        left=right=NULL;
    }
};

int height(struct node*node){
    if(node==NULL) return -1;   
    int lh=height(node->left);
    int rh=height(node->right);
    return max(lh,rh)+1;

}


/// using queue and stack
void zigzagq( struct node*root){
    stack<struct node*> st;
    queue<struct node*> q;
    bool ltr= true;
    q.push(root);
    struct node*curr=NULL;
    while(!q.empty()){
       int size=q.size();
       while(size){
          -- size;
             curr= q.front();
           q.pop();
           if(ltr==true){
               cout<<curr->data<<" ";
           }
           else {
               st.push(curr);
           }
           if(curr->left!=NULL)   q.push(curr->left);
           if(curr->right!=NULL)   q.push(curr->right);
           
       }
       if(ltr==false) {
           while(!st.empty())
           {    cout<<st.top()->data<<" ";
                 st.pop();
               
           }

       }
       ltr=!ltr;
    }
}



int main() 
{
 struct node*root= new node(1);
 root->left= new node(2);
 root->right=new node(7);
 root->left->left=new node(3);
 root->left->right= new node(4);
 root->left->right->left= new node(5);
 root->left->right->right= new node(6);
 root->right->right=new node(12);
zigzagq(root);
return 0;
}


