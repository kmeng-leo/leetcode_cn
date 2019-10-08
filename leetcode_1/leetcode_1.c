/*
int* twoSum(int* nums, int numsSize, int target, int *returnSize)
{
    int i, temp;
    int maximum = 0;
    int *map_table = NULL;
    static int a[2]={0};
    
    for (i = 0; i < numsSize; i++) {
        if (nums[i] > maximum) {
            maximum = nums[i];
        }
    }

    map_table = (int *)malloc(sizeof(int) * (maximum + 1));
    memset(map_table, -1, sizeof(int) * (maximum + 1));
    
    for (i = 0; i < numsSize; i++) {
        map_table[nums[i]] = i;
    }
    
    for (i = 0; i < numsSize; i++) {
        temp = target - nums[i];
        if (temp > 0) {
            if (map_table[temp] > 0) {
                a[0] = i;
                a[1] = map_table[temp];
                *returnSize = 2;
                return a;
            }
        }
    }
    
	for (int i = 0; i < numsSize - 1; i++)
	{
		for (int j = i+1; j < numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				a[0] = i;
				a[1] = j;
                *returnSize = 2;
				return a;
			}
		}
	}
	return 0;
}
*/
    
int* twoSum(int* nums, int numsSize, int target, int *returnSize)
{
    static int a[2]={0};
    
	for (int i = 0; i < numsSize - 1; i++)
	{
		for (int j = i+1; j < numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				a[0] = i;
				a[1] = j;
                *returnSize = 2;
				return a;
			}
		}
	}
	return 0;
}
