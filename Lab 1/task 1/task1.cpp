#include <iostream>
#include <vector>
using namespace std;

int summation(const vector<int>* arr) {
    int sum = 0;
    for(int num : *arr) {
        sum += num;
    }
    return sum;
}

int maximum(const vector<int>* arr) {
    int max = (*arr)[0];
    for(int num : *arr) {
        if(num > max) max = num;
    }
    return max;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cout << "Enter element " << i+1 << ": ";
        cin >> arr[i];
    }
    cout << "Summation: " << summation(&arr) << endl;
    cout << "Maximum: " << maximum(&arr) << endl;
    return 0;
}
