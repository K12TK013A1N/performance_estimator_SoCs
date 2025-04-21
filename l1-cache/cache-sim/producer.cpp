/*This should produce an assembly code, with random accesses
in a large array, target is to beat the prefetcher*/
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void visitAll(vector<int>&arr, int stride_size){
  int n = arr.size();
  vector<bool>visited(n,false);
  int idx = 0;
  while(true){
    if(!visited[idx]){
      visited[idx] = true;
      int next_idx = arr[idx];
      if(!visited[next_idx]){
        idx = next_idx;
      }else{
        int i;
        for(i=0;i<n;i+=stride_size){
          if(!visited[i]){
            arr[idx] = i;
            idx = i;
            break;
          }
        }
        if(i==n){
          break;
        }
      }
    }else{
      break;
    }
  }
  arr[idx] = 0;
}

vector<int> generateRandomness(int arr_size, int stride_size){
  vector<int>arr(arr_size,-1);
  for(int i=0; i<arr_size; i+=stride_size){
    arr[i] = i;
  }
  int j=arr_size-stride_size;
  srand(time(NULL));
  while (j>=0)
  {
    int rand_idx = rand() % (j+1);
    rand_idx = rand_idx - (rand_idx%stride_size);
    swap(arr[j],arr[rand_idx]);
    j-=stride_size;
  }
  visitAll(arr,stride_size);
  return arr;
}

void init(fstream &myFile, int arr_size){
  myFile<<".section .text\n";
  myFile<<".global _start\n";
  myFile<<"_start:\n";
  myFile<<"    add x0, sp, #0\n"; //x0 stores last index i.e n-1
  myFile<<"    sub sp, sp, #" << to_string(arr_size)<<"\n";
  myFile<<"    add x1, sp, #0\n"; //x1 stores first index i.e 0
  myFile<<"    add x2, x1, #0\n";
  myFile<<"    add x3, x1, #0\n";
  myFile<<"\n";
}

void dependecyGenerator(fstream &myFile, int n, int stride_size){
  vector<int>arr = generateRandomness(n,stride_size);
  myFile<<"fill_arr:\n";
  for(int i=0; i<n; i+=stride_size){
    int imm = arr[i];
    int first_16 = arr[i] >> 16;
    int rest_16 = arr[i] ^ (first_16<<16);
    myFile<<"    mov x4, #" <<to_string(rest_16)<<"\n";
    myFile<<"    movk x4, #" <<to_string(first_16) << ", lsl #16"<<"\n";
    myFile<<"    add x3, x1, x4\n";
    myFile<<"    str x3, [x2, #0]\n";
    myFile<<"    add x2, x2, #"<<to_string(stride_size)<<"\n";
  }
}

void legalAccess(fstream &myFile, int loop_limit){
  myFile<<"    mov x3, #"<<to_string(loop_limit)<<"\n";
  myFile<<"    mov x2, #0\n";
  myFile<<"\n";
  myFile<<"run_arr:\n";
  myFile<<"    ldr x1, [x1, #0]\n";
  myFile<<"    add x2, x2, #1\n";
  myFile<<"    cmp x2, x3\n";
  myFile<<"    blt run_arr\n";
  myFile<<"\n";
}

void end(fstream &myFile){
  myFile << "end:\n";
  myFile << "    mov x8, #93\n";
  myFile << "    mov x0, #0\n";
  myFile << "    svc #0\n";
}

int main(int argc, char* argv[]){
  fstream myFile;
  myFile.open("output.S", ios::out);
  if(myFile.is_open()){
    cout << "output.S is created\n";
  }
  int arr_size;
  cout << "size of array in (bytes): ";
  cin >> arr_size;
  int stride = 64;
  int loop_limit = 1073741824;
  init(myFile,arr_size);
  /*array size must be a factor of stride size.*/
  dependecyGenerator(myFile,arr_size,stride);
  legalAccess(myFile, loop_limit);
  end(myFile);
  myFile.close();
}