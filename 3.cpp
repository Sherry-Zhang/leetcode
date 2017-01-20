class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i, j;
        int max_len = 0;
        int visit[128];
        int len = 1;
        for(i = 0; i < s.size();i++)
        {
            memset(visit,0,128 * sizeof(int));
            len = 0;
            for(j = i;j < s.size();j++)
            {
                if(visit[s[j]])
                    break;
                else
                {
                    visit[s[j]] = 1;
                    ++len;
                }
            }
            if(len > max_len)
                max_len = len;
        }
        return max_len;
    }
};
