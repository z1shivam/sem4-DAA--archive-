#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainMultiplication(vector<int>& p, int i, int j) {
    if (i == j)
        return 0;
    
    int minOps = INT_MAX;
    for (int k = i; k < j; k++) {
        int cost = matrixChainMultiplication(p, i, k) +
                   matrixChainMultiplication(p, k + 1, j) +
                   p[i - 1] * p[k] * p[j];
        
        if (cost < minOps)
            minOps = cost;
    }
    return minOps;
}

int main() {
    vector<int> p;
    p.push_back(3);
    p.push_back(7);
    p.push_back(6);
    p.push_back(2);
    p.push_back(9);
    
    int n = p.size();
    
    int minOperations = matrixChainMultiplication(p, 1, n - 1);
    
    cout << "Minimum number of multiplications needed: " << minOperations << endl;
    
    return 0;
}

