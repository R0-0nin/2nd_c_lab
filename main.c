#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
int about(){

    printf("%s", "\nWelcome to the graph editor! It`s a program, what allows creating, editing and deleting graphs. ");
    printf("%s", "It works using adjacency matrix technology. It means, that if you want to see your graph, you will see a matrix, ");
    printf("%s", "created with your instructions. In this program '0' means edge`s absence, while '1' means edge`s existence. ");
    printf("%s", "'8' means impossibility of creating edge because of 1 knot.\n\n");
    printf("%s", "Good luck, fella!\n\n");
}


int deletegraph(){

    remove("C:\\Users\\dsmet\\Desktop\\a.txt");
    printf("\n%s","Graph is deleted successfully!");

}

int opening(){
    char size[255];
    char arr[255];
    FILE *file;
    file = fopen("C:\\Users\\dsmet\\Desktop\\a.txt", "r");
    fgets(size, 255, file);

    fgets(arr, 255, file);

    int x = size[0] - '0';
    int graf[3][3];
    memset(graf, 0, sizeof(graf));

    int y = arr[1] - '0';
    graf[0][1] = y;
    //printf("%d", y);
    int j = 0;

    for(int i = 0; i < x; i++)
    {
        for (int k = 0; k < x; k++)
        {

            y = arr[j] - '0';
            graf[i][k] = y;
            j = j + 1;
        }

    }

    fclose(file);

    edit(x, graf);
}


int upload(int x, int graf[][x])
{
    FILE *file;
    file = fopen("C:\\Users\\dsmet\\Desktop\\a.txt", "w+t");
    fprintf(file, "%d\n", x);
    for (int i = 0; i < x; i++){

        for(int j = 0; j < x; j++){

            fprintf(file, "%d", graf[i][j]);

        }
    }

    fclose(file);

    getch();

    return 0;
}

int observe(int x, int graf[][x])
{
    printf("\n");
    int i, k;
    int c = x;
    int igraf[c][c];
    char sgraf[c][c];

    printf("%c ", '|');

    for (i = 0; i < c; i++)
    {
        for (k = 0; k < c; k++)
        {
            if (i == k)
                sgraf[i][k] = 'X';
            else if (graf[i][k] == 0)
                sgraf[i][k] = '0';
            else if (graf[i][k] == 1)
                sgraf[i][k] = '1';

        }
    }

    sgraf[0][0] = 'X';
    for (i = 0; i < c; i++)
    {
        igraf[i][0] = i + 1;
        igraf[0][i] = i + 1;
        printf("%d ", igraf[i][0]);

    }
    printf("\n");
    for (i = 0; i < c; i++)
    {
        printf("%d ", igraf[0][i]);
        for (k = 0; k < c; k++)
        {
            if (k >= 9)
                printf("%c  ", sgraf[i][k]);
            else
                printf("%c ", sgraf[i][k]);
        }
        printf("\n");
    }
    printf("\n");
}

int creater()
{
    printf("Welcome to the graph creator!\n\nWhat`s the count of knots would you like to create?\nN = ");
    int x;
    scanf("%d", &x);
    int graf[x][x];
    int i, k;
    for(i = 0; i < x; i++)
    {
        for(k = 0; k < x; k++)
        {
            graf[i][k] = 0;

        }

    }
    printf("\n");
    printf("%s %d %s","Graph with", x ,"edges has created successfully!\n\nWould you like to edit your graph?\n");
    if (answer() == 1){
        printf("\n");
        edit(x, graf);
    }
    else
        printf("%s", "Okay, bye!");
        return graf;
}

int rebrocreater(int x, int graf[][x]){
    int i, k;
    printf("%s", "Which knots do you want to connect?\nFirst: ");

    scanf("%d", &i);

    if (i > x || i < 0)
    {
        printf("%s", "Choose another!\n");
        rebrocreater(x, graf);
    }
    printf("%s", "And second: ");
    scanf("%d", &k);
    if (k > x || k < 0)
    {
        printf("%s", "Choose another!\n");
        rebrocreater(x, graf);

    }
    if (i != k){
    graf[i - 1][k - 1] = 1;
    graf[k - 1][i - 1] = 1;
    printf("%s", "Edge is created successfully!\n\n");

    return graf;
    }
    else
        printf("%s", "Error! choose another knots!\n\n");
        rebrocreater(x, graf);
}


int rebrodeleter(int x, int graf[][x]){
    int i, k;
    printf("%s", "Which knots do you want to disconnect?\nFirst: ");

    scanf("%d", &i);

    if (i > x || i < 0)
    {
        printf("%s", "Choose another!\n");
        rebrocreater(x, graf);
    }
    printf("%s", "And second: ");
    scanf("%d", &k);
    if (k > x || k < 0)
    {
        printf("%s", "Choose another!\n");
        rebrocreater(x, graf);

    }
    if (i != k){
    graf[i - 1][k - 1] = 0;
    graf[k - 1][i - 1] = 0;
    printf("%s", "Edge is deleted successfully!\n\n");

    return graf;
    }
    else
        printf("%s", "Error! choose another knots!\n\n");
        rebrocreater(x, graf);
}

int answer(){
    printf("%s", "Y/N: ");
    char str1[1024];
    scanf("%s", &str1);
    char str2[1024] = "Y";
    if (strcmp (str1, str2) == 0)
        return 1;
    else
        return 2;
}

int edit(int x, int graf[][x]){
    char AE[1024] = "AE";
    char DE[1024] = "DE";
    char AK[1024] = "AK";
    char DK[1024] = "DK";
    char S[1024] = "S";
    char E[1024] = "E";
    char choose[1024];

    printf("%s", "What do you want to do with your graph?\n\nAdd edges - AE\nDelete edges - DE\nAdd knots - AK\nDelete knots - DK\nSee my graph - S\nExit - E\n\nSo...:");
    scanf("%s", &choose);

    if (strcmp (choose, AE) == 0){

        rebrocreater(x, graf);
        edit(x, graf);
    }
    else if (strcmp (choose, DE) == 0){

        rebrodeleter(x, graf);
        edit(x, graf);
    }
    else if (strcmp (choose, AK) == 0){

        adder(x, graf);
        edit(x, graf);
    }
    else if (strcmp (choose, DK) == 0){

        deleter(x,graf);
        edit(x, graf);
    }
    else if (strcmp (choose, S) == 0){
        observe(x, graf);
        edit(x, graf);
    }
    if (strcmp (choose, E) == 0){
        upload(x, graf);
    }

}


int adder(int x, int graf[][x]){
    printf("%s", "How many knots do you want to add?\n\nN = ");
    int a;
    scanf("%d", &a);
    int c = x + a;
    int pgraf[c][c];
    int i, k;
    memset(pgraf, 0, sizeof(pgraf));

    for(i = 0; i < x; i++)
    {
        for(k = 0; k < x; k++)
        {
            pgraf[i][k] = graf[i][k];

        }
    }


    x = c;
    printf("%s", "Knots are added successfully!\n\n");
    edit(x, pgraf);
}

int deleter(int x, int graf[][x])
{
    printf("%s", "How many knots do you want to delete?\n\nN = ");
    int a;
    scanf("%d", &a);
    int c = x - a;
    int pgraf[c][c];
    int i, k;
    memset(pgraf, 0, sizeof(pgraf));

    for(i = 0; i < x; i++)
    {
        for(k = 0; k < x; k++)
        {
            pgraf[i][k] = graf[i][k];

        }

    }

    x = c;
    printf("%s", "Knots are deleted successfully!\n\n");
    edit(x, pgraf);
}

int main()
{
    printf("%s", "Welcome to the Graphs, what do u want to do?\n\nOpen existing graph - O\nCreate graph - C\nDelete graph - D\nAbout program - A\n\nSo...: ");
    char choose[1024];
    char O[1024] = "O";
    char C[1024] = "C";
    char D[1024] = "D";
    char A[1024] = "A";
    scanf("%s", &choose);
    if (strcmp (choose, O) == 0){
        printf("\n");
        opening();
    }
    else if (strcmp (choose, C) == 0){
        printf("\n");
        creater();
    }
    else if (strcmp (choose, D) == 0){
        deletegraph();
    }
    else if (strcmp (choose, A) == 0)
        about();
    return 0;
}
