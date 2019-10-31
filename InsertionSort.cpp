#include <iostream>
#include <vector>
#include<cassert>
#include<ctime>
#include "BinaryInsertionSort.h"
#include "LinkedList.h"
#include "Node.h"
using namespace std;

int main() {

    int seed, length;
    bool validL=false;
    LinkList list;
    //cout<<"Please enter seed and length"<<endl;
    /*cin >> seed;
    while(!validL){
        cin>> length;
        if(length>0){
            validL=true;
        }else{
            cout<<"please enter length greater than 0"<<endl;
        }
    }*/
    seed=3;



    srand(seed);
    for(int i=1;i<=10000;i=i+100) {
        length=i;
        cout<<length<<" ";
        vector<int> v(length);

        // generate vector of random integers
        for (int i = 0; i < v.size(); i++) {
            int value = rand() % 100;
            v[i] = value;
            if (list.head == nullptr) {
                list.head = new Node(value);
            } else {
                Node *cursor = list.head;
                while (cursor->next != nullptr) {
                    cursor = cursor->next;
                }
                cursor->next = new Node(value);
            }
        }
        //list.printList();


        clock_t start_binaryInsertionSort = clock();
        // binary insertion sort
        insertionSort(v, v.size());
        clock_t end_binaryInsertionSort = clock();


        clock_t start_InsertionSort = clock();
        // Insertion Sort using linked lists
        list.InsertionSort();
        clock_t end_InsertionSort = clock();


        double elapsed_binaryInsertion = double(end_binaryInsertionSort - start_binaryInsertionSort) / CLOCKS_PER_SEC;
        double elapsed_InsertionSort = double(end_InsertionSort - start_InsertionSort) / CLOCKS_PER_SEC;

        cout << elapsed_binaryInsertion << " " << elapsed_InsertionSort << endl;

        // check if sorted
       /* for (int i = 1; i < v.size(); i++) {
            assert(v[i - 1] <= v[i]);
        }*/

        // print out sorted list
        for (int i = 0; i < v.size(); i++) {
            // cout << v[i] << endl;
        }


       // list.printList();
    }


}