#include <iostream>

using namespace std;

int main(){
    register long long size = 256*1024;
    register long long n = 4096; //2^12
    char arr[size];
    register char x;
    for(register long long i=0; i<size*n; i++){
        x = arr[i%size];
    }
    cout << x;
}