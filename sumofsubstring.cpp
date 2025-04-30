#include <iostream>
#include <string>
using namespace std;

long long totalSum = 0;

void backtrack(string s, int start, long long current) {
    if (start == s.length()) {
        return;
    }

    long long num = 0;
    for (int i = start; i < s.length(); i++) {
        num = num * 10 + (s[i] - '0');
        totalSum += num;
        backtrack(s, i + 1, num);
    }
}

long long sumOfSubstrings(string s) {
    totalSum = 0;
    backtrack(s, 0, 0);
    return totalSum;
}

int main() {
    string s = "123";
    cout << "Sum of substrings (backtracking): " << sumOfSubstrings(s) << endl;
    return 0;
}
