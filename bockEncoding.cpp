#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    // 4B5B encoding
    string ans = "";
    for (int i = 0; i < s.size(); i += 4)
    {
        string t = s.substr(i, 4);
        if (t == "0000")
            ans += "11110";
        else if (t == "0001")
            ans += "01001";
        else if (t == "0010")
            ans += "10100";
        else if (t == "0011")
            ans += "10101";
        else if (t == "0100")
            ans += "01010";
        else if (t == "0101")
            ans += "01011";
        else if (t == "0110")
            ans += "01110";
        else if (t == "0111")
            ans += "01111";
        else if (t == "1000")
            ans += "10010";
        else if (t == "1001")
            ans += "10011";
        else if (t == "1010")
            ans += "10110";
        else if (t == "1011")
            ans += "10111";
        else if (t == "1100")
            ans += "11010";
        else if (t == "1101")
            ans += "11011";
        else if (t == "1110")
            ans += "11100";
        else if (t == "1111")
            ans += "11101";
        ans += " ";
    }
    cout << ans;

    return 0;
}
