#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;


static bool ispanlindrom(const string& _s)
{
    int len = _s.size();
    for (int i = 0; i < (len / 2); i++)
    {
        if (_s[i] != _s[len - i - 1])
            return false;
    }
    return true;
}

string longestPalindrome(string s) {
    string ret;
    int len = s.size();
    string tmp;
    for (int i = len; i > 0; i--)
    {
        for (int j = 0; j < (len - i + 1); j++)
        {
            tmp = s.substr(j, i);
            if (ispanlindrom(tmp))
            {
                ret = tmp;
                break;
            }
            tmp = "";
        }
        if ("" != ret)
            break;
    }
    return ret;
}

int main()
{
    //vector<string> tc = { "eat","tea","tan","ate","nat","bat" };
    string tc = "glwhcebdjbdroiurzfxxrbhzibilmcfasshhtyngwrsnbdpzgjphujzuawbebyhvxfhtoozcitaqibvvowyluvdbvoqikgojxcefzpdgahujuxpiclrrmalncdrotsgkpnfyujgvmhydrzdpiudkfchtklsaprptkzhwxsgafsvkahkbsighlyhjvbburdfjdfvjbaiivqxdqwivsjzztzkzygcsyxlvvwlckbsmvwjvrhvqfewjxgefeowfhrcturolvfgxilqdqvitbcebuooclugypurlsbdfquzsqngbscqwlrdpxeahricvtfqpnrfwbyjvahrtosovsbzhxtutyfjwjbpkfujeoueykmbcjtluuxvmffwgqjgrtsxtdimsescgahnudmsmyfijtfrcbkibbypenxnpiozzrnljazjgrftitldcueswqitrcvjzvlhionutppppzxoepvtzhkzjetpfqsuirdcyqfjsqhdewswldawhdyijhpqtrwgyfmmyhhkrafisicstqxokdmynnnqxaekzcgygsuzfiguujyxowqdfylesbzhnpznayzlinerzdqjrylyfzndgqokovabhzuskwozuxcsmyclvfwkbimhkdmjacesnvorrrvdwcgfewchbsyzrkktsjxgyybgwbvktvxyurufsrdufcunnfswqddukqrxyrueienhccpeuqbkbumlpxnudmwqdkzvsqsozkifpznwapxaxdclxjxuciyulsbxvwdoiolgxkhlrytiwrpvtjdwsssahupoyyjveedgqsthefdyxvjweaimadykubntfqcpbjyqbtnunuxzyytxfedrycsdhkfymaykeubowvkszzwmbbjezrphqildkmllskfawmcohdqalgccffxursvbyikjoglnillapcbcjuhaxukfhalcslemluvornmijbeawxzokgnlzugxkshrpojrwaasgfmjvkghpdyxt";
    longestPalindrome(tc);
    return 0;
}