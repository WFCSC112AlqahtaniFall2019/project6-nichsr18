//
// Created by Sarah Nicholls on 10/24/19.
//

#include "LinkedList.h"
#include<iostream>
using namespace std;
LinkList::LinkList(){
    //cout<<"constructor called"<<endl;

}
LinkList::LinkList(const LinkList &list){
    //cout<<"copy constructor called"<<endl;
    Node* curr=head;
    Node* srcCurr=list.head;
    while(srcCurr!=nullptr) {
        curr= new Node;
        curr->value = (srcCurr->value);
        curr=curr->next;
        srcCurr=srcCurr->next;
    }
}
LinkList::~ LinkList(){
    //cout<<"destructor called"<<endl;
    delete head->next;
}


LinkList& LinkList:: operator=(const LinkList &rhs){
LinkList temp(rhs);
swap(head, temp.head);

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


void LinkList::InsertionSort() {
    //cout<<"insertion sort called"<<endl;
    Node* curr;
    Node* prev;
    Node* loc;
    Node* mockH =new Node;
    mockH->next=head;
    curr = head->next;
    prev=head;
    while (curr != nullptr) {
        loc=mockH;
        while(loc->next->value<curr->value){
            loc=loc->next;
        }

        if(curr->value<=prev->value) {
                prev->next = curr->next;
                curr->next = loc->next;
                loc->next = curr;
                curr = prev->next;


        }else{
            prev=curr;
            curr=curr->next;
        }

    }
    head=mockH->next;
    mockH->next=nullptr;
    delete mockH;
}


