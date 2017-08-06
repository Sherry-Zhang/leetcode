//69ms,beats 24%
#include <iostream>
#include <string>
#include <map>
using namespace std;
//问题：将0-3999范围内的罗马数字转换成整数表示
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m = {
            { 'I', 1 }, { 'X', 10 }, { 'C', 100 }, { 'M', 1000 },
            { 'V', 5 }, { 'L', 50 }, { 'D', 500 }
        };
        int len = s.size();
        int num = 0;    //转换后的数字
        int tmp = m[s[0]];
        for (auto &c : s)       //对字符串的每个字符进行遍历
        {
            int cmp = m[c] / tmp;
            if (cmp > 1 && cmp <= 10)      //如果相邻字符右边代表的值比左边的大，且不超过1个数量级，就相减
                num = num - tmp + m[c] - tmp;        //需要多减一次上次循环加上的tmp
            else
                num += m[c];
            tmp = m[c];
        }
        return num;
    }
};

int main()
{
    string s;
    Solution ans;
    cin >> s;
    cout << ans.romanToInt(s) << endl;
    return 0;
}
