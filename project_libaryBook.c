#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h> 


char categorise[][15] = {"Computer", "Phylosophy", "Law", "Civil", "Eletronic", "Medicine"};

//=================== All Function ======================//
void mainmenu(void);
void Password(void);
void AddBook(void);
void Deletebook(void);
int Getdata();
int checkId(int t);
int CheckId(int);
void Searchbook(void);
void Veiwbook(void);
void Editbook(void);
void Exitmainmenu(void);
void ReturnFun(void);
int dt();

FILE *fp, *ft, *fs;
int s;
char findbook;
char password[10] = {"chantha"};


struct Book
{
    int id;
    char stname[30];
    char name[20];
    char author[20];
    int qauntity;
    float price;
    int count;
    int rankno;
    char *cat;
};

struct Book a;
int main()
{
    Password();
    return 0;
}

//========================== Function mainmenu ===========================//
void mainmenu()
{
    system("cls");
    dt();
    printf("\n\t-------------------- Main Menu --------------------");
    printf("\n\t| 1. Add Books                                     |\n");
    printf("\t| 2. Delete Books                                  |\n");
    printf("\t| 3. Search Books                                  |\n");
    printf("\t| 4. Veiw All Books                                |\n");
    printf("\t| 5. Edit Books		                           |\n");
    printf("\t| 6. Exit			                   |");
    printf("\n\t----------------------------------------------------");
    int i;
    printf("\n\n\tEnter your choice number(1-6): ");
    switch (getch())
    {
    case '1':
        AddBook();
        break;
    case '2':
        Deletebook();
        break;
    case '3':
        Searchbook();
        break;
    case '4':
        Veiwbook();
        break;
    case '5':
        Editbook();
        break;
    case '6':
        system("cls");
        Sleep(2000);
        printf("\n\t Please wait for 2 second");
        exit(0);
        break;
    default:
        system("cls");
        mainmenu();
    }
}

//=========================== Function Password ============================//

void Password()
{
    system("cls");

    char d[35] = "Password protected";
    char ch, pass[10];
    int i = 0, j;
    printf("\n\t");
    for (j = 0; j < 35; j++)
    {
        Sleep(50);
        printf("!");
    }
    printf(" ");
    for (j = 0; j < 20; j++)
    {
        Sleep(50);
        printf("%c", d[j]);
    }
    printf(" ");
    for (j = 0; j < 35; j++)
    {
        Sleep(50);
        printf("!");
    }
    printf("\n\tEnter your password: ");
    while (ch != 13)
    {
        ch = getch();
        if (ch != 13 && ch != 8)
        {
            putch('*');
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    if (strcmp(pass, password) == 0)
    {
        printf("\n\n\tPassword Match...");
        printf("\n\n\tPlease press any key to continue...");
        getch();
        mainmenu();
    }
    else
    {
        printf("\n\n\tIncorrect Password! Please try again....!");
        printf("\n\n\tBy press any key");
        system("cls");
        getch();
        Password();
    }
}
//==========================================================================//

//============================ Function Add book =========================//

void AddBook()
{
    system("cls");
    printf("\n\t====== Please select the category ======");
    printf("\n\t| 1. Computer                            |");
    printf("\n\t| 2. Phylosophy                          |");
    printf("\n\t| 3. Law                                 |");
    printf("\n\t| 4. Civil                               |");
    printf("\n\t| 5. Eletronic                           |");
    printf("\n\t| 6. Medicine                            |");
    printf("\n\t| 7. Go to Main Menu                     |");
    printf("\n\t=========================================");
    printf("\n\tEnter your category: ");
    scanf("%d", &s);
    if (s == 7)
        mainmenu();
    system("cls");
    fp = fopen("Mydata.txt", "ab+");
    if (Getdata() == 1)
    {
        a.cat = categorise[s - 1];
        fseek(fp, 0, SEEK_END);
        fwrite(&a, sizeof(a), 1, fp);
        fclose(fp);
        printf("\n\tThe record saved successfully..");
        printf("\n\tSave any more ?(Y?N): ");
        if (getch() == 'n')
            mainmenu();
        else
            system("cls");
        AddBook();
    }
}
//==========================================================================//

//============================ Function Delete book =========================//

void Deletebook(void)
{
    system("cls");
    printf("\n\t====== Delete Books ======");
    int d;
    char another = 'y';
    while (another == 'y')
    {
        system("cls");
        printf("\n\tEnter Book ID: ");
        scanf("%d", &d);
        fp = fopen("Mydata.txt", "r");
        rewind(fp);
        while (fread(&a, sizeof(a), 1, fp) == 1)
        {
            if (a.id == d)
            {
                printf("\n\tThe record is avaliable");
                printf("\n\tThe Book Name is %s", a.name);
                printf("\n\tThe Rack No is %d", a.rankno);
                findbook = 't';
            }
        }
        if (findbook != 't')
        {
            printf("\n\tNo record found..!");
            if (getch())
                mainmenu();
        }
        if (findbook == 't')
        {
            printf("\n\tDo you to delete? (Y?N): ");
            if (getch() == 'y')
            {
                ft = fopen("test.txt", "wb");
                rewind(fp);
                while (fread(&a, sizeof(a), 1, fp) == 1)
                {
                    if (a.id != d)
                    {
                        fseek(ft, 0, SEEK_CUR);
                        fwrite(&a, sizeof(a), 1, ft);
                    }
                }
                fclose(ft);
                fclose(fp);
                remove("Mydata.txt");
                rename("test.txt", "Mydata.txt");
                // int i=0;
                // int e;
                // if(i==0){
                //     e=1;
                // }
                // if(e==1){
                //     ft = fopen("test.txt", "wb+");
                // }
                system("cls");
                if (findbook == 't')
                {
                    printf("\n\tThe record successfully deleted..!");
                    printf("\n\tDelete another record? (Y/N): ");
                    if(getch() == 'y'){
                        Deletebook();
                    }
                    else{
                       mainmenu(); 
                    }
                }
                else
                {
                    mainmenu();
                    fflush(stdin);
                    another = getch();
                }
            }
            mainmenu();
        }
    }
}
//=====================================================================//

//========================== Function Search book =====================//
void Searchbook()
{
    system("cls");
    dt();
    printf("\n\t================== Search Books ==================");
    printf("\n\t1.Search by ID ");
    printf("\n\t2.Search by Name ");
    printf("\n\tPlease Enter your choice: ");
    int d;
    fp = fopen("Mydata.txt", "rb+");
    rewind(fp);
    switch (getch())
    {
    case '1':
        system("cls");
        printf("\n\t==================== Search Book by ID ===================");
        printf("\n\t Enter ID Book:");
        scanf("%d", &d);
        printf("\n\t Searching............");
        while (fread(&a, sizeof(a), 1, fp) == 1)
        {
            if (a.id == d)
            {
                Sleep(2);
                printf("\n\tThe book is avaliable");
                printf("\n\t");
                printf("\n\t Author : %s", a.author);
                printf("\n\t Book Name : %s", a.name);
                printf("\n\t Qauntity : %d", a.qauntity);
                printf("\n\t Price : %.2f", a.price);
                printf("\n\t RackNo : %d", a.rankno);
                findbook = 't';
            }
        }
        if (findbook != 't')
        {
            printf("\n\t Not record found..!");
        }
        printf("\n\tTry another one? (Y/N): ");
        if (getch() == 'y')
        {
            Searchbook();
        }
        else
        {
            mainmenu();
        }
        break;
    case '2':
        printf("\n\t==================== Search by Name ===================");
        char s[15];
        system("cls");
        printf("\n\t Please Enter book Name: ");
        scanf("%s", &s);
        int d = 0;
        while (fread(&a, sizeof(a), 1, fp) == 1)
        {
            if (strcmp(a.name, (s)) == 0)
            {
                printf("\n\t The book is avaliable");
                printf("\n\t ID : %d", a.id);
                printf("\n\t Book Name : %s", a.name);
                printf("\n\t Author : %s", a.author);
                printf("\n\t Quantity : %d", a.qauntity);
                printf("\n\t Price : %.2f", a.price);
                printf("\n\t RackNo : %d", a.rankno);
            }
        }
        if (d == 0)
        {
            printf("\n\t Not record found..!");
        }
        printf("\n\tTry another one? (Y/N): ");
        if (getch() == 'y')
        {
            Searchbook();
        }
        else
        {
            mainmenu();
        }
        break;
        default:
            getch();
            Searchbook();
    }
    fclose(fp);
}
//===========================================================================//

//========================== Function Veiw book =============================//
void Veiwbook()
{
    system("cls");
    printf("\n\t================================================ Veiw Books ==========================================");
    int i = 0, j;
    dt();
    printf("\n\t ============================================ Show Book List ==========================================");
    printf("%-18s%-12s%-19s%-16s%-18s%-15s%-16s", "\n\tCategory", "ID", "Book Name", "   Author", "Qauntity", "  Price", "RackNo\n");
    printf("======================================================================================================");
    j = 4;
    fp = fopen("Mydata.txt", "rb");
    while (fread(&a, sizeof(a), 1, fp) == 1)
    {
        printf("\n");
        printf("\n\t%-18s%-12d%-19s%-16s%-18d$%-15.2f%-16d", a.cat, a.id, a.name, a.author, a.qauntity, a.price, a.rankno);
        printf("\n");
        j++;
        i = i + a.qauntity;
    }
    printf("\n\tTotal Book = %d", i);
    fclose(fp);
    ReturnFun();
}
//==============================================================================//

//================================= Function Edit book =========================//

void Editbook()
{
    system("cls");
    dt();
    printf("\n\t================== Edit Books ==================");
    int c = 0, e, d;
    printf("\n\t------------- Edit your book---------------");
    char another = 'y';
    while (another == 'y')
    {
        system("cls");
        printf("\n\tEnter Book ID to Edit: ");
        scanf("%d", &d);
        fp = fopen("Mydata.txt", "rb+");
        while (fread(&a, sizeof(a), 1, fp) == 1)
        {
            if (checkId(d) == 0)
            {
                printf("\n\tThe Book is available");
                printf("\n\tThe Book id : %d", a.id);
                printf("\n\tEnter the New Name: ");
                scanf("%s", &a.name);
                printf("\n\tEnter the New Author: ");
                scanf("%s", &a.author);
                printf("\n\tEnter the New Qauntity: ");
                scanf("%d", &a.qauntity);
                printf("\n\tEnter the New Price: ");
                scanf("%f", &a.price);
                printf("\n\tEnter the New RackNo: ");
                scanf("%d", &a.rankno);
                printf("\n\tYour record is edited....!");
                fseek(fp, ftell(fp) - sizeof(a), 0);
                fwrite(&a, sizeof(a), 1, fp);
                fclose(fp);
                c = 1;
            }
            if (c == 0)
            {
                printf("\n\tNot record found....!");
            }
        }
        printf("\n\tEdit another record? (Y/N): ");
        fflush(stdin);
        another = getch();
    }
    ReturnFun();
}
//=========================================================================//

//============================ Function Get data ==========================//
int Getdata()
{
    int t;
    printf("\n\t Enter the Information Below");
    printf("\n\t Category: %s", categorise[s - 1]);
    printf("\n\t Book ID: ");
    scanf("%d", &t);
    if (checkId(t) == 0)
    {
        printf("\n\t The book id exist");
        getch();
        mainmenu();
        return 0;
    }
    a.id = t;
    printf("\n\tBook Name: ");
    scanf("%s", &a.name);
    fflush(stdin);
    printf("\n\tAuthor: ");
    scanf("%s", &a.author);
    printf("\n\tQauntity: ");
    scanf("%d", &a.qauntity);
    printf("\n\tPrice: ");
    scanf("%f", &a.price);
    printf("\n\tRack No: ");
    scanf("%d", &a.rankno);
    return 1;
}
int checkId(int t)
{
    rewind(fp);
    while (fread(&a, sizeof(a), 1, fp) == 1)
        if (a.id == t)
            return 0;
    return 1;
}
void ReturnFun(void)
{
    printf("\n\tPlease Enter to Mianmenu ");
a:
    if (getch() == 13)
    {
        mainmenu();
    }
    else
    {
        goto a;
    }
}
//=================================================================================//

//=================================== Function Data time ===========================//
int dt()
{
    time_t now;
    time(&now);
    printf("\n\tLocal date and time is : %s", ctime(&now));
    return 0;
}
//===================================================================================//
