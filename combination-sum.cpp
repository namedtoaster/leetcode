#include <iostream>
#include <vector>

// I don't think I did this very cleanly with the class layout, but it works
// wasn't really sure how to do it better

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    m_target = target;
    m_cands = candidates;
    
    vector<int> cur = {};
    dfs(0, cur, 0);

    vector<vector<int>> out = res;
    res.clear();
    return out;
  }

  void dfs(int i, vector<int>& cur, int total) {
    if (total == m_target) {
      vector<int> copy = cur;
      res.push_back(copy);

      return;
    }

    if (i >= m_cands.size() || total > m_target)
      return;

    cur.push_back(m_cands[i]);
    dfs(i, cur, total + m_cands[i]);
    cur.pop_back();
    dfs(i + 1, cur, total);
  }

  int m_target;
  vector<int> m_cands;
  vector<vector<int>> res;
};

void printSolution(vector<vector<int>> sol) {
  cout << "[";
  for (vector<int> s : sol) {
    cout << "[";
    for (int val : s ) {
      cout << val << ' ';
    }
    cout << "]";
    
  }
  cout << "]" << endl;
}

int main() {
  vector<pair<vector<int>, int>> tests;
  tests.push_back(make_pair<vector<int>, int>({2,3,6,7}, 7));
  tests.push_back(make_pair<vector<int>, int>({2,3,5}, 8));
  tests.push_back(make_pair<vector<int>, int>({2}, 1));

  Solution sol;
  for (pair<vector<int>, int> cands_tgt : tests) {
    printSolution(sol.combinationSum(cands_tgt.first, cands_tgt.second));
  }
}
