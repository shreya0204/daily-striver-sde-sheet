// Best Time to Buy and Sell Stocks

int maxProfit(vector<int> &prices)
{
    int size = prices.size();
    int mini = INT_MAX;

    int profit = 0;
    for (int i = 0; i < size; i++)
    {
        mini = min(mini, prices[i]);
        profit = max(profit, prices[i] - mini);
    }

    return profit;
}