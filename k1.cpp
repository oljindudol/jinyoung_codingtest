#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int h = pow(2, n - 1);

    for (int i = 0; i < n; ++i)
    {
        int t = arr1[i] | arr2[i];
        int check = h;
        answer.push_back("");
        for (int j = 0; j < n; ++j)
        {
            if (check == (check & t))
            {
                answer[i] += '#';
            }
            else
            {
                answer[i] += ' ';
            }
            check /= 2;
        }
    }
    return answer;
}