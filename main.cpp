#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        vector<int> roman(128);

        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        for (int i = 0; i + 1 < s.length(); ++i)
            if (roman[s[i]] < roman[s[i + 1]])
                ans -= roman[s[i]];
            else
                ans += roman[s[i]];

        return ans + roman[s.back()];
    }
};

// Test function to run example cases
void testRomanToInt() {
    Solution solution;
    
    // Test case 1
    string s1 = "III";
    cout << "Test 1: Input = " << s1 << ", Output = " << solution.romanToInt(s1) << endl;
    
    // Test case 2
    string s2 = "LVIII";
    cout << "Test 2: Input = " << s2 << ", Output = " << solution.romanToInt(s2) << endl;
    
    // Test case 3
    string s3 = "MCMXCIV";
    cout << "Test 3: Input = " << s3 << ", Output = " << solution.romanToInt(s3) << endl;
}

int main() {
    testRomanToInt();
    return 0;
}
