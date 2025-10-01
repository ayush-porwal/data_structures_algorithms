#include <bits/stdc++.h>

using namespace std;

bool flag = false;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

void dfs(vector<vector<char>> &colorMatrix, vector<vector<bool>> &visited, int x, int y, int parentX, int parentY)
{
  visited[x][y] = true;

  for (int i = 0; i < 4; i++)
  {
    int xNew = x + dx[i];
    int yNew = y + dy[i];
    if (xNew >= 0 && xNew < colorMatrix.size() && yNew >= 0 && yNew < colorMatrix[0].size() && colorMatrix[xNew][yNew] == colorMatrix[x][y])
    {
      if (visited[xNew][yNew] && (xNew != parentX || yNew != parentY))
      {
        flag = true;
        return;
      }
      else if (!visited[xNew][yNew])
      {
        dfs(colorMatrix, visited, xNew, yNew, x, y);
      }
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;

  vector<vector<char>> colorMatrix(n, vector<char>(m));
  vector<vector<bool>> visited(n, vector<bool>(m, false));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> colorMatrix[i][j];
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (!visited[i][j])
      {
        dfs(colorMatrix, visited, i, j, -1, -1);
      }
    }
  }

  cout << (flag ? "Yes\n" : "No\n");
}

// Refer this solution from Queue for implementation purposes
// #include <bits/stdc++.h>
// using namespace std;

// int n, m;
// string board[51];
// bool visited[51][51];
// bool findCycle = false;
// int dx[] = {1, -1, 0, 0};
// int dy[] = {0, 0, 1, -1};

// void dfs(int x, int y, int fromX, int fromY, char needColor)
// {
//   if (x < 0 || x >= n || y < 0 || y >= m)
//     return;
//   if (board[x][y] != needColor)
//     return;
//   if (visited[x][y])
//   {
//     findCycle = true;
//     return;
//   }
//   visited[x][y] = true;
//   for (int f = 0; f < 4; f++)
//   {
//     int nextX = x + dx[f];
//     int nextY = y + dy[f];
//     if (nextX == fromX && nextY == fromY)
//       continue;
//     dfs(nextX, nextY, x, y, needColor);
//   }
// }

// int MAIN()
// {
//   cin >> n >> m;
//   for (int i = 0; i < n; i++)
//     cin >> board[i];
//   memset(visited, false, sizeof(visited));
//   for (int i = 0; i < n; i++)
//     for (int j = 0; j < m; j++)
//       if (!visited[i][j])
//         dfs(i, j, -1, -1, board[i][j]);
//   cout << (findCycle ? "Yes" : "No") << endl;
//   return 0;
// }

// int main()
// {
// #ifdef LOCAL_TEST
//   freopen("in.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
// #endif
//   ios ::sync_with_stdio(false);
//   cout << fixed << setprecision(16);
//   return MAIN();
// }