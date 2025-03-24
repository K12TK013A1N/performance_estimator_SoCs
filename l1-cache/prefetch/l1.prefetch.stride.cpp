#include <iostream>
using namespace std;

int main(){
    int size = 256 * 1024; // 2^18
    int arr[size];

    // Initialize only at multiples of 16.
    for (int i = 0; i < size - 16; i += 16){
        arr[i] = i + 16;
    }
    arr[size - 16] = 0; // close the cycle

    int n = 4096 * 16; // 2^12
    int j = 0;
    unsigned long long d = static_cast<unsigned long long>(size) * n; // total iterations

    for (unsigned long long i = 0; i < d; i++){
        j = arr[j];
        // Insert a memory barrier to prevent optimization of the loop.
        asm volatile("" ::: "memory");
    }
    
    cout << j;
    return 0;
}
