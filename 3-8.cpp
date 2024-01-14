class Solution {
public:
    void pushdata(int _n, int _k, int depth, int from, vector<int> tmp, vector<vector<int>>& _out)
    {
        if (depth == _k)
        {
            _out.push_back(tmp);
            return;
        }
        int to = _n - (_k - depth) + 1;
        for (int i = from; i < to; ++i)
        {
            vector<int> tmptmp = tmp;
            tmptmp.push_back(i + 1);
            pushdata(_n, _k, depth + 1, i + 1, tmptmp, _out);

        }
    }


    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        vector<vector<int>> ret;

        pushdata(n, k, 0, 0, tmp, ret);

        return ret;
    }
};