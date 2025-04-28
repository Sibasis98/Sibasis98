#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;
condition_variable cv;
mutex mtx;

int i = 1;
void print_odd() {
    unique_lock<mutex> lock(mtx);
    while (i <= 10) {
        if (i % 2 != 0) {
            cout << "Odd " << i << endl;
            i++;
            cv.notify_one();
        } else {
            cv.wait(lock);
        }
    }
}

void print_even() {
    unique_lock<mutex> lock(mtx);
    while (i <= 10) {
        if (i % 2 == 0) {
            cout << "Even " << i << endl;
            i++;
            cv.notify_one();
        } else {
            cv.wait(lock);
        }
    }
}

int main()
{
  thread t2(print_odd);
  thread t1(print_even);
  t1.join();
  t2.join();

  return 0;
}
