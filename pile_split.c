#include <iostream>
#include <cmath>
using namespace std;

int num_piles(int n, int m, int p) {
  if (n == 0)
    return 0;
  if (n <= m)
    return 1;
  
  int arr[p];
  int retval = 0;
  
  int div = n / p;
  int rem = n % p;
  
  // handle if div == 0 later
  
  if (div != 0) {
    for (int i = 0; i < p - 1; i++)
      arr[i] = div;

    arr[p - 1] = div + rem;
    int extra = arr[p - 1] - div;

    if (extra > 1) {
      int index = p - 2;

      while (extra-- > 0) {
        arr[index]++;
        arr[p - 1]--;
      }
    }
  }
  
  else {
    for (int i = 0; i < p; i++) {
      if (i < rem)
        arr[i] = 1;
      else
        arr[i] = 0;
    }
  }
  
  for (int i = 0; i < p; i++)
    retval += num_piles(arr[i], m, p);
  
  return retval;
}

int main() {
  string input;
  cin >> input;
  int n = stoi(input);
  
  cin >> input;
  int m = stoi(input);
  
  cin >> input;
  int p = stoi(input);
  
  cout << num_piles(n, m, p);

  return 0;
}
