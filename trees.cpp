#include<iostream>
using namespace std;
class BT{
  public:
  int data;
  BT*left;
  BT*right;
  //constructor
  BT(int x)
 {
    data=x;
    left=NULL;
    right=NULL;     
}


};

BT* create()
{  
    int val;
    cout<<"accept the value from user:"<<endl;
    cin>>val;
    if(val==-1)
    {
        return NULL;
    }
    BT* newnode = new BT(val);
    cout<<"enter thhe left child of "<<val<<endl;
    newnode->left=create();
     cout<<"enter thhe right child of "<<val<<endl;
    newnode->right=create();
    return newnode;
}


void display(BT*root)
{
    if (root == NULL){
        return;
    }
    cout << root->data << " ";
    display(root->left);
    display(root->right);
}
int main()
{
    BT*root=create();
    display(root);


    return 0;
}