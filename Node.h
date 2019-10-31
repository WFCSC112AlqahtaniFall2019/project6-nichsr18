#ifndef NODE_H
#define NODE_H

class Node {
public:
    // Node constructor
    Node(int v = 0, Node* n = nullptr)
    {
        value = v;
        next = n;
    }
    ~Node(){
            delete next;
    }

    friend class LinkList;

    Node* next;
private:

    int value;

};

#endif //NODE_H
