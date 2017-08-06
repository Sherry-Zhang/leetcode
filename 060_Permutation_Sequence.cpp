//简单粗暴next_permutation解法
class Solution {
public:
    string getPermutation(int n, int k) {
        string nums;
        for(int i = 1;i <= n;++i)
            nums.push_back(i + '0');
        for(int i= 1; i < k;++i)
            next_perm(nums, n);
        return nums;
    }
private:
    void next_perm(string& s, int n)
    {
        int i, j;
        for(i = n -2; i >= 0; --i)
        {
            if(s[i+1] > s[i])
                break;
        }
        for(j = n - 1; j > i; --j)
        {
            if(s[j] > s[i])
                break;
        }
        swap(s[i],s[j]);
        reverse(s.begin()+i+1, s.end());
    }
};
