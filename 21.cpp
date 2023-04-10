#pragma GCC optimize("03")

#include <iostream>

int main() {
    int n; std::cin >> n;
    
    int* dp = new int[n + 1];
    dp[0] = 0; dp[1] = 1;
    for (int curr = 2; curr <= n; ++curr) dp[curr] = 1e9;
	for (int k = 1; k*k*k <= n; ++k){
    int q = k*k*k;
    for (int curr = q; curr <= n; ++curr)
    		if (dp[curr] > dp[curr - q] + 1)
                dp[curr] = dp[curr - q] + 1;
    }
        
    std::cout << dp[n];
    free(dp);
}
