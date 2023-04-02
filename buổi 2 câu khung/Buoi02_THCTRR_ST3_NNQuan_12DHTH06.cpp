#include<iostream>
#include<fstream>
#include<stack>
using namespace std;
struct dothi
{
	//flag: loai do thi 0 la vo huong, 1 la co huong
	//n: so dinh cua do thi
	//w[50][50]: ma tran ke hoac ma tran trong sos
	int flag, n, w[50][50];
};
void doc_file(dothi& g,char filename[])
{
	ifstream file;
	file.open(filename, ios::in);
	if (file.fail())
	{
		cout << "loi doc file ";
		return;
	}
	else
	{
		file >> g.flag;
		file >> g.n;
		for (int i = 1; i <= g.n; i++)
		{
			for (int j = 1; j <= g.n; j++)
			{
				file >> g.w[i][j];
			}
		}
	}
	file.close();
}
void xuat_do_thi(dothi g)
{
	if (g.flag == 0)
	{
		cout << "do thi vo huong " << endl;
	}
	else
	{
		cout << "do thi co huong " << endl;
	}
	cout << "MA TRAN KE HOAC MA TRAN TRONG SO "<<endl;
	for (int i = 1; i <= g.n; i++)
	{
		for (int j = 1; j <= g.n; j++)
		{
			cout << g.w[i][j]<<" ";
		}
		cout <<endl;
	}
}
struct canh
{
	int u, v;
};
//danh dau cac dinh da xet hay chua, dau tien khoi tao cac dinh chua xet
int chua_xet[100];
void xuat_cay_khung(canh T[], int so_canh)
{
	cout << endl;
	cout << "cay khung : ";
	for (int i = 1; i <= so_canh; i++)
	{
		cout <<"(" << T[i].u <<","<< T[i].v <<")"<<" ";
	}
}
void cay_khung_DFS(dothi g, canh T[], int& so_canh, int u)
{
	chua_xet[u] = 1;
	for (int v = 1; v <= g.n; v++)
	{
		if (g.w[u][v]!=0&&chua_xet[v]==0)
		{
			so_canh++;
			T[so_canh].u = u;
			T[so_canh].v = v;
			if (so_canh == g.n - 1)
			{
				xuat_cay_khung(T, so_canh);
				return;
			}
			else
			{
				cay_khung_DFS(g, T, so_canh, v);
			}
		}
	}
}
void cay_khung_BFS(dothi g, canh T[], int& so_canh)
{
	for (int u = 1; u <= g.n; u++)
	{
		for (int v = 1; v <= g.n; v++)
		{
			if (g.w[u][v] !=0 && chua_xet[v] == 0)
			{
				so_canh++;
				T[so_canh].u = u;
				T[so_canh].v = v;
				chua_xet[v] = 1;
				chua_xet[v] = 1;
				if (so_canh == g.n - 1)
				{
					xuat_cay_khung(T, so_canh);
					return;
				}
			}
		}
	}
}
void DFS(int u)//, canh T[],dothi g, canh T[], int& so_canh)
{
	stack<int>st;

	cout << "DFS(" << u << "): ";
}
void main()
{
	dothi g;
	char filename[] = "input.txt";
	doc_file(g,filename);
	xuat_do_thi(g);
	canh T[100];
	int so_canh = 0;
	for (int i = 1; i <= g.n; i++)
	{
		chua_xet[i] = 0;
	}
	cay_khung_DFS(g, T, so_canh, 1);
	//cay_khung_BFS(g, T, so_canh);
}