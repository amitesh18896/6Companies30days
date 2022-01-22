class Solution {
public:
    // 1. IDENTIFY PEAKS
    // 2. TRAVERSE BACKWARDS WHILE PREVIOUS ELEMENT -
    // - IS SMALLER THAT CURRENT (i.e. GO TO THE START ROOT OF THE MOUNTAIN)
    // 3. TRAVERSE FORWARD WHILE NEXT ELEMENT IS SMALLER THAN CURRENT 
    // (i.e. GO TO THE END ROOT OF THE MOUNTAIN)
    // 4 . ADD THEM TO CALCULATE THE MOUNTAIN LENGTH
   // Ans in one pass
   //O(N) ,O(1)
    int longestMountain(vector<int>& arr) {
        if(arr.size() == 0)
            return 0;
        int n=arr.size();
        int maxlength=0;
        for(int i=1;i<n-1;i++)
        {
            if((arr[i]>arr[i-1]) && (arr[i]>arr[i+1])) //peak found
            {
                // int start_of_mnt=i-1;
                // int end_of_mnt=i+1;
                
                int start_of_mnt=i;
                int end_of_mnt=i;
                
                while(start_of_mnt>0 && arr[start_of_mnt]>arr[start_of_mnt-1])
                {
                    start_of_mnt--;//getting to the start of mountain
                }
                while(end_of_mnt<n-1 && arr[end_of_mnt]>arr[end_of_mnt+1])
                {
                    end_of_mnt++;//getting to the last of the mountain
                }
                maxlength=max(maxlength,end_of_mnt-start_of_mnt+1); //find highest length of mountain
                i=end_of_mnt;
                
            }
        }
        return maxlength;
    }
};


//ans in two passes forward pass,backward pass

