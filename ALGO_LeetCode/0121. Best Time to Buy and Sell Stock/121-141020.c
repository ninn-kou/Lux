// Hao Ren
// 14 October, 2020
// 121. Best Time to Buy and Sell Stock

// Just like "1. Two Sum", we use two loops to find the maximum difference.
int maxProfit(int *prices, int pricesSize) {
    int maxProfit = 0;
    for (int i = 0; i < pricesSize; i++) {
        for (int j = i + 1; j < pricesSize; j++) {
            int currentProfit = prices[j] - prices[i];
            if (currentProfit > maxProfit) {
                maxProfit = currentProfit;
            }
        }
    }
    return maxProfit;
}
