//
// Created by benda on 13/01/19.
//

#ifndef CLIENT_SERVER_PRIORITYQUEUE_H
#define CLIENT_SERVER_PRIORITYQUEUE_H

#include <iostream>

using namespace std;

class PriorityQueue {
    
    struct node {
        int data;
        int priority;
        struct node *next;
    };
    node *front = nullptr;

public:
    void insertPQ(int data, int priority) {
        node *temp, *ptr;
        temp = new node;
        temp->data = data;
        temp->priority = priority;

        if (front == nullptr || priority < front->priority) {
            temp->next = front;
            front = temp;

        } else {
            ptr = front;
            while (ptr->next != nullptr && ptr->next->priority <= priority)
                ptr=ptr->next;
            temp->next = ptr->next;
            ptr->next = temp;
        }
    }
    void deletePQ() {
        node *temp;

        if(front == nullptr)
            cout<<"Priority Queue Underflow\n";

        else {
            temp = front;
            cout<<"Deleted item is: "<<temp->data<<endl;
            front = front->next;
            free(temp);
        }
    }
    void displayPQ() {
        node *ptr;
        ptr = front;

        if (front == nullptr)
            cout<<"Priority Queue is empty\n";

        else {
            cout<<"Queue elements in decreasing priority are :\n";
            while(ptr != nullptr) {
                cout<<ptr->data<<" ";
                ptr = ptr->next;
            }
            cout<<endl;
        }
    }
};

#endif //CLIENT_SERVER_PRIORITYQUEUE_H
