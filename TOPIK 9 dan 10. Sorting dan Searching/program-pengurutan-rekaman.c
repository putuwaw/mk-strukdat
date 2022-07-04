#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct mahasiswa
{
  int nim;
  char nama[100];
  char alamat[100];
  char gol;
  struct mahasiswa *next;
} mhs;
mhs *head, *curr, *temp;
void tambah_data()
{
  curr = (mhs *)malloc(sizeof(mhs));
  printf("Masukkan NIM Mahasiswa: ");
  scanf("%d", &curr->nim);
  fflush(stdin);
  printf("Masukkan Nama Mahasiswa: ");
  gets(curr->nama);
  printf("Masukkan Alamat Mahasiswa: ");
  gets(curr->alamat);
  printf("Masukkan Golongan Mahasiswa: ");
  scanf("%c", &curr->gol);
  if (head == NULL)
  {
    head = curr;
    curr->next = NULL;
  }
  else
  {
    temp = head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = curr;
    curr->next = NULL;
  }
}
void sort_nama_alamat()
{
  bool sorted = false;
  while (!sorted)
  {
    sorted = true;
    curr = head;
    while (curr->next != NULL)
    {
      int compName = strcmp(curr->nama, curr->next->nama);
      int compAlamat = strcmp(curr->alamat, curr->next->alamat);
      if (compName > 0)
      {
        // create temp
        sorted = false;
        temp = (mhs *)malloc(sizeof(mhs));
        temp->nim = curr->nim;
        strcpy(temp->nama, curr->nama);
        strcpy(temp->alamat, curr->alamat);
        temp->gol = curr->gol;
        // first swap
        curr->nim = curr->next->nim;
        strcpy(curr->nama, curr->next->nama);
        strcpy(curr->alamat, curr->next->alamat);
        curr->gol = curr->next->gol;
        // second swap
        curr->next->nim = temp->nim;
        strcpy(curr->next->nama, temp->nama);
        strcpy(curr->next->alamat, temp->alamat);
        curr->next->gol = temp->gol;
        // free
        free(temp);
        temp = NULL;
      }
      else if (compName == 0 && compAlamat > 0) // same name
      {
        // create temp
        sorted = false;
        temp = (mhs *)malloc(sizeof(mhs));
        temp->nim = curr->nim;
        strcpy(temp->nama, curr->nama);
        strcpy(temp->alamat, curr->alamat);
        temp->gol = curr->gol;
        // first swap
        curr->nim = curr->next->nim;
        strcpy(curr->nama, curr->next->nama);
        strcpy(curr->alamat, curr->next->alamat);
        curr->gol = curr->next->gol;
        // second swap
        curr->next->nim = temp->nim;
        strcpy(curr->next->nama, temp->nama);
        strcpy(curr->next->alamat, temp->alamat);
        curr->next->gol = temp->gol;
        // free
        free(temp);
        temp = NULL;
      }
      curr = curr->next;
    }
  }
}
void sort_gol_nama()
{
  bool sorted = false;
  while (!sorted)
  {
    sorted = true;
    curr = head;
    while (curr->next != NULL)
    {
      int compName = strcmp(curr->nama, curr->next->nama);
      if (curr->gol > curr->next->gol)
      {
        // create temp
        sorted = false;
        temp = (mhs *)malloc(sizeof(mhs));
        temp->nim = curr->nim;
        strcpy(temp->nama, curr->nama);
        strcpy(temp->alamat, curr->alamat);
        temp->gol = curr->gol;
        // first swap
        curr->nim = curr->next->nim;
        strcpy(curr->nama, curr->next->nama);
        strcpy(curr->alamat, curr->next->alamat);
        curr->gol = curr->next->gol;
        // second swap
        curr->next->nim = temp->nim;
        strcpy(curr->next->nama, temp->nama);
        strcpy(curr->next->alamat, temp->alamat);
        curr->next->gol = temp->gol;
        // free
        free(temp);
        temp = NULL;
      }
      else if ((curr->gol == curr->next->gol) && compName > 0)
      {
        // create temp
        sorted = false;
        temp = (mhs *)malloc(sizeof(mhs));
        temp->nim = curr->nim;
        strcpy(temp->nama, curr->nama);
        strcpy(temp->alamat, curr->alamat);
        temp->gol = curr->gol;
        // first swap
        curr->nim = curr->next->nim;
        strcpy(curr->nama, curr->next->nama);
        strcpy(curr->alamat, curr->next->alamat);
        curr->gol = curr->next->gol;
        // second swap
        curr->next->nim = temp->nim;
        strcpy(curr->next->nama, temp->nama);
        strcpy(curr->next->alamat, temp->alamat);
        curr->next->gol = temp->gol;
        // free
        free(temp);
        temp = NULL;
      }
      curr = curr->next;
    }
  }
}
void lihat_data()
{
  curr = head;
  while (curr != NULL)
  {
    printf("NIM: %d\n", curr->nim);
    printf("Nama: %s\n", curr->nama);
    printf("Alamat: %s\n", curr->alamat);
    printf("Golongan: %c\n", curr->gol);
    printf("\n");
    curr = curr->next;
  }
}
int main()
{
  head = NULL;
  do
  {
    system("cls");
    printf("PROGRAM MENGURUTKAN REKAMAN\n");
    printf("=============================\n");
    printf("1. Tambah Mahasiswa\n");
    printf("2. Urutkan data menurut nama + alamat\n");
    printf("3. Urutkan data menurut golongan + nama\n");
    printf("4. Exit\n");
    int pil;
    printf("Masukkan Pilihan : ");
    scanf("%d", &pil);
    switch (pil)
    {
    case 1:
      system("cls");
      tambah_data();
      system("pause");
      break;
    case 2:
      system("cls");
      sort_nama_alamat();
      lihat_data();
      system("pause");
      break;
    case 3:
      system("cls");
      sort_gol_nama();
      lihat_data();
      system("pause");
      break;
    case 4:
      return 0;
      break;
    default:
      printf("Pilihan harus 1-4!\n");
      break;
    }
  } while (true);
  return 0;
}