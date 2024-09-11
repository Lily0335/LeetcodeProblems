#include <iostream>

class Solution {
public:
    void reverseString(char s[]) {
        int left = 0;
        int right = 0;
        
        // Calculate the length of the string (number of characters)
        while (s[right] != '\0') {
            right++;
        }
        right--;  // Adjust right to the last valid index
        
        while (left < right) {
            // Swap the characters at the left and right pointers
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            
            // Move the pointers towards the center
            left++;
            right--;
        }
    }
};

int main() {
    char s1[] = "hello";
    
    Solution().reverseString(s1);
    
    std::cout << s1 << std::endl;

    char s2[] = "Hannah";
    
    Solution().reverseString(s2);
    
    std::cout << s2 << std::endl;

    return 0;
}
