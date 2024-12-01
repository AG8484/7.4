#include "vector.h"
//#include "vector.cpp"
#include <iostream>

using namespace std;

int main() 
{
    mine::Vector<int> vec;

    vec.pushback(10);
    vec.pushback(20);
    vec.pushback(30);

    cout << "foreach loop:\n";
    for (auto& value : vec) 
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
