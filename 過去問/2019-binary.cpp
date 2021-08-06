#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main()
{
  for (int i1 = 0; i1 < 2; i1++)
  {
    for (int i2 = 0; i2 < 2; i2++)
    {
      for (int i3 = 0; i3 < 2; i3++)
      {
        for (int i4 = 0; i4 < 2; i4++)
        {
          for (int i5 = 0; i5 < 2; i5++)
          {
            bool firsteq = ~(~i1 | (~i3 & ~i4) | (i1 & i4) | (i1 & ~i2 & i3));
            bool secondeq = ~(((~i4 & ~i5) | (~i1 & ~i4 & i5)) | (i1 & ~i2) | i4);
            if (firsteq & secondeq == 1)
            {
              cout << i1 << " " << i2 << " " << i3 << " " << i4 << " " << i5 << endl;
            }
          }
        }
      }
    }
  }
}