#include<iostream>
#include<stack>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;
    node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};
void inorderiterative(node* root)
{
    stack<node*> st;
    node* curr=root;
    while(curr != NULL || !st.empty())
  
    {
        while(curr!=NULL)
        {
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        cout<<curr->data<<" ";
        cout<<" ";
        cout<<"\n";
        curr=curr->right;
       


    }


}
int main() {

    node* root= new node(1);
    root->left= new node(3);
    root->right= new node(4);
    root->left->left= new node(5);
    root->left->right= new node(7);
    cout<<"inorder traversal"<<endl;
    inorderiterative(root);
    return 0;
}