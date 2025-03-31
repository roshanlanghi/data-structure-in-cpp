#include<iostream>
using namespace std;
class matrix{
    public:
    int m[100][100];
    matrix()
    {
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<100;j++)
            {
                m[i][j]=0;
            }
        }
    }

    void edge(int x,int y)
    {
        m[x][y]=1;
        m[y][x]=1;
    }
};
class list{
    public:
    string data;
    list *next;

    list(string x)
    {
        data=x;
        next=NULL;
    }
    list(){

    }
    void insert(list *&head,list *temp)
    {
        
        if(head==NULL)
        {
            head=temp;
        }else{
            list *current=head;
            while(current->next!=NULL)
            {
                current = current->next;
            }
            current->next=temp;
        }
    }
    void display(list *current)
    {
        if(current==NULL)
        {
            return;
        }
        while(current!=NULL)
        {
            cout<<current->data<<" ";
            current=current->next;
        }
    }
};
int main()
{
    matrix am;
    int ch,City,edges,no,c1,c2;
    string arr[20],v1,v2,d;
    list *hed[20],*temp;
    list l;
    do{
        cout<<"\n1.Adjancancy matrix\n2.Output(AM)\n3.Adjacency list\n4.Output(AL)\n5.Exit\nEnter choice :";
        cin>>ch;
        switch(ch)
        {
            case 1://input AM
                    cout<<"Enter no.of Cities:";
                    cin>>City;
                    for(int i=0;i<City;i++)
                    {
                        cout<<"City-"<<i+1<<":";
                        cin>>arr[i];
                    }
                    cout<<"Enter no.of edges:";
                    cin>>edges;
                    for(int i=0;i<edges;i++)
                    {
                        cout<<"edge-"<<i+1<<endl;
                        cout<<"\tCity-1 :";
                        cin>>v1;
                        cout<<"\tCity-2 :";
                        cin>>v2;
                        for(int k=0;k<City;k++)
                        {
                            if(v1==arr[k])
                            {  
                                c1=k;
                            }
                            if(v2==arr[k])
                            {
                                c2=k;
                            }
                        }
                        
                        am.edge(c1,c2);
                    }
                    break;
            case 2://output of AM 
                   for(int i=0;i<City;i++)
                   {
                    cout<<"\t"<<arr[i];
                   }
                   cout<<"\n\n\n";
                   for(int i=0;i<City;i++)
                   {
                    cout<<arr[i]<<"\t";
                    for(int j=0;j<City;j++)
                    {
                        cout<<am.m[i][j]<<"\t";
                    }
                    cout<<"\n\n";
                   }
                   break;
            case 3://adjacency list
                   cout<<"Enter no.of Cities :";
                   cin>>City;
                   cout<<"Enter Cities :"<<endl;
                   for(int i=0;i<City;i++)
                   {
                    cout<<"City-"<<i+1<<": ";
                    cin>>arr[i];
                   }
                   for(int i=0;i<City;i++)
                   {
                    hed[i]=NULL;
                    cout<<"Enter no.of adjacent Cities for City-"<<arr[i]<<" :";
                    cin>>no;
                    for(int j=0;j<no;j++)
                    {
                        cout<<"City-"<<j+1<<" :";
                        cin>>d;
                        temp=new list(d);
                        if(hed[i]==NULL)
                        {
                            hed[i]=temp;
                        }else{
                        l.insert(hed[i],temp);
                        }
                    }
                   
                   }
                 break;

            case 4://output of AL
                   for(int i=0;i<City;i++)
                   {
                    cout<<arr[i]<<"-->";
                    l.display(hed[i]);
                    cout<<endl;
                   }
                   break;
                   
            case 5:
            cout<<"exist.........."<<endl;
            break;

        }
    }while(ch!=5);
    return 0;
}
