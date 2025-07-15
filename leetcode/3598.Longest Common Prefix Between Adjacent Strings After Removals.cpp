/*
 * @lc app=leetcode id=3598 lang=cpp
 * @lcpr version=30201
 *
 * [3598] Longest Common Prefix Between Adjacent Strings After Removals
 */

// @lc code=start
class Solution
{
public:
    int getPrefixLength(string word1, string word2)
    {
        int sum = 0;
        int n = min(word1.size(), word2.size());

        for (int i = 0; i < n; i++)
        {
            if (word1[i] == word2[i])
                sum++;
            else
                break;
        }

        return sum;
    }

    vector<int> longestCommonPrefix(vector<string> &words)
    {
        int n = words.size();

        if (n <= 2)
        {
            return vector<int>(n, 0);
        }

        vector<int> lpc(n, 0), prefixarr(n, 0), suffixarr(n, 0);

        for (int i = 1; i < n; i++)
        {
            lpc[i] = getPrefixLength(words[i - 1], words[i]);
        }

        for (int i = 1; i < n; i++)
        {
            prefixarr[i] = max(prefixarr[i - 1], lpc[i]);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            suffixarr[i] = max(suffixarr[i + 1], lpc[i + 1]);
        }

        vector<int> ans(n, 0);

        for (int i = 1; i < n - 1; i++)
        {
            ans[i] = max({prefixarr[i - 1],
                          getPrefixLength(words[i - 1], words[i + 1]),
                          suffixarr[i + 1]});
        }

        ans[n - 1] = prefixarr[n - 2];
        ans[0] = suffixarr[1];

        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["jump","run","run","jump","run"]\n
// @lcpr case=end

// @lcpr case=start
// ["dog","racer","car"]\n
// @lcpr case=end

 */
