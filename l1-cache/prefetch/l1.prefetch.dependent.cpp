#include <iostream>

using namespace std;

int main(){
    register int size = 256*1024;
    int arr[size];
    for(register int i=0; i<size; i++){
        arr[i] = i+1;
    }
    arr[size-1] = 0;
    register int j = 0;
    for(register int i=0; i<1073741824; i++){
        j = arr[j];
    }
    cout << j;
}