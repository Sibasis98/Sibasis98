#include <iostream>
#include <thread>

using namespace std;

template <typename T> void print(T a)
{
  cout << a << endl;
};

class My
{
  int data;
  public: 
    My()
    {
      cout << "Hello" << endl;
      data = -1;
    }
    My(int a) : data(a){}
    //My(My &obj)
    // Incase of pointer of an object, we can not change the value of the object
    My(My &obj)
    {
      ++(obj.data);
      this->data = obj.data;
    }

    void Print(int f)
    {
      cout << "Obj " << f << "Data " << this->data << endl;
    }
};

int main()
{
  My obj;

  My obj1(5);
  obj1.Print(1);

  My obj2(obj1);
  obj2.Print(2);

  auto f = [] (int a) { cout << "Hello " << a << endl; };

  //f(10);

  thread t1(f, 10);
  t1.join();
  thread t2(&My::Print, &obj, 20);
  t2.join();

  print(1);

  return 0;
}
