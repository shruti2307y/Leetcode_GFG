//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
       int l=0;
       Node *curr=head;
       // check length of list
       while(curr){
           l++;
           curr=curr->next;
       }
       if(l==1) return 1;
       int mid=l/2;
       Node *left=NULL,*end=NULL;
       curr=head;
       while(mid>1){
           curr=curr->next;
           mid--;
       }
       // assign head pointer of right list
       if(l%2==0){
           end=curr->next;
       }
       else{
           end=curr->next->next;
       }
       //reverse first half of list
       curr=head;
       Node *prev=NULL;
       Node *next=curr->next;
       mid=l/2;
       while(mid>1){
           curr->next=prev;
           prev=curr;
           curr=next;
           next=curr->next;
           mid--;
           
       }
       curr->next=prev;
       left=curr;
       //cout<<left->data<<end->data;
      while(left!=NULL&&end!=NULL){
         
          if(left->data!=end->data) return 0;
          left=left->next;
          end=end->next;
      }
      
       return 1;
       
        
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends