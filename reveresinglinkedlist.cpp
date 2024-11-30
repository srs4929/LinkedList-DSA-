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

void rev()
{
    node* prev=NULL;
    node* curr=head;
    node* next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;//store the next node

        curr->next=prev;//reversing
        prev=curr;
        curr=next;

    }
    head=prev;
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
    cout<<"After reversing"<<endl;
    rev();
    display();
   


}