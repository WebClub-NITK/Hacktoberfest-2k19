/*
**  PROGRAM: XOR Linked List implementation
**
**  PURPOSE: This is a simple C++ program to
**           implement a memory effecient Linked List
**           (also called XOR Linked List) written towards
**           submission to the Hacktoberfest 2019 repository.
**
**  USAGE:   cd "path/to/file" && 
**           g++ xor_linked_list.cpp -o xor_linked_list && 
**           "path/to/file/"xor_linked_list <number of nodes>
**
**  HISTORY: Written by Aditya J Karia, Oct 2019.
*/

#include <iostream>
#include <cstdlib>

// Node Structure
struct XorNode
{
    int id;
    XorNode *link;
};

// LinkedList Class
class XorLinkedList
{
public:
    XorNode *head;
    XorNode *tail;

    XorNode *nextNode(XorNode *node, XorNode *prevNode)
    {
        return ((XorNode *)((uintptr_t)node->link ^ (uintptr_t)prevNode));
    }

    // To delete a node from the list
    void deleteList(void)
    {
        XorNode *prev, *current;

        prev = NULL;
        current = head;

        while (current)
        {
            std::cout << "Node removed: " << current->id << std::endl;
            current->link = nextNode(current, prev);

            if (prev)
                delete prev;

            if (!current->link)
            {
                delete current;
                current = NULL;

                continue;
            }

            prev = current;
            current = current->link;
        }

        std::cout << std::endl;
    }

    // Insert node after current Node
    void insertAfter(XorNode *newNode, int id)
    {
        XorNode *prev, *current, *next;

        prev = NULL;
        current = head;

        while (current)
        {
            next = nextNode(current, prev);

            if (current->id == id)
            {
                // Fix the current "next" node
                if (next)
                    next->link = (XorNode *)((uintptr_t)next->link ^ (uintptr_t)current ^ (uintptr_t)newNode);

                // Fix current node
                current->link = (XorNode *)((uintptr_t)newNode ^ (uintptr_t)next ^ (uintptr_t)current->link);

                // Fix new node
                newNode->link = (XorNode *)((uintptr_t)current ^ (uintptr_t)next);

                break;
            }

            prev = current;
            current = next;
        }
    }

    void traverse(XorNode *root)
    {
        XorNode *current, *prev, *next;

        prev = NULL;
        current = root;

        while (current)
        {
            std::cout << "Node found: " << current->id << std::endl;

            next = nextNode(current, prev);
            prev = current;
            current = next;
        }

        std::cout << std::endl;
    }

    void insert(int id)
    {
        XorNode *newNode = new XorNode;

        if (!newNode)
        {
            std::cerr << "[ERROR] Failed to insert new node." << std::endl;
            return;
        }

        newNode->id = id;
        newNode->link = NULL;

        std::cout << "Node added: " << newNode->id << std::endl;

        if (!head)
            head = tail = newNode;
        else
        {
            insertAfter(newNode, tail->id);
            tail = newNode;
        }

        return;
    }
};

int main(int argc, char *argv[])
{
    XorLinkedList *list = new XorLinkedList;

    int nodeCount;

    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <nodes>" << std::endl;
        return 1;
    }

    nodeCount = atoi(argv[1]);

    std::cout << "# Adding " << nodeCount << " nodes to list" << std::endl;

    for (int i = 0; i < nodeCount; i++)
        list->insert(i);

    std::cout << std::endl;

    std::cout << "# Forward traversal" << std::endl;
    list->traverse(list->head);

    std::cout << "# Backward traversal" << std::endl;
    list->traverse(list->tail);

    std::cout << "# Removing nodes from list" << std::endl;
    list->deleteList();

    delete list;
    list = NULL;

    return 0;
}