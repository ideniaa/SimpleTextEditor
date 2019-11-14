#pragma once
#include <string>
using namespace std;

class NodeList
{
private:
     struct Node              // a node of the list
     {
          char elem;        // element value
          Node* prev;          // previous in list
          Node* next;         // next in list
     };
public:
     class Iterator               // an iterator for the list
     {
     public:
          char& operator*();     // reference to element
          bool operator==(const Iterator& p) const;    // compare positions
          bool operator!=(const Iterator& p) const;
          Iterator& operator++();  // move to next position
          Iterator& operator--();  // move to previous position
          friend class NodeList;   // give NodeList access
     private:
          Node* v;                 // pointer to node
          Iterator(Node* u);       // constructor for Iterator
     };
public:
     NodeList();              // constructor
     int size() const;        // list size
     bool empty() const;      // is list empty?
     Iterator begin() const;  // beginning position
     Iterator end() const;    // last position (just beyond)
     void insertFront(const char& e);  // insert at front
     void insertBack(const char& e);  // insert at rear
     void insert(const Iterator& p, const char& e);  // insert e before p
     void eraseFront();       // remove first
     void eraseBack();        // remove last
     void erase(const Iterator& p);     // remove p
     Iterator atIndex(int i) const;          // get position from index
     int indexOf(const Iterator& p) const;   // get index from position
     ~NodeList();                            // destructor
private:
     int n;                   // number of items
     Node* header;            // head-of-list sentinel
     Node* trailer;           // tail-of-list sentinel
};
