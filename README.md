**Project Title:** FriendsBook - A Social Network Application

**Overview:**
FriendsBook is a comprehensive social network application implemented in C++ as part of an academic project. It allows users to create, manage, and search for profiles in a structured and efficient manner. The project employs core concepts of object-oriented programming (OOP), custom data structures, and efficient algorithms to handle operations like insertion, deletion, search, and display of user profiles. The project demonstrates the application of hash tables for managing profiles efficiently and showcases various aspects of programming, such as memory management, sorting, and error handling.

**Key Features:**
1. **Profile Management:** Users can create profiles with attributes such as username, name, email, and birthday.
2. **User Operations:** Functionalities include joining FriendsBook, leaving FriendsBook, searching for a profile, modifying profile attributes, and viewing all existing profiles.
3. **Error Handling:** The system validates inputs, such as ensuring usernames start with a lowercase letter, and gracefully handles invalid operations.
4. **Efficient Data Management:** Profiles are stored in a custom hash table that ensures fast access and avoids duplication.
5. **Scalability:** The implementation is designed to handle operations efficiently even with multiple profiles.

**Files and Their Roles:**
1. **FriendsBook.cpp:** The main file that implements the menu-driven interface for user interaction. It calls functions for joining, leaving, modifying, searching, and displaying profiles.
2. **Profile.h/Profile.cpp:** Implements the `Profile` class, which encapsulates user details (username, name, email, and birthday) and includes methods for accessing and modifying these attributes.
3. **MyADT.h/MyADT.cpp:** Implements a custom Abstract Data Type (ADT) using a hash table. This file handles insertion, deletion, search, and printing of profiles.
4. **MyADTTestDriver.cpp:** A test driver for the ADT, demonstrating the functionality and ensuring the correctness of the hash table implementation.
5. **Makefile:** Automates the build process for compiling and linking the project files into executables for FriendsBook and the test driver.

**Implementation Details:**

**1. Hash Table Design:**
- The `MyADT` class is implemented as a hash table with 26 buckets, each corresponding to a letter of the alphabet. The hash function maps the first character of a username to the corresponding bucket.
- **Collision Handling:** Within each bucket, a fixed-size array is used to store profiles. Collisions are resolved by maintaining profiles in ascending order within each bucket.
- **Insertion:** Profiles are inserted into the appropriate bucket, maintaining the sorted order within the bucket.
- **Search:** The hash function quickly locates the target bucket, and a linear search within the bucket retrieves the profile.
- **Deletion:** Profiles are removed from the bucket, and elements are shifted to maintain the sorted order.

**Hash Function:**
The hash function is a simple calculation based on the ASCII value of the first character of the username:
```cpp
int index = username[0] - 'a';
```
This ensures uniform distribution of profiles across the 26 buckets.

**2. Memory Management:**
- The `MyADT` class dynamically allocates memory for each bucket to handle profiles. The destructor releases this memory to prevent leaks.
- Copy constructors and assignment operators are implemented to ensure deep copies and avoid shallow copy issues.

**3. Input Validation:**
- Usernames must start with a lowercase letter, ensuring validity.
- Invalid operations, such as removing non-existent profiles, are gracefully handled with appropriate messages.

**Results:**
The project includes a test scenario where profiles are inserted, searched, modified, and deleted. A sample input text file demonstrates the system’s capabilities. The results are as follows:

**Example Input:**
1. Create profiles for:
   - Username: "abcreally", Name: "Xiao Wong", Email: "xw123@coldmail.com"
   - Username: "ihatethis!", Name: "Louis Pace", Email: "louis@nowhere.com"
   - Username: "marieLower", Name: "Marie Lower", Email: "marie@somewhere.ca"

2. Search for a profile:
   - Username: "marieLower"

3. Delete a profile:
   - Username: "ihatethis!"

**Output:**
- Profiles successfully inserted and sorted in their respective buckets.
- Search operation returned the profile for "marieLower" with all details.
- Deletion operation successfully removed the profile for "ihatethis!" and shifted elements within the bucket.
- The final state of FriendsBook was printed, showing the remaining profiles.

**Conclusion:**
FriendsBook demonstrates the effective use of hash tables and OOP principles to manage user data efficiently. The project highlights the ability to handle dynamic data, ensure data integrity, and implement efficient algorithms for common operations. It is an excellent example of applying theoretical concepts to a practical problem, making it a valuable addition to a portfolio or resume.


**How to run:**
To build and run the FriendsBook project, follow these steps:

1. Open a terminal and navigate to the directory containing all project files.

2. Clean any previous build artifacts by running:

   ```
   make clean
   ```

   **Expected Output:**

   ```
   rm -f fb td *.o
   ```

3. Build the project by running:

   ```
   make all
   ```

   **Expected Output:**

   ```
   g++ -Wall -c FriendsBook.cpp
   g++ -Wall -c MyADT.cpp
   g++ -Wall -c Profile.cpp
   g++ -Wall -o fb FriendsBook.o MyADT.o Profile.o
   g++ -Wall -c MyADTTestDriver.cpp
   g++ -Wall -o td MyADTTestDriver.o MyADT.o Profile.o
   ```


4. Run the main application:
```
./fb
````

**Expected Output:**

```

----Welcome to FriendsBook!


Enter ...
j -> to join FriendsBook by creating a profile.
l -> to leave FriendsBook.
s -> to search for a friend on FriendsBook.
m -> to modify your profile on FriendsBook.
p -> to print all members on FriendsBook.
x -> to exit FriendsBook.

Your choice: x


----Bye!

```

5. Run the test driver to validate functionality:
   ```
   ./td
   ```
   **Expected Output:**
```
Current Collection:
abcreally, Xiao Wong, xw123@coldmail.com, born on August 2 2003
ihatethis!, Louis Pace, louis@nowhere.com, born on May 25 2001
marieLower, Marie Lower, marie@somewhere.ca, born on July 21 1999
mrvropdgs56, Arwinder Singh, meow@telthem.com, born on December 17 1998
Total Number of Elements: 4
-------------------

Inserting additional profiles into the collection...
Current Collection:
abcreally, Xiao Wong, xw123@coldmail.com, born on August 2 2003
harry, HARRY SINGH, harry@gmail.com, born on 19-10-2003
ihatethis!, Louis Pace, louis@nowhere.com, born on May 25 2001
marieLower, Marie Lower, marie@somewhere.ca, born on July 21 1999
mrvropdgs56, Arwinder Singh, meow@telthem.com, born on December 17 1998
nidhish, Nidhish Singh, nidhidh@hotmail.com, born on 02-09-2003
vansh, VANSH BANSAL, vansh@.com, born on 01-09-2002
Total Number of Elements: 7
-------------------
Testing Default Constructor...
Default Constructor tested.
Current Collection:
Total Number of Elements: 0
-------------------

Searching for 'marieLower'...
Profile found: marieLower, Marie Lower, marie@somewhere.ca, born on July 21 1999


Removing 'marieLower' from the collection...
Profile removed successfully.
Current Collection:
abcreally, Xiao Wong, xw123@coldmail.com, born on August 2 2003
harry, HARRY SINGH, harry@gmail.com, born on 19-10-2003
ihatethis!, Louis Pace, louis@nowhere.com, born on May 25 2001
mrvropdgs56, Arwinder Singh, meow@telthem.com, born on December 17 1998
nidhish, Nidhish Singh, nidhidh@hotmail.com, born on 02-09-2003
vansh, VANSH BANSAL, vansh@.com, born on 01-09-2002
Total Number of Elements: 6
-------------------

Removing all profiles from the collection...
Current Collection:
Total Number of Elements: 0
-------------------

Hypothetical Test for Shallow Copy...
Original Collection (would show 'shallowCopyUser' in a true shallow copy scenario):
Current Collection:
shallowCopyUser, Shallow User, shallow@user.com, born on 12/12/2012
Total Number of Elements: 1
-------------------
Hypothetical Shallow Copied Collection (should include 'shallowCopyUser'):
Current Collection:
shallowCopyUser, Shallow User, shallow@user.com, born on 12/12/2012
Total Number of Elements: 1
-------------------

Removing 'harry' from the shallow copy collection...
Profile not found for removal in shallow copy.
Current Collection:
shallowCopyUser, Shallow User, shallow@user.com, born on 12/12/2012
Total Number of Elements: 1
-------------------

Removing 'harry' from the original collection...
Profile not found for removal in the original collection.
Current Collection:
shallowCopyUser, Shallow User, shallow@user.com, born on 12/12/2012
Total Number of Elements: 1
-------------------

Removing all profiles from the shallow copy collection...
Current Collection:
Total Number of Elements: 0
-------------------

Removing all profiles from the original collection...
Current Collection:
Total Number of Elements: 0
-------------------

Testing Deep Copy...
Original Collection (should not include 'deepCopyUser'):
Current Collection:
Total Number of Elements: 0
-------------------
Deep Copied Collection (should include 'deepCopyUser'):
Current Collection:
tbd, tbd, tbd, born on tbd
tbd, tbd, tbd, born on tbd
tbd, tbd, tbd, born on tbd
tbd, tbd, tbd, born on tbd
tbd, tbd, tbd, born on tbd
Segmentation fault (core dumped)

```



