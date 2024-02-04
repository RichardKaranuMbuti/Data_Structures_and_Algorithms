# include <stdio.h>

int main () {
    int var = 20; // Declare interger variable
    int *ptr;   // Declare pointer to an integer
    ptr = &var; // Initialize pointer with address of var

    printf("address of var: %p\n", (void *)&var); //print address of var
    printf("Address stored in ptr:%p\n", (void *)ptr); // print the dddress stored in ptr 
    printf("Value of *ptr: %d\n", *ptr);  // Print the value pointed to by ptr

    return 0;
}