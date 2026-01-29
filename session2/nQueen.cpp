class Solution {
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> cols(n, false), diag1(2*n, false), diag2(2*n, false);
        backtrack(0, n, current, cols, diag1, diag2, result);
        return result;
    }
    
private:
    void backtrack(int row, int n, vector<int>& current,
                   vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2,
                   vector<vector<int>>& result) {
        if (row == n) {
            result.push_back(current);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (cols[col] || diag1[row - col + n] || diag2[row + col]) continue;
            current.push_back(col + 1);
            cols[col] = diag1[row - col + n] = diag2[row + col] = true;
            backtrack(row + 1, n, current, cols, diag1, diag2, result);
            current.pop_back();
            cols[col] = diag1[row - col + n] = diag2[row + col] = false;
        }
    }
};
