#include<iostream>
#include <queue>
using namespace std;

int main() {

  
  priority_queue<int, vector<int>, greater<int>> numbers;

  
  numbers.push(1);
  numbers.push(20);
  numbers.push(7);

  
  cout << "Top element: " << numbers.top();

  return 0;
}