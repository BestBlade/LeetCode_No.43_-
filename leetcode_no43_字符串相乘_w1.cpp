/*------------------------------------------------------------------|
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/multiply-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	旋转四角
*
*	执行用时：52 ms, 在所有 C++ 提交中击败了28.94%的用户
*	内存消耗：14.3 MB, 在所有 C++ 提交中击败了11.18%的用户
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

string multiply(string num1, string num2)
{
	if (num1.size() < num2.size())
	{
		return multiply(num2, num1);
	}

	if (num2 == "0")
	{
		return num2;
	}

	vector<vector<int> > res;

	for (int i = num1.size() - 1; i >= 0; i--)
	{
		vector<int> ans;
		int overflow = 0;
		int x = 0;
		int j = num2.size() - 1;

		while (j >= 0)
		{
			x = (num1[i] - '0') * (num2[j] - '0') + overflow;
			ans.push_back(x % 10);
			overflow = x / 10;
			j--;
		}

		if (j == -1 && overflow != 0)
		{
			ans.push_back(overflow);
			res.push_back(ans);
		}
		else
		{
			res.push_back(ans);
		}
	}

	vector<int> k(num1.size() + num2.size());

	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			k[i + j] += res[i][j];
			if (k[i + j] > 9)
			{
				k[i + j] -= 10;
				k[i + j + 1]++;
			}
		}
	}
	if (k[k.size() - 1] == 0)
	{
		k.pop_back();
	}
	reverse(k.begin(), k.end());

	string result;
	for (int i = 0; i < k.size(); i++)
	{
		result.push_back(k[i] + '0');
	}
	return result;
}

int main()
{
	string num1 = "99";
	string num2 = "9";

	cout << multiply(num1, num2) << endl;
}