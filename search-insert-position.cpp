#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    int m;

    while (l <= r) {
      m = l + (r - l) / 2;
      if (nums[m] == target) return m;
      else if (nums[m] < target) l = m + 1;
      else r = m - 1;
    }
    return l;
  }
};

int main() {
  vector<pair<vector<int>, int>> tests;
  tests.push_back(make_pair<vector<int>, int>({1,3,5,6}, 5));
  tests.push_back(make_pair<vector<int>, int>({1,3,5,6}, 2));
  tests.push_back(make_pair<vector<int>, int>({1,3,5,6}, 7));

  Solution sol;
  for (pair<vector<int>, int> nums_tgt: tests) {
    cout << sol.searchInsert(nums_tgt.first, nums_tgt.second) << endl;
  }
}
