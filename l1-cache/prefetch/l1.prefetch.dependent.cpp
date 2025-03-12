#include <iostream>

using namespace std;

int main(){
    register int size = 256*1024;
    int arr[size];
    for(register int i=0; i<size; i++){
        arr[i] = i+1;
    }
    arr[size-1] = 0;
    register int n=4096; //2^12
    register int j = 0;
    for(register int i=0; i<size*n; i++){
        j = arr[j];
    }
    cout << j;
}