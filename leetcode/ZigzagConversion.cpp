#include <iostream>
#include <string>
#include <vector>

std::string convert(const std::string& s, int numRows) {
    if (numRows == 1 || numRows >= s.length()) {
        return s;
    }

    std::vector<std::string> rows(std::min(numRows, int(s.length())));
    int currentRow = 0;
    bool goingDown = false;

    for (char c : s) {
        rows[currentRow] += c;
        if (currentRow == 0 || currentRow == numRows - 1) {
            goingDown = !goingDown;
        }
        currentRow += goingDown ? 1 : -1;
    }

    std::string result;
    for (const std::string& row : rows) {
        result += row;
    }
    return result;
}

int main() {
    std::cout << "Example 1. PAYPALISHIRING : " << convert("PAYPALISHIRING", 3); std::cout << "\n";
    std::cout << "Example 2. PAYPALISHIRING : " << convert("PAYPALISHIRING", 4); std::cout << "\n";

}
    