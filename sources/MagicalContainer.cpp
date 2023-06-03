//
// Created by super on 5/25/23.
//

#include "MagicalContainer.hpp"
#include <unistd.h>

int ariel::MagicalContainer::size() const {
    return sizeOfContainer;
}

int ariel::MagicalContainer::at(int elm) const {
    return 1;
}

void ariel::MagicalContainer::addElement(int elm) {
    node *newNode = new node(elm);
    if (this->size() == 0 || this->head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else if (newNode->data < head->data) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else {
        node* runner = head;
        while (runner->next != nullptr && newNode->data > runner->data) {
            runner = runner->next;
        }
        if (runner->next == nullptr) {
            runner->next = newNode;
            newNode->prev = runner;
            tail = newNode;
        } else {
            newNode->next = runner;
            newNode->prev = runner->prev;
            runner->prev->next = newNode;
            runner->prev = newNode;
        }
    }
    sizeOfContainer++;
}


int ariel::MagicalContainer::removeElement(int elm) {
    return 1;
}

void ariel::MagicalContainer::print() {
    node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}