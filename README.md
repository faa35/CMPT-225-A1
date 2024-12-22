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

