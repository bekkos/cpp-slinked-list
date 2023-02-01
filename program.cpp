#include <iostream>
#include "linked_list.h"
#include <vector>


int main()
{
    linked_list list;
    for(int i = 0; i < 10; i++)
    {
        list.add_node(to_string(i));
    }
    list.print_list();
    cout << "\n\n";

    return 0;
}