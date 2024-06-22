//#include <iostream>
//#include <cstring>
//#include<ctime>
#include<bits/stdc++.h>
using namespace std;

// Function to find the length of the Longest Common Subsequence (LCS)
int LCSLength(string X, string Y, string &lcs) {
    int m = X.length();
    int n = Y.length();
    
    int dp[m + 1][n + 1];

    // Initialize the dp array
    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= n; j++)
        dp[0][j] = 0;

    // Fill the dp array in bottom-up manner
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    // Backtrack to construct the LCS
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs = X[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    
    return dp[m][n];
}

int main() {
    string X = "ACGGA";
    string Y = "ACTG";
    string lcs = "";
   
    int z=LCSLength(X,Y,lcs);
   
    cout << "Length of Longest Common Subsequence: " << z << endl;
    cout << "Longest Common Subsequence: " << lcs << endl;
  
    return 0;
}

