#include<bits/stdc++.h>
using namespace std;
struct node
{
   int data;
   node* next;
};

node* head=NULL;
node* tail=NULL;

void in(int x)
{
    node* p=new node;
    p->data=x;
    p->next=NULL;
    if(head==NULL)
    {
        head=p;
        tail=p;
    }
    else
    {
        tail->next=p;
        tail=p;
    }
}

int middle()
{
    int length=0;
    node* temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        length++;
    }
    return length;
}

void middlevalue()
{
    

    int mid_ind=middle()/2;
    node* temp=head;

    while(mid_ind--)
    {
         head=head->next;
    }
    cout<<head->data<<endl;
}




int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        in(x);
    }

    middlevalue();


}   
    


