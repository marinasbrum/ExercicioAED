# include <stdio.h>

int searchInsert(int nums[], int numsSize, int target){
		for (int i = 0; i < numsSize; i++)
			if (nums[i] == target)
        return i;
			else if (nums[i] > target)
            return i;
}

int main(){
		int nums[] = { 3, 5, 6 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 2;
    printf("%d\n", searchInsert(nums, numsSize, target));
    return 0;
}