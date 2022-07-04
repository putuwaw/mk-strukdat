#include <stdio.h>   // standart I/O
#include <stdlib.h>  // system("cls")
#include <windows.h> // cursor position
#include <time.h>    // get time

struct
{
  char kode[100];
  char nama[100];
  char bhndsr[100];
  int jumlah;
  char hpu[100];
} mebel[100];

int counter = 0; // global var to count mebel

void input_barang()
{
  system("cls"); // clear output screen
  printf("\t\t\t\t\t\t-- INPUT BARANG --\n\n");
  printf("Banyaknya barang yang akan Anda masukkan: ");
  int i, n;
  scanf("%d", &n);
  fflush(stdin);
  for (i = 0; i < n; i++)
  {
    printf(":: Kode Barang\t  : [%d] : ", counter + 1);
    gets(mebel[counter].kode);
    printf(":: Nama Barang\t  : [%d] : ", counter + 1);
    gets(mebel[counter].nama);
    printf(":: Bahan Dasar\t  : [%d] : ", counter + 1);
    gets(mebel[counter].bhndsr);
    printf(":: Jumlah\t  : [%d] : ", counter + 1);
    scanf("%d", &mebel[counter].jumlah);
    fflush(stdin);
    printf(":: Harga Per Unit : [%d] : ", counter + 1);
    gets(mebel[counter].hpu);
    printf("\n");
    counter++; // inc counter every iteration
  }
  printf("Tekan ENTER untuk kembali\n");
  char chr;
  scanf("%c", &chr);
}

void lihat_barang()
{
  system("cls"); // clear output screen
  printf("\t\t\t\t\t\t-- PERSEDIAAN BARANG --\n");
  char baris[6][20] = {"No.", "Kode Barang", "Nama Barang", "Bahan Dasar", "Jumlah", "Harga Per Unit"};
  if (counter > 0)
  {
    printf("%-5s | %-15s | %-20s | %-20s | %-10s | %-20s |\n", baris[0], baris[1], baris[2], baris[3], baris[4], baris[5]);
    printf("===========================================================================================================\n");
    int i;
    for (i = 0; i < counter; i++)
    {
      printf("%-5d | %-15s | %-20s | %-20s | %-10d | %-20s |\n", i + 1, mebel[i].kode, mebel[i].nama, mebel[i].bhndsr, mebel[i].jumlah, mebel[i].hpu);
    }
    printf("\n");
  }
  else
  {
    printf("Belum ada persediaan barang!\n");
  }
  printf("Tekan ENTER untuk kembali\n");
  char chr;
  scanf("%c", &chr);
}

int main()
{
  do
  {
    system("cls"); // clear output screen
    printf("\t\t+--------------------------------------------------------------------------------+\n");
    printf("\t\t|                           TUGAS DATABASE TOKO MEBEL                            |\n");
    printf("\t\t+--------------------------------------------------------------------------------+\n");
    printf("\t\t|                                                                                |\n");
    printf("\t\t|                                                                                |\n");
    printf("\t\t|                           1. Input Barang                                      |\n");
    printf("\t\t|                           2. Lihat Stok Barang                                 |\n");
    printf("\t\t|                           3. Exit                                              |\n");
    printf("\t\t|                                                                                |\n");
    printf("\t\t|                                                                                |\n");
    printf("\t\t|                           PILIH [1,2,3] :                                      |\n");
    printf("\t\t|                                                                                |\n");
    printf("\t\t|                                                                                |\n");
    printf("\t\t|  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  |\n");
    printf("\t\t==================================================================================\n");
    printf("\n\t\t             Created by: Putu Widyantara Artanta Wibawa | 2108561005              \n\n");

    //	time calc
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    int day, month, year, hour, minute;
    hour = local->tm_hour;
    minute = local->tm_min;
    day = local->tm_mday;
    month = local->tm_mon + 1;
    year = local->tm_year + 1900;

    // date and time output
    printf("\t\tDate: %02d-%02d-%d\t\t\t\t\t\t\tTime: %02d.%02d\n", day, month, year, hour, minute);

    //	user input
    int pil;
    COORD pos;
    pos.X = 60;
    pos.Y = 10;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // change cursor position
    scanf("%d", &pil);
    fflush(stdin);
    if (pil == 1)
    {
      input_barang(); // input barang
    }
    else if (pil == 2)
    {
      lihat_barang(); // lihat stok barang
    }
    else if (pil == 3)
    {
      pos.X = 0;
      pos.Y = 24;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // change cursor position
      return 0;                                                       // exit
    }
  } while (1);
}