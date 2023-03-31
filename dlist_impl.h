#ifndef DLIST_IMPL_H
#define DLIST_IMPL_H

#include <cstdlib>
#include <iostream>

#include "dlist.h"

using namespace std;

template <class T>
bool Dlist<T>::isEmpty() const {
    // EFFECTS: returns true if list is empy, false otherwise
    return this->first == nullptr || this->last == nullptr;
}

template <class T>
void Dlist<T>::insertFront(T *op) {
    // MODIFIES this
    // EFFECTS inserts o at the front of the list
    node *n = new node;
    n->op = op;
    n->next = this->first;
    n->prev = nullptr;
    if (this->first != nullptr) {
        this->first->prev = n;
    }
    this->first = n;
    if (this->last == nullptr) {
        this->last = n;
    }
}

template <class T>
void Dlist<T>::insertBack(T *op) {
    // MODIFIES this
    // EFFECTS inserts o at the back of the list
    node *n = new node;
    n->op = op;
    n->next = nullptr;
    n->prev = this->last;
    if (this->last != nullptr) {
        this->last->next = n;
    }
    this->last = n;
    if (this->first == nullptr) {
        this->first = n;
    }
}

template <class T>
T *Dlist<T>::removeFront() {
    // MODIFIES this
    // EFFECTS removes and returns first object from non-empty list
    //         throws an instance of emptyList if empty
    if (this->isEmpty()) {
        throw emptyList();
    }
    node *temp = this->first;
    this->first = this->first->next;
    if (this->first != nullptr) {
        this->first->prev = nullptr;
    }
    T *result = temp->op;
    delete temp;
    return result;
}

template <class T>
T *Dlist<T>::removeBack() {
    // MODIFIES this
    // EFFECTS removes and returns last object from non-empty list
    //         throws an instance of emptyList if empty
    if (this->isEmpty()) {
        throw emptyList();
    }
    node *temp = this->last;
    this->last = this->last->prev;
    if (this->last != nullptr) {
        this->last->next = nullptr;
    }
    T *result = temp->op;
    delete temp;
    return result;
}

//* Maintenance methods *//
template <class T>
Dlist<T>::Dlist() {
    // constructor
    this->first = nullptr;
    this->last = nullptr;
}

template <class T>
Dlist<T>::Dlist(const Dlist &l) {
    // copy constructor
    this->first = nullptr;
    this->last = nullptr;
    this->copyAll(l);
}

template <class T>
Dlist<T> &Dlist<T>::operator=(const Dlist &l) {
    // assignment operator
    if (this != &l) {
        this->removeAll();
        this->copyAll(l);
    }
    return *this;
}

template <class T>
Dlist<T>::~Dlist() {
    // destructor
    this->removeAll();
}

//* Utility methods *//
template <class T>
void Dlist<T>::removeAll() {
    // EFFECT: called by destructor/operator= to remove and destroy
    //         all list elements
    while (!this->isEmpty()) {
        node *temp = this->first;
        this->first = this->first->next;
        delete temp->op;
        delete temp;
    }
    this->first = nullptr;
    this->last = nullptr;
}

template <class T>
void Dlist<T>::copyAll(const Dlist &l) {
    // EFFECT: called by copy constructor/operator= to copy elements
    //         from a source instance l to this instance
    while (!l.isEmpty()) {
        this->insertBack(l.first->op);
    }
}

#endif  // DLIST_IMPL_H