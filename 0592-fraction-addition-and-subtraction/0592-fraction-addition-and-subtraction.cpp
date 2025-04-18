class Solution {
    long long lcm(long long a, long long b) {
        return (1ll * a * b) / __gcd(a, b);
    }

    long long lcm_of_list(const vector<long long>& nums) {
        long long result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            result = lcm(result, nums[i]);
        }
        return result;
    }

public:
    string fractionAddition(string expression) {
        vector<long long> numerators;
        vector<long long> denominators;

        int i = 0, n = expression.size();
        while (i < n) {
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                sign = (expression[i] == '-') ? -1 : 1;
                i++;
            }

            long long num = 0;
            while (i < n && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }

            i++; // skip '/'
            long long den = 0;
            while (i < n && isdigit(expression[i])) {
                den = den * 10 + (expression[i] - '0');
                i++;
            }

            numerators.push_back(sign * num);
            denominators.push_back(den);
        }

        long long common_lcm = lcm_of_list(denominators);
        long long total = 0;
        for (int i = 0; i < numerators.size(); i++) {
            total += (common_lcm / denominators[i]) * numerators[i];
        }

        if (total == 0) return "0/1";

        long long gcd_final = __gcd(abs(total), common_lcm);
        total /= gcd_final;
        common_lcm /= gcd_final;

        return to_string(total) + "/" + to_string(common_lcm);
    }
};
