class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string cmp = s;
        if (isdigit(s[0]))
            reverse(s.begin(), s.end());
        else
            return false;
        if (s == cmp)
            return true;
        else
            return false;
    }
};
