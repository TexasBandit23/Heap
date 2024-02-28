/*
Author: Tejas Pandit
Heap
Last Edited: 2/26/2024
This code allows for the user to manually enter numbers or enter numbers from a file to create a binary tree or a heap
This is a tree where each child is smaller than its parent so, the largest number is the root
The user can add numbers manually or from a file, print the tree, remove the root, or clear the while tree
PRINT function was provided in class and Vikram Vasudevan provided code for reading in from a file
*/

//imports
#include <iostream>
#include <cstring>
#include "fstream"

using namespace std;

//function prototypes
void addNum(int &count, int (&heap)[101], int inputNum);
void print(int index, int count, int end, int (heap)[101]);
void removeNum(int &count, int (&heap)[101]);

int main()
{
  //intialize variables
  bool running = true; //keep running until this is false
  char input[81]; //for user input
  int inputNum; //inputted number
  int heap[101]; //heap in the form of an array, numbers are entered here
  heap[0] = -1; //the 0th index should not be used for the heap
  int count = 1; //index of next clear space in array, increments when element is added

  //clear array/heap to start
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

    //if user types add, take in an input number and pass to add function
    if (strcmp(input, "ADD") == 0){
      int inputNum;
      cout << "Enter a number between 1-1000" << endl;
      cin >> inputNum;
      cin.ignore(80, '\n');
      addNum(count, heap, inputNum);
    }
    
    //read through numbers file and add using add function
    //help from Vikram Vasudevan
    else if (strcmp(input, "FILE") == 0){
      int intx;
      ifstream fin("numbers.txt");

      while(fin >> intx){
	addNum(count, heap, intx);
      }
    }

    //print
    else if (strcmp(input, "PRINT") == 0){
      print(1, 0, count, heap);
    }

    //remove
    else if (strcmp(input, "REMOVE") == 0){
      removeNum(count, heap);
    }

    //remove all by calling remove until array/heap is empty
    else if(strcmp(input, "REMOVE ALL") == 0){
      for (int i = count; i > 1; i--){
	removeNum(count, heap);
      }
    }

    //end function as running is false
    else if(strcmp(input, "QUIT") == 0){
      cout << "Goodbye..." << endl;
      running = false;
    }
  } 
}

//add function
void addNum(int &count, int (&heap)[101], int inputNum){
  heap[count] = inputNum; //add the number to the next open space in the array, this will be at index "count"
  //if count is 1, the array is empty and the inputted number becomes the root
  if (count == 1){
    
  }
  //otherwise need to find correct placement for number
  else{
    int index = count;
    int index1 = count;
    //keep going up the heap until we reach the root or reach a bigger number
    while(index != 1){
      index = index/2; //finds the parent of the node we are currently looking
      //if the inputted number is larger than its parent, switch them and then continue working up the tree
      if(heap[index1] > heap[index]){ 
	int temp = heap[index1];
	heap[index1] = heap[index];
	heap[index] = temp;
	index1 = index;
      }
      //if the inputted number is smaller, it is in the right spot and we can stop going up the tree
      else{
	index = 1;
      }
    }
  }
  count++; //we have added a number to the heap so increment 
}

//remove function
void removeNum(int &count, int (&heap)[101]){
  //print out the value of the root, the number to be removed
  cout << heap[1] << endl;
  int temp = heap[count - 1]; //set the last number in the array to be the root
  //cout << temp << endl;
  heap[1] = temp;
  heap[count - 1] = NULL; //clear the space the last number was in as we are removing a number
  count--; //number was removed
  int currentIndex = 1;
  //work our way down the tree
  while(currentIndex < count){
    int index1 = currentIndex * 2;
    int index2 = index1 + 1;
    int largerIndex;
    //start by finding which of the two children is bigger and saving the index
    if (heap[index1] < heap[index2]){
      largerIndex = index2;
    }
    else if (heap[index1] > heap[index2]){
      largerIndex = index1;
    }

    //if the larger child is larger than the parent, switch the two and keep working down the tree
    if(heap[currentIndex] < heap[largerIndex]){
      int tempNum = heap[currentIndex];
      heap[currentIndex] = heap[largerIndex];
      heap[largerIndex] = temp;
      currentIndex = largerIndex;
    }
    //if the parent is larger, it is in the right spot so stop working down the tree
    else if(heap[currentIndex] >= heap[largerIndex]){
      currentIndex = count;
    }
  }
}

//print function provided
void print(int index, int count, int end, int (heap)[101]){
  if (heap[1] == NULL){
    cout << "";
  }
  else{
    if((index*2) + 1 < end){
      print((index*2) + 1, count + 1, end, heap); //recursion 
    }
    for (int i = 0; i < count; i++){
      cout << '\t';
    }
    cout << heap[index] << endl;
    if((index*2) < end){
      print((index*2), count + 1, end, heap); //recursion
    }
  }
}
