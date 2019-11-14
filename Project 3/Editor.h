#pragma once
#include <string>
#include "NodeList.h"
using namespace std;

class Editor
{
public:
     Editor(string s);       // constructor
     void left();             // move cursor left one character
     void right();            // move cursor right one character
     void insertChar(char c); // insert character before cursor
     void deleteChar();       // delete character at cursor
     int getPosition();       // get current position of cursor
     void goToPosition(int i);     // go to position i
     void display();          // display string and number of characters
     void quit();             // stop program
private:
     int cursor;              // holds cursor position
     string text;             // holds string input
     NodeList list;           // list of characters
     NodeList::Iterator iterator = list.end();  // iterator to go through chars
};