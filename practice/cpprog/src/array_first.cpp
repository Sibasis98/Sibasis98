#include <iostream>
#include <array>

using namespace std;

int main()
{
    array <int, 5>  arr1;
    array <int, 5>  arr2;
    arr1.fill(1);
    arr2.fill(2);

    arr1.swap(arr2);

    for (int a = 0; a < arr1.size(); a++)
    {
        cout << "arr1 at - " << arr1.at(a) << endl;
        cout << "arr2 - " << arr2[a] << endl;
    }

    arr1[0] = 5;
    arr1[4] = 9;
    arr1[5] = 100;

    cout << "Fornt " << arr1.front() << " Back " << arr1.back() << " 5th " << arr1.at(5) << endl;
    
    return 0;
}