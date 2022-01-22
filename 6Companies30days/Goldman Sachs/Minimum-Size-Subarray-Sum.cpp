// O(N) 
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left_pointer=0;
        int right_pointer=0;
        int sum_of_subarray=0;
        int min_size_of_subarray = INT_MAX;
        // Move pointer from begin to end and check if subarray sum >= target 
        while(right_pointer<nums.size())
        {
            sum_of_subarray += nums[right_pointer];
            //move the right pointer ahead
            right_pointer++;
            if(sum_of_subarray>=target)
            {
                while(sum_of_subarray>=target)
                {
                    min_size_of_subarray = min(min_size_of_subarray,right_pointer - left_pointer);
                    // Now move the left pointer and subtract its contribution from the sum of subarray till sum < target sum
                    sum_of_subarray -= nums[left_pointer];
                    left_pointer++;
                }
            }
        }
        return min_size_of_subarray == INT_MAX ? 0:min_size_of_subarray;
    }
};

