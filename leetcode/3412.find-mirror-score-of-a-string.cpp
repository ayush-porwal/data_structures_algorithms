#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long calculateScore(string s)
    {
        int n = s.size();
        long long ans = 0;
        unordered_map<char, vector<int>> uMap = {};

        for (int i = 0; i < n; i++)
        {
            char ch = 'a' + ('z' - s[i]);

            if (uMap.find(ch) != uMap.end())
            {
                ans += i - uMap['a' + ('z' - s[i])].back();
                uMap['a' + ('z' - s[i])].pop_back();

                if (uMap['a' + ('z' - s[i])].size() == 0)
                {
                    uMap.erase('a' + ('z' - s[i]));
                }
            }
            else
            {
                if (uMap.find(s[i]) != uMap.end())
                {
                    uMap[s[i]].push_back(i);
                }
                else
                {
                    uMap.insert({s[i], {i}});
                }
            }
        }

        return ans;
    }
};