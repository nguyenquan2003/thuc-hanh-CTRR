#include<stdio.h>
#include<conio.h>
#include< stdlib.h>

#define MAXV 50
#define VC 100
struct Graph
{
    int flag;
    int n;
    int w[MAXV][MAXV];
};
int chuaxet[MAXV];

struct bando
{
    int dinhbd;
    int chieudai;
};

void DocFlie(Graph& g)
{
    FILE* f = fopen("Input_ABC.txt", "r");
    if (f == NULL)
        printf("khong the mo duoc file!");
    else
    {
        fscanf(f, "%d", &g.flag);
        fscanf(f, "%d", &g.n);
        for (int i = 1; i <= g.n; i++)
            for (int j = 1; j <= g.n; j++)
                fscanf(f, "%d", &g.w[i][j]);
    }
}
void Xuat_Do_Thi(Graph g)
{
    if (g.flag == 0)
        printf("\nDo thi vo huong.");
    else
        printf("\nDo thi co huong");
    printf("\nMa tran ke hoac ma tran trong so cua do thi: ");
    for (int i = 1; i <= g.n; i++)
    {
        printf("\n");
        for (int j = 1; j <= g.n; j++)
            printf("%5d", g.w[i][j]);
    }
}
void xuatbangchieudai(Graph g, bando bangchieudai[MAXV][MAXV])
{
    printf("\nBang mo ta thuat toan Prim tim cay khung nho nhat: ");
    for (int i = 1; i <= g.n; i++)
        printf("%10d", i);
    for (int i = 0; i <= g.n; i++)
    {
        printf("\n------------------------\n");
        for (int j = 1; j <= g.n; j++)
            printf("\t(%d, %d)", bangchieudai[i][j].dinhbd, bangchieudai[i][j].chieudai);

    }
}
void xuatCayKhungPrim(Graph g, bando bangchieudai[MAXV][MAXV])
{
    printf("\nDanh sach cac canh thuoc cay khung nho nhat");
    int i = 2;
    while (i <= g.n)
    {
        printf("\t(%d, %d)", bangchieudai[g.n][i].dinhbd, i);
        i++;
    }
}
void Prim(Graph g, bando bangchieudai[MAXV][MAXV], int dinhkhoidau)
{
    int chuaxet[MAXV];
    for (int i = 1; i <= g.n; i++)
    {
        chuaxet[i] = 0;
        bangchieudai[0][i].chieudai = VC;
        bangchieudai[0][i].dinhbd = 0;
    }
    bangchieudai[0][dinhkhoidau].chieudai = 0;
    bangchieudai[0][dinhkhoidau].dinhbd = 0;
    int i = 0;
    while (i < g.n)
    {
        int chondinhbd_min = 1;
        while (chuaxet[chondinhbd_min] == 1)
            chondinhbd_min++;
        for (int j = 1; j < g.n; j++)
        {
            if (chuaxet[j] == 0 && bangchieudai[i][j].chieudai < bangchieudai[i][chondinhbd_min].chieudai)
                chondinhbd_min = j;
        }
        /*printf("\n------------%d",chondinhbd_min);
        getch();*/
        chuaxet[chondinhbd_min] = 1;
        i++;
        for (int j = 1; j <= g.n; j++)
        {
            if (chuaxet[j] == 1 || g.w[chondinhbd_min][j] == VC)
                bangchieudai[i][j] = bangchieudai[i - 1][j];
            if (chondinhbd_min != j && chuaxet[j] == 0 && g.w[chondinhbd_min][j] < VC)
                if (bangchieudai[i - 1][j].chieudai > g.w[chondinhbd_min][j])
                {
                    bangchieudai[i][j].chieudai = g.w[chondinhbd_min][j];
                    bangchieudai[i][j].dinhbd = chondinhbd_min;
                }
                else
                    bangchieudai[i][j] = bangchieudai[i - 1][j];
        }
    }
}
void main()
{
    Graph G1;
    DocFlie(G1);
    Xuat_Do_Thi(G1);
    bando bangchieudai[MAXV][MAXV];
    Prim(G1, bangchieudai, 1);
    xuatbangchieudai(G1, bangchieudai);
    xuatCayKhungPrim(G1, bangchieudai);
    _getch();
}