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

void in(int x)
{
   node* p=new node;
   p->data=x;
   p->prev=NULL;
   p->next=NULL;

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

void del(int value)
{
    node* ptr=head;
    if(ptr==NULL) return;
    int count=1;
    while(ptr!=NULL&& ptr->data!=value)
    {
        ptr=ptr->next;
    }
    ptr->prev->next=ptr->next;
    if(ptr->next!=NULL)
    {
        ptr->prev->next=ptr->next;
    }
    delete ptr;
    if(ptr==head)
    {
        head=head->next;
        head->prev=NULL;
        delete ptr;
    }
     if(ptr==tail)
     {
        tail=tail->prev;
        tail->next=NULL;
        delete ptr;
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
        in(x);
    }
    display();
    cout<<"After deletion"<<endl;
    del(3);
    display();
}