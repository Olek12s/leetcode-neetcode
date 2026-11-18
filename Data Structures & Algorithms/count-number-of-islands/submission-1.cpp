class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {

                if (grid[r][c] == '1') {
                    ++islands;
                    
                    queue<pair<int, int>> q;
                    q.push({r, c});
                    grid[r][c] = '0';   // visited

                    while (!q.empty()) {
                        auto [currR, currC] = q.front();
                        q.pop();

                        for (auto [dr, dc] : directions) {
                            int newR = currR + dr;
                            int newC = currC + dc;

                            if (newR >= 0 && newR < rows && newC >= 0 && newC < cols && grid[newR][newC] == '1') {
                                grid[newR][newC] = '0';
                                q.push({newR, newC});
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }
};