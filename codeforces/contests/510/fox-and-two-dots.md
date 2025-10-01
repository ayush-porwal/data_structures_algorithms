Ai implementation for class based approach

```c++
#include <iostream>
#include <vector>

using namespace std;

class CycleDetector {
private:
    const vector<int> dx = {-1, 1, 0, 0};
    const vector<int> dy = {0, 0, -1, 1};
    vector<vector<char>>& grid;
    vector<vector<bool>>& visited;
    int rows, cols;
    
    bool isValid(int x, int y) const {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }
    
    bool dfs(int x, int y, int parentX, int parentY) {
        visited[x][y] = true;
        char currentColor = grid[x][y];
        
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if (!isValid(newX, newY) || grid[newX][newY] != currentColor) {
                continue;
            }
            
            // Skip parent cell
            if (newX == parentX && newY == parentY) {
                continue;
            }
            
            // Cycle detected
            if (visited[newX][newY]) {
                return true;
            }
            
            // Continue DFS
            if (dfs(newX, newY, x, y)) {
                return true;
            }
        }
        
        return false;
    }
    
public:
    CycleDetector(vector<vector<char>>& g, vector<vector<bool>>& v, int r, int c) 
        : grid(g), visited(v), rows(r), cols(c) {}
    
    bool hasCycle() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j]) {
                    if (dfs(i, j, -1, -1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    CycleDetector detector(grid, visited, n, m);
    cout << (detector.hasCycle() ? "Yes\n" : "No\n");
    
    return 0;
}
```