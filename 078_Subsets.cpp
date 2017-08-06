//二进制转换法
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        int len = nums.size();
        int count = pow(2,len);
        for(int i = 0;i < count; ++i)
        {
            vector<int> c;
            int tmp = i;
            for(int j = 0;j < len; ++j)
            {
                bool choose = tmp & 1;
                tmp = tmp >> 1;
                if(choose)
                    c.push_back(nums[j]);
            }
            ans.push_back(c);
        }
        return ans;
    }
};
