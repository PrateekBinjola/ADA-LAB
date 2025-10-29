#include <stdio.h> #include <stdlib.h> #include <time.h>
struct Item {
int weight, profit; float ratio;
};
// Greedy Fractional Knapsack
float fractionalKnapsack(struct Item items[], int n, int capacity) {
 // Calculate ratio
for(int i=0; i<n; i++)
items[i].ratio = (float)items[i].profit / items[i].weight;
// Sort items by ratio descending
for(int i=0; i<n-1; i++) {
for(int j=i+1; j<n; j++) { if(items[i].ratio < items[j].ratio) { struct Item temp = items[i];
 
items[i] = items[j];
 items[j] = temp; }
}
}
float totalProfit = 0;
 int w = 0;
for(int i=0; i<n; i++) {
if(w + items[i].weight <= capacity) {
w += items[i].weight;
totalProfit += items[i].profit;
} else {
int remain = capacity - w;
totalProfit += items[i].profit * ((float)remain / items[i].weight); break;
}
}
return totalProfit;
 }
// 0/1 Knapsack using 1D DP
int knapsackDP(int weight[], int profit[], int n, int capacity) { int *dp = (int *)calloc(capacity + 1, sizeof(int));
for(int i=0; i<n; i++) {
for(int w=capacity; w>=weight[i]; w--) {
if(dp[w] < profit[i] + dp[w - weight[i]]) dp[w] = profit[i] + dp[w - weight[i]];
}
 
}
 int result = dp[capacity]; free(dp);
return result;
}
int main() {
 int n = 1000; // number of items
int capacity = 4000; // knapsack capacity struct Item items[n];
int weight[n], profit[n];
// Generate random items
srand(time(NULL));
for(int i=0; i<n; i++) {
items[i].weight = weight[i] = rand() % 50 + 1; items[i].profit = profit[i] = rand() % 100 + 1;
}
// Measure Greedy time
 clock_t start = clock();
float greedyProfit = fractionalKnapsack(items, n, capacity); clock_t end = clock();
double greedyTime = (double)(end - start) / CLOCKS_PER_SEC;
// Measure DP time
start = clock();
int dpProfit = knapsackDP(weight, profit, n, capacity); end = clock();
 
double dpTime = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Fractional Knapsack Profit = %.2f, Time = %.6f seconds\n", greedyProfit, greedyTime);
printf("0/1 Knapsack Profit = %d, Time = %.6f seconds\n", dpProfit, dpTime);
return 0; }
