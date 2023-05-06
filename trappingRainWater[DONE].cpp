#include <bits/stdc++.h>

using namespace std;

//precalculation
int trap(vector<int>& height) {
    int res = 0;
    int n = height.size();

    vector<int> left(height.size());
    vector<int> right(height.size());

    int water = 0;

    left[0] = height[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i-1], height[i]);
    
    right[n-1] = height[n-1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i+1], height[i]);

    for (int i = 1; i < n - 1; i++)
    {
        int var = min(left[i-1], right[i+1]);
        if (var > height[i]){
            water += var - height[i];
        }
    }

    return water;
}

//using stack
int maxWaterUsingStack(vector<int> &height){
    stack<int> st;

    int ans = 0;
    int n = height.size();

    for(int i = 0; i < n; i++){
        while((!st.empty()) && (height[st.top()] < height[i])){
            int pop_height = height[st.top()];
            st.pop();

            if (st.empty())
                break;

            int distance = i - st.top() - 1;

            int min_height = min(height[st.top()], height[i]) - pop_height;

            ans += distance * min_height;
        }
        st.push(i);
    }
    return ans;
}

//horizontal scan method
int trappedWater(vector<int>& arr)
{
    int num_blocks = 0;
    int n = 0;
    int max_height = INT_MIN;
  
    // Find total blocks, max height and length of array
    for (auto height : arr) {
        num_blocks += height;
        n += 1;
        max_height = max(max_height, height);
    }
  
    // Total water, left pointer and right pointer
    // initialized to 0 and n - 1
    int total = 0;
    int left = 0;
    int right = n - 1;
  
    for (int i = 1; i <= max_height; i++) {
  
        // Find leftmost point greater than current row (i)
        while (arr[left] < i)
            left += 1;
  
        // Find rightmost point greater than current row (i)
        while (arr[right] < i)
            right -= 1;
  
        // water in this row = right - left  + 1
        total += (right - left + 1);
    }
  
    total -= num_blocks;
    return total;
}


//two pointer
int maxWater(int arr[], int n)
{ 
    // Indices to traverse the array
    int left = 0;
    int right = n-1;
   
    // To store Left max and right max 
    // for two pointers left and right
    int l_max = 0;
    int r_max = 0;
   
    // To store the total amount 
    // of rain water trapped
    int result = 0;
    while (left <= right)
    {
   
      // We need check for minimum of left 
      // and right max for each element
      if(r_max <= l_max)
      {
   
        // Add the difference between 
        // current value and right max at index r
        result += max(0, r_max-arr[right]);
   
        // Update right max
        r_max = max(r_max, arr[right]);
   
        // Update right pointer
        right -= 1;
      }
      else
      { 
   
        // Add the difference between 
        // current value and left max at index l
        result += max(0, l_max-arr[left]);
   
        // Update left max
        l_max = max(l_max, arr[left]);
   
        // Update left pointer
        left += 1;
      }
    }
    return result;
}