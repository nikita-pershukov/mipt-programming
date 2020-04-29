#include <iostream>

using namespace std;

template <typename ... Tail>
void PrintSize(Tail...){}

template <typename HeadType, typename ... Tail>
void PrintSize(HeadType h, Tail ... args)
{
    cout << sizeof(HeadType) << " : " << h << endl;
    PrintSize(args...);
}

int main()
{
    cout << "Hello World!" << endl;
    PrintSize(int(2), float(3), double(4), size_t(5));
    return 0;

}

