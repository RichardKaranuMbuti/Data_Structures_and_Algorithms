#include <iostream>

int main() {
    int var = 20;      // Declare an integer variable
    int *ptr;          // Declare a pointer to an integer

    ptr = &var;        // Initialize the pointer with the address of var

    std::cout << "Address of var: " << &var << std::endl;  // Print the address of var
    std::cout << "Address stored in ptr: " << ptr << std::endl; // Print the address stored in ptr
    std::cout << "Value of *ptr: " << *ptr << std::endl;   // Print the value pointed to by ptr

    return 0;
}
