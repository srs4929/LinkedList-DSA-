#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;
    node* prev;
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
       p->next=head;
       head->prev=p;
       head=p;
       
    }
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
           insert(x);
       }
       display();
}
