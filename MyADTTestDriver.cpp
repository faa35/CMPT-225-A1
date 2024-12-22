/*
 * MyADTTestDriver.cpp
 *
 * Description: Test Driver for MyADT class.
 * 
 * Author: Fardin Abdulla
 * Created on: February 2, 2024
 * 
 */



#include <iostream>
#include "Profile.h"
#include "MyADT.h"

using namespace std;

// Function to print the contents of the data collection
void printCollection(MyADT &collection) {
    cout << "Current Collection:" << endl;
    collection.print();
    cout << "Total Number of Elements: " << collection.getElementCount() << endl;
    cout << "-------------------" << endl;
}

int main() {

    MyADT* myCollection = new MyADT;

    // Profiles from the assignment
    Profile profile1("abcreally", "Xiao Wong", "xw123@coldmail.com", "August 2 2003");
    Profile profile2("ihatethis!", "Louis Pace", "louis@nowhere.com", "May 25 2001");
    Profile profile3("marieLower", "Marie Lower", "marie@somewhere.ca", "July 21 1999");
    Profile profile4("mrvropdgs56", "Arwinder Singh", "meow@telthem.com", "December 17 1998");

    // Inserting profiles into the collection
    myCollection->insert(profile1);
    myCollection->insert(profile2);
    myCollection->insert(profile3);
    myCollection->insert(profile4);

    printCollection(*myCollection);

    // Additional profiles
    Profile profile5("harry" , "HARRY SINGH" , "harry@gmail.com" , "19-10-2003" );
    Profile profile6("vansh" , "VANSH BANSAL" , "vansh@.com" , "01-09-2002" );
    Profile profile7("nidhish" , "Nidhish Singh" , "nidhidh@hotmail.com" , "02-09-2003" );

    cout << "\nInserting additional profiles into the collection..." << endl;
    myCollection->insert(profile5);
    myCollection->insert(profile6);
    myCollection->insert(profile7);

    printCollection(*myCollection);

    // Test Default Constructor
    cout << "Testing Default Constructor..." << endl;

    MyADT* myEmptyCollection = new MyADT;
    cout << "Default Constructor tested." << endl;
    printCollection(*myEmptyCollection);

    // Test Search
    cout << "\nSearching for 'marieLower'..." << endl;
    Profile* foundProfile = myCollection->search(profile3); 
    if (foundProfile != nullptr) {
        cout << "Profile found: " << *foundProfile << endl;
    } else {
        cout << "Profile not found." << endl;
    }

    // Test Remove
    cout << "\nRemoving 'marieLower' from the collection..." << endl;
    if (myCollection->remove(profile3)) {
        cout << "Profile removed successfully." << endl;
    } else {
        cout << "Profile not found for removal." << endl;
    }
    printCollection(*myCollection);

    // Test RemoveAll
    cout << "\nRemoving all profiles from the collection..." << endl;
    myCollection->removeAll();
    printCollection(*myCollection);

    // Hypothetical Test for Shallow Copy
    cout << "\nHypothetical Test for Shallow Copy..." << endl;
    MyADT* myCollectionShallowCopy = myCollection; // Pointing to the original object

    // Add another profile to the hypothetical shallow copy
    Profile profile8("shallowCopyUser", "Shallow User", "shallow@user.com", "12/12/2012");
    myCollectionShallowCopy->insert(profile8);

    // Print the original and the hypothetical shallow copy
    cout << "Original Collection (would show 'shallowCopyUser' in a true shallow copy scenario):" << endl;
    printCollection(*myCollection);

    cout << "Hypothetical Shallow Copied Collection (should include 'shallowCopyUser'):" << endl;
    printCollection(*myCollectionShallowCopy);

    // Test Remove (for shallow copy)
    cout << "\nRemoving 'harry' from the shallow copy collection..." << endl;
    if (myCollectionShallowCopy->remove(profile5)) {
        cout << "Profile removed successfully from shallow copy." << endl;
    } else {
        cout << "Profile not found for removal in shallow copy." << endl;
    }
    printCollection(*myCollectionShallowCopy);

    // Test Remove (for original collection)
    cout << "\nRemoving 'harry' from the original collection..." << endl;
    if (myCollection->remove(profile5)) {
        cout << "Profile removed successfully from the original collection." << endl;
    } else {
        cout << "Profile not found for removal in the original collection." << endl;
    }
    printCollection(*myCollection);

    // Test RemoveAll (for shallow copy)
    cout << "\nRemoving all profiles from the shallow copy collection..." << endl;
    myCollectionShallowCopy->removeAll();
    printCollection(*myCollectionShallowCopy);

    // Test RemoveAll (for original collection)
    cout << "\nRemoving all profiles from the original collection..." << endl;
    myCollection->removeAll();
    printCollection(*myCollection);

    // Test Deep Copy
    cout << "\nTesting Deep Copy..." << endl;
    MyADT myCollectionCopy = *myCollection; // Create a deep copy of myCollection

    // Add another profile to the copy
    Profile profile9("deepCopyUser", "Deep User", "deep@user.com", "11/11/2011");
    myCollectionCopy.insert(profile9);

    // Print the original and the copy
    cout << "Original Collection (should not include 'deepCopyUser'):" << endl;
    printCollection(*myCollection);

    cout << "Deep Copied Collection (should include 'deepCopyUser'):" << endl;
    printCollection(myCollectionCopy);

    // Clean up
    delete myCollection;
    delete myEmptyCollection;

    return 0;
}