#include "Editor.h"
#include <iostream>
using namespace std;

Editor::Editor(string s)         // constructor
{
     text = s;
     const char *cPtr = text.c_str();   // change string to char array
     while (*cPtr != NULL)
     {       
          list.insertBack(*cPtr);       // create list of char
          cPtr++;                       // go to next char
     }
     cursor = list.size();              // cursor position is at end of string
}                                       // 0 if empty string
void Editor::left()
{
     if (iterator == list.begin())       // do nothing if at beginning
     {
          cout << "Cursor is at the beginning (ignore).\n" << endl;
          return;
     }               
     --iterator;                         // move cursor left one character
     --cursor;
     cout << "Moved cursor left.\n" << endl;
}

void Editor::right()                  
{
     if (iterator == list.end())         // do nothing if at end
     {
          cout << "Cursor is at the end (ignore).\n" << endl;
          return;
     }
     ++iterator;                         // move cursor right one character
     ++cursor;
     cout << "Moved cursor right.\n" << endl;
}
void Editor::insertChar(char c)          // insert character c before just before cursor
{
     list.insert(iterator, c);
     cursor++;                           // move cursor one position ahead due to new char added before cursor
     cout << "Inserted character " << c << endl << endl;
}
void Editor::deleteChar()               // delete character just at the cursor
{   
     NodeList::Iterator temp = iterator;    // temp iterator to hold current position
     if (iterator == list.end())            // if not at end
     {
          cout << "Cursor is at the end. No character to delete (ignore).\n" << endl;
          return;
     }
                                        // cursor position is unchanged
     list.erase(iterator);              // delete char 
     iterator = temp;                   // give back position to original iterator
     cout << "Deleted one character.\n" << endl;
}
int Editor::getPosition()               // provide current position i of cursor
{                                       // 0 <= i <= n - 1
     return list.indexOf(iterator);
}
void Editor::goToPosition(int i)         // go to position i if i is a valid position
{                                        // 0 <= i <= n - 1
     if (i < 0 || i > list.size())
     {
          cout << "Invalid position.\n" << endl;
          return;
     }

     iterator = list.atIndex(i);
     cursor = i;                        // update cursor variable to match iterator
     cout << "Moved to position " << cursor << endl << endl;
}
void Editor::display()                  // display string and number of characters
{                                       // include spaces and cursor
     cout << "String: \"";
     if (cursor == list.size())                // if cursor is same number as size, display cursor at end
     {
          for (NodeList::Iterator it = list.begin(); it != list.end(); ++it)
          {
               cout << *it;
          }
          cout << ">";
     }
     else
     {
          int counter = 0;                   // counts number of loops 
          for (NodeList::Iterator start = list.begin(); start != list.end(); ++start)
          {                                  // counter goes through possible positions until it
               if (counter == cursor)        // matches the cursor's current position 
                    cout << ">";             // display the cursor
               cout << *start;               // display the char
               counter++;                   
          }
     }
     cout << "\"" << endl;
     cout << "Length: " << list.size() << endl << endl;
}
void Editor::quit()                     // stop the program
{
     exit(1);
}