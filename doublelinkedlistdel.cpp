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

void ins(int x)
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

void del()
{
    node* temp=head;
    head=head->next;
    delete(temp);
    
}

void dellast()
{
    node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    delete(temp->next);
}

void delposition(int pos)
{
    node* temp=head;
    int count=1;
    while(temp!=NULL&& count<pos)
    {
        temp=temp->next;
        count++;
    }
    if(temp==NULL) return;

    if(temp==head)
    {
       head=head->next;
       delete temp; 
    }
    if(tail==NULL)
    {
        tail=tail->prev;
        tail->next=NULL;
        delete temp;
        return ;
    }

    temp->prev->next=temp->next;
    if(temp->next!=NULL)
    {
        temp->prev->next=temp->next;
    }
    delete temp;

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
        ins(x);
    }
    cout<<"Before deletion"<<endl;

    display();
    del();
    cout<<"After deletion at the first position"<<endl;
    display();
    dellast();
    cout<<"After deletion at the last position"<<endl;
    display();
    cout<<"After deletion at a given position"<<endl;
    delposition(4);
    display();

}