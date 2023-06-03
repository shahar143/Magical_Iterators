//
// Created by super on 5/25/23.
//

#ifndef MAGICAL_ITERATORS_MAGICALCONTAINER_H
#define MAGICAL_ITERATORS_MAGICALCONTAINER_H
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
    Node(): data(0), prev(nullptr), next(nullptr){}
    Node(int data): data(data), prev(nullptr), next(nullptr){}
    int operator*() const{
        return data;
    }
}node;

namespace ariel{
    class MagicalContainer {
        Node *head;
        Node *tail;
        int sizeOfContainer;
    public:
        MagicalContainer(): head(new node()), tail(head), sizeOfContainer(0){}

        virtual ~MagicalContainer() {
            Node *temp = head;
            while (temp != nullptr) {
                Node *next = temp->next;
                delete temp;
                temp = next;
            }
        };

        MagicalContainer(const MagicalContainer &other) = delete;
        MagicalContainer(MagicalContainer &&other) = delete;
        MagicalContainer &operator=(const MagicalContainer &other) = delete;
        MagicalContainer &operator=(MagicalContainer &&other) = delete;

        int size() const;

        int at(int elm) const;

        void addElement(int elm);

        int removeElement(int elm);

        void print();


        class AscendingIterator {
            MagicalContainer &container;
            Node *current_node;
            int current_indx;
        public:
            AscendingIterator(MagicalContainer &container)
                    : container(container), current_node(container.head), current_indx(0) {}

            AscendingIterator(MagicalContainer &container, Node *node, int indx)
                    : container(container), current_node(node), current_indx(indx) {}

            AscendingIterator begin() {
                return AscendingIterator(container, container.head, 0);
            }

            AscendingIterator end() {
                return AscendingIterator(container, nullptr, container.sizeOfContainer);
            }

            int operator*() const {
                return current_node->data;
            }

            bool operator==(const AscendingIterator &other) const {
                return current_node == other.current_node;
            }

            bool operator!=(const AscendingIterator &other) const {
                return current_node != other.current_node;
            }

            AscendingIterator &operator++() {
                if (current_node != nullptr) {
                    current_indx++;
                    current_node = current_node->next;
                }
                return *this;
            }

            AscendingIterator operator++(int) {
                AscendingIterator temp = *this;
                if (current_node != nullptr) {
                    current_indx++;
                    current_node = current_node->next;
                }
                return temp;
            }
        };

        class PrimeIterator {
            Node *first_prime;
            Node *last_prime;
            Node *current_prime;

            static bool isPrime(int num) {
                if (num < 2){
                    return false;
                }
                for (int i = 3; i < sqrt(num); i++) {
                    if (num % i == 0){
                        return false;
                    }
                }
                return true;
            }

        public:
            PrimeIterator() : first_prime(nullptr), last_prime(nullptr), current_prime(nullptr) {}

            PrimeIterator(const MagicalContainer &container)
                    : first_prime(nullptr), last_prime(nullptr), current_prime(nullptr) {
                Node *node = container.head;
                while (node != nullptr) {
                    if (isPrime(node->data)) {
                        first_prime = node;
                        break;
                    }
                    node = node->next;
                }
                last_prime = container.tail;
                current_prime = first_prime;
            }

            PrimeIterator begin() {
                return *this;
            }

            PrimeIterator end() {
                PrimeIterator temp = *this;
                temp.current_prime = nullptr;
                return temp;
            }

            int operator*() const {
                return current_prime->data;
            }

            bool operator==(const PrimeIterator &other) const {
                return current_prime == other.current_prime;
            }

            bool operator!=(const PrimeIterator &other) const {
                return current_prime != other.current_prime;
            }

            PrimeIterator &operator++() {
                if (current_prime != nullptr) {
                    current_prime = current_prime->next;
                    while (current_prime != nullptr && !isPrime(current_prime->data)){
                        current_prime = current_prime->next;
                    }
                }
                return *this;
            }

            PrimeIterator operator++(int) {
                PrimeIterator temp = *this;
                if (current_prime != nullptr) {
                    current_prime = current_prime->next;
                    while (current_prime != nullptr && !isPrime(current_prime->data)){
                        current_prime = current_prime->next;
                    }
                }
                return temp;
            }
        };


        class SideCrossIterator {
            Node *start_node;
            Node *end_node;
            Node *current_node;
            bool start_or_end;
        public:
            SideCrossIterator(): start_node(nullptr), end_node(nullptr), current_node(nullptr), start_or_end(false) {}

            SideCrossIterator(const MagicalContainer &container): start_node(container.head), end_node(container.tail),
                    current_node(container.head), start_or_end(false) {}

            SideCrossIterator &operator++() {
                this->current_node = this->current_node->next;
                return *this;
            }

            SideCrossIterator begin() {
                this->current_node = this->start_node;
                return *this;
            }

            SideCrossIterator end() {
                this->current_node = this->start_node;
                return *this;
            }

            int operator*() const {
                return current_node->data;
            }

            bool operator==(const SideCrossIterator &other) const {
                return current_node == other.current_node;
            }

            bool operator!=(const SideCrossIterator &other) const {
                return current_node != other.current_node;
            }

            SideCrossIterator operator++(int) {
                SideCrossIterator sci = SideCrossIterator(*this);
                this->current_node++;
                return sci;
            }

        };

    };
}

#endif //MAGICAL_ITERATORS_MAGICALCONTAINER_H
