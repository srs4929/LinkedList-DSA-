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

void insert_position(int x,int pos)
{
    node* p=new node;
    p->data=x;
    p->next=NULL;
    node* temp=head;
    if(temp==NULL) return;

    for(int i=0;i<(pos-1)&&temp!=NULL;i++)
    {
        temp=temp->next;
    }
    p->next=temp->next;
    temp->next=p;
    temp=p;
}

void display()
{
    node* ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
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

    display();
    cout<<"After insertion"<<endl;
    insert_position(78,2);
    display();


}