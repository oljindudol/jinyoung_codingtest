#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string ret = "";
    sort(timetable.begin(), timetable.end(), greater<string>());
    vector<vector<int>> vv;
    vector<int> dtime;
    int ttime = 540;

    for (int i = 0; i < n; ++i)
    {
        ttime = 540 + i * t;
        dtime.push_back(ttime);
        vector<int> vtmp;
        for (int j = 0; j < m; ++j)
        {
            if (0 == timetable.size())
            {
                break;
            }
            auto t = timetable.back();
            int tt = stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));

            if (ttime >= tt)
            {
                vtmp.push_back(tt);
                timetable.pop_back();
            }
            else
            {
                break;
            }
        }
        vv.push_back(vtmp);
    }

    int last = -1;
    for (int i = 0; i < n; ++i)
    {
        int idx = n - i - 1;
        int sz = vv[idx].size();

        for (int j = 0; j < sz; ++j)
        {
            if (m != sz)
            {
                //정원만큼 차있지 않을 경우
                string h = "0" + to_string(dtime[idx] / 60);
                string m = "0" + to_string(dtime[idx] % 60);
                ret = h.substr(h.size() - 2, 2) + ":" + m.substr(m.size() - 2, 2);
                return ret;
            }
            else
            {
                auto t = vv[idx][sz - j - 1];
                if (-1 == last)
                {
                    last = t;
                    continue;
                }
                if (t != last)
                {
                    string h = "0" + to_string(t / 60);
                    string m = "0" + to_string(t % 60);
                    ret = h.substr(h.size() - 2, 2) + ":" + m.substr(m.size() - 2, 2);
                    return ret;
                }
            }
        }
    }
    if (0 == vv[0].size())
    {
        string h = "0" + to_string(dtime[dtime.size() - 1] / 60);
        string mm = "0" + to_string(dtime[dtime.size() - 1] % 60);
        ret = h.substr(h.size() - 2, 2) + ":" + mm.substr(mm.size() - 2, 2);
        return ret;
    }

    string h = "0" + to_string((vv[0][0] - 1) / 60);
    string mm = "0" + to_string((vv[0][0] - 1) % 60);
    ret = h.substr(h.size() - 2, 2) + ":" + mm.substr(mm.size() - 2, 2);
    return ret;
}