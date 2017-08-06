class Solution {
public:
    long long reverse(int x)
    {
        string s = to_string(x);
        if (s[0] == '-')
            std::reverse(s.begin() + 1, s.end());
        else
            std::reverse(s.begin(), s.end());
         //judge if overflow
        long long trans = stoll(s);
        int ans = (int)stoll(s);
        if (ans != trans)
            return 0;
        return ans;
    }
};
