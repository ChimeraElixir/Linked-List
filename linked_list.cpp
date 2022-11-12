#include <bits/stdc++.h>
using namespace std;

struct node{
    struct node *prev;
    int roll_no;
    char name[20];
    int year;
    char section:
    char from[20];
    struct node * next;
}*start=NULL;

typedef struct node node;

node* create(){
    node * newnode;
    newnode=(node*)malloc(sizeof(node));
    cout<<"Enter roll no\n";
    cin>>newnode->roll_no;
    cout<<"Enter Name\n";
    gets(newnode->name);
    cout<<"Enter year\n";
    cin>>newnode->year;
    cout<<"Enter section\n";
    cin>>newnode->section;
    cout>>"Enter which state you came from\n";
    gets(newnode->from);
    return newnode;
    
}

void create_a_list_of_n_node(int n){
    
}

void insert_at_begining(){

    node newnode=create();
    if(start){
        start=newnode();
    }
    else{
        start->prev=newnode;
        newnode->prev=start;
        newnode->next=start;
        start=newnode;
    }
}
void insert_at_end{
    node newnode=create();
    node* temp;
    temp=start;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}
void insert_at_mid(){
    if(start){
        cout<<"Empty Record";
        return;
    }
    else{
        node newnode=create();
        node *temp=start;
        int temp_roll_no;
        cout>>"Enter roll no\n";
        cin>>temp_roll_no;

        while (temp->roll_no!=temp_roll_no)
        {
            temp=temp->next;
        }
        temp->next->prev=newnode;
        nenode->next=temp->next;
        temp->next=nennode;
        newnode->prev=temp;
    }   
}

void
   

    


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    
    
    return 0;
}
