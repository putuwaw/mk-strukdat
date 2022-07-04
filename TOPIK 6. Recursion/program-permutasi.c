#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int n;

void permutation(int level, int *save, bool *isUsed)
{
  if (level > n)
  {
    int i;
    for (i = 1; i <= n; i++)
    {
      int temp = save[i] + 64;
      char chr = temp;
      printf("%c ", chr);
    }
    printf("\n");
  }
  else
  {
    int a;
    for (a = 1; a <= n; a++)
    {
      if (!isUsed[a])
      {
        isUsed[a] = true;
        save[level] = a;
        permutation(level + 1, save, isUsed);
        isUsed[a] = false;
      }
    }
  }
}

int main()
{
  printf("N = ");
  scanf("%d", &n);
  int *save;
  bool *isUsed;
  save = malloc(n * sizeof(int));
  isUsed = malloc(n * sizeof(bool));
  memset(isUsed, 0, sizeof(isUsed));
  memset(save, 0, sizeof(save));
  permutation(1, save, isUsed);
  return 0;
}