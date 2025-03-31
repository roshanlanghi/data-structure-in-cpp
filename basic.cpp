#include <iostream>
using namespace std;
class roshan{
    public:
    int s;
    void i()
    {cout<<"gt";
    cin>>s;


}
};
int main()
{
    int arr[78];
    int n=2;
    roshan a;
 
    for(int i=0;i<n;i++){
      cout<<"accept the elements in the array:";
      cin>>arr[i];


    }
    cout<<"accept the elements in the array:";
    for(int i=0;i<n;i++){
        
        cout<<arr[i];
        cout<<""<<endl;
  
  
      }
   
    a.i();
}