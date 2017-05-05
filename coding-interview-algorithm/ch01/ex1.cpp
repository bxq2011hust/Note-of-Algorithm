#include <iostream>
#include <cassert>
#include <stack>
using namespace std;

// http://wuchong.me/blog/2014/03/25/interview-link-questions/
// http://www.cnblogs.com/zhyg6516/archive/2011/03/29/1998831.html

struct Node
{
    Node* next;
    int value;
};
Node* createList(int n);
void destoryList(Node *head);
int listLength(Node * head);
void printList(Node *head);
void reversePrint(Node * head);
void reversePrint_Recursive(Node * head);
Node* mergeSortList(Node * head1,Node *head2);

Node * reverseList(Node * head);
Node * recursiveReverse(Node * head);
void deleteNode(Node *node);
Node* invKthNode(Node *head,int k);
bool hasCircle(Node *head,Node *&circleNode);
Node* findLoopPort(Node *head);
Node * middleNode(Node *head);
bool isIntersect(Node* head1,Node *head2);
Node * findIntersectNode(Node *head1,Node *head2);

int main()
{
    Node * head=createList(10);
    cout<<"len: "<<listLength(head)<<endl;
    printList(head);
    Node * invKth=invKthNode(head,5);
    cout<<invKth->value<<endl;

    reversePrint_Recursive(head);
    //reverse
    // head=reverseList(head);
    // head=recursiveReverse(head);
    
    // printList(head);    
    destoryList(head);
    return 0;
}

Node* createList(int n)
{
    if(n<=0) return NULL;
    Node *head=new Node;
    head->value=0;
    Node *tmp=head;
    for(int i=1;i<n;++i)
    {
       tmp->next=new Node;
       tmp->next->value=i;
       tmp=tmp->next;
       tmp->next=NULL;
    }
    return head;
}

void destoryList(Node *head)
{
    Node *next = NULL;
    while(head)
    {
        next=head->next;
        delete head;
        head=next;
    }
}

// length
int listLength(Node * head)
{
    if(head==NULL) return 0;
    int len=1;
    head=head->next;
    while(head)
    {
        ++len;
        head=head->next;
    }
    return len;
}

void printList(Node *head)
{
    while(head)
    {
        cout<<head->value<<" ";
        head=head->next;
    }
    cout<<endl;
}

void reversePrint(Node * head)
{
    std::stack<Node*> s;
    while(head!=NULL)
    {
        s.push(head);
        head=head->next;
    }
    Node *tmp;
    while(!s.empty())
    {
        tmp=s.top();
        std::cout<<tmp->value<<" ";
        s.pop();
    }
}

void reversePrint_Recursive(Node * head)
{
    if(head==NULL) return;
    reversePrint_Recursive(head->next);
    std::cout<<head->value<<" ";
  
}

Node * reverseList(Node * head)
{
    if(head==NULL||head->next==NULL) return head;
    Node * pre,*curr,*next;
    pre=head;
    curr=head->next;
    head->next=NULL;

    while(curr)
    {
        next=curr->next;
        curr->next=pre;
        pre=curr;
        curr=next;
    }
    return pre;
}



Node * recursiveReverse(Node * head)
{
    if(head==NULL||head->next==NULL) return head;
    Node* newHead=recursiveReverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

void deleteNode(Node *node)
{
    assert(node!=NULL);
    assert(node->next != NULL);
    Node *pNext=node->next;
    node->value=pNext->value;
    node->next=pNext->next;
    delete pNext;
}

Node* mergeSortList(Node * head1,Node *head2)
{
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    Node *newHead=NULL;
    if(head1->value < head2->value)
    {
        newHead=head1;
        head1=head1->next;
    }
    else
    {
        newHead=head2;
        head2=head2->next;
    }
    
    Node *tmp=newHead;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->value < head2->value)
        {
            tmp->next=head1;
            head1=head1->next;
        }
        else
        {
            tmp->next=head2;
            head1=head2->next;      
        }
        tmp=tmp->next;
        tmp->next=NULL;
    }
    if(head1!=NULL) tmp->next=head1;
    else if(head2!= NULL) tmp->next=head2;
    return newHead;
}

Node* invKthNode(Node *head,int k)
{
    if(head==NULL||k<0) return NULL;
    Node *p1,*p2;
    p1=p2=head;
    int i=k;
    for(;i>0 && p1!=NULL;--i)
    {
        p1=p1->next;
    }
    // 链表长度小于k
    if(i > 0)  return NULL;
    while(p1 != NULL)
    {
        p2=p2->next;
        p1=p1->next;
    }
    return p2;
}

bool hasCircle(Node *head,Node *&circleNode)
{
    Node* fast,*slow;
    fast=slow=head;
    while(fast!=NULL && slow!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)
        {
            circleNode = fast;
            return true;
        }
            
    }

    return false;
}

Node* findLoopPort(Node *head)
{
    if(head == NULL || head->next == NULL) return NULL;
    Node* fast,*slow;
    fast=slow=head;
    while(fast!=NULL && slow!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)
            break;
    }
    // 不存在环
    if(fast!=slow) return NULL;

    fast=head;
    while(fast!=head)
    {
        fast=fast->next;
        slow=slow->next;
    }
    return fast;
}

Node * middleNode(Node *head)
{
    if(head==NULL) return head;
    Node *slow,*fast;
    fast=slow=head;
    while(fast!=NULL && fast->next!=NULL &&fast->next->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

bool isIntersect(Node* head1,Node *head2)
{
    if(head1==NULL||head2==NULL) return false;
    while(head1->next!=NULL) head1=head1->next;
    while(head2->next!=NULL) head2=head2->next;
    if(head1==head2) return true;
    return false;
}

bool isIntersectWithLoop(Node *head1,Node *head2)
{
    Node *circleNode1,*circleNode2;
    if(!hasCircle(head1,circleNode1)) return false;
    if(!hasCircle(head2,circleNode2)) return false;

    Node *tmp=circleNode2->next;
    while(tmp!=circleNode2)
    {
        if(tmp == circleNode1) return true;
        tmp=tmp->next;
    }
    return false;
}

Node * findIntersectNode(Node *head1,Node *head2)
 {
     int len1=listLength(head1);
     int len2=listLength(head2);
     if(len1>len2)
     {
         for(int i=0;i<len1-len2;++i) head1=head1->next;

     }
     else
     {
         for(int i=0;i<len2-len1;++i) head2=head2->next;
     }
     while(head1!=NULL)
     {
         if(head1==head2) return head1;
         head1=head1->next;
         head2=head2->next;
     }
     return NULL;

 }
