#include <iostream>

using namespace std;

int main(){
    register int size = 256*1024;
    int arr[size];
    for(register int i=0; i<size-16; i++){
        arr[i] = i+16;
    }
    arr[size-16] = 0;
    register int n=4096*16; //2^12
    register int j = 0;
    for(register long long i=0; i<size*n; i++){
        j = arr[j];
    }
    cout << j;
}