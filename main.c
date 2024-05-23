#include <stdio.h>
#include <stdlib.h>

// data structure
struct Admin
{
    char username[100], pass[100];
};

struct User
{
    char nama[100], username[100], nohp[100], password[100];
};

struct Menu
{
    char menu_mie[100];
    long harga;
};

struct Bahan
{
    char nama_bahan[100];
    int jumlah;
};

// primitive data type
long nominal;
char input_username_user[100];
char input_password_user[100];

FILE *data_user;
FILE *data_user2;
FILE *data_menu;
FILE *data_bahan;
FILE *data_riwayat;
FILE *data_saldo;

// helper
int CountText(char *text)
{
    int length;
    while (*text)
    {
        length++;
        text++;
    }
    return length;
}

void PrintPaddingText(char *text)
{
    int width = 50;
    int length_text = CountText(text);
    int space = (width - length_text) / 2;
    for (int i = 0; i < space; i++)
    {
        printf("=");
    }
    printf(text);
    for (int i = 0; i < space; i++)
    {
        printf("=");
    }
    printf("\n");
}


// penjual
void login_penjual()
{
    system("cls");

    struct Admin admin = {"admin1", "pass1"};
    PrintPaddingText("LOGIN ADMIN");

    char username[50];
    char password[50];
    printf("Masukkan Username: ");
    scanf("%s", &username);

    printf("Masukkan Password: ");
    scanf("%s", &password);

    if (strcmp(admin.username, username) == 0 && strcmp(admin.pass, password) == 0)
    {
        printf("LOGIN BERHASIL\n");
        PrintPaddingText("SELAMAT DATANG ADMIN");
        // ke menu admin
        system("pause");
    }
    else
    {
        printf("Username Atau Password Salah! Silakan Coba Lagi!\n");
        // ke action jika salah username or password
        system("pause");
    }
}

// menu utama
void menu_utama()
{
    // array of string(string itu sendiri array of char)
    char menus[3][20] = {
        "Penjual", // 20
        "Pembeli", // 20
        "Exit"     // 20
    };

    int choice;

    system("cls");
    PrintPaddingText("SILAKAN PILIH MENU");
    PrintPaddingText("SELAMAT DATANG DI DASKOMIE");
    for (int i = 0; i < 3; i++)
    {
        printf("%d. %s\n", i + 1, menus[i]);
    }

    // Get user input
    printf("Pilih menu: ");
    scanf("%d", &choice);

    // Check user input
    if (choice < 1 || choice > 3)
    {
        printf("Pilihan tidak tersedia, Mohon pilih angka dari 1 sampai dengan 3.\n");
    }

    switch (choice)
    {
    case 1:
        printf("menu penjual");
        login_penjual();
        break;
    case 2:
        printf("menu pembeli");
        break;
    case 3:
        printf("Exit from application");
        system("exit");
    }
}

int main()
{
    menu_utama();
}