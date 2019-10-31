#include <iostream>
#include <vector>
#include<cassert>
#include "BinaryInsertionSort.h"
#include "LinkedList.h"
#include "Node.h"
using namespace std;

int main() {

    int seed, length;
    bool validL=false;
    LinkList list;
    cout<<"Please enter seed and length"<<endl;
    cin >> seed;
    while(!validL){
        cin>> length;
        if(length>0){
            validL=true;
        }else{
            cout<<"please enter length greater than 0"<<endl;
        }
    }



    srand(seed);

    vector<int> v(length);

    // generate vector of random integers
    for (int i = 0; i < v.size(); i++) {
        int value=rand() % 100;
        v[i] = value;
        if( list.head == nullptr){
        list.head = new Node(value);
        }else {
             Node* cursor = list.head;
            while ( cursor ->next != nullptr){
                 cursor = cursor -> next;
            }
            cursor -> next = new Node ( value );
        }
    }
    list.printList();

    // binary insertion sort
    insertionSort(v, v.size());

    // check if sorted
    for (int i = 1; i < v.size(); i++) {
        assert(v[i-1] <= v[i]);
    }

    // print out sorted list
    for (int i = 0; i < v.size(); i++) {
       // cout << v[i] << endl;
    }

    // Insertion Sort using linked lists


    list.InsertionSort();
    list.printList();



}