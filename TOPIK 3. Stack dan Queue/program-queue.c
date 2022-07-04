#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int *data, head, tail;
} Queue;

Queue antrian;
int MAX = 5, *temp;

void create()
{
  antrian.data = (int *)malloc(MAX * sizeof(int));
  antrian.head = antrian.tail = -1;
}
int isEmpty()
{
  if (antrian.head == -1)
  {
    return 1;
  }
  return 0;
}
int isFull()
{
  if (antrian.tail == MAX - 1)
  {
    return 1;
  }
  return 0;
}
void push(int num)
{
  if (isEmpty())
  {
    antrian.head += 1;
  }
  else if (isFull())
  {
    temp = (int *)malloc(MAX * 2 * sizeof(int));
    int i;
    for (i = 0; i < MAX; i++)
    {
      temp[i] = antrian.data[i];
    }
    free(antrian.data);
    antrian.data = temp;
    MAX *= 2;
  }
  antrian.tail++;
  antrian.data[antrian.tail] = num;
}
void pop()
{
  if (isEmpty())
  {
    printf("Tidak bisa pop, queue underflow!\n");
  }
  else
  {
    int i;
    for (i = 0; i < antrian.tail; i++)
    {
      antrian.data[i] = antrian.data[i + 1];
    }
    antrian.tail -= 1;
  }
}
void search(int num)
{
  int i;
  for (i = 0; i <= antrian.tail; i++)
  {
    if (antrian.data[i] == num)
    {
      printf("Elemen %d berada pada urutan ke-%d\n", num, i + 1);
    }
  }
}
void edit(int pos, int edit)
{
  printf("Melakukan pengeditan pada elemen urutan ke %d\n", pos);
  printf("Nilai awal elemen adalah: %d\n", antrian.data[pos - 1]);
  antrian.data[pos - 1] = edit;
  printf("Nilai setelah diedit adalah: %d\n", antrian.data[pos - 1]);
}
void info()
{
  int maxData, minData, sum = 0, i;
  float avg;
  for (i = 0; i <= antrian.tail; i++)
  {
    sum += antrian.data[i];
    if (i == 0)
    {
      maxData = antrian.data[i];
      minData = antrian.data[i];
    }
    else
    {
      if (antrian.data[i] > maxData)
      {
        maxData = antrian.data[i];
      }
      else if (antrian.data[i] < minData)
      {
        minData = antrian.data[i];
      }
    }
  }
  printf("Nilai total dari queue adalah: %d\n", sum);
  avg = (float)sum / antrian.tail;
  printf("Nilai rata-rata dari queue adalah: %f\n", avg);
  printf("Elemen terbesar dari queue adalah: %d\n", maxData);
  printf("Elemen terkecil dari queue adalah: %d\n", minData);
}
void view()
{
  int i;
  for (i = 0; i <= antrian.tail; i++)
  {
    printf("%d ", antrian.data[i]);
  }
}
int main()
{
  // initiation
  create();
  // process
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);
  push(6);
  pop();
  push(1);
  pop();
  push(2);
  push(3);
  push(4);
  push(5);
  push(6);
  search(4);
  edit(5, 100);
  info();
  view();
  return 0;
}