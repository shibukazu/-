#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
vector<int> shifts;
//京大法＋通常構成法
void makeShifts(string pattern, string target)
{
  for (int j = 0; j < pattern.size(); j++)
  {
    int size = j - 1;
    bool found = false;
    while (size > 0 && !found)
    {
      for (int i = 0; i < size; i++)
      {
        if (pattern[i] != pattern[j - size + i])
        {
          size--;
          break;
        }
        else if (i == size - 1 && pattern[size] != pattern[j])
        {
          found = true;
          break;
        }
      }
    }
    if (size <= 0)
    {
      if (pattern[j] == pattern[0])
        shifts[j] = j + 1;
      else
        shifts[j] = j - 0;
    }
    else
      shifts[j] = j - size;
  }
}
int string_matcher(string text, string pattern)
{
  int i, j;
  j = 0;
  for (i = 0; i < text.length(); i++)
  {
    if (text[i] == pattern[j])
    {
      j = j + 1;
      if (j == pattern.length())
        return i - j + 1;
    }
    else
    {
      if (j < shifts[j])
        j = 0;
      else
        j = j - shifts[j], i = i - 1;
    }
  }
  return -1;
}
int main()
{
  string target, pattern;
  cin >> target >> pattern;
  shifts = vector<int>(pattern.length());
  makeShifts(pattern, target);
  cout << string_matcher(target, pattern) << endl;
}