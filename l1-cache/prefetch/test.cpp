int main(){
  register int size = 16 * 1024; // 2^14
  int arr[size]; //size of arr = 64 KB
  for(register int i=0; i<size-16; i+=16){
    arr[i] = i+16;
  }
  arr[size-16] = 0; //cycle closing
  register int access = 1073741824; //2^30
  register int j = 0;
  for(register int i=0; i<access; i++){
    j = arr[j];
  }
  return j;
}