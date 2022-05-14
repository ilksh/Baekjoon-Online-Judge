#include<iostream>
#include<string.h>
using namespace std;
bool is_used[26];
int cnt;

bool check(string word)
{
	memset(is_used, 0, sizeof(is_used));
	is_used[word[0] - 'a'] = true;

	int word_size = word.length();
	for (int i = 1; i < word_size; i++)
	{
		int cur = word[i] - 'a';
		if (is_used[cur] && word[i] != word[i - 1])
			return false;

		is_used[cur] = true;
		
	}
	return true;
}

int main()
{
	string s;
	int test_case;
	cin >> test_case;
	while (test_case--)
	{
		cin >> s;
		if (check(s) == true)
			cnt++;
	}
	cout << cnt;
}