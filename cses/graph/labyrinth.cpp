#include <bits/stdc++.h>

using namespace std;

bool flag = false;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
vector<char> dirs = {'U', 'D', 'L', 'R'};

void bfs(vector<string> &maze, vector<vector<bool>> &visited, pair<int, int> &start, vector<char> &path)
{
    queue<pair<int, int>> nodes;
    vector<vector<pair<int, int>>> parent(maze.size(), vector<pair<int, int>>(maze[0].size(), {-1, -1}));
    vector<vector<char>> parentDir(maze.size(), vector<char>(maze[0].size()));

    nodes.push(start);

    visited[start.first][start.second] = true;

    while (!nodes.empty() && !flag)
    {
        auto currentNode = nodes.front();
        nodes.pop();

        for (int i = 0; i < 4; i++)
        {
            pair<int, int> newStart = {currentNode.first + dx[i], currentNode.second + dy[i]};

            if (newStart.first < 0 || newStart.first >= maze.size() || newStart.second < 0 || newStart.second >= maze[0].size())
            {
                continue;
            }

            if (visited[newStart.first][newStart.second] || maze[newStart.first][newStart.second] == '#')
            {
                continue;
            }

            visited[newStart.first][newStart.second] = true;
            parent[newStart.first][newStart.second] = currentNode;
            parentDir[newStart.first][newStart.second] = dirs[i];

            if (maze[newStart.first][newStart.second] == 'B')
            {
                flag = true;

                // Reconstruct path from end to start
                pair<int, int> cur = newStart;
                while (cur != start)
                {
                    path.push_back(parentDir[cur.first][cur.second]);
                    cur = parent[cur.first][cur.second];
                }
                reverse(path.begin(), path.end());

                return;
            }

            nodes.push(newStart);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    pair<int, int> start, end;

    vector<char> path;
    vector<string> maze(n);
    vector<vector<bool>> visited(n, vector<bool>(m));

    for (int i = 0; i < n; i++)
    {
        string row = "";
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            row += ch;

            if (ch == 'A')
            {
                start = {i, j};
            }
            else if (ch == 'B')
            {
                end = {i, j};
            }
        }
        maze[i] = row;
    }

    bfs(maze, visited, start, path);

    cout << (flag ? "YES\n" : "NO\n");

    if (flag)
    {
        cout << path.size() << "\n";
        cout << string(path.begin(), path.end()) << endl;
    }

    return 0;
}