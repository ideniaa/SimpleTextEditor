#include "NodeList.h"

NodeList::Iterator::Iterator(Node* u)
{
     v = u;              // constructor for Node*
}
char& NodeList::Iterator::operator*()
{
     return v->elem;     // reference to the element
}
bool NodeList::Iterator::operator==(const Iterator& p) const
{
     return v == p.v;    // compare positions
}
bool NodeList::Iterator::operator!=(const Iterator& p) const
{
     return v != p.v;     
}
NodeList::Iterator& NodeList::Iterator::operator++()
{
     v = v->next;
     return *this;       // move to next position
}
NodeList::Iterator& NodeList::Iterator::operator--()
{
     v = v->prev;
     return *this;       // move to previous position
}
