#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
    if (a.substr(a.find(" ") + 1, a.length())
        == b.substr(b.find(" ") + 1, b.length()))
    {
        return a.substr(0, a.find(" ")) < b.substr(0, b.find(" "));
    }

    return a.substr(a.find(" ") + 1, a.length())
        < b.substr(b.find(" ") + 1, b.length());
}


vector<string> reorderLogFiles(vector<string>& logs) {
    vector<string> ret;
    vector<string> Dl;


    vector<string>::iterator iter = logs.begin();
    //auto iter = logs.begin();
    for (; logs.end() != iter; iter++)
    {
        if ((*iter)[(*iter).find(" ")+1] >= '0' &&(*iter)[(*iter).find(" ") + 1]<='9')
        {
            Dl.push_back(*iter);
        }
        else
        {
            ret.push_back(*iter);
        }
    }

    sort(ret.begin(), ret.end(), compare);
    ret.insert(ret.end(), Dl.begin(), Dl.end());

    return ret;
}



int main()
{
    vector<string> tc = { "a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo","a2 act car" };
    reorderLogFiles(tc);
	return 0;
}