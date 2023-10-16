#include <queue>
#include <vector>
#include <functional> // for std::greater

int kth_largest(std::vector<int> values, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    for (int i = 0; i < k; ++i) {
        minHeap.push(values[i]);
    }
    for (int i = k; i < values.size(); ++i) {
        if (values[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(values[i]);
        }
    }
    return minHeap.top();
}
