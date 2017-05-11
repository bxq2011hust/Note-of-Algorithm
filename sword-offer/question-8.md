## 面试题8 旋转数组的最小数字

<!-- TOC -->

- [面试题8 旋转数组的最小数字](#面试题8-旋转数组的最小数字)
- [题目](#题目)
    - [思路](#思路)
    - [实现](#实现)
    - [牛客网](#牛客网)

<!-- /TOC -->

## 题目
输入一个递增的数组的旋转，找出最小值

### 思路
1. 两个指针初始分别指向头`first`和尾`last`，指针`mid`指向中间元素
2. 如果`*mid>=*first`则`first=mid`；如果`*mid<=*last`则`last=mid`，重复直到`last-first==1`，此时`*last`即是最小值
3. 第二步时当`*first==*min==*last`则只能顺序遍历查找，例如`10111`与`11101`

### 实现
```cpp
int minNumberInRotateArray(int *nums, int len)
{
	if (nums == NULL || len <= 0)
		return 0;
        // throw new std::exception("Invalid parameters");
	int first = 0;
	int last = len - 1;
	int minIndex = first;
	while (nums[first] >= nums[last])
	{
		if (last - first == 1)
		{
			minIndex = last;
			break;
		}
		minIndex = (first + last) / 2;
		// 如果first last minIndex指向的三个数字相等，则只能顺序查找
		if (nums[first] == nums[minIndex] && nums[minIndex] == nums[last])
		{
			int minValue = nums[first];
			for (int i = first; i <= last; ++i)
			{
				if (minValue > nums[i])
					minValue = nums[i];
			}
		}
		if (nums[minIndex] >= nums[first])
			first = minIndex;
		else if (nums[minIndex] <= nums[last])
			last = minIndex;
	}
	return nums[minIndex];
}
``` 
### 牛客网
```cpp
class Solution
{
  public:
	int minNumberInRotateArray(vector<int> rotateArray)
	{
		if (rotateArray.empty())
			return 0;
		int first = 0;
		int last = rotateArray.size() - 1;
		int minIndex = first;
		while (rotateArray[first] >= rotateArray[last])
		{
			if (last - first == 1)
			{
				minIndex = last;
				break;
			}
			minIndex = (first + last) / 2;
			// 如果first last minIndex指向的三个数字相等，则只能顺序查找
			if (rotateArray[first] == rotateArray[minIndex] && rotateArray[minIndex] == rotateArray[last])
			{
				int minValue = rotateArray[first];
				for (int i = first; i <= last; ++i)
				{
					if (minValue > rotateArray[i])
						minValue = rotateArray[i];
				}
			}
			if (rotateArray[minIndex] >= rotateArray[first])
				first = minIndex;
			else if (rotateArray[minIndex] <= rotateArray[last])
				last = minIndex;
		}
		return rotateArray[minIndex];
	}
};
``` 

