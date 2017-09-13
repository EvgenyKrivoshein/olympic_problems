/*
http://www.spoj.com/problems/FRQPRIME/
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>
 
using namespace std;
 
vector<int> GeneratePrimes() 
{
  int n = 200000;
  vector<int> result;
  result.reserve(n / 2);
  vector<char> prime(n + 1, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i <= n; ++i) {
    if (prime[i]) {
      result.push_back(i);
      for (uint64_t j = i*i; j <= n; j += i)
        prime[j] = false;
    }
  }
 
  return result;
}
 
int main() 
{
  const vector<int>& primes = GeneratePrimes();
  
  int numOfTests = 0;
  cin >> numOfTests;
 
  int N = 0;
  int K = 0;
 
  for (int t = 0; t < numOfTests; ++t) {
    cin >> N;
    cin >> K;
 
    if (K == 0)
    {
      cout << (N*(uint64_t)(N - 1)) / 2 << endl;
      continue;
    }
 
    uint64_t result = 0;
    int begin = 0;
    int end = K - 1;
    for (int i = 2; primes[end] <= N; ++i) {
      result += N - primes[end] + 1;
 
      while (i >= primes[begin]) {
        ++begin;
        ++end;
      }
    }
 
    cout << result << endl;
  }
 
  return 0;
} 