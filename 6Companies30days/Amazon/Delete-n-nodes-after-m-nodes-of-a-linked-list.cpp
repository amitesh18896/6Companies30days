// { Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert(int n1)
{
    int n,value;
    n=n1;
    struct Node *temp;
    
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp=start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp=temp->next;
        }
    }
}

 // } Driver Code Ends
/*
delete n nodes after m nodes
  The input list will have at least one element  
  Node is defined as 

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/
class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here  
        Node* temp=head;
        int count=1;
        while(temp)
        { 
            //reach the mth node
            while(temp && count<M)
            {
                temp=temp->next;
                count++;
            }
        //end of ll
        if(!temp)
        {
            break;
        }
        //mth node reached, make prev the current mth node
        Node * prev=temp;
        //move the node forward
        temp=temp->next;
        int ans=0;
        //move till n nodes
        while(temp && ans<N)
        { 
          temp=temp->next;
          ans++;
        }
        //delete those nodes and link prev to current temp
        prev->next=temp;
        }
    }
};



// { Driver Code Starts.
int main()
{
    int t,n1;
    cin>>t;
    while (t--) {
        cin>>n1;
        int m,n;
        cin>>m;
        cin>>n;
        insert(n1);
        Solution ob;
        ob.linkdelete(start,m,n);
        printList(start);
    }
    
    return 0;
}
  // } Driver Code Ends
