//
// Created by Sarah Nicholls on 10/24/19.
//
#include"Node.h"
#ifndef BINARYINSERTIONSORT_LINKEDLIST_H
#define BINARYINSERTIONSORT_LINKEDLIST_H
class LinkList {
public:
    LinkList(int l=1, int s=0);
    LinkList(const LinkList &list);
    ~ LinkList();
    LinkList& operator=(const LinkList &rhs);
    void printList() const;
    void InsertionSort();
    void insertAfter(Node*& h,Node*& c);
    Node* findLoc(int item);


private :
    Node *head; // start of the list};
    Node *curr; //used for storing value to insert
    Node *loc;  //used for iterating through list and storing where value is to be inserted



};
#endif //BINARYINSERTIONSORT_LINKEDLIST_H
