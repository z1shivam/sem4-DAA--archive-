#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent items
struct Item {
    int weight;
    int value;
};

// Comparator function to sort items by value per unit weight
bool compareItems(const Item& item1, const Item& item2) {
    return (double)item1.value / item1.weight > (double)item2.value / item2.weight;
}

// Function to solve the Fractional Knapsack problem
double fractionalKnapsack(int capacity, vector<Item>& items) {
    double maxValue = 0.0;

    // Sort items based on value per unit weight
    sort(items.begin(), items.end(), compareItems);

    // Iterate through items and add them to knapsack
    for (int i = 0; i < items.size(); ++i) {
        const Item& item = items[i];
        if (capacity <= 0) {
            break;
        }

        // If weight of item is less than or equal to remaining capacity, include it entirely
        if (item.weight <= capacity) {
            maxValue += item.value;
            capacity -= item.weight;
        } else { // Otherwise, include a fraction of it
            maxValue += ((double)capacity / item.weight) * item.value;
            break; // Capacity exhausted
        }
    }

    return maxValue;
}

int main() {
     vector<Item> items;
    items.push_back({10, 60});
    items.push_back({30, 100});
    items.push_back({30, 120});

    int capacity = 50;

    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value possible = " << maxValue << endl;

    return 0;
}


