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
*	执行用时：4 ms, 在所有 C++ 提交中击败了98.59%的用户
*	内存消耗：6.5 MB, 在所有 C++ 提交中击败了78.07%的用户
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

	vector<int> res(num1.size() + num2.size());

	for (int i = num1.size() - 1; i >= 0; i--)
	{
		for (int j = num2.size() - 1; j >= 0; j--)
		{
			int ans = res[i + j + 1] + (num1[i] - '0') * (num2[j] - '0');

			res[i + j + 1] = ans % 10;										/*	从i+j+1倒叙填充到0，不用再反转了	*/
			res[i + j] += ans / 10;
		}
	}

	string result;
	for (int i = 0; i < res.size(); i++)
	{
		if (i == 0 && res[i] == 0)
		{
			continue;
		}
		result.push_back(res[i] + '0');
	}
	return result;
}

int main()
{
	string num1 = "456";
	string num2 = "123";
	cout << multiply(num1, num2) << endl;
}