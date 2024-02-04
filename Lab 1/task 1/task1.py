'''
Define two functions: summation and maximum both of which take an integer array of length
0<= n<= ∞. The summation function gets the sum of the integers while the maximum function
obtains the largest integer in the array.
Within the main function; declare an array of length n, obtain the n from the user, then allow the
user to enter these n integers storing them in the array. Call the two functions in turns and display
their outputs.
'''

def summation(arr):
    sum = 0
    for i in arr:
        sum += i
    return sum

def maximum(arr):
    max = arr[0]
    for i in arr:
        if i < max:
            continue
        max = i
    return max

def main():
    n = int(input("Enter the length of the array:  "))
    arr = []
    for i in range(n):
        value = int(input(f"Enter item {i+1}: "))
        arr.append(value)
    print(arr)
    print(f"Sum of all:  {summation(arr)}")
    print(f"Max of array: {maximum(arr)}")

main()