#include <iostream>
#include <iomanip>
#include "NodeList.h"
#include "Editor.h"
using namespace std;

int main()
{

     cout << "Idenia's Simple Text Editor\n";
     int pos;            // holds position to go to
     int currPos;        // holds current position
     int opt;            // holds user option
     string input;       // holds string input
     char letter;        // holds character to enter
     bool flag = false;  // changes to true if user input invalid
     
     do {
          cout << "Enter a starting string: ";
          getline(cin, input);                                   // get user string input
          cout << "Editing document . . .\n\n";
          flag = false;
          for (int i = 0; i < input.length(); i++)
          {
               if (!isalpha(input[i]) && !isspace(input[i]))     // only allow letters and space chars as valid
               {
                    cout << "Error: characters can only be letters or spaces.\n" << endl;
                    flag = true;
                    break;
               }
          }

     } while (flag);

     Editor txtEditor(input);                          // create new editor class with string input
     cout << endl;

     cout << setw(20) << "Editing Menu" << endl;       // display menu
     cout << "1. Left" << endl;
     cout << "2. Right" << endl;
     cout << "3. Insert character" << endl;
     cout << "4. Delete character" << endl;
     cout << "5. Get current position" << endl;
     cout << "6. Go to position" << endl;
     cout << "7. Display" << endl;
     cout << "8. Quit" << endl << endl;

     do
     {
          cout << "Enter an option: ";
          cin >> opt;                                  // get user option
          switch (opt)
          {
          case 1: txtEditor.left();
               break;
          case 2: txtEditor.right();
               break;
          case 3: cout << "Enter a character: ";
               cin >> letter;
               txtEditor.insertChar(letter);
               break;
          case 4: txtEditor.deleteChar();
               break;
          case 5: currPos = txtEditor.getPosition();
               cout << "Current position: " << currPos << endl << endl;
               break;
          case 6: cout << "Enter a position: ";
               cin >> pos;
               txtEditor.goToPosition(pos);
               break;
          case 7: txtEditor.display();
               break;
          case 8: cout << "Thanks for using my editor program.\n";
               txtEditor.quit();
               break;
          default: cout << "Invalid option. Please choose number between 1 - 8.\n\n";
          }

     } while (opt);

     return 0;
}
