#include <iostream>

//#pragma pack(push, 1)
struct St2
{
  virtual void fun3() = 0;
};

struct St1 //: public St2
{
  int var1;
  int var2;
  static char flag;  // size of the char i.e 1 is not included, as static are stored in data segment memory, so sizeof only included the non-static member and padding + vptr

  void fun1()
  {
    std::cout << "hello" << std::endl;
  }

  // due to virtual function, size will increase as it is stored the function pointer(vptr) per object wise, and no. of virtual function is not affect the size, as vptr create per object, and one vptr is created for each object
  virtual void fun2(){}
  void fun3()
  {
    std::cout << "Hi" << std::endl;
  }
};
//#pragma pack(pop)

int main()
{
  St1 st;

  std::cout << sizeof(st) << std::endl;
  std::cout << sizeof(St1) << std::endl;
  st.fun1();
//  st.fun3();

  return 0;
}
