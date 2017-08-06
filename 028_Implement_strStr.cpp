#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        auto ans = haystack.find(needle);
        if (ans != string::npos)
            return ans;
        else
            return -1;
    }
};

int main()
{
    string s1,s2;   //s1是待查找的，s2是需要查找的字符串
    Solution ans;
    cin >> s1 >> s2;
    cout << ans.strStr(s1, s2) << endl;
}
