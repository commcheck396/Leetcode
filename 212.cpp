    class Solution {
    public:
        // s 记录 words 中出现的单词，t 记录已经搜索到的单词
        unordered_set<string> s, t;
        // ret 为结果数组
        vector<string> ret;
        // 全局变量，拷贝 board
        vector<vector<char>> ch;
        // 网格行数、列数
        int n, m;
        // 四个搜索方向
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

        // 深度优先搜索函数，参数 i, j 为当前所在位置， cur 为当前组好的字符串，vis 为标记数组
        void dfs(int i, int j, string cur, vector<vector<bool>>& vis) {
            // 剪枝：如果当前字符串长度大于10，直接返回，因为不会出现在 words 中
            if(cur.size() > 10) return;

            // 如果当前字符串在 words 中出现过，记录到结果中。
            if(s.count(cur)) {
                t.insert(cur);
            }
            for(int k = 0; k < 4; ++k) {
                // 向四个方向走一步，保证新的位置在网格内，且本分支没有被遍历过
                int xx = i + dx[k], yy = j + dy[k];
                if(xx >= 0 && xx < n && yy >= 0 && yy < m && !vis[xx][yy]) {
                    // 标记为 true，防止重复利用
                    vis[xx][yy] = true;
                    dfs(xx, yy, cur + ch[xx][yy], vis);
                    // 标记为 false
                    vis[xx][yy] = false;
                }
            }
        }

        vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
            // 初始化
            for(string w : words) s.insert(w);
            ch = board;
            n = board.size(), m = board[0].size();

            // 声明空字符串，用于第一步的搜索
            string s;
            vector<vector<bool>> vis(n, vector<bool>(m));

            // 从所有位置开始搜索
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    vis[i][j] = true;
                    dfs(i, j, s + board[i][j], vis);
                    vis[i][j] = false;
                }
            }

            // 将所有搜到的字符串存入结果数组并返回
            for(string tt : t) ret.push_back(tt);
            return ret;
        }
    };