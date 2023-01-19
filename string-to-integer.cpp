#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int myAtoi(string s) {
    long int ret = 0;
    bool neg = false;
    bool signSet = false;
    bool numSet = false;

    int zero = static_cast<int>('0');
    int nine = static_cast<int>('9');

    for (char ch : s) {
      if (ch == ' ') {
	if (!numSet) continue;
	else return ret;
      }

      if (ch == '-' || ch == '+') {
	if (signSet) break;
      }
      
      if (ch == '-' && !numSet) {
	neg = true;
	signSet = true;
      }
      else if (ch == '+' && !numSet) {
	neg = false;
	signSet = true;
      }
      else if (ch < zero || ch > nine) {
	if (ch != ' ') break;
      }
      else {
	if (ch >= zero && ch <= nine) {
	  ret = ret * 10 + ch - zero;
	  numSet = true;
	}
	else break;
      }
    }

    int max = 2147483647;

    cout << ret << endl;
    if (!neg && ret >= max)
      return max;
    if (neg && ret > max)
      return -max - 1;

    return neg ? -ret : ret;
  }
};

int main() {
  vector<string> tests;
  tests.push_back("42");
  tests.push_back("      -42");
  tests.push_back("4193 with words");
  tests.push_back("-2147483649");
  tests.push_back("3.14149");
  tests.push_back("+1");
  tests.push_back("+-12");
  tests.push_back("00000-42a1234");
  tests.push_back("   +0 123");
  tests.push_back("-2147483647");
  tests.push_back("-91283472332");

  Solution sol;
  for (string str : tests) {
    cout << sol.myAtoi(str) << endl;
  }
}
