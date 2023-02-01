#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node
{
    struct Node *next;
    string value;
};


class linked_list
{   
    private:
        Node *head, *tail;
    public:
        linked_list();
        void add_node(string n);
        void add_at_index(int index, string value);
        void replace_at_index(int index, string value);
        void print_list();
        void delete_at_index(int index);
        string get_at_index(int index);
};