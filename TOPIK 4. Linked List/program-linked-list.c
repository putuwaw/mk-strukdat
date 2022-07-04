#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct node
{
  int data;
  struct node *next;
  struct node *prev;
} node;

node *head, *tail, *temp1, *temp2;

void init()
{
  head = tail = NULL;
}

int isEmpty()
{
  if (head == NULL && tail == NULL)
  {
    return TRUE;
  }
  return FALSE;
}

void push_back(int num)
{
  if (isEmpty())
  {
    temp1 = malloc(sizeof(node));
    temp1->data = num;
    temp1->next = NULL;
    temp1->prev = NULL;
    head = temp1;
    tail = temp1;
  }
  else
  {
    temp1 = head;
    while (temp1->next != NULL)
    {
      temp1 = temp1->next;
    }
    temp2 = malloc(sizeof(node));
    temp1->next = temp2;
    temp2->data = num;
    temp2->prev = temp1;
    temp2->next = NULL;
    tail = temp2;
  }
}
void push_front(int num)
{
  if (isEmpty())
  {
    temp1 = malloc(sizeof(node));
    temp1->data = num;
    temp1->next = NULL;
    temp1->prev = NULL;
    head = temp1;
    tail = temp1;
  }
  else
  {
    if (head->next == NULL)
    {
      temp1 = malloc(sizeof(node));
      temp1->data = num;
      temp1->next = head;
      temp1->prev = NULL;
      head = temp1;
      tail->prev = temp1;
    }
    else
    {
      temp1 = malloc(sizeof(node));
      temp1->data = num;
      temp1->next = head;
      temp1->prev = NULL;
      head = temp1;
    }
  }
}
void pop_back()
{
  if (isEmpty())
  {
    printf("Tidak bisa melakukan pop back, linked list kosong!\n");
  }
  else
  {
    temp1 = head;
    if (temp1->next == NULL)
    {
      head = tail = NULL;
      free(temp1);
      temp1 = NULL;
    }
    else
    {
      while (temp1->next != NULL)
      {
        temp1 = temp1->next;
      }
      tail = temp1->prev;
      tail->next = NULL;
      free(temp1);
      temp1 = NULL;
    }
    printf("Pop back berhasil dilakukan\n");
  }
}
void pop_front()
{
  if (isEmpty())
  {
    printf("Tidak bisa melakukan pop front, linked list kosong!\n");
  }
  else
  {
    if (head->next == NULL)
    {
      free(head);
      head = tail = NULL;
    }
    else
    {
      temp1 = head;
      head = head->next;
      head->prev = NULL;
      free(temp1);
      temp1 = NULL;
    }
    printf("Pop front berhasil dilakukan\n");
  }
}

void view()
{
  if (isEmpty())
  {
    printf("Linked list masih kosong!\n");
  }
  else
  {
    temp1 = head;
    while (temp1 != NULL)
    {
      printf("%d ", temp1->data);
      temp1 = temp1->next;
    }
    printf("\n");
  }
}

int main()
{
  init();
  init();
  int pil, number;
  do
  {
    system("cls");
    printf("================================\n");
    printf("      PROGRAM LINKED-LIST       \n");
    printf("================================\n");
    printf("1. Tambah data di belakang (push back)\n");
    printf("2. Tambah data di depan (push front)\n");
    printf("3. Hapus data di belakang (pop back)\n");
    printf("4. Hapus data di depan (pop front)\n");
    printf("5. Cek apakah linked list kosong\n");
    printf("6. Tampilkan linked list\n");
    printf("7. Keluar\n");
    printf("Pilihan: ");
    scanf("%d", &pil);
    switch (pil)
    {
    case 1:
      system("cls");
      printf("Masukkan data yang akan ditambahkan di belakang: ");
      scanf("%d", &number);
      push_back(number);
      printf("Data berhasil ditambahkan\n");
      system("pause");
      break;
    case 2:
      system("cls");
      printf("Masukkan data yang akan ditambahkan di depan: ");
      scanf("%d", &number);
      push_front(number);
      printf("Data berhasil ditambahkan\n");
      system("pause");
      break;
    case 3:
      system("cls");
      pop_back();
      system("pause");
      break;
    case 4:
      system("cls");
      pop_front();
      system("pause");
      break;
    case 5:
      system("cls");
      if (isEmpty())
      {
        printf("Linked list kosong!\n");
      }
      else
      {
        printf("Linked list tidak kosong!\n");
      }
      system("pause");
      break;
    case 6:
      system("cls");
      view();
      system("pause");
      break;
    case 7:
      return 0;
      break;
    default:
      printf("Input harus antara 1 sampai 7!\n");
      break;
    }
  } while (TRUE);
  return 0;
}