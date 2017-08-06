//最简单的一种，无需考虑重复，直接用交换法解即可
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> >ans;
        permutation(nums,ans,0,nums.size());
        return ans;
    }
private:
   void permutation(vector<int>& nums,vector<vector <int> >&ans, int start, int len)
   {
       if(start == len - 1)
       {
           ans.push_back(nums);
           return;
       }
       for(int i = start; i < len;++i)
       {
           swap(nums[start],nums[i]);
           permutation(nums,ans,start+1,len);
           swap(nums[start],nums[i]);
       }
   }
};
