#include <iostream>
#include <cstring>

using namespace std;

void addNum(int &count, int (&heap)[101]);
void print(int index, int count, int end, int (heap)[101]);

int main()
{
  bool running = true;
  char input[81];
  int inputNum;
  int heap[101];
  heap[0] = -1;
  int count = 1;

  cout << "This is Heap..." << endl;
  
  while(running == true){
    cout << endl;
    cout << "Type: ADD, PRINT, DELETE, or QUIT" << endl;

    cin.get(input, 81);
    cin.ignore(81, '\n');

    if (strcmp(input, "ADD") == 0){
      addNum(count, heap);
    }

    else if (strcmp(input, "PRINT") == 0){
      print(1, 0, count, heap);
    }
    
    else if(strcmp(input, "QUIT") == 0){
      running = false;
    }
  } 
}

void addNum(int &count, int (&heap)[101]){
  int inputNum;
  cout << "Enter a number between 1-1000" << endl;
  cin >> inputNum;
  cin.ignore(80, '\n');
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

void print(int index, int count, int end, int (heap)[101]){
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
