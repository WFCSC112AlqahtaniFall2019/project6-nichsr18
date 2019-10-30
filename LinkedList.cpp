//
// Created by Sarah Nicholls on 10/24/19.
//

#include "LinkedList.h"
#include<iostream>
using namespace std;
LinkList::LinkList(int l, int s){
    cout<<"constructor called"<<endl;
    srand(s);
    head=new Node(rand()%100);
    curr=head;
    loc=head;
    for(int i=0; i<l-1;i++){
        curr = curr -> next;
        curr -> next = new Node ( rand()%100 );
    }
    printList();

}
LinkList::LinkList(const LinkList &list){
    cout<<"copy constructor called"<<endl;
    head = new Node;
    curr = head;
    loc=head;
    while(curr->next!=nullptr) {
        curr= new Node;
        *curr = *(list.curr);
        curr=curr->next;
    }
}
LinkList::~ LinkList(){
    cout<<"destructor called"<<endl;
    delete head->next;
}


LinkList& LinkList:: operator=(const LinkList &rhs){
curr=head;
LinkList temp(rhs);
while(curr->next!=nullptr){
    swap(curr, temp.curr);
}
return *this;
}

void LinkList::printList() const{
    Node * cursor = head;
    if (! cursor ){
        cout<<"empty list"<<endl;
    }else {
        while (cursor) {
            cout << cursor->value << endl;
            cursor = cursor->next;
        }
    }
}

void LinkList::insertAfter(Node*& c, Node*& p){
    //Case 1: insert at head
    if(loc==head) {
        head = c;
        head->next = loc;
        loc->next = c->next;

    }//Case 2: insert in list
    else{
        Node* newNode=c;
        newNode->next=loc->next;
        loc->next=newNode;
        p->next=c->next;
        delete c;

    }
}
//finds the location for the value to be inserted after
Node* LinkList::findLoc(int item) {
    Node* prev=head;
    Node* crnt;

    if(item<prev->value) {//returns head if item should be inserted at front of the list
        return prev;
    }
    prev=prev->next;
    crnt=prev->next;
    while(crnt->next!=nullptr){

        if ((item>prev->value) && (item<=crnt->value)){
            return crnt;//returns node when item should be inserted after
        }
        prev=crnt;
        crnt=crnt->next;
    }
    return prev;//if at end of list returns last element in array
}
void LinkList::InsertionSort() {
    curr = head->next;
    Node* prev=head;
    while (curr->next != nullptr) {
        loc=findLoc(curr->value);
        insertAfter(head, prev);
        prev=curr;
        curr=curr->next;
        printList();
    }
}
