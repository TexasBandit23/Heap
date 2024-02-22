#include <iostream>
#include <cstring>

using namespace std;

void addNum(int &count, int (&heap)[101]);
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

  cout << "This is Heap..." << endl;
  
  while(running == true){
    cout << endl;
    cout << "Type: ADD, RANDOM, PRINT, DELETE, or QUIT" << endl;

    cin.get(input, 81);
    cin.ignore(81, '\n');

    //cout << heap[count - 1] << endl;
    
    if (strcmp(input, "ADD") == 0){
      addNum(count, heap);
    }

    else if (strcmp(input, "RANDOM") == 0){
      int numbers[25];
      fstream numbers_stream;

      numbers_stream.open("numbers.txt");
      for (int i = 0; i < 25; i++){
	int num;
	numbers_stream.getline
      }
      
    }
    
    else if (strcmp(input, "PRINT") == 0){
      print(1, 0, count, heap);
    }

    else if (strcmp(input, "DELETE") == 0){
      removeNum(count, heap);
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

void removeNum(int &count, int (&heap)[101]){
  int temp = heap[count - 1];
  //cout << temp << endl;
  heap[1] = temp;
  heap[count - 1] = -1;
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
