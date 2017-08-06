#include <iostream>
#include <string>
using namespace std;

//beats 10.61%
class Solution {
public:
    string intToRoman(int num) {
        char R[2][4] = {
            { 'I', 'X', 'C', 'M' },		//1,10,100,1000
            { 'V', 'L', 'D' }				//5,50,500
        };
        int c[4];
        for (int i = 0; i < 4; ++i)
        {
            c[i] = num % 10;		//依次存放个/十/百/千位的系数
            num /= 10;
        }
        string ans = "";
        for (int i = 3; i >= 0; --i)
        {
            if (c[i] < 4)
                ans.append(c[i], R[0][i]);
            else if (c[i] == 4)
                ans = ans + R[0][i] + R[1][i];	//右边减左边
            else if (c[i] == 5)
                ans += R[1][i];
            else if (c[i] > 5 && c[i] < 9)
            {
                ans += R[1][i];
                ans.append(c[i] - 5, R[0][i]);
            }
            else if (c[i] == 9)
                ans = ans + R[0][i] + R[0][i + 1];
        }
        return ans;
    }
};

int main()
{
    int num;
    Solution ans;
    cin >> num;
    cout << ans.intToRoman(num) << endl;
    return 0;
}
