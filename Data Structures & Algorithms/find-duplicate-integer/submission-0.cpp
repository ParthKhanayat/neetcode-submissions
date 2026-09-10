class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //FLOYD'S ALGORITHM
        int slow=0;
        int fast=0;
        //Phase 1
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);

        //Phase 2
        int slow2=0;
        do{
            slow=nums[slow];
            slow2=nums[slow2];
        }while(slow!=slow2);
        return slow;
    }
};
