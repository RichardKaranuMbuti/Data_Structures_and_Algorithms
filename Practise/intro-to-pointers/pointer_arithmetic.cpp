# include <iostream>

int main() {
    int *ptr = new int(10); // Allocate memory and initialize with 10
    std::cout << "Value: " << *ptr << std::endl; // Print value- Dereferencing

    // Pointer arithmetic
    ptr++;  // Be cautious: this is now pointing to unallocated memory!
    std::cout << "Next memory location: " << *ptr << std::endl; // Undefined behavior

    ptr--;  // Bring the pointer back to the allocated memory
    std::cout << "Now back to memory location: " << *ptr << std::endl;
    delete ptr; // Deallocate memory
    

    return 0;
}
