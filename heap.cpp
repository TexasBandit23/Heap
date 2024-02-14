#include <iostream>
#include <cstring>

using namespace std;

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
    else if(strcmp(input, "QUIT") == 0){
      running = false;
    }
  }
  for (int i = 0; i < count; i++){
    cout << heap[i] << " " << i << endl;
  }
    
}
