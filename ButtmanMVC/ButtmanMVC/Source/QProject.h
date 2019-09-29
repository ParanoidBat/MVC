#ifndef QPROJECT_H_INCLUDED
#define QPROJECT_H_INCLUDED
#include "Model.h"

struct node{
    Model model;

    node * next= NULL;
    node * prev= NULL;
};

//This is a double linked circular queue
class QProject{
    node * iterate(bool, node *); //iterate is private member only to be used within class

public:
    int size= 0; /*As, because of being circular, 'next' and 'prev' will never be null, we can't depend on
    them to iterate through the queue, we need to record its size for that purpose*/

    node *tail= NULL;

    node *head= NULL;

    node *insert(Model, node *);

    void remove(node *);

    node * searchByTitle(string, node*);

    node * searchByCast(string, node *);
};

#endif // QPROJECT_H_INCLUDED
