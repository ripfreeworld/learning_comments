#include <algorithm>
#include <iostream>
#include <vector>


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
