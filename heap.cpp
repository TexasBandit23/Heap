/*
Author: Tejas Pandit
Heap
Last Edited: 2/26/2024
This code allows for the user to manually enter numbers or enter numbers from a file to create a binary tree or a heap
This is a tree where each child is smaller than its parent so, the largest number is the root
The user can add numbers manually or from a file, print the tree, remove the root, or clear the while tree
PRINT function was provided in class and Vikram Vasudevan provided code for reading in from a file
*/


#include <iostream>
#include <cstring>
#include "fstream"

using namespace std;

void addNum(int &count, int (&heap)[101], int inputNum);
void print(int index, int count, int end, int (heap)[101]);
void removeNum(int &count, int (&heap)[101]);

int main()
{
  bool running = true;
  char input[81];
  int inputNum;
  int heap[101];
  heap[0] = -1;
  int count = 1;

  for (int i = 0; i < 101; i++){
    heap[i] = NULL;
  }

  cout << "This is Heap..." << endl;

  cout << "Type ADD to add a number to the heap manually..." << endl;
  cout << "Type FILE to add in numbers from a file..." << endl;
  cout << "Type PRINT to print the heap..." << endl;
  cout << "Type REMOVE to remove the head/root number..." << endl;
  cout << "Type REMOVE ALL to clear the heap..."  << endl;
  cout << "Type QUIT to end the program." << endl;

  
  while(running == true){
    cout << endl;
    cout << "Type: ADD, FILE, PRINT, REMOVE, REMOVE ALL, or QUIT" << endl;

    cin.get(input, 81);
    cin.ignore(81, '\n');

    //cout << heap[count - 1] << endl;
    
    if (strcmp(input, "ADD") == 0){
      int inputNum;
      cout << "Enter a number between 1-1000" << endl;
      cin >> inputNum;
      cin.ignore(80, '\n');
      addNum(count, heap, inputNum);
    }
    else if (strcmp(input, "FILE") == 0){
      int intx;
      ifstream fin("numbers.txt");

      while(fin >> intx){
	addNum(count, heap, intx);
      }
    }
    else if (strcmp(input, "PRINT") == 0){
      print(1, 0, count, heap);
    }

    else if (strcmp(input, "REMOVE") == 0){
      removeNum(count, heap);
    }
    else if(strcmp(input, "REMOVE ALL") == 0){
      for (int i = count; i > 1; i--){
	removeNum(count, heap);
      }
    }
    
    else if(strcmp(input, "QUIT") == 0){
      cout << "Goodbye..." << endl;
      running = false;
    }
  } 
}

void addNum(int &count, int (&heap)[101], int inputNum){
  heap[count] = inputNum;
  if (count == 1){
    
  }
  else{
    int index = count;
    int index1 = count;
    while(index != 1){
      index = index/2;
      if(heap[index1] > heap[index]){
	int temp = heap[index1];
	heap[index1] = heap[index];
	heap[index] = temp;
	index1 = index;
      }
      else{
	index = 1;
      }
    }
  }
  count++;
}

void removeNum(int &count, int (&heap)[101]){
  cout << heap[1] << endl;
  int temp = heap[count - 1];
  //cout << temp << endl;
  heap[1] = temp;
  heap[count - 1] = NULL;
  count--;
  int currentIndex = 1;
  while(currentIndex < count){
    int index1 = currentIndex * 2;
    int index2 = index1 + 1;
    int largerIndex;
    if (heap[index1] < heap[index2]){
      largerIndex = index2;
    }
    else if (heap[index1] > heap[index2]){
      largerIndex = index1;
    }

    if(heap[currentIndex] < heap[largerIndex]){
      int tempNum = heap[currentIndex];
      heap[currentIndex] = heap[largerIndex];
      heap[largerIndex] = temp;
      currentIndex = largerIndex;
    }
    else if(heap[currentIndex] >= heap[largerIndex]){
      currentIndex = count;
    }
  }
}

void print(int index, int count, int end, int (heap)[101]){
  if (heap[1] == NULL){
    cout << "";
  }
  else{
    if((index*2) + 1 < end){
      print((index*2) + 1, count + 1, end, heap); 
    }
    for (int i = 0; i < count; i++){
      cout << '\t';
    }
    cout << heap[index] << endl;
    if((index*2) < end){
      print((index*2), count + 1, end, heap);
    }
  }
}
