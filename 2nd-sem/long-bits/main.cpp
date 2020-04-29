#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <cstring>

using namespace std;

class CLongBits{
private:
    int *p;
    int n;
public:
CLongBits(){
    p = new int[200];
    for ( int i = 0; i < 200; ++i) {
        p[i] = 0;
    }
    n = 200;
    };

CLongBits::CLongBits(CLongBits& string){
    p = new int[200];
    for ( int i = 0; i < 200; ++i)
    this->p[i] = string.p[i];
    n = string.n;
};

friend istream& operator>>(istream& in, CLongBits& str){
    char* arr = new char[200];
    in >> arr;
    int i = strlen(arr)-1, k = 0;
    while (arr[k] == '0'){
        k++;
    }
    str.n = 0;
    for (i; i >= k; --i) {
        str.p[str.n] = arr[i] - '0';
        str.n++;
    };
    str.n--;
    return in;
};

friend ostream& operator<<(ostream& out, CLongBits str){
    for (int i = str.n; i >= 0; --i) {
        out << str.p[i];
    }
    cout << endl;
    return out;
};

CLongBits& operator=(CLongBits & string) {
    if(string == (*this))
        return *this;
    int* new_p = new int[200];
    for ( int i = 0; i < 200; ++i)
        new_p[i] = string.p[i];
    delete[] p;
    p = new_p;
    n = string.n;
    return *this;
};

CLongBits operator+(CLongBits string) {
        CLongBits temp;
        int k = max(this->n, string.n);
        temp.n = k+1;
        int plus = 0;
        for (int i = 0; i <= k+1; ++i) {
            temp.p[i] = (this->p[i] + string.p[i] + plus) % 10;
            plus = (this->p[i] + string.p[i] + plus) / 10;
        }
        if (temp.p[temp.n] == 0) temp.n--;
        return temp;
};

CLongBits operator+(int shrt){
    CLongBits temp = *this;
        int plus = 0, i = 0;
        temp.p[0] += shrt;
        while (temp.p[i] / 10 > 0) {
            plus = temp.p[i] / 10;
            temp.p[i] = temp.p[i] % 10;
            i++;
            temp.p[i] += plus;
        }
        if (temp.p[temp.n] == 0) temp.n--;
        return temp;
};
    ~CLongBits(){ delete[] p;};
    CLongBits operator-(CLongBits &string);
    CLongBits operator-(int shrt);
    CLongBits operator*(CLongBits &string);
    CLongBits operator*(int shrt);
    CLongBits operator/(CLongBits &string);
    CLongBits operator/(int shrt);
    bool operator==(CLongBits &string);
    bool operator>(CLongBits &string);
    bool operator<(CLongBits &string);
    void no();
    int WhoIsHere(int);
    void Print();
};
int main() {
    CLongBits a, b;
    cin >> a >> b;
    CLongBits c = a + b;
    cout << c;
    return 0;
}
