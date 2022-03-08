#include "List.h"

List::List():
    head(NULL)
{
}


List::List(const List &ruleOfThree)
{
}

List &List::operator=(const List &ruleOfThree)
{
}

void List::insertAtBegin(int val)
{
    ListNode *newnode = new ListNode(val);
    newnode->next = this->head;
    this->head = newnode;
}

void List::insertAtEnd(int val)
{
    if (head == NULL)
    {
        insertAtBegin(val);
        return;
    }

    ListNode *newnode = new ListNode(val);
    ListNode *ptr = this->head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next; //Get last element untill it is not null
    }
    ptr->next = newnode;
}

void List::insertAtPos(int pos, int val)
{
    ListNode *newnode = new ListNode(val);
    if (pos == 1)
    {
        newnode->next = this->head;
        this->head = newnode;
        return;
    }
    pos--;
    ListNode *ptr = this->head;
    while (ptr != NULL && --pos)
    {
        ptr = ptr->next;
    }

    if (ptr == NULL)
        return;
    newnode->next = ptr->next;
    ptr->next = newnode;
}

void List::remove(int toBeRemoved)
{
    if (this->head == NULL)
        return; //empty
    if (this->head->data == toBeRemoved)
    {
        //first node to be removed
        ListNode *temp = this->head;
        this->head = this->head->next;
        delete (temp);
        return;
    }
    ListNode *ptr = this->head;
    while (ptr->next != NULL && ptr->next->data != toBeRemoved)
        ptr = ptr->next;
    if (ptr->next == NULL)
        return; //not found
    ListNode *temp = ptr->next;
    ptr->next = ptr->next->next;
    delete (temp);
}

void List::print()
{
    ListNode *ptr = this->head;
    while (ptr != NULL)
    {
        std::cout <<"The data is : "<<std::dec<< ptr->data <<std::endl;;
        ptr = ptr->next;
    }
   
}

List::~List()
{
    ListNode *ptr = this->head, *next = NULL;
    while (ptr != NULL)
    {
        next = ptr->next;
        delete (ptr);
        ptr = next;
    }
}