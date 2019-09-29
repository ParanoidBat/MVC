#include "QProject.h"
#include "Model.h"
#include <iostream>

node* QProject::iterate(bool l_sl, node* n){ // 1 to iterate to last node, 0 for 2nd last
    node *tmp;
    if(!l_sl){
        if(n->next == tail) return n;
    }
    else
        if(n == tail) return n;
		
    tmp=iterate(l_sl,n->next);
    return tmp;
}

node* QProject::insert(Model model, node * n){
    node *tmp = new node;
    tmp->model= model;

    if(!head){
        // if its first node, it's both head and tail
        head=tmp;
        n=head;
        tail= head;

        head->next= tail;
        head->prev= tail;

        tail->next= head;
        tail->prev= head;

        size++;
        return NULL;
    }

    if(n == NULL){
        n=tmp;

        tail= n;
        tail->next= head;
        head->prev= tail;

        size++;
        return tail;
    }
    else if(tail == n){ //if its last node, make it new tail
        tail= tmp;

        tail->next= head;
        tail->prev= n;

        n->next= tail;
        head->prev= tail;

        size++;
        return n;
    }

    node *temp= insert(model, n->next);
    n->next = temp;
    temp->prev= n;

    return n;
}

void QProject::remove(node * n){ //remove tail
        node *tmp, *temp;

        tmp=iterate(1,n);//iterate to last
        temp=iterate(0,n);//iterate to 2nd last

        delete tmp;

        temp->next=head;
        tail= temp;

        size--;
}

node * QProject::searchByTitle(string title, node * n){
    node * iterate= n;

    for (int i= 0; i < size; i++){ //iterate through the whole queue to find title
        if(iterate->model.getTitle() == title) return iterate;

        iterate= iterate->next;
    }

    delete iterate;
    iterate= NULL;

    return NULL;
}

node* QProject::searchByCast(string cast, node *n){
    vector<string> vcast= n->model.getCrew().getCast();

    for(int i=0; i< vcast.size(); i++){
        if(cast == vcast[i]) return n;
    }

    return NULL; //not found
}
