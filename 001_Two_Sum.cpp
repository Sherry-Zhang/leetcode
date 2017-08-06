class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unsigned i,j;
        vector <int> ans(2);
        for(i = 1;i < nums.size();i++)
        {
            for(j = 0;j < i;j++)
            {    if(nums[j] + nums[i] == target)
                 {
                     ans[0] = j;
		             ans[1] = i;
                     return ans;
                 }
            }
        }
        return ans;
    }
};
