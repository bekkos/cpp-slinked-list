#include <iostream>
#include <vector>
#include "linked_list.h"

using namespace std;


linked_list::linked_list(){
    head = NULL;
    tail = NULL;
}

void linked_list::add_node(string n)
{
    Node *tmp = new Node;
    tmp->value = n;
    tmp->next = NULL;

    if(head == NULL) {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tail->next;
    }

}

void linked_list::add_at_index(int index, string value)
{
    Node* tmp = new Node;
    tmp->value = value;
    tmp->next = NULL;

    if(head == NULL && index > 0)
    {
        cout << "Error inserting at specific index: List contains no elements. Inserting at position 0.";
        add_node(value);
        return;
    }

    if(index == 0)
    {
        tmp->next = head;
        head = tmp;
        return;
    }

    int i = 1; 
    Node* previous = head;
    Node* pointer = head->next;
    while(pointer != NULL)
    {
        if(index==i)
        {
            tmp->next = pointer;
            previous->next = tmp;
            return;
        }
        previous = pointer;
        pointer = pointer->next;
        i++;
    }

    if(index==i)
    {
        add_node(value);
        return;
    }

    cout << "Error: Out of bounds. \n";
}

void linked_list::replace_at_index(int index, string value)
{
    /* 
        Could just replace value,
        future proofing by swapping nodes.
    */
    
    Node* tmp = new Node;
    tmp->value = value;
    tmp->next = NULL;

    if(index == 0)
    {
        Node* toDelete = head;
        tmp->next = head->next;
        head = tmp;
        delete toDelete;
        return;
    }

    int i = 1; 
    Node* previous = head;
    Node* pointer = head->next;
    while(pointer != NULL)
    {
        if(index==i)
        {
            tmp->next = pointer->next;
            previous->next = tmp;
            delete pointer;
            return;
        }
        previous = pointer;
        pointer = pointer->next;
        i++;
    }

    cout << "Error: Out of bounds. \n";
}



void linked_list::print_list()
{
    Node* pointer = head;
    int i = 0;
    while(pointer != NULL) 
    {
        cout << to_string(i) << " - " << pointer->value << endl;
        pointer = pointer->next;
        i++;
    }
}

void linked_list::delete_at_index(int index)
{
    if(index == 0)
    {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    int i = 1;
    Node* previous = head;
    Node* pointer = head->next;
    while(pointer != NULL)
    {
        if(index == i)
        {
            previous->next = pointer->next;
            delete pointer;
            break;
        }
        previous = pointer;
        pointer = pointer->next;
        i++;
    }
}

string linked_list::get_at_index(int index)
{
    if(head == NULL)
    {
        return NULL;
    }
    
    Node* pointer = head;

    int i = 0;
    while(pointer != NULL)
    {
        if(i==index)
        {
            return pointer->value;
        }
        pointer = pointer->next;
        i++;
    }
    return NULL;
}

