#include<iostream>
using namespace std;
class BT{
public:
   int data;
   BT*left;
   BT*right;


   //constructor
   BT(int val)
   {
        data=val;
        left=NULL;
        right=NULL;



   }

};
BT *CREATE()
{
    int val;
    cin>>val;
    BT *newnode = new BT(val);
    cout<<"accept the left child of "<<val<<":";
    newnode->left=CREATE();
    cout<<"accept the right child of "<<val<<":";
    newnode->right=CREATE();

}
void display(BT *root)
{

    if(root=NULL)
    {
        return;
    }
    cout<<root->data;
    display(root->left);
    display(root->right);
}

int main()
{

    cout<<"accept the root value of binary tree:";
    BT *root=CREATE();
    display(root);
    return 0;
}