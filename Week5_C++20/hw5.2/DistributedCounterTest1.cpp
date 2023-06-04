#include"DistributedCounter1.h"
#include<thread>
#include<iostream>
#include<chrono>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace mpcs;
using namespace std;
size_t const reps{100'000'000};
size_t const threadCount{10};
DistributedCounter c;

void countALot()
{
  for (size_t s = 0; s < reps; s++)
    c++;
}

int main()
{
  vector<jthread> threads;
  auto start = chrono::high_resolution_clock::now();
  for (size_t s = 0; s < threadCount; s++){
    threads.push_back(jthread(countALot));
    for (int i = 0; i<10000000; i++)
    {
      std::this_thread::yield();
      std::this_thread::yield();
      std::this_thread::yield();
    }
  }
  // for (auto &thr : threads)
  //   thr.join();
  auto end = chrono::high_resolution_clock::now();
  cout << "Count is " << c.get() << endl;
  cout << "Elapsed time is " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
  return 0;

//  count is 1000000000
// Elapsed time is 1341014ms
}