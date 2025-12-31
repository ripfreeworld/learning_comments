#include <algorithm>
#include <iostream>
#include <vector>

/*
有一堆长度不一的积木，把这堆积木叠成一面墙，墙的每层可以放一个积木，或将两个积木拼接起来，要求每层的长度相同。
若必须用完这些积木，叠成的墙最多为多少层?

输出描述
输出一个数字，为墙的最大层数，如果无法按要求叠成每层长度一致的墙，则输出-1。
*/

int CheckNumLevels(std::vector<int> vecNums)
{
	if (vecNums.empty())
	{
		return 0;
	}
	std::sort(vecNums.begin(), vecNums.end(), std::greater<>());
	auto size = static_cast<int>(vecNums.size());

	auto left = vecNums.begin();
	auto right = vecNums.end() - 1;

	// all elements are same
	if (*left == *right)
	{
		return size;
	}

	// normal case
	int res = 0;
	// assumption: length of each level equals left
	int maxLength = *left;
	while (left < right)
	{
		if (*left == maxLength)
		{
			++left; // move iterator
			++res;
		}
		else
		{
			break;
		}
	}
	std::size_t count = std::distance(left, vecNums.end());
	// left and right should not point to a same element in the middle, which is not sufficient to compose a level
	if (count % 2 == 0)
	{
		while (left < right)
		{
			if (*left + *right == maxLength)
			{
				++left;
				--right;
				++res;
			}
			else
			{
				break;
			}
		}
		// this assumption has made to the end - this must yield a higher result than the other
		if (left > right)
		{
			return res;
		}
	}

	// the other assumption: length of each level equals left + right
	if (size % 2 != 0)
	{
		// odd count cannot be fully paired
		return -1;
	}
	// reset
	left = vecNums.begin();
	right = vecNums.end() - 1;

	maxLength = *left + *right;
	while (left < right)
	{
		if (*left + *right == maxLength)
		{
			++left;
			--right;
		}
		else
		{
			return -1;
		}
	}

	return size / 2;
}

int main()
{
	std::vector<int> input = { 6, 3, 3, 6};

	int res = CheckNumLevels(input);

	std::cout << res << std::endl;
}
