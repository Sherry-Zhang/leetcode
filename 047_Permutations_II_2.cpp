////去重复的全排列的解法2：递归去重版
//beats 90.1%
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > ans;
        permutation(ans, nums, 0, nums.size());
        return ans;
    }
private:
    void permutation(vector<vector<int> > &ans,vector<int>&nums, int start, int len)
    {
        if (start == len - 1)
        {
            ans.push_back(nums);
            return;
        }
        for (int i = start; i < len; ++i)
        {
            bool flag = true;
            for (int j = start; j < i; ++j)
            {
                if (nums[j] == nums[i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                swap(nums[i], nums[start]);
                permutation(ans, nums, start + 1, len);
                swap(nums[i], nums[start]);
            }
        }
    }
};
