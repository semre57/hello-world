# hello-world
 a very basic array implementation on c for unix/macos systems
 
 *-----------------------------------------------------------------------------------------------------------------------------------------
 *The code can compile for UNIX/MacOS systems. For Windows systems visit dyn-array.c file and change <unistd.h> which is preprocessor command     with <windows.h>. Also you need to use Sleep() instead of sleep().*
 
 *The capacity of array equal to 16 by default.*
 
 *When the size reaches the capacity value, the capacity of the array is automatically equalized to 2 times the current capacity.*
 -----------------------------------------------------------------------------------------------------------------------------------------*

The add function adds an element to the array and increases the size by 1.

The del function removes an element from the array and decreases the size by 1.

The get function prints the element at the entered index to standard output.

The set function replaces the element at the selected index with input.

The contains function queries whether the entered value is an element of the array. If the value is present in the array, it prints the index to standard output.

The size function prints the current size of the array to standard output.

The capacity function prints the current capacity of the array to standard output.

The shrink function frees up unused memory by setting capacity equal to size.

The clear function clears the array. It also sets capacity equal to default.

The printArray function prints all elements of the array to standard output.

The clearLoc function is used to clear allocated memory. Destroys the Array. It exit program automatically.
