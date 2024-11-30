#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* prev;
    node* next;
};
node* head=NULL;
node* tail=NULL;


void insert(int x)
{
    node* p=new node;
    p->data=x;
    p->next=NULL;
    p->prev=NULL;
    if(head==NULL)
    {
      head=p;
      tail=p;  
    }
    else
    {
        tail->next=p;
        p->prev=tail;
        tail=p;
    }
}



int ins(int x,int pos)
{
    node* p=new node;
    p->data=x;
    p->next=NULL;
    p->prev=NULL;
    if(pos==1)
    {
        p->next=head;
        head->prev=p;
        head=p;
    }
    else
    {
        node* ptr=head;
        for(int i=1;i<(pos-1)&& ptr!=NULL;i++)
        {
            ptr=ptr->next;
        }

        p->next=ptr->next;
        p->prev=ptr;
        ptr->next=p;
    }

    
}

void display()
{
    node* temp=head;
    while(temp!=NULL)
    {
       cout<<temp->data<<endl;
       temp=temp->next; 
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
        insert(x);
    }
    display();
    cout<<"After insertion at position"<<endl;
    ins(78,3);
    display();



}