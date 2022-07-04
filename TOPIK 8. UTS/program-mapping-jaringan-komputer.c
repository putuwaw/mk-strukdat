#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
#define TRUE 1
#define FALSE 0

typedef struct
{
  char IP[100];
  char computerName[100];
  char computerPos[100];
} element;
element *hashTable[MAX];

unsigned long long int convertToInt(char *str)
{
  unsigned long long int result = 0;
  int len = strlen(str), i;
  for (i = 0; i < len; i++)
  {
    if (str[i] == '.')
    {
      continue;
    }
    else
    {
      result *= 10;
      result = result + (str[i] - '0');
    }
  }
  return result;
}

int getHashKey(unsigned long long int IP)
{
  // find the nearest prime number smaller than MAX
  int i, j, isPrime, key;
  for (i = MAX; i > 1; i--)
  {
    isPrime = TRUE;
    for (j = 2; j * j <= i; j++)
    {
      if (i % j == 0)
      {
        isPrime = FALSE;
        break;
      }
    }
    if (isPrime)
    {
      key = i;
      break;
    }
  }
  return IP % key;
}

void insertData(char *address, char *compName, char *compPos)
{
  unsigned long long int iAddress = convertToInt(address);
  int key = getHashKey(iAddress);
  while (hashTable[key] != NULL)
  {
    key++;
    key %= MAX;
  }
  hashTable[key] = (element *)malloc(sizeof(element));
  strcpy(hashTable[key]->IP, address);
  strcpy(hashTable[key]->computerName, compName);
  strcpy(hashTable[key]->computerPos, compPos);
  printf("Data berhasil ditambahkan!\n");
}

void viewData()
{
  int i;
  const char null[] = "--";
  printf("DATA MAPPING SISTEM JARINGAN KOMPUTER\n");
  printf("=======================================================\n");
  for (i = 0; i < MAX; i++)
  {
    if (hashTable[i] == NULL)
    {
      printf("%-3d | %-20s | %-20s | %-15s\n", i + 1, null, null, null);
    }
    else
    {
      printf("%-3d | %-20s | %-20s | %-15s\n", i + 1, hashTable[i]->IP, hashTable[i]->computerName, hashTable[i]->computerPos);
    }
  }
}

int findDeleteTarget(int key, char *ip, char *compName, char *compPos)
{
  int iplen = strlen(ip), name = strlen(compName), pos = strlen(compPos), i, noDiff = TRUE;
  for (int i = 0; i < iplen; i++)
  {
    if (ip[i] != hashTable[key]->IP[i])
    {
      noDiff = FALSE;
      return noDiff;
    }
  }
  if (noDiff)
  {
    for (i = 0; i < name; i++)
    {
      if (compName[i] != hashTable[key]->computerName[i])
      {
        noDiff = FALSE;
        return noDiff;
      }
    }
  }
  if (noDiff)
  {
    for (i = 0; i < pos; i++)
    {
      if (compPos[i] != hashTable[key]->computerPos[i])
      {
        noDiff = FALSE;
        return noDiff;
      }
    }
  }
  return noDiff;
}

void deleteData(char *address, char *compName, char *compPos)
{
  unsigned long long iAddress = convertToInt(address);
  int key = getHashKey(iAddress), maxRepeat = 2 * MAX, found = FALSE;
  while (maxRepeat)
  {
    if (hashTable[key] == NULL)
    {
      key++;
      maxRepeat--;
    }
    else
    {
      if (findDeleteTarget(key, address, compName, compPos))
      {
        found = TRUE;
        free(hashTable[key]);
        hashTable[key] = NULL;
        maxRepeat = 0;
        printf("Data berhasil dihapus!\n");
      }
      else
      {
        key++;
        maxRepeat--;
      }
    }
  }
  if (!found)
  {
    printf("Data tidak berhasil dihapus!\n");
  }
}

int main()
{

  do
  {
    char ip[100], name[100], pos[100];
    int counter = 0, pil;
    system("cls");
    printf("PROGRAM MAPPING\n");
    printf("=========================\n");
    printf("1. Tambah Data\n2. Hapus Data\n3. Tampilkan Data\n4. Exit\n");
    scanf("%d", &pil);
    fflush(stdin);
    switch (pil)
    {
    case 1:
      system("cls");
      printf("TAMBAH DATA\n");
      printf("======================\n");
      printf("Masukkan IP komputer: ");
      gets(ip);
      printf("Masukkan nama komputer: ");
      gets(name);
      printf("Masukkan letak komputer: ");
      gets(pos);
      insertData(ip, name, pos);
      system("pause");
      break;
    case 2:
      system("cls");
      printf("HAPUS DATA\n");
      printf("======================\n");
      printf("Masukkan IP komputer: ");
      gets(ip);
      printf("Masukkan nama komputer akan dihapus: ");
      gets(name);
      printf("Masukkan posisi komputer akan dihapus: ");
      gets(pos);
      deleteData(ip, name, pos);
      system("pause");
      break;
    case 3:
      system("cls");
      viewData();
      system("pause");
      break;
    case 4:
      return 0;
    default:
      printf("Input harus antara 1 - 3!\n");
      system("pause");
      break;
    }
  } while (TRUE);
  return 0;
}