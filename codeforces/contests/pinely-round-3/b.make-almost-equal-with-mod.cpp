#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int newArrSize = (n * (n - 1)) / 2;

        vector<int> boredArr(newArrSize);

        int max = INT_MIN;

        for (int i = 0; i < newArrSize; i++)
        {
            cin >> boredArr[i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (max < boredArr[i])
            {
                max = boredArr[i];
            }

            cout << boredArr[i] << " ";
        }

        cout << 1000000000 << " \n";
    }

    return 0;
}