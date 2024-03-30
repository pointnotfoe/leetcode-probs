/*
Author: pointnotfoe
Leetcode: https://leetcode.com/problems/find-median-from-data-stream/
295. Find Median from Data Stream
Hard

6456

122

Add to List

Share
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 

Constraints:

-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.
 

Follow up:

If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
*/
/*
Runtime: 623 ms, faster than 15.99% of C++ online submissions for Find Median from Data Stream.
Memory Usage: 117.1 MB, less than 66.50% of C++ online submissions for Find Median from Data Stream.
*/
class MedianFinder {
public:
    MedianFinder(){
        
    }
    
    void addNum(int num) {
        lower.push(num);
        upper.push(-lower.top());
        lower.pop();
        if (lower.size() < upper.size())
        {
          lower.push(-upper.top());
          upper.pop();
        }
    }
    
    double findMedian() {
        double median = lower.top();
        if ( lower.size() <= upper.size() )
        {
          median = (median +(-1.0 * upper.top())) /2;
        }
        return median;
    }
  priority_queue<int> lower;
  priority_queue<int> upper;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/*educative, grokking the coding interview
Runtime: 300 ms, faster than 90.71% of C++ online submissions for Find Median from Data Stream.
Memory Usage: 117.2 MB, less than 22.33% of C++ online submissions for Find Median from Data Stream.
*/
class MedianFinder {
public:
    MedianFinder(){
        
    }
    
    void addNum(int num) {
        if (maxHeap.empty() || maxHeap.top() >= num) {
          maxHeap.push(num);
        } else {
          minHeap.push(num);
        }

        // either both the heaps will have equal number of elements or max-heap will have one
        // more element than the min-heap
        if (maxHeap.size() > minHeap.size() + 1) {
          minHeap.push(maxHeap.top());
          maxHeap.pop();
        } else if (maxHeap.size() < minHeap.size()) {
          maxHeap.push(minHeap.top());
          minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
          // we have even number of elements, take the average of middle two elements
          return maxHeap.top() / 2.0 + minHeap.top() / 2.0;
        }
        // because max-heap will have one more element than the min-heap
        return maxHeap.top();
    }
  priority_queue<int> maxHeap;                             // containing first half of numbers
  priority_queue<int, vector<int>, greater<int>> minHeap;  // containing second half of numbers

};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


//timelimit exceeded
class MedianFinder {
public:
    MedianFinder():data(),cached_mean(0.0),cached_size(0) {
        
    }
    
    void addNum(int num) {
        data.insert((double)num);
    }
    
    double findMedian() {
        size_t size = data.size();
        if (cached_size == size)
        {
            return cached_mean;
        }
        cached_size = size;
        multiset<double>::iterator itr = data.begin();
        std::advance(itr, (size-1)/2);
        cached_mean = (*itr);
        if ((size % 2) == 0)//even number of elements
        {
            //++itr;
            //ans += (*++itr);
            //ans = (ans/2.0);            
            cached_mean = (cached_mean + (*++itr))/2.0;
        }
        return cached_mean;
    }
    multiset<double> data;
    double cached_mean;
    size_t cached_size;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */