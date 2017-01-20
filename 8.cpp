class Solution {
public:
    int myAtoi(string str) {
        int len = str.size();
        bool sign = false;
        char *p = &str[0];
        while (*p == ' ')
        {
            ++p;
            --len;
        }
        if (*p == '+' || *p == '-')
        {
            ++p;
            --len;
            sign = true;
        }
        long long num = 0;
        int i;
        if (len == 0)    //valid check;
            return 0;
        else
        {
            for (i = 0; i < len; ++i)
            {
                if (!isdigit(p[i]))
                    break;
                num = num * 10 + p[i] - '0';
            }
        }
        int ans = (int)num;
        if (ans != num || i > 10)
        {
            if (sign == true && *(p - 1) == '-')
                return -2147483648;
            else
                return 2147483647;
        }
        if (sign == true && *(p-1) == '-')
            ans = -ans;
        return ans;
    }
};
