#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node * next;
}*first=NULL;


void create(int arr[],int n){
    int i;
    first=new node();
    struct node *t,*last;
    first->data=arr[0];
    first->next=NULL;
    last =first;

    for (int i = 1; i < n; i++)
    {
        /* code */  
        t=new node();
        t->data=arr[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }
    
}

void display(struct node *p){
    while (p!=NULL)
    {
        /* code */
        cout<<p->data;
        p=p->next;
    }
    
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int arr[]={1,5,3,6,7,8};
    create(arr,6);
    display(first);
    
    return 0;
}
