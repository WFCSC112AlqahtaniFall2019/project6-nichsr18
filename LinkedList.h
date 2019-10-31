//
// Created by Sarah Nicholls on 10/24/19.
//
#include"Node.h"
#ifndef BINARYINSERTIONSORT_LINKEDLIST_H
#define BINARYINSERTIONSORT_LINKEDLIST_H
class LinkList {
public:
    LinkList();
    LinkList(const LinkList &list);
    ~ LinkList();
    LinkList& operator=(const LinkList &rhs);
    void printList() const;
    void InsertionSort();
    Node *head;// start of the list


};
#endif //BINARYINSERTIONSORT_LINKEDLIST_H
