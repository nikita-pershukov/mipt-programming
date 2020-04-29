#include "All_include.h"
#include "Matrix.h"

int main()
{
    cout << "Write n" << endl;
    int n;
    cin >> n;
    matrix<int> novo(n, n);
    cout << "Novo is created" << endl;
    cin.get();
    for(int i = 0; i < novo.Get_M(); ++i)
        for(int j = 0; j < novo.Get_N(); ++j)
            novo.Set(i,j, i + j+1);
    cout << "Novo is counted" << endl;
    cout << novo;
    cin.get();
    matrix<int> xudonoser(n, n);
    cout << "Xudonoser is created" << endl;
    cin.get();
    for(int i = 0; i < xudonoser.Get_M(); ++i)
        for(int j = 0; j < xudonoser.Get_N(); ++j)
            xudonoser.Set(i,j, i * j+1);
    cout << "Xudonoser is counted" << endl;
    cout << xudonoser;
    cin.get();
    matrix<int> sum(n, n);
    cout << "Sum is created" << endl;
    cin.get();
    sum = novo + xudonoser;
    cout << "Sum is counted" << endl;
    cout << sum;
    cin.get();
    cout << "Sum_sled is counted" << endl;
    cout << sum.Get_sled() << endl;
    cin.get();
    cout << "Sum_det is counted" << endl;
    cout << sum.Get_det() << endl;
    cin.get();
    matrix<int> diff(n, n);
    cout << "Diff is created" << endl;
    cin.get();
    diff = novo - xudonoser;
    cout << "Diff is counted" << endl;
    cout << diff;
    cin.get();
    matrix<int> mult(n, n);
    cout << "Mult is created" << endl;
    cin.get();
    mult = novo * xudonoser;
    cout << "Mult is counted" << endl;
    cout << mult;
    cin.get();
    cout << "Mult_det is counted" << endl;
    cout << mult.Get_det() << endl;
    cin.get();
    cout << "Mult_trans is counted" << endl;
    cout << mult.Get_trans() << endl;
    cin.get();
    mult[0][0] = -666;
    cout << "Mult is edited" << endl;
    cout << mult;
    cin.get();
    return 0;
}
