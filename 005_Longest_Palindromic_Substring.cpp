#include <iostream>
#include <vector>
#include <string>
using namespace std;
//时间复杂度为ｏ(n^2)的版本
//思路:遍历所有的回文串的轴心位置，计算每个回文串的长度，找到最长串并返回，需要注意的是奇数串和偶数串的情况要分开
class Solution {
public:
    string longestPalindrome(string s) {
        auto s_len = s.size();	//字符串长度，问题的规模
        vector <int> length1(s_len);	//以每个位置为轴心的回文串的长度（奇数长）
        vector <int> length2(s_len - 1);	//以间隔位置为轴心的回文串长度（偶数长）
        int left, right;
        int m1 = 0, m2 = 0;				//分别为最初奇数串的轴心位置和最长偶数串的轴心位置
        for (int i = 0; i < s_len; ++i)
        {
            left = right = i;
            while (left >= 0 && right < s_len && s[left] == s[right])
            {
                --left;
                ++right;
            }
            length1[i] = right - left - 1;       //计算回文串长度
            if (length1[i] > length1[m1])
                m1 = i;
        }
        for (int i = 0; i < s_len - 1; ++i)
        {
            left = i;
            right = i + 1;
            while (left >= 0 && right < s_len && s[left] == s[right])
            {
                --left;
                ++right;
            }
            length2[i] = right - left - 1;
            if (length2[i] > length2[m2])
                m2 = i;
        }
        if (length1[m1] > length2[m2])
            return s.substr(m1 - length1[m1] / 2, length1[m1]);
        else
            return s.substr(m2 - length2[m2] / 2 + 1, length2[m2]);
    }
};

int main()
{
    string s;
    cin >> s;
    Solution ans;
    cout << ans.longestPalindrome(s) << endl;
    return 0;
}
