#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int MAX_N = 100;
const int MAX_K = 100;
const int INF = INT_MAX / 2;

struct State {
    int cost;
    bool used_coupon;
};

int main() {
    int n;
    cin >> n;
    vector<int> prices(n + 1); // +1 to make it less error-prone, so prices[1] represents day 1
    for (int i = 1; i <= n; i++) { // we skip day 0, so start with i = 1
        cin >> prices[i];
    }
// dp stands for dynamic programming
    // dp[i][j] - min cost for first i meals with j coupons remaining
    vector<vector<State>> dp(n + 1, vector<State>(n + 2, {INF, false}));
    // each member of vector is vector to set of structures
    // all those structures are initialized with infinite cost and not used coupons
    // The same logic with n + 1 here as in prices, we start from day 1
    // n + 2 dimension represents coupons remaining, +2 in case, might be truncated probably.
    
    dp[0][0] = {0, false}; // we need it to represent a valid starting point (day 0) to reference
// first we need to fill the DP table:
    for (int i = 1; i <= n; i++) // i stand for days
    {
        for (int j = 0; j <= n; j++) { // j stand for coupons
            // Option 1: Pay for current meal without using coupon
            if (j >= (prices[i] > 100 ? 1 : 0))
	// if prices more than 100, then compare j with 1, otherwise 0
	    {
                int new_j = j - (prices[i] > 100 ? 1 : 0);
                if (dp[i-1][new_j].cost + prices[i] < dp[i][j].cost) {
                    dp[i][j].cost = dp[i-1][new_j].cost + prices[i];
                    dp[i][j].used_coupon = false;
                }
            }
            // Option 2: Use coupon for current meal (if available)
            if (j + 1 <= n && i > 1) // starting with day 2 (i > 1)
	    {
                if (dp[i-1][j+1].cost < dp[i][j].cost) {
                    dp[i][j].cost = dp[i-1][j+1].cost;
                    dp[i][j].used_coupon = true;
                }
            }
        }
    }
    // Now, in every cell we have the total cost of all meals
    // (or INF, if it's invalid path, meaning dp[2][3] is invalid
    // because it's impossible to have 3 coupons after 2 meals)
    // let's find minimal cost and corresponding coupon count
    int min_cost = INF;
    int remaining_coupons = 0;
    for (int j = 0; j <= n; j++) {
        if (dp[n][j].cost <= min_cost) // overwrite the total cost until we find the minimum
	{
            min_cost = dp[n][j].cost;
            remaining_coupons = j; // so we can use them later...
        }
    }
    // Trace back to find used coupons, namely days when we used them
    vector<int> used_days;
    int current_j = remaining_coupons;
    for (int i = n; i >= 1; i--) {
        if (dp[i][current_j].used_coupon) {
            used_days.push_back(i);
            current_j++;
        } else {
            current_j += (prices[i] > 100 ? 1 : 0);
        }
    }
    cout << min_cost << endl;
/*    cout << remaining_coupons << " " << used_days.size() << endl;
    for (int i = used_days.size() - 1; i >= 0; i--) {
        cout << used_days[i] << endl;
    }*/
    return (0);
}
