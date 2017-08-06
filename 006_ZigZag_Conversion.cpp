class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        int len = s.size();
        vector <vector<char> > zigzag(numRows, vector<char>(len));
        string out;
        int i = 0, j = 0;
        bool down = true;
        for (char tmp : s)
        {
            zigzag[i][j] = tmp;
            if (down)
            {
                if (i != numRows - 1)
                    ++i;
                else
                {
                    down = false;
                    ++j;
                    --i;
                }
                continue;
            }
            else
            {
                if (i)
                {
                    ++j;
                    --i;
                }
                else
                {
                    down = true;
                    ++i;
                }
            }
        }
        len = j + 1;
        for (i = 0; i < numRows; ++i)
            for (j = 0; j < len; ++j)
                if (zigzag[i][j])
                    out.push_back(zigzag[i][j]);
        return out;
    }

};
