/* 

Train Reservation system.
Created by Sugam Phirke on 22-05-2021 at 17:35:06 in Embarcadero Dev-C++.

*/

#include<stdio.h>

#include<conio.h>

#include<stdlib.h>

#include<string.h>

#include<windows.h>

#include<dos.h>

#include<ctype.h>

#include<process.h>

#include<time.h>

struct date {
    char str1[10];
    char str2[10];
    char str3[10];
}; struct date d;

struct high {
    char boarding[10];
    char destiny[10];
}; struct high b1;

struct departure {
    char depart[10];
    char status[20];
}; struct departure e;

struct ages {
    char name[20];
    int age;
    char randbal[6];
    int z, h;
}; struct ages j;

struct train {
    char no[20];
    char station[20];
}; struct train t;

struct name {
    char name[100][30];
    char age[100][30];
}; struct name n;

struct user {
    char username[20];
    char fname[20];
    char lname[20];
    char age[20];
    char email[40];
    char mno[20];
}; struct user u, U;

struct info {
    char a[10];
    char b[10];
};struct info g;

struct password {
    char pass[20];
}; struct password p;

FILE * fp;
int choice;
char fname[20], lname[20], uname[20], pss[20], C;
char stationno1[10], stationno2[10];

int menu();
void createaccount();
void createpassword();
void gotoxy(int, int);
void login();
void seepassword();
void help();
int gold();
void trains();
void routeselection();
void reservation();
void verification();
void trains_display_schedule();
void ages();
void my_pay();
void cancelreservation();
void process();
void ticket_printing();
void end();

int main() {
    system("color 2E");
    while (1) {
        switch (menu()) {
        case 1:
            createaccount();
            break;

        case 2:
            login();
            break;

        case 3:
            help();
            break;

        case 4:
            end();
        default:
            printf("Invalid Choice! ");
            break;
        }
    }

    return 0;
}

int menu() {
    int i;
    gotoxy(42, 4);
    printf(" -------------------------------------------------");
    gotoxy(42, 5);
    printf("    |                                         |");
    gotoxy(42, 6);
    printf("    |        <----<<<< Menu >>>>---->         |");
    gotoxy(42, 7);
    printf("    |                                         |");
    gotoxy(42, 8);
    printf(" -------------------------------------------------");
    gotoxy(52, 11);
    printf("1. Create Account  \n");
    gotoxy(52, 12);
    printf("2. Login  \n");
    gotoxy(52, 13);
    printf("3. Need Help?  \n");
    gotoxy(52, 14);
    printf("4. Exit  \n");
    gotoxy(52, 16);
    printf("   Enter your choice :  ");
    scanf("%d", & i);
    return i;
}

void createaccount() {
    char str1[10];
    char age[10];
    char email[20];
    struct user U;
    FILE * fp;
    system("cls");

    gotoxy(43, 4);
    printf(" -----------------------------------------------------------");
    gotoxy(43, 5);
    printf("    |                                                   |");
    gotoxy(43, 6);
    printf("    |        <----<<<< CREATE ACCOUNT >>>>---->         |");
    gotoxy(43, 7);
    printf("    |                                                   |");
    gotoxy(43, 8);
    printf(" -----------------------------------------------------------");

    printf("\n\n\n");
    printf("\t\t\t\t\t    Enter your First Name: ");
    fflush(stdin);
    gets(U.fname);
    printf("\n");
    printf("\t\t\t\t\t    Enter your Last Name: ");
    gets(U.lname);
    printf("\n");
    printf("\t\t\t\t\t    Enter your Age: ");
    scanf("%s", & age);

    for (int k = 0; k < strlen(age); k++) {
        if (isdigit(age[k]) == 1) {
            strcpy(U.age, age);
        } else {
            printf("\n\t\t\t\t\t\tEnter a valid age!");
            getch();
            system("cls");
            createaccount();

        }
    }

    printf("\n");
    printf("\t\t\t\t\t    Enter Email Address: ");
    scanf("%s", & email);

    for (int j = 0; j < strlen(email); j++) {
        if ((email[j] >= 33 && email[j] <= 64) || (email[j] >= 91 && email[j] <= 126)) {
            strcpy(U.email, email);
        } else {
            printf("\n\t\t\t\t\t\tEnter a valid E-mail address!");
            getch();
            system("cls");
            main();

        }
    }

    printf("\n");
    printf("\t\t\t\t\t    Enter your Mobile Number: ");
    fflush(stdin);
    scanf("%s", & str1);
    int len = strlen(str1);
    for (int m = 0; m < strlen(str1); m++) {
        if (isdigit(str1[m]) == 1) {
            if (len == 10) {
                strcpy(U.mno, str1);
            } else if (len != 10) {
                printf("\t\t\t\t\t\t!*Enter a valid Mobile Number*!");
                getch();
                system("cls");
                createaccount();

            }
        } else {
            printf("\t\t\t\t\t\t!*Enter a valid Mobile Number*!");
            getch();
            system("cls");
            createaccount();

        }
    }

    printf("\n");
    printf("\t\t\t\t\t    Create a Username: ");
    scanf("%s", U.username);
    printf("\n");

    createpassword();

    fp = fopen("./User.txt", "wb+");
    if (fp == NULL) {
        printf("\nError opened file\n");
        exit(1);
    }
    fwrite( & U, sizeof(struct user), 1, fp);
    fclose(fp);
    system("cls");
    char otp[6], votp[6], c;
    int i;
    srand((unsigned) time(NULL));
    for (i = 0; i < 5; i++) {
        c = rand() % 10 + 48;
        otp[i] = c;
    }
    gotoxy(37, 4);
    printf(" -------------------------------------------------------------");
    gotoxy(37, 5);
    printf("    |                                                     |");
    gotoxy(37, 6);
    printf("    |        <----<<<< OTP VERIFICATION >>>>---->         |");
    gotoxy(37, 7);
    printf("    |                                                     |");
    gotoxy(37, 8);
    printf(" -------------------------------------------------------------");

    char sstr[20];
    int p = 7, l = 4, f = 0;

    while (f < l) {
        sstr[f] = U.mno[p + f - 1];
        f++;
    }
    sstr[f] = '\0';

    printf("\n\n\n\t\t\t\t\tOTP has been sent to your mobile number ******%s: %s", sstr, otp);
    printf("\n\n\t\t\t\t\tVerify OTP: ");
    scanf("%s", & votp);
    if (strcmp(otp, votp) == 0) {
        printf("\n\t\t\t\t\t\t\t\t!OTP Verified!");
    } else {
        printf("\n\t\t\t\t\t\t*OTP Mismatched*");
    }
    otp[i] = '\0';
    gotoxy(90, 30);
    printf("Press any key to continue...");
    getch();
    system("cls");
    gotoxy(55, 17);
    printf(" Account Created Successfully.");
    gotoxy(90, 30);
    printf("Press any key to continue...");
    getch();
    system("cls");
}

void createpassword() {
    int v;
    FILE * fp;
    struct user U;
    struct password p;
    char password[20], vpass[20], opinion[5], vopinion[5] = "Yes";
    int sizeflag = 1, digitflag = 0, splcharflag = 0, charflag = 0;
    system("cls");

    gotoxy(40, 4);
    printf(" -----------------------------------------------------------");
    gotoxy(40, 5);
    printf("    |                                                   |");
    gotoxy(40, 6);
    printf("    |        <----<<<< CREATE PASSWORD >>>>---->        |");
    gotoxy(40, 7);
    printf("    |                                                   |");
    gotoxy(40, 8);
    printf(" -----------------------------------------------------------");

    printf("\n\n\n\t\t\t\tEnsure that following parameters are followed while you create your Password:\n\t\t\t\t\tPassword length must be minimum 6 and maximum 12.\n\t\t\t\t\tPassword must consist of minimum one character.\n\t\t\t\t\tPassword must consist of at least one digit.\n\t\t\t\t\tPassword must contain of minimum one special character.\n\n\t\t\t\t\t\tEnter your Password: ");
    scanf("%s", password);
    int len = strlen(password);
    if (len < 6 || len > 12) {
        sizeflag = 0;
    }
    for (int i = 0; i < len; i++) {
        if (password[i] >= 48 && password[i] <= 57) {
            digitflag = 1;
        }
        if ((password[i] >= 65 && password[i] <= 90) || (password[i] >= 97 && password[i] <= 122)) {
            charflag = 1;
        }
        if ((password[i] >= 33 && password[i] <= 47) || (password[i] >= 58 && password[i] <= 64) || (password[i] >= 91 && password[i] <= 96)) {
            splcharflag = 1;
        }
    }

    if (!sizeflag) {
        printf("\n This password is not valid. Password length must be minimum 6 and maximum 12.");
    }
    if (!charflag) {
        printf("\n This password is not valid. Password must consist minimum one character.");
    }
    if (!digitflag) {
        printf("\n This password is not valid. Password must consist of at least one digit.");
    }
    if (!splcharflag) {
        printf("\n This password is not valid. Password must contain of minimum one special character.");
    }
    v = sizeflag + charflag + digitflag + splcharflag;
    if (sizeflag && charflag && digitflag && splcharflag) {
        printf("\n\n\t\t\t\t\t!###### Strength of your Password: %d/4 ######!", v);
    } else {
        printf("\n\n\n\t\tOops Looks like the Password you entered is not a valid one!\n\tDo you want to Re-Enter a new Password(Yes/No): ");
        scanf("%s", & opinion);
        if (strcmp(opinion, vopinion) == 0) {
            system("cls");
            createpassword();

        } else {
            exit(0);
        }
    }
    printf("\n\n\n\t\t\t\t\t\tPlease Confirm your Password: ");

    int i = 0;
    char c = ' ';
    while (i < strlen(password)) {
        vpass[i] = getch();
        c = vpass[i];
        if (c == 13) break;
        else printf("*");
        i++;
    }
    vpass[i] = '\0';
    i = 0;

    if (strcmp(password, vpass) == 0) {
        printf("\n\n\t\t\t\t\tYour Password has been verified and saved as: ");
        strcpy(p.pass, vpass);
        printf("%s", p.pass);
    } else {
        printf("!*Password Mismatched*!");
        getch();
        system("cls");
        createpassword();

    }

    fp = fopen("C:\\Details_Customer\\Password.txt", "wb+");
    if (fp == NULL) {
        printf("\nError opened file\n");
        exit(1);
    }
    fwrite( & p, sizeof(struct password), 1, fp);
    fclose(fp);
    gotoxy(90, 30);
    printf("Press any key to continue...");
    getch();
}

void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void login() {
    char uname[20], pss[20];
    FILE * fp1;
    FILE * fp2;
    int v;
    int r, q;
    struct user u;
    struct password p;
    system("cls");
    gotoxy(34, 4);
    printf(" -----------------------------------------------------------------");
    gotoxy(34, 5);
    printf("    |                                                         |");
    gotoxy(34, 6);
    printf("    |        <----<<<< LOGIN TO YOU ACCOUNT >>>>---->         |");
    gotoxy(34, 7);
    printf("    |                                                         |");
    gotoxy(34, 8);
    printf(" -----------------------------------------------------------------");
    printf("\n\n");
    printf("\t\t\t\t\t\t  Enter Username: ");
    scanf("%s", uname);
    printf("\n");
    printf("\t\t\t\t\t\t  Enter Password: ");
    scanf("%s", pss);
    fp1 = fopen("C:\\Details_Customer\\User.txt", "rb+");
    fp2 = fopen("C:\\Details_Customer\\Password.txt", "rb+");
    if (fp1 == NULL) {
        printf("\"File not found\"");

    }
    while (fread( & u, sizeof(struct user), 1, fp1)) {
        if (strcmp(uname, u.username) == 0) {
            while (fread( & p, sizeof(struct password), 1, fp2)) {
                if (strcmp(pss, p.pass) == 0) {
                    gotoxy(43, 16);
                    printf("!YOU HAVE SUCCESSFULLY LOGGED INTO YOUR ACCOUNT!");
                    gotoxy(90, 30);
                    printf(" Press any key to continue...");
                    getch();
                    system("cls");
                } else {
                    printf("There is a technical glitch in the system!\n Please try again!");
                    getch();
                    exit(0);
                }
            }
        } else {
            printf("\n Username Or Password is Incorrect.\n\n");
            getch();
            exit(0);
        }
    }
    fclose(fp);
    system("cls");
    int i, j, a;
    gotoxy(30, 10);
    printf("Do you want to continue with your train journey reservation process?");
    gotoxy(30, 11);
    printf("Press 1 to continue.");
    gotoxy(30, 12);
    printf("Press 0 to Exit the Portal.");
    gotoxy(89, 20);
    printf("=======");
    gotoxy(90, 21);
    printf("|   |");
    gotoxy(89, 22);
    printf("=======");
    gotoxy(92, 21);

    scanf("%d", & v);
    system("cls");
    if (v == 1) {
        gotoxy(62, 12);
        printf("WELCOME");
        gotoxy(60, 14);
        printf("%s %s", u.fname, u.lname);
        gotoxy(54, 16);
        printf("TRAIN RESERVATION SYSTEM");
        gotoxy(20, 28);
        printf("Loading! Please wait....");
        gotoxy(20, 29);
        printf("We appreciate your patience!");
        gotoxy(10, 30);
        for (r = 1; r <= 120; r++) {
            for (q = 0; q <= 100000000; q++);
            printf("%c", 177);
        }
    } else if (v == 0) {
        exit(0);
    } else {
        printf("Enter a valid input!");
    }
    system("cls");

    trains();

}

void forgotdetails() {
    system("cls");
    char mobileno[20];
    FILE * fp;
    struct user u;
    struct password p;
    system("cls");
    gotoxy(34, 4);
    printf(" -----------------------------------------------------------------");
    gotoxy(34, 5);
    printf("    |                                                         |");
    gotoxy(34, 6);
    printf("    |        <----<<<< Account VERIFICATION >>>>---->         |");
    gotoxy(34, 7);
    printf("    |                                                         |");
    gotoxy(34, 8);
    printf(" -----------------------------------------------------------------");
    printf("\n\n\n");
    printf("\t\t\t\t\t    Enter your registered mobile number: ");
    scanf("%s", & mobileno);
    fp = fopen("C:\\Details_Customer\\User.txt", "rb+");
    if (fp == NULL) {
        printf("File not found");

    }
    while (fread( & u, sizeof(struct user), 1, fp)) {
        if (strcmp(mobileno, u.mno) == 0) {
            printf("\n\n");
            printf("\t\t\t\t\t\t    !!!Account has been verified!!!\n");
            printf("\t\t\t\t\t    Press any key to see your login credentials...\n");
            getch();
            gotoxy(45, 17);
            printf("        Your Login Credentials Are..\n\n");
            printf("\n\t\t\t\tName: %s %s \n", u.fname, u.lname);
            printf("\n\t\t\t\tAge: %s\n", u.age);
            printf("\n\t\t\t\tE-mail: %s\n", u.email);
            printf("\n\t\t\t\tUsername: %s\n\n", u.username);
        } else {
            printf("Entry does not match with registry.\nPlease Enter a valid registered number.");
        }
    }
    fclose(fp);
    gotoxy(90, 30);
    printf("Press any key to continue...");
    getch();
    system("cls");
}

void seepassword() {
    system("cls");
    char mobileno[20];
    FILE * fp1;
    FILE * fp2;
    struct user u;
    struct password p;
    system("cls");
    gotoxy(34, 4);
    printf(" -----------------------------------------------------------------");
    gotoxy(34, 5);
    printf("    |                                                         |");
    gotoxy(34, 6);
    printf("    |        <----<<<< Account VERIFICATION >>>>---->         |");
    gotoxy(34, 7);
    printf("    |                                                         |");
    gotoxy(34, 8);
    printf(" -----------------------------------------------------------------");
    printf("\n\n\n");
    printf("\t\t\t\t\t    Enter your registered mobile number: ");
    scanf("%s", & mobileno);
    fp1 = fopen("C:\\Details_Customer\\User.txt", "rb+");
    if (fp1 == NULL) {
        printf("\"File not found\"");

    }
    while (fread( & u, sizeof(struct user), 1, fp1)) {
        if (strcmp(mobileno, u.mno) == 0) {
            printf("\n\n");
            printf("\t\t\t\t\t\t    !!!Account has been verified!!!\n");
            printf("\t\t\t\t\t      Press any key to see your login password...\n");
            getch();
        }
        fp2 = fopen("C:\\Details_Customer\\Password.txt", "rb+");
        if (fp2 == NULL) {
            printf("\nError opened file\n");
            exit(1);
        }
        while (fread( & p, sizeof(struct password), 1, fp2)) {
            printf("\n\n\t\t\t\t\t\t\tYour password is: %s", p.pass);
            getch();
        }
        fclose(fp);
        gotoxy(90, 30);
        printf("Press any key to continue...");
        getch();

        system("cls");
    }
}

void help() {
    while (1) {
        switch (gold()) {
        case 1:
            forgotdetails();
            break;

        case 2:
            seepassword();
            break;

        case 3:
            system("cls");
            main();
        default:
            printf("Invalid Choice! ");
            break;
        }
    }

}

int gold() {
    system("cls");
    int i;
    gotoxy(40, 4);
    printf(" -------------------------------------------------");
    gotoxy(40, 5);
    printf("    |                                         |");
    gotoxy(40, 6);
    printf("    |        <----<<<< HELP >>>>---->         |");
    gotoxy(40, 7);
    printf("    |                                         |");
    gotoxy(40, 8);
    printf(" -------------------------------------------------");

    printf("\n\n\n\t\t\t\t\t\t1. Forgot Login Details?  \n");
    printf("\t\t\t\t\t\t2. Forgot Login Password?  \n");
    printf("\t\t\t\t\t\t3. Exit  \n");
    printf("\n\t\t\t\t\t\tEnter your choice :  ");
    scanf("%d", & i);
    return i;
}

void trains() {
    system("color 1E");
    system("cls");
    int options;
    start:
        gotoxy(32, 4);
    printf(" ---------------------------------------------------------------------");
    gotoxy(32, 5);
    printf("    |                                                             |");
    gotoxy(32, 6);
    printf("    |        <----<<<< TRAIN RESERVATION SYSTEM >>>>---->         |");
    gotoxy(32, 7);
    printf("    |                                                             |");
    gotoxy(32, 8);
    printf(" ---------------------------------------------------------------------");
    printf("\n\n\n");
    printf("\t\t\t\t\t\t1. Journey Route Selection");
    printf("\n\t\t\t\t\t\t2. Reservation & Schedule");
    printf("\n\t\t\t\t\t\t3. My_Pay");
    printf("\n\t\t\t\t\t\t4. Cancel Reservation");
    printf("\n\t\t\t\t\t\t5. Ticket Printing");
    printf("\n\t\t\t\t\t\t6. Exit");
    printf("\n\t\t\t\t\t\tEnter your choice: ");
    scanf("%d", & options);
    system("cls");
    switch (options) {
    case 1:
        reservation();
        break;
    case 2:
        verification();
        break;
    case 3:
        my_pay();
    case 4:
        cancelreservation();
        break;
    case 5:
        ticket_printing();
        break;
    case 6:
        system("cls");
        main();
        break;
    default:
        printf("\nInvalid choice");
        break;
    }
}

void routeselection() {
    printf("\n\n\n");
    printf("\t\t\t-----------------------------------------------------------------------------------\n");
    printf("\t\t\t |    Sr.  No.   | \t\tNames of Stations\t         |\tCode\t |\n");
    printf("\t\t\t-----------------------------------------------------------------------------------\n");
    printf("\t\t\t |\t1\t | \tChhatrapati Shivaji Terminus, Mumbai\t |\tCSTM\t |\n");
    printf("\t\t\t |\t2\t | \tVijaywada Junction\t                 |\tBZA\t |\n");
    printf("\t\t\t |\t3\t | \tKanpur Junction\t                         |\tCNB\t |\n");
    printf("\t\t\t |\t4\t | \tNew Delhi Railway Station\t         |\tNDLS\t |\n");
    printf("\t\t\t |\t5\t | \tPatna Junction Railway Station\t         |\tPNBE\t |\n");
    printf("\t\t\t |\t6\t | \tPT. Deen Dayal Upadhyaya Junction\t |\tDDU\t |\n");
    printf("\t\t\t |\t7\t | \tAllahabad Junction\t                 |\tALD\t |\n");
    printf("\t\t\t |\t8\t | \tChennai Central\t                         |\tMAS\t |\n");
    printf("\t\t\t |\t9\t | \tKalyan Railway Station\t                 |\tKYN\t |\n");
    printf("\t\t\t |\t10\t | \tSealdah Railway Station\t                 |\tSDAH\t |\n");
    printf("\t\t\t |\t11\t | \tAkola Junction\t                         |\tAK\t |\n");
    printf("\t\t\t |\t12\t | \tAgra Cantt\t                         |\tAGC\t |\n");
    printf("\t\t\t |\t13\t | \tAjmer Junction\t                         |\tAII\t |\n");
    printf("\t\t\t |\t14\t | \tVaranasi Junction\t                 |\tBSB\t |\n");
    printf("\t\t\t |\t15\t | \tJaisalmer Railway Station\t         |\tJSM\t |\n");
    printf("\t\t\t |\t16\t | \tBangalore City Railway Station\t         |\tSBC\t |\n");
    printf("\t\t\t |\t17\t | \tAhmedabad Junction\t                 |\tADI\t |\n");
    printf("\t\t\t |\t18\t | \tMughalsarai Junction\t                 |\tMGS\t |\n");
    printf("\t\t\t |\t19\t | \tJaipur Railway Station\t                 |\tJP\t |\n");
    printf("\t\t\t |\t20\t | \tMysore Railway Station\t                 |\tMYS\t |\n");
    printf("\t\t\t |\t21\t | \tKanyakumari Railway Station\t         |\tCAPE\t |\n");
    printf("\t\t\t |\t22\t | \tHowrah Junction Railway Station          |\tHWH\t |\n");
    printf("\t\t\t-----------------------------------------------------------------------------------");
    gotoxy(92, 3);
}

void reservation() {

    struct high b1;

    struct teledir {
        char stationno[10];
        char stationname[20];

    };
    struct teledir t;
    FILE * fp;
    char sname[20], sname1[20], c;
    int ch;

    char stationno1[10], stationno2[10];
    system("cls");
    gotoxy(20, 1);
    printf("Select your Source Station from the below chart: ");
    gotoxy(89, 2);
    printf("=======");
    gotoxy(90, 3);
    printf("|   |");
    gotoxy(89, 4);
    printf("=======");
    gotoxy(92, 3);
    routeselection();
    scanf("%s", sname);

    fp = fopen("telephone11.txt", "rb");
    system("cls");

    while (fread( & t, sizeof(t), 1, fp)) {
        if (strcmp(sname, t.stationno) == 0) {
            gotoxy(45, 17);
            printf("Your Boarding Station is selected as %s!", t.stationname);

            strcpy(b1.boarding, t.stationname);

            gotoxy(90, 30);
            printf("Press any key to continue...");
            getch();
        }
    }
    fclose(fp);

    system("cls");
    gotoxy(20, 1);
    printf("Select your Destination Station From the below chart: ");
    gotoxy(89, 2);
    printf("=======");
    gotoxy(90, 3);
    printf("|   |");
    gotoxy(89, 4);
    printf("=======");
    gotoxy(92, 3);
    routeselection();
    scanf("%s", sname1);
    system("cls");

    fp = fopen("telephone11.txt", "rb");
    system("cls");

    while (fread( & t, sizeof(t), 1, fp)) {
        if (strcmp(sname1, t.stationno) == 0) {
            gotoxy(45, 17);
            printf("Your Destination Station is selected as %s!", t.stationname);

            strcpy(b1.destiny, t.stationname);

            gotoxy(90, 30);
            printf("Press any key to continue...");
            getch();

        }
    }
    fclose(fp);
    system("cls");
    FILE * fp1;
    fp1 = fopen("a.txt", "wb");
    fwrite( & b1, sizeof(b1), 1, fp1);
    fclose(fp1);
    trains();
}

void verification() {
    char vfy[10], verify[5] = "Yes", verify1[5] = "No";
    struct high b1;
    FILE * fp;
    fp = fopen("a.txt", "rb");
    fread( & b1, sizeof(b1), 1, fp);
    gotoxy(30, 10);
    printf("Your journey is set from %s to %s!", b1.boarding, b1.destiny);
    gotoxy(30, 11);
    printf("Do you want to continue with your input?");
    gotoxy(30, 12);
    printf("1. Type Yes to continue.");
    gotoxy(30, 13);
    printf("2. Type No to return to Menu.");

    gotoxy(89, 20);
    printf("=========");
    gotoxy(90, 21);
    printf("|     |");
    gotoxy(89, 22);
    printf("=========");
    gotoxy(92, 21);

    scanf("%s", & vfy);

    if (stricmp(vfy, verify) == 0) {
        trains_display_schedule();
    } else if (strcmp(vfy, verify1)) {
        trains();
    }
    fclose(fp);
}

void trains_display_schedule() {
    int no;
    struct info g;
    struct ages j;
    int train_no, passengers;
    int month[12] = {
        31,
        28,
        31,
        30,
        31,
        30,
        31,
        31,
        30,
        31,
        30,
        31
    };
    char week[7][10];
    int date, mon, year, i, r, s = 0;
    system("cls");
    strcpy(week[0], "Sunday");
    strcpy(week[1], "Monday");
    strcpy(week[2], "Tuesday");
    strcpy(week[3], "Wednesday");
    strcpy(week[4], "Thursday");
    strcpy(week[5], "Friday");
    strcpy(week[6], "Saturday");
    gotoxy(42, 12);
    printf("Enter the date of travel(dd/mm/yyyy) : ");
    scanf("%d / %d / %d", & date, & mon, & year);
    itoa(date, d.str1, 10);
    itoa(mon, d.str2, 10);
    itoa(year, d.str3, 10);
    FILE * ptr1;
    ptr1 = fopen("dates.txt", "wb");
    fwrite( & d, sizeof(d), 1, ptr1);
    fclose(ptr1);

    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
        month[1] = 29;
    for (i = 0; i < mon - 1; i++)
        s = s + month[i];
    s = s + (date + year + (year / 4) - 2);
    s = s % 7;
    gotoxy(92, 12);
    printf("(%s)", week[s]);
    getch();

    struct high b1;
    FILE * fp;
    fp = fopen("a.txt", "rb");
    fread( & b1, sizeof(b1), 1, fp);
    int k, b, a, h;
    for (h = 0; h <= 7; h++) {
        gotoxy(56, 17);
        printf("Checking Availability");
        for (k = 0; k <= 6; k++) {
            for (b = 0; b < 100000000; b++)
                a = b;
            printf(".");
        }
        system("cls");
    }

    gotoxy(45, 6);
    printf("   <<<<<<<<List of available trains>>>>>>>>");
    printf("\n\n");
    gotoxy(45, 7);
    printf("1674. RAJDHANI EXPRESS");
    gotoxy(45, 8);
    printf("Departure- 5:45AM\tAC tier 3\tFare:450Rs/-");
    gotoxy(45, 9);
    printf("8610. DURONTO EXPRESS");
    gotoxy(45, 10);
    printf("Departure- 8:25AM\tAC tier 1\tFare:815Rs/-");
    gotoxy(45, 11);
    printf("9112. JAN SHATABDI EXPRESS");
    gotoxy(45, 12);
    printf("Departure- 12:15PM\tSleeper  \tFare:225Rs/-");
    gotoxy(45, 13);
    printf("3907. VANDE BHARAT");
    gotoxy(45, 14);
    printf("Departure- 16:40PM\tAC tier 2\tFare:300Rs/-");
    gotoxy(45, 15);
    printf("2053. GATIMAN EXPRESS");
    gotoxy(45, 16);
    printf("Departure- 20:00PM\tAC tier 3\tFare:450Rs/-");
    gotoxy(45, 17);
    printf("4095. ANTYODAYA EXPRESS");
    gotoxy(45, 18);
    printf("Departure- 23:10PM\tAC tier 1\tFare:600Rs/-");
    int val;
    gotoxy(38, 21);
    printf("Enter the train number in which you want to travel: ");
    scanf("%s", g.a);
    val = atoi(g.a);
    int z;
    gotoxy(50, 22);
    printf("Enter number of passengers: ");
    scanf("%s", g.b);
    FILE * fp5;
    fp5 = fopen("Sugam.txt", "wb");
    fwrite( & g, sizeof(g), 1, fp5);
    fclose(fp5);
    FILE * ptr;
    ptr = fopen("principles.txt", "wb");
    FILE * fhptr;
    fhptr = fopen("departure.txt", "wb");

    int val1 = atoi(g.b);
    switch (val) {
    case 1674:
        system("cls");
        gotoxy(54, 10);
        printf("Train name: RAJDHANI EXPRESS");
        gotoxy(54, 11);
        printf("Train number: 1674");
        gotoxy(54, 12);
        printf("Departure scheduled at 5:45AM");
        char depart[10] = "5:45AM";
        strcpy(e.depart, depart);
        char status[20] = "AC tier 3";
        strcpy(e.status, status);
        gotoxy(54, 13);
        printf("Status: AC tier 3");
        gotoxy(54, 14);
        z = 450 * val1;
        fwrite( & z, sizeof(z), 1, ptr);
        fwrite( & e, sizeof(e), 1, fhptr);
        printf("Total fare: %dRs", z);
        getch();
        break;

    case 8610:
        system("cls");
        gotoxy(54, 10);
        printf("Train name: DURONTO EXPRESS");
        gotoxy(54, 11);
        printf("Train number: 8610");
        gotoxy(54, 12);
        printf("Departure scheduled at 8:25AM");
        char depart1[10] = "8:25AM";
        strcpy(e.depart, depart1);
        char status1[20] = "AC tier 1";
        strcpy(e.status, status1);
        gotoxy(54, 13);
        printf("Status: AC tier 1");
        gotoxy(54, 14);
        z = 815 * val1;
        fwrite( & z, sizeof(z), 1, ptr);
        fwrite( & e, sizeof(e), 1, fhptr);
        printf("Total fare: %dRs", z);
        getch();
        break;

    case 9112:
        system("cls");
        gotoxy(54, 10);
        printf("Train name: JAN SHATABDI EXPRESS");
        gotoxy(54, 11);
        printf("Train number: 9112");
        gotoxy(54, 12);
        printf("Departure scheduled at 12:15PM");
        char depart2[10] = "12:15PM";
        strcpy(e.depart, depart2);
        char status2[20] = "Sleeper";
        strcpy(e.status, status2);
        gotoxy(54, 13);
        printf("Status: Sleeper");
        gotoxy(54, 14);
        z = 225 * val1;
        fwrite( & z, sizeof(z), 1, ptr);
        fwrite( & e, sizeof(e), 1, fhptr);
        printf("Total fare: %dRs", z);
        getch();
        break;

    case 3907:
        system("cls");
        gotoxy(54, 10);
        printf("Train name: VANDE BHARAT");
        gotoxy(54, 11);
        printf("Train number: 3907");
        gotoxy(54, 12);
        printf("Departure scheduled at 16:40PM");
        char depart3[10] = "16:40PM";
        strcpy(e.depart, depart3);
        char status3[20] = "AC tier 2";
        strcpy(e.status, status3);
        gotoxy(54, 13);
        printf("Status: AC tier 2");
        gotoxy(54, 14);
        z = 300 * val1;
        fwrite( & z, sizeof(z), 1, ptr);
        fwrite( & e, sizeof(e), 1, fhptr);
        printf("Total fare: %dRs", z);
        getch();
        break;

    case 2053:
        system("cls");
        gotoxy(54, 10);
        printf("Train name: GATIMAN EXPRESS");
        gotoxy(54, 11);
        printf("Train number: 2053");
        gotoxy(54, 12);
        printf("Departure scheduled at 20:00PM");
        char depart4[10] = "20:00PM";
        strcpy(e.depart, depart4);
        char status4[20] = "AC tier 3";
        strcpy(e.status, status4);
        gotoxy(54, 13);
        printf("Status: AC tier 3");
        gotoxy(54, 14);
        z = 450 * val1;
        fwrite( & z, sizeof(z), 1, ptr);
        fwrite( & e, sizeof(e), 1, fhptr);
        printf("Total fare: %dRs", z);
        getch();
        break;

    case 4095:
        system("cls");
        gotoxy(54, 10);
        printf("Train name: ANTYODAYA EXPRESS");
        gotoxy(54, 11);
        printf("Train number: 4095");
        gotoxy(54, 12);
        printf("Departure scheduled at 23:10PM");
        char depart5[10] = "23:10PM";
        strcpy(e.depart, depart5);
        char status5[20] = "AC tier 1";
        strcpy(e.status, status5);
        gotoxy(54, 13);
        printf("Status: AC tier 1");
        gotoxy(54, 14);
        z = 600 * val1;
        fwrite( & z, sizeof(z), 1, ptr);
        fwrite( & e, sizeof(e), 1, fhptr);
        printf("Total fare: %dRs", z);
        getch();
        break;

    default:
        printf("Invalid Input!");
        exit(0);
    }
    fclose(ptr);
    fclose(fhptr);

    int x;
    do {
        gotoxy(48, 17);
        printf("Do you want to continue to book the ticket(s)?");
        gotoxy(48, 18);
        printf("Press 1 to book");
        gotoxy(48, 19);
        printf("Press 0 to return to Main Menu");
        gotoxy(48, 20);
        printf("Enter your choice: ");
        scanf("%d", & x);

        switch (x) {
        case 1:
            ages();
            break;

        }
    } while (x != 0);
}

void ages() {
    char name[100][30];
    int age[100];
    char val1[10];
    system("cls");
    struct ages j;
    struct info g;
    FILE * fp5;
    fp5 = fopen("Sugam.txt", "rb");
    while (fread( & g, sizeof(g), 1, fp5)) {
        gotoxy(45, 6);
        printf("Enter names and ages of %s passengers.", g.b);
        strcpy(val1, g.b);
    }
    int val = atoi(val1);
    for (int l = 1; l < (val + 1); l++) {

        printf("\n\t\t\t\t\t\tEnter name of passenger %d: ", l);
        fflush(stdin);
        scanf("%[^\n]s", & n.name[l]);

        printf("\t\t\t\t\t\tEnter age of passenger %d: ", l);
        fflush(stdin);
        scanf("%d", & age[l]);
        printf("\n\n");
    }
    FILE * f;
    f = fopen("clientnames1.txt", "wb");
    fwrite( & n, sizeof(n), 1, f);

    FILE * f1;
    f1 = fopen("clientages1.txt", "wb+");
    fwrite(age, sizeof(int), sizeof(age), f1);
    fclose(f1);

    int loop;
    printf("\t\t\t\t\t\tPassengers Data:");
    here:
        for (loop = 1; loop < (val + 1); loop++)
            printf("\n\t\t\t\t\t\t\t%s [%d]\n\t\t\t\t\t\t\t", n.name[loop], age[loop]);
    getch();
    system("cls");
    gotoxy(47, 17);
    printf("Please proceed with your ticket payment through My_Pay!");
    getch();
    trains();
}

void my_pay() {
    system("color 5F");
    struct ages j;
    struct user u, U;
    system("cls");
    char str[20];
    int bal = 0;
    gotoxy(50, 6);
    printf("Please Link your Bank account with My_Pay!");
    gotoxy(46, 7);

    int b;
    printf("Enter your 10 digit bank account number: ");
    scanf("%s", & str);

    int k, z, a, h;
    for (h = 0; h <= 7; h++) {
        gotoxy(56, 17);
        printf("Finding your account");
        for (k = 0; k <= 6; k++) {
            for (z = 0; z < 100000000; z++)
                a = z;
            printf(".");
        }
        system("cls");
    }
    system("cls");

    if (strlen(str) == 10) {
        gotoxy(58, 17);
        printf("Account found!");
        getch();
    } else {
        gotoxy(56, 17);
        printf("No such bank account in existence!");
        gotoxy(53, 18);
        printf("We are experiencing a technical glitch! Please try again later!");
        exit(0);
    }
    fp = fopen("C:\\Details_Customer\\User.txt", "rb");
    fread( & U, sizeof(struct user), 1, fp);

    system("cls");
    char otp[6], votp[6], c;
    int i;
    srand((unsigned) time(NULL));
    for (i = 0; i < 5; i++) {
        c = rand() % 10 + 48;
        otp[i] = c;
    }
    gotoxy(37, 4);
    printf(" -------------------------------------------------------------");
    gotoxy(37, 5);
    printf("    |                                                     |");
    gotoxy(37, 6);
    printf("    |        <----<<<< OTP VERIFICATION >>>>---->         |");
    gotoxy(37, 7);
    printf("    |                                                     |");
    gotoxy(37, 8);
    printf(" -------------------------------------------------------------");

    char sstr[20];
    int p = 7, l = 4, f = 0;

    while (f < l) {
        sstr[f] = U.mno[p + f - 1];
        f++;
    }
    sstr[f] = '\0';

    printf("\n\n\n\t\t\t\tOTP has been sent to your mobile number ******%s linked with this account.", sstr);
    Sleep(7000);
    printf("\n\n\n\t\t\t\t\tMy_Pay :: Your One Time Password is: %s", otp);
    printf("\n\n\t\t\t\t\tVerify OTP: ");
    scanf("%s", & votp);
    if (strcmp(otp, votp) == 0) {
        printf("\n\t\t\t\t\t\t\t\t!OTP Verified!");
    } else {
        printf("\n\t\t\t\t\t\t*OTP Mismatched*");
    }
    otp[i] = '\0';
    gotoxy(90, 30);
    printf("Press any key to continue...");
    getch();
    system("cls");

    char ssstr[20];
    int p1 = 7, l1 = 4, f1 = 0;

    while (f1 < l) {
        ssstr[f1] = str[p1 + f1 - 1];
        f1++;
    }
    ssstr[f1] = '\0';
    printf("Your bank account ******%s has been successfully linked with My_Pay!", ssstr);
    system("cls");
    gotoxy(60, 12);
    printf("!***ACCOUNT DETAILS***!");

    char r;
    int v;
    srand((unsigned) time(NULL));
    for (v = 0; v <= 4; v++) {
        r = rand() % 10 + 48;
        j.randbal[v] = r;
        j.h = atoi(j.randbal);
    }
    FILE * fp6;
    fp6 = fopen("C:\\Details_Customer\\User.txt", "rb");
    while (fread( & u, sizeof(struct user), 1, fp6)) {
        gotoxy(50, 14);
        printf("Account holder Name: %s %s", u.fname, u.lname);
        gotoxy(50, 15);
        printf("Linked Mobile Number: %s", u.mno);
        gotoxy(50, 16);
        printf("Age of Account holder: %s", u.age);
        gotoxy(50, 17);
        printf("E-mail Linked with account: %s", u.email);
    }
    gotoxy(50, 18);
    printf("Account Balance: Rs.%d", j.h);

    int t;
    FILE * ptr = fopen("principles.txt", "rb");
    fread( & z, sizeof(z), 1, ptr);
    getch();
    system("cls");
    gotoxy(28, 15);
    printf("Do you want to make a payment of Rs.%d for your train tickets through My_Pay?", z);
    gotoxy(41, 16);
    printf("1. Yes");
    gotoxy(41, 17);
    printf("2. No");
    gotoxy(41, 18);
    printf("Enter your choice: ");
    scanf("%d", & t);
    switch (t) {
    case 2:
        trains();
        break;
    case 1:
        goto here;
        break;

    }
    here:
        process();

    int x = j.h - z;
    if (x >= 0) {
        system("cls");
        gotoxy(58, 17);
        printf("Payment Successful!");
        gotoxy(52, 18);
        printf("Your updated Balance is: Rs.%d/-", j.h - z);
    } else if (x < 0) {
        system("cls");
        gotoxy(52, 17);
        printf("Payment Failed! Insufficient Balance!");
    }
    getch();
    trains();
}

void cancelreservation() {
    struct high b1;
    FILE * fp;
    fp = fopen("a.txt", "rb");
    fread( & b1, sizeof(b1), 1, fp);

    int ch;
    printf("Are you sure you want to cancel reservation?");
    printf("\n1. Cancel\n2. Abort cancellation");
    printf("\nEnter your choice: ");
    scanf("%d", & ch);
    switch (ch) {
    case 1:
        printf("Your Reservation scheduled from %s to %s is canceled!", b1.boarding, b1.destiny);
        printf("\nYou will shortly recieve your payment(if processed).");
        getch();
        system("cls");
        gotoxy(58, 17);
        printf("Loading System...");
        Sleep(5000);
        trains();
        break;
    case 2:
        gotoxy(44, 17);
        printf("Your Reservation is completed for journey from %s to %s!", b1.boarding, b1.destiny);
        break;
    }
    fclose(fp);
}

void process() {
    system("cls");
    int a, z, r, q;
    system("color 2F");
    gotoxy(20, 28);
    printf("Loading...");
    for (int k = 0; k <= 6; k++) {
        for (z = 0; z < 100000000; z++)
            a = z;
        printf(".");
    }
    system("cls");
    system("color 6F");
    gotoxy(20, 28);
    printf("Linking deatils...");
    for (int k = 0; k <= 6; k++) {
        for (z = 0; z < 100000000; z++)
            a = z;
        printf(".");
    }
    system("cls");
    system("color 1F");
    gotoxy(20, 28);
    printf("Processing your payment...");
    for (int k = 0; k <= 6; k++) {
        for (z = 0; z < 100000000; z++)
            a = z;
        printf(".");
    }
    system("cls");
    system("color 8F");
    gotoxy(20, 28);
    printf("Granting Permissions...");
    for (int k = 0; k <= 4; k++) {
        for (z = 0; z < 100000000; z++)
            a = z;
        printf(".");
    }
    system("cls");
    system("color 0F");
    gotoxy(20, 28);
    printf("Connecting to bank server...");
    for (int k = 0; k <= 4; k++) {
        for (z = 0; z < 100000000; z++)
            a = z;
        printf(".");
    }
    system("cls");
    system("color 4F");
    gotoxy(20, 28);
    printf("Transacting...");
    for (int k = 0; k <= 4; k++) {
        for (z = 0; z < 100000000; z++)
            a = z;
        printf(".");
    }
    system("cls");
    system("color 3F");
    gotoxy(20, 28);
    printf("Processing...");
    for (int k = 0; k <= 6; k++) {
        for (z = 0; z < 100000000; z++)
            a = z;
        printf(".");
    }
    system("cls");
    system("color 5F");
    gotoxy(20, 28);
    printf("Almost done...!");
    gotoxy(20, 29);
    printf("We appreciate your patience!");
    gotoxy(10, 30);
    for (r = 1; r <= 120; r++) {
        for (q = 0; q <= 10000000; q++);
        printf("%c", 177);
    }
}

void ticket_printing() {
    struct date d;
    struct info g;
    struct high b1;
    struct user u;
    struct name n;
    char val1[10];
    FILE * ptr1;
    ptr1 = fopen("dates.txt", "rb");
    fread( & d, sizeof(d), 1, ptr1);
    FILE * fp5;
    fp5 = fopen("Sugam.txt", "rb");
    fread( & g, sizeof(g), 1, fp5);
    FILE * fp;
    fp = fopen("a.txt", "rb");
    fread( & b1, sizeof(b1), 1, fp);
    FILE * fp6;
    fp6 = fopen("C:\\Details_Customer\\User.txt", "rb");
    fread( & u, sizeof(struct user), 1, fp6);
    strcpy(val1, g.b);
    int val = atoi(val1);
    FILE * ptr2 = fopen("clientnames1.txt", "r");
    fread( & n, sizeof(n), 1, ptr2);
    FILE * fhptr;
    fhptr = fopen("departure.txt", "rb");
    fread( & e, sizeof(e), 1, fhptr);

    printf("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\xB2       TICKET        \xB2");
    printf("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\xB2 Name: %s %s  \xB2", u.fname, u.lname);
    printf("\n\t\xB2 PRN:17489321        \xB2");
    printf("\n\t\xB2 Train no:%s       \xB2", g.a);
    printf("\n\t\xB2 From:%s           ", b1.boarding);
    gotoxy(30, 7);
    printf("\xB2");
    printf("\n\t\xB2 To:%s              ", b1.destiny);
    gotoxy(30, 8);
    printf("\xB2");
    printf("\n\t\xB2 Age:%s              \xB2", u.age);
    printf("\n\t\xB2 Status:%s        ", e.status);
    gotoxy(30, 10);
    printf("\xB2");
    printf("\n\t\xB2 Departure-%s       ", e.depart);
    gotoxy(30, 11);
    printf("\xB2");
    printf("\n\t\xB2 Date:%s/%s/%s      \xB2", d.str1, d.str2, d.str3);
    printf("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\xB2   HAPPY JOURNEY!    \xB2");
    printf("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n");
    printf("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\xB2   This Ticket is    \xB2");
    printf("\n\t\xB2    alloted to %s     \xB2", g.b);
    printf("\n\t\xB2     passengers!     \xB2");
    printf("\n\t\xB2                     \xB2");
    printf("\n\t\xB2Names of passengers: \xB2");
    for (int t = 1; t < (val + 1); t++)
        printf("\n\t  %s       ", n.name[t]);
    gotoxy(30, 22);
    printf("\xB2");
    gotoxy(30, 23);
    printf("\xB2");
    gotoxy(30, 24);
    printf("\xB2");
    gotoxy(30, 25);
    printf("\xB2");
    gotoxy(8, 22);
    printf("\xB2");
    gotoxy(8, 23);
    printf("\xB2");
    gotoxy(8, 24);
    printf("\xB2");
    gotoxy(8, 25);
    printf("\xB2");
    gotoxy(30, 26);
    printf("\xB2");
    gotoxy(30, 27);
    printf("\xB2");
    gotoxy(8, 26);
    printf("\xB2");
    gotoxy(8, 27);
    printf("\xB2");
    gotoxy(30, 28);
    printf("\xB2");
    gotoxy(8, 28);
    printf("\xB2");
    printf("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\xB2   HAPPY JOURNEY!    \xB2");
    printf("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    fclose(ptr1);
    fclose(fp5);
    fclose(fp);
    fclose(fp6);
    fclose(ptr2);
    fclose(fhptr);
    getch();
    trains();
}

void end() {
    system("color 0F");
    system("cls");
    gotoxy(35, 8);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(48, 9);
    printf(" TRAIN RESERVATION SYSTEM :: SUGAM PHIRKE");
    gotoxy(48, 10);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(48, 12);
    printf(" !***CPPS MINI PROJECT '21[C LANGUAGE]***!");
    gotoxy(48, 30);
    exit(0);
}