#include <iostream>
#include <string>

using namespace std;

const int leng = 260;

int num[leng], st[leng];

bool is_digit(char c)
{
    return ((c > '0'-1) && (c < '9'+1));
}

void add(int x)
{
    int mod = x;
    for (int i = 0; i < leng; ++i)
    {
        num[i] += mod;
        mod = num[i] / 10;
        num[i] %= 10;
    }
}

void div2()
{
    int mod = 0;
    for (int i = leng; i >= 0; --i)
    {
        num[i] += mod * 10;
        mod = num[i] % 2;
        num[i] /= 2;
    }
}

void mul10()
{
    for (int i = leng - 1; i >= 1; --i)
        num[i] = num[i - 1];
    num[0] = 0;
}

bool not_a_null()
{
    for (int i = 0; i < leng; ++i)
        if (num[i] != 0)
            return 1;
    return 0;
}

string to_bin()
{
    string ans;
    if (!not_a_null())
        return "0";
    while (not_a_null())
    {
        ans += num[0] % 2 + '0';
        div2();
    }
    for (int i = 0; i < ans.length() / 2; ++i)
    {
        char temp = ans[i];
        ans[i] = ans[ans.length() - 1 - i];
        ans[ans.length() - 1 - i] = temp;
    }
    return ans;
}



void printnum()
{
    int i = leng;
    while (num[i] == 0) --i;
    while (i >= 0)
    {
        cout << num[i];
        --i;
    }
    cout << endl;
}

int main()
{
    string s;
    getline(cin, s);
    int i = 0;
    while (i < s.length())
    {
        if (is_digit(s[i]))
        {
            for (int i = 0; i < leng; ++i)
                num[i] = 0;
            while (i < s.length() && is_digit(s[i]))
            {
                mul10();
                add(s[i] - '0');
                ++i;
            }
            cout << to_bin();
        }
        else
        {
            cout << s[i];
            ++i;
        }
    }

}
