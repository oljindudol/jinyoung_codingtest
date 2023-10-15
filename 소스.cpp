#include <stdio.h>
#include <vector>
#include <string>

using namespace std;


vector<string> reorderLogFiles(vector<string>& logs) {
    vector<string> Ll;
    vector<string> Dl;

    vector<string>::iterator iter = logs.begin();

    for (; logs.end() != iter; iter++)
    {
        if ((*iter)[0] == 'l')
        {
            Ll.push_back(*iter);
        }
        else
        {
            Dl.push_back(*iter);
        }
    }

}


int main()
{
    vector<string> tc =
	return 0;
}