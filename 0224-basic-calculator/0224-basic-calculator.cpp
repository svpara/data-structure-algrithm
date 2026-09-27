class Solution {
public:
    int calculate(string s) {
        long long ans = 0;
        long long num = 0;
        int sign = 1;

        stack<int> st;
        st.push(1);

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '(') {
                st.push(sign);
            }
            else if (c == ')') {
                st.pop();
            }
            else if (c == '+' || c == '-') {
                ans += sign * num;

                sign = (c == '+' ? 1 : -1) * st.top();

                num = 0;
            }
        }

        ans += sign * num;

        return (int)ans;
    }
};