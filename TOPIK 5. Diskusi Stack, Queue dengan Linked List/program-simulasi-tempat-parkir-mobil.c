#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define MAX 30

typedef struct node
{
  char name[MAX];
  struct node *next;
  struct node *prev;
} car;

car *head, *tail, *m1;
int sumCar = 0;
char carName[MAX];

void init()
{
  head = tail = NULL;
}

int isEmpty()
{
  if (head == NULL)
  {
    return TRUE;
  }
  return FALSE;
}

int isFull()
{
  if (sumCar == MAX)
  {
    return TRUE;
  }
  return FALSE;
}

void add_car(char id[])
{ // push back
  if (isEmpty())
  {
    m1 = (car *)malloc(sizeof(car));
    strcpy(m1->name, id);
    head = tail = m1;
    head->next = head->prev = NULL;
    sumCar++;
    printf("Mobil berhasil ditambahkan!\n");
  }
  else if (isFull())
  {
    printf("Parkir Penuh!\n");
  }
  else
  {
    m1 = (car *)malloc(sizeof(car));
    strcpy(m1->name, id);
    m1->next = NULL;
    m1->prev = tail;
    tail->next = m1;
    tail = m1;
    sumCar++;
    printf("Mobil berhasil ditambahkan!\n");
  }
}

void remove_car(int pos)
{
  if (isEmpty())
  {
    printf("Parkir masih kosong, tidak ada yang bisa dikeluarkan!\n");
  }
  else
  {
    if (pos < 1 || pos > sumCar)
    {
      printf("Posisi tidak valid!\n");
    }
    else
    {
      if (sumCar == 1)
      { // jumlah mobil 1
        m1 = head;
        head = NULL;
        free(m1);
        m1 = NULL;
      }
      else
      { // mobil > 1
        if (pos == 1)
        { // head
          m1 = head;
          head = head->next;
          head->prev = NULL;
          free(m1);
          m1 = NULL;
        }
        else if (pos == sumCar)
        { // tail
          m1 = tail;
          tail = tail->prev;
          tail->next = NULL;
          free(m1);
          m1 = NULL;
        }
        else
        { // middle
          m1 = head;
          int i = 1;
          while (i != pos)
          {
            m1 = m1->next;
            i++;
          }
          m1->prev->next = m1->next;
          m1->next->prev = m1->prev;
          free(m1);
          m1 = NULL;
        }
      }
      sumCar--;
      printf("Mobil berhasil keluar!\n");
    }
  }
}
void view_car()
{
  if (isEmpty())
  {
    printf("Tempat parkir masih kosong!\n");
  }
  else
  {
    m1 = head;
    int i = 1;
    while (m1 != NULL)
    {
      if (i == 1)
      {
        printf("-----------------------\n");
      }
      printf("| [%d] %-15s | \n", i, m1->name);
      printf("-----------------------\n");
      m1 = m1->next;
      i++;
    }
  }
}

int main()
{
  init();
  do
  {
    system("cls");
    printf("=========================\n");
    printf("PROGRAM SIMULASI PARKIR\n");
    printf("=========================\n");
    printf("1. Tambah Mobil\n");
    printf("2. Mobil Keluar\n");
    printf("3. Lihat Parkir\n");
    printf("4. Exit\n");
    int pil;
    scanf("%d", &pil);
    switch (pil)
    {
    case 1:
      system("cls");
      char temp[MAX];
      printf("TAMBAH MOBIL\n");
      printf("===============\n");
      printf("Ketikkan identitas mobil (plat): ");
      fflush(stdin);
      gets(temp);
      add_car(temp);
      system("pause");
      break;
    case 2:
      system("cls");
      int pos;
      printf("KELUARKAN MOBIL\n");
      printf("===============\n");
      printf("Ketikkan posisi mobil yang akan dikeluarkan: ");
      scanf("%d", &pos);
      remove_car(pos);
      system("pause");
      break;
    case 3:
      system("cls");
      view_car();
      system("pause");
      break;
    case 4:
      return 0;
    default:
      printf("Input harus 1 sampai 3!\n");
      system("pause");
      break;
    }
  } while (TRUE);
}
