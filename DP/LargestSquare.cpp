#include<iostream>
#include<algorithm>
using namespace std;

int getLargestSquare(vector<vector<int>> G, int H, int W)
{
    int maxWidth = 0;
    int dp[H][W];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            dp[i][j] = (G[i][j] + 1) % 2;
            maxWidth |= dp[i][j];
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (G[i][j]) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                maxWidth = max(maxWidth, dp[i][j]);
            }

        }
    }

    return maxWidth * maxWidth;
}


int main(void)
{
    int H, W;
    cin >> H >> W;
    vector<vector<int>> G(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> G[i][j]; 
        }
    }
    cout << getLargestSquare(G, H, W) << endl;

    return 0;
}