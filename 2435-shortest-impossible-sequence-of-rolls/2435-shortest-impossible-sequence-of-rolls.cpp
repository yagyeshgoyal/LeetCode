class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_set<int> seen;
        int count = 0;

        for (int roll : rolls) {
            seen.insert(roll);
            if (seen.size() == k) {
                count++;
                seen.clear(); // Start forming the next sequence
            }
        }

        return count + 1; // Add 1 for the last incomplete sequence
    }
};
