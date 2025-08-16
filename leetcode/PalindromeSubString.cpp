#include <iostream>
#include <string>

std::string longestPalindrome(std::string s) {
    if (s.empty()) return "";
    int start = 0, max_len = 1;
    int n = s.size();
    for (int i = 0; i < n; i++) {
            int left = i, right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > max_len) {
                    start = left;
                    max_len = right - left + 1;
                }
                left--;
                right++;
            }

            left = i, right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > max_len) {
                    start = left;
                    max_len = right - left + 1;
                }
                left--;
                right++;
            }
        }

    return s.substr(start, max_len);
}

int main() {
    std::cout << longestPalindrome("hello wore") << std::endl;

    return 0;
}