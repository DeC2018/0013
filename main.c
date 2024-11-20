#include <stdio.h>
#include <string.h>

int romanToInt(char* s) {
    int f = 0;  // Initialize the result to 0
    
    // Iterate over each character in the string
    for (int i = 0; i < strlen(s); i++) {
        // Check for subtraction cases first
        if (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) 
            f -= 1;  // Subtract 1 for IV or IX
         else if (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) 
            f -= 10; // Subtract 10 for XL or XC
         else if (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')) 
            f -= 100; // Subtract 100 for CD or CM
        
        // For normal cases, just add the corresponding value
        else if (s[i] == 'I') {
            f += 1;
        } else if (s[i] == 'V') {
            f += 5;
        } else if (s[i] == 'X') {
            f += 10;
        } else if (s[i] == 'L') {
            f += 50;
        } else if (s[i] == 'C') {
            f += 100;
        } else if (s[i] == 'D') {
            f += 500;
        } else if (s[i] == 'M') {
            f += 1000;
        }
    }
    
    return f;  // Return the computed integer value
}

// Function to test the romanToInt implementation
void testRomanToInt() {
    // Test case 1: III = 3
    char test1[] = "III";
    printf("Test 1: Input = %s, Output = %d\n", test1, romanToInt(test1));
    
    // Test case 2: LVIII = 58
    char test2[] = "LVIII";
    printf("Test 2: Input = %s, Output = %d\n", test2, romanToInt(test2));
    
    // Test case 3: MCMXCIV = 1994
    char test3[] = "MCMXCIV";
    printf("Test 3: Input = %s, Output = %d\n", test3, romanToInt(test3));
}

int main() {
    // Run the test cases
    testRomanToInt();
    return 0;
}
