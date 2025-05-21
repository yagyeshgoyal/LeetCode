class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        vector<int> target(128, 0);
        vector<int> window(128, 0);

        // Populate target character frequency
        for (char c : t) target[c]++;

        int required = t.size();  // total characters needed
        int formed = 0;           // characters matched
        int i = 0, j = 0;
        int minLen = INT_MAX, start = 0;

        while (j < s.size()) {
            char rightChar = s[j];
            window[rightChar]++;

            // Count only if the character was needed and within limits
            if (target[rightChar] > 0 && window[rightChar] <= target[rightChar]) {
                formed++;
            }

            // Try to shrink the window if all characters are matched
            while (formed == required) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                char leftChar = s[i];
                window[leftChar]--;

                
                if (target[leftChar] > 0 && window[leftChar] < target[leftChar]) {
                    formed--;
                }
                i++;
            }

            j++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
