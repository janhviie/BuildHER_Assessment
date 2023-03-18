#include <bits/stdc++.h>
using namespace std;

// HARD 1
// QUESTION - Return the max sliding window.

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int i = 0, j = 0;
    deque<int> dq;
    vector<int> ans;

    while (j - i != k)
    {
        if (dq.empty())
        {
            dq.push_front(j);
        }
        else
        {
            // pops from front of dequeue until nums[j] is greater than front of dequeue
            while (!dq.empty() && nums[dq.front()] <= nums[j])
            {
                dq.pop_front();
            }
            dq.push_front(j);
        }
        j++;
    }

    ans.push_back(nums[dq.back()]);

    while (j < nums.size())
    {
        // pops the back element of dequeue if it lies outside of the window
        if (j - dq.back() > k - 1)
        {
            dq.pop_back();
        }

        // Keeps popping until nums[j] is greater than front of dequeue
        while (!dq.empty() && nums[dq.front()] <= nums[j])
        {
            dq.pop_front();
        }
        dq.push_front(j);

        // for every iteration of j, the back element of dequeue will be the largest element value in the window
        ans.push_back(nums[dq.back()]);
        j++;
    }

    return ans;
}

int main()
{
    // Input Format -:
    // First Line consisting of N, the length of array
    // Second Line consisting of K, the window size
    // Third Line - N space-separated integers, the elements of the array

    int len;
    cin>>len;
    int k;
    cin>>k;

    vector<int> arr;
    while (len--)
    {
       int elem;
       cin>>elem;
       arr.push_back(elem);
    }

    vector<int> ans;
    ans = maxSlidingWindow(arr,k);

    cout<<"Max Sliding Window values -: "<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}

// TIME COMPLEXITY - O(N) where N is length of array.
// SPACE COMPLEXITY - O(K) where K is size of window. Dequeue of size K is required for operation.