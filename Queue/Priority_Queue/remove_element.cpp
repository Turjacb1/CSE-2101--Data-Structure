#include<iostream>
#include <queue>
using namespace std;

void displayPriorityQueue(priority_queue<int> pq); 

int main() {


  priority_queue<int> numbers;

 
  numbers.push(1);
  numbers.push(20);
  numbers.push(7);
 
  cout << "Initial: ";
  displayPriorityQueue(numbers);
  
  numbers.pop();
  cout << "Final : ";
  displayPriorityQueue(numbers);

  return 0;
}


void displayPriorityQueue(priority_queue<int> pq) {
  while(!pq.empty()) {
    cout << pq.top() << ", ";   
    pq.pop();
  }

  cout << endl;
}