

/*                                      *****CODESTUDIO******                                                   */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int signum(int a, int b)
{
    if (a == b)
        return 0;
    else if (a > b)
        return 1;
    else
        return -1;
}
void call_median(int element, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, int &median)
{
    switch (signum(maxHeap.size(), minHeap.size()))
    {
    case 0:
        if (element > median)
        {
            minHeap.push(element);
            median = minHeap.top();
        }
        else
        {
            maxHeap.push(element);
            median = maxHeap.top();
        }
        break;
    case 1:
        if (element > median)
        {
            minHeap.push(element);
            median = (maxHeap.top() + minHeap.top()) / 2;
        }
        else
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();

            maxHeap.push(element);

            median = (maxHeap.top() + minHeap.top()) / 2;
        }
        break;

    case -1:
        if (element < median)
        {
            maxHeap.push(element);
            median = (maxHeap.top() + minHeap.top()) / 2;
        }
        else
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();

            minHeap.push(element);

            median = (maxHeap.top() + minHeap.top()) / 2;
        }
        break;
    }
}

vector<int> findMedian(vector<int> &arr, int n)
{

    // Write your code here
    vector<int> ans;

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int median = -1;

    for (int i = 0; i < n; i++)
    {
        call_median(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }
    return ans;
}
int main()
{
    vector<int> arr{1,2,3};
    arr = findMedian(arr,3);

    for(int i=0;i<3;i++)
    {
        cout<<arr[i]<<" ";
    }
}