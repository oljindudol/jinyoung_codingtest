#include <string>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int ret = 0;
    unordered_map<string, int> cache;

    for (int i = 0; i < cities.size(); ++i)
    {
        for (auto& c : cities[i])
        {
            c = tolower(c);
        }

        if (cache.end() == cache.find(cities[i]) || 0 == cache[cities[i]])
        {
            ret += 5;
        }
        else
        {
            ret += 1;
        }

        ++cache[cities[i]];


        if (cacheSize < cache.size())
        {
            --cache[cities[i - cacheSize]];;
        }

    }

    return ret;
}