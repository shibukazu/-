#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 11
#define MAXK 100
#define MAXLINE 255
char *W[N] = {"break", "case", "continue", "do", "else", "for", "goto", "if", "return", "switch", "while"};
int A[N];
int C[MAXK];

void main()
{
  int i, j, k = 0;
  char *B[N];
  char line[MAXLINE];
  FILE *fp;
  fp = fopen("./2008-input.txt", "r");
  while (fgets(line, MAXLINE, fp) != NULL)
  {
    for (j = 0; j < N; j++)
      if (strstr(line, W[j]) != NULL)
      {
        A[j]++;
        if (k < A[j])
        {
          if (k < MAXK)
            k = A[j];
          else
            exit(1);
        }
      }
  }
  fclose(fp);
  for (j = 0; j < N; j++)
    C[A[j]]++;
  for (i = k; i >= 0; i--)
  {
    for (j = 0; j < N; j++)
    {
      if (A[j] == i)
      {
        printf("%s\n", W[j]);
        C[i]--;
      }
      if (C[i] == 0)
        break;
    }
  }
  /*
  for (i = k - 1; i >= 0; i--)
    C[i] += C[i + 1];
  for (j = N; j >= 0; j--)
  {
    B[C[A[j]] - 1] = W[j];
    C[A[j]]--;
  }
  for (j = 0; j < N; j++)
    printf("%s\n", B[j]);
  */
}