#include <bits/stdc++.h>
using namespace std;

void printvect(vector<int> &nums)
{
    for (auto &num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> nums(n);
        int nume = 0, numo = 0;
        for (auto &num : nums)
        {
            cin >> num;
            if (num % 2 == 0)
                nume++;
            else
                numo++;
        }
        if (nume >= 1 && numo >= 1)
        {
            sort(nums.begin(), nums.end());
            printvect(nums);
        }
        else
        {
            printvect(nums);
        }
    }
    return 0;
}