// Day 31 — Heaps
// Problem: Find Median from Data Stream
//
// My notes:
// Pattern: Two Heaps
// Idea: Divide the numbers into two halves.
//       smallHeap is a max-heap containing the smaller half.
//       largeHeap is a min-heap containing the larger half.
//       The tops of the two heaps meet at the median junction.
//       Keep the heap sizes balanced so their sizes differ by at most 1.
//       If sizes are equal, median = average of both tops.
//       Otherwise, median = top of the larger heap.
//
// Why two heaps?
//       Max-heap gives the largest element of the smaller half.
//       Min-heap gives the smallest element of the larger half.
//       These two elements are exactly around the median.
//
// Time: O(log n) for addNum()
//       O(1) for findMedian()
// Space: O(n)


class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> smallHeap;
    priority_queue<int, vector<int>, greater<int>> largeHeap;
// LargeHeap is minHeap as its top gives us the element at the median junction and has the elements more than or equal to median so store min elements
// Exact oposite is for smallHeap
public:
    MedianFinder() {}
    
    void addNum(int num) {
        smallHeap.push(num);
        if(!largeHeap.empty() && smallHeap.top() > largeHeap.top()){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if(smallHeap.size() > largeHeap.size() + 1){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if(largeHeap.size() > smallHeap.size() + 1){
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {
        if(smallHeap.size() == largeHeap.size()){
            return (smallHeap.top() + largeHeap.top())/2.0;
        }
        else if(smallHeap.size() > largeHeap.size()){
            return double(smallHeap.top());
        }
        else{
            return double(largeHeap.top());
        }
    }
};

