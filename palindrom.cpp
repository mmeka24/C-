#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
  char input[80]; // raw input from the user 
  char converted[80]; // input without the punctuation and put to lowercase 
  int counter = 0; //keeps track of num of chars in word array 
  char backward[80];// reverse the order to find if its a pali or not 
  char tempvar; //temporary variable to put chars into the arrays

    
    cout << "Enter something to see if it is a palindrome: ";
    cin.getline(input, 80); // stores user input in input array 
  
    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            tempvar = input[i];
            converted[counter++] = tolower(tempvar); // Convert to lowercase and stored in word counter 
        }
    }

    converted[counter] = '\0';
  

    // Loop below puts the input into backwards array to check if its a palindrome or not 
    for (int i = 0; converted[i] != '\0'; ++i) {
        tempvar = converted[i];
        backward[strlen(converted) - i - 1] = tempvar; // subtracting one to start at the 0 index value 

    }
    backward[counter] = '\0'; // Null-terminate the backward string

    // Compares the converted char array (all lower case) and backward char array to see if they're equal
    if (strcmp(converted, backward) == 0) {
      cout << "Palindrome\n"; // if they are equal
    } else {
      cout << "Not a palindrome\n"; // if they are not equal
    }

    return 0;
}
