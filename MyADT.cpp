/*
 * MyADT.cpp
 * 
 * Class Description: A linear data collection ADT.
 * 
 * Class Invariant: Data collection with the following characteristics:
 *                  - This is a value-oriented data collection and 
 *                    the elements are kept in ascending sort order of search key.
 *                  - Each element is unique (no duplicates). 
 *                  - Its data structure (CDT) is not expandable. This signifies that 
 *                    when this data collection becomes full, you do not have to resize 
 *                    its data structure (not in this Assignment 1). 
 *
 * Author: AL and Fardin Abdulla
 * Last modified on: Feb. 2024
 */



#include <iostream>
#include <cctype>
#include "MyADT.h" // Header file of MyADT file
#include "Profile.h" // Header file of Profile class



using std::cout;
using std::endl;




// Default constructor.

MyADT::MyADT() {

   // cout << "MyADT::default constructor executed!" << endl; // For testing purposes ...
   // You can also use the above to figure out when this constructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.

/* Put your code here */

    unsigned int i;

    for (i = 0; i < MAX_ALPHA; i++) {

        elements[i] = nullptr;

        elementCount[i] = 0;

    }

} 



// Copy constructor - Covered in Lab 3

MyADT::MyADT(const MyADT& rhs) {

   // cout << "MyADT::copy constructor executed!" << endl; // For testing purposes ...
   // You can also use the above to figure out when this constructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.

   /* Put your code here */

    for (unsigned int i = 0; i < MAX_ALPHA; i++) {

        if (rhs.elements[i] != nullptr) {

            elements[i] = new Profile[MAX_ELEMENTS];

            elementCount[i] = rhs.elementCount[i];

            for (unsigned int k = 0; k < elementCount[i]; k++) {

                elements[i][k] = rhs.elements[i][k];

            }

        }

        else {

            elements[i] = nullptr;

        }

    }

} 



// Overloaded assignment operator - Covered in Lab 5
// Therefore, we shall not be overloading this operator in our Assignment 1
// MyADT & MyADT::operator=(const MyADT& rhs) {
   // cout << "MyADT::operator= executed!" << endl; // For testing purposes ... 
   // You can also use the above to figure out when this overloaded assignment = operator is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.
   
   /* Put your code here */

//}



// Destructo
// Description: Destroys this object, releasing heap-allocated memory.

MyADT::~MyADT() {

   // cout << "MyADT::destructor" << endl; // For testing purposes ...
   // You can also use the above to figure out when this destructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.
   /* Put your code here */

    for (unsigned int i = 0; i < MAX_ALPHA; i++) {

        if (elements[i] != nullptr) {

            delete[] elements[i];

            elements[i] = nullptr;

        }

    }

} 



// Description: Returns the total number of elements currently stored in the data collection MyADT.
unsigned int MyADT::getElementCount() const {

    /* Put your code here */

    unsigned int totalElement = 0;

    for (unsigned int i = 0; i < MAX_ALPHA; i++) {

        totalElement += elementCount[i];

    }

    return totalElement;

}



// Description: Inserts an element in the data collection MyADT.
// Precondition: newElement must not already be in the data collection MyADT.
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
// Returns "true" when the insertion is successfull, otherwise "false".
bool MyADT::insert(const Profile& newElement) {

    char key = newElement.getSearchKey();

    int index = key - 'a'; 

    if (elements[index] == nullptr) {

        elements[index] = new Profile[MAX_ELEMENTS];

    }

    if (elementCount[index] >= MAX_ELEMENTS) {

        return false; 

    }

    unsigned int insertPosition = 0;

    while (insertPosition < elementCount[index] && elements[index][insertPosition] < newElement) {

        insertPosition++;

    }

    for (unsigned int j = elementCount[index]; j > insertPosition; j--) {

        elements[index][j] = elements[index][j - 1];

    }

    elements[index][insertPosition] = newElement;

    elementCount[index]++;

    return true;

} 



// Description: Removes an element from the data collection MyADT.
// Postcondition: toBeRemoved (if found) is removed and the appropriate elementCount is decremented.
// Returns "true" when the removal is successfull, otherwise "false".
bool MyADT::remove(const Profile& toBeRemoved) {

    /* Put your code here */

    // Remove a profile from ADT

    char searchKey = toBeRemoved.getSearchKey();

    int index = searchKey - 'a'; 

    if (elementCount[index] == 0 || elements[index] == nullptr) {

        return false;

    }

    unsigned int i;

    bool found = false;

    for (i = 0; i < elementCount[index]; i++) {

        if (elements[index][i] == toBeRemoved) {

            found = true;

            break;

        }

    }

    if (!found) {

        return false;

    }

    for (unsigned int j = i; j < elementCount[index] - 1; j++) {

        elements[index][j] = elements[index][j + 1];

    }

    elementCount[index]--;

    return true;

}



// Description: Removes all elements from the data collection MyADT.
// Postcondition: MyADT reverts back to its initialization state, i.e.,
// the state it is in once it has been constructed (once
// the default constructor has executed). 
void MyADT::removeAll() {

    /* Put your code here */

    for (unsigned int i = 0; i < MAX_ALPHA; i++) {

        if (elements[i] != nullptr) {

            delete[] elements[i];

            elements[i] = nullptr;

            elementCount[i] = 0;

        }

    }

} 



// Description: Searches for target element in the data collection MyADT.
// Returns a pointer to the element if found, otherwise, returns nullptr.
Profile* MyADT::search(const Profile& target) {

    /* Put your code here */

    char searchKey = target.getSearchKey();

    int index = searchKey - 'a';

    if (elementCount[index] == 0 || elements[index] == nullptr) {

        return nullptr;

    }

    for (unsigned int i = 0; i < elementCount[index]; i++) {

        if (elements[index][i].getSearchKey() == searchKey && elements[index][i] == target) {

            return &elements[index][i]; // Found the target

        }

    }

    return nullptr;

} 



// Description: Prints all elements stored in the data collection MyADT in ascending order of search key.
// ***For Testing Purposes - Not part of this class' public interface.***

void MyADT::print() {

    /* Put your code here */

    for (unsigned int i = 0; i < MAX_ALPHA; i++) {

        if ((elements[i]) != nullptr) {

            for (unsigned int j = 0; j < elementCount[i]; j++) {

                cout << elements[i][j];

            }

        }

    }

} 



// End of implementation file*/