#include <iostream>

using namespace std;

class Base{
    int value;
    public:
        Base ()
        {
            this->value = 1;
        }
        void print()
        {
            cout << "First Class, value " << this->value << endl;
        }
        int sum(int a, int b)
        {
            return a + b;
        }
        int sum(int a, int b, int c)
        {
            return a + b + c;
        }     
};

int main()
{
    Base b;
    b.print();
    int ret = b.sum(5, 6);
    cout << ret <<endl;
    ret = b.sum(5, 6, 7);
    cout << ret << endl;
}