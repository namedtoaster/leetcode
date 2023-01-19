#include <string>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;

    while (l <= r) {
      int mid = (l + r) / 2;
      if (target == nums[mid]) return mid;

      // left sorted portion
      if (nums[l] <= nums[mid]) {
	if (target > nums[mid] || target < nums[l]) {
	  l = mid + 1;
	}
	else {
	  r = mid - 1;
	}
      }
      // right sorted portion
      else {
	if (target < nums[mid] || target > nums[r]) {
	  r = mid - 1;
	}
	else {
	  l = mid + 1;
	}
      }
    }
    
    return -1;
  }
};

int main() {
  vector<pair<vector<int>, int>> tests;

  tests.push_back(make_pair<vector<int>, int>({4,5,6,7,0,1,2}, 0));
  tests.push_back(make_pair<vector<int>, int>({4,5,6,7,0,1,2}, 3));
  tests.push_back(make_pair<vector<int>, int>({1}, 0));

  Solution sol;
  for (pair<vector<int>, int> nums_tgt : tests) {
    cout << sol.search(nums_tgt.first, nums_tgt.second) << endl;
  }
}
