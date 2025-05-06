#include <iostream>
#include <string>
#include <vector>
using namespace std;

string highestValuePalindrome(string s, int n, int k) {
    vector<bool> changed(n, false);
    int left = 0, right = n - 1;

    // First pass: make it a palindrome with minimal changes
    while (left < right) {
        if (s[left] != s[right]) {
            s[left] = s[right] = max(s[left], s[right]);
            changed[left] = changed[right] = true;
            k--;
        }
        left++;
        right--;
    }

    // If not enough changes to make it a palindrome
    if (k < 0) return "-1";

    // Second pass: try to maximize the palindrome
    left = 0; right = n - 1;
    while (left <= right) {
        if (left == right) {
            if (k > 0 && s[left] != '9') {
                s[left] = '9';
                k--;
            }
        } else {
            if (s[left] != '9') {
                if (changed[left] || changed[right]) {
                    if (k >= 1) {
                        s[left] = s[right] = '9';
                        k--;
                    }
                } else {
                    if (k >= 2) {
                        s[left] = s[right] = '9';
                        k -= 2;
                    }
                }
            }
        }
        left++;
        right--;
    }

    return s;
}

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    cout << highestValuePalindrome(s, n, k) << endl;
    return 0;
}
