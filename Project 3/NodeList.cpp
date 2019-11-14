#include "NodeList.h"

NodeList::NodeList()          // constructor
{
     n = 0;                   // intially empty
     header = new Node;       // create sentinels
     trailer = new Node;
     header->next = trailer;  // have them point to each other
     trailer->prev = header;
}
int NodeList::size() const
{
     return n;                // list size
}
bool NodeList::empty() const
{
     return (n == 0);         // is list empty?
}
NodeList::Iterator NodeList::begin() const
{
     return Iterator(header->next);     // begin position is first item
}
NodeList::Iterator NodeList::end() const
{
     return Iterator(trailer);          // end position beyond last
}
void NodeList::insert(const NodeList::Iterator& p, const char& e)
{                              // insety e before p
     Node* w = p.v;           // p's node
     Node* u = w->prev;       // p's predecessor
     Node* v = new Node;      // new node to insert
     v->elem = e;             
     v->next = w;             // link in v before w
     w->prev = v;
     v->prev = u;             // link in v after u
     u->next = v;
     n++;
}
void NodeList::insertFront(const char& e)
{
     insert(begin(), e);      // insert at front
}
void NodeList::insertBack(const char& e)
{
     insert(end(), e);        // insert at rear
}
void NodeList::erase(const Iterator& p)
{                             // remove p
     Node* v = p.v;           // node to remove
     Node* w = v->next;       // successor
     Node* u = v->prev;       // predecessor
     u->next = w;             // unlink p
     w->prev = u;
     delete v;                // delete node
     n--;                     // one fewer element
}
void NodeList::eraseFront()
{
     erase(begin());          // remove first
}
void NodeList::eraseBack()
{
     erase(--end());          // remove last
}
NodeList::Iterator NodeList::atIndex(int i) const
{                             // get position from index
     Iterator p = begin();
     for (int j = 0; j < i; j++) ++p;
     return p;
}
int NodeList::indexOf(const Iterator& p) const
{
     Iterator q = begin();
     int j = 0;
     while (q != p)
     {                        // until finding p
          ++q;                // advance and count hops
          ++j;
     }
     return j;
}
NodeList::~NodeList()         // destructor
{
     while (!empty())
          eraseFront();        // remove all but sentinels
     delete header;            // remove the sentinels
     delete trailer;
}
