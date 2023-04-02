#define _crt_secure_no_warnings
#include<fstream>
#include<iostream>
using namespace std;
#define vc 100
#define maxv 50
struct graph
{
	int flag;
	int n;
	int m[50][50];
};
void initgraph(graph& g)
{
	g.flag = -1;
	g.n = 0;
	for (int i = 0; i < maxv; i++)
	{
		for (int j = 0; j < maxv; j++)
		{
			g.m[i][j] = vc;
		}
	}
}
bool doc_danh_sach_canh(char filename[], graph& g)
{
	initgraph(g);
	ifstream file;
	file.open(filename, ios_base::in);
	if (file.fail())
	{
		cout << "loi doc file ";
		g.flag = -1;
		return false;
	}
	int so_canh;
	file >> g.flag; //doc loai do thi
	file >> g.n; //doc so dinh
	file >> so_canh; //doc so canh
	for (int i = 0; i < so_canh; i++)
	{
		int dau, cuoi;
		file >> dau >> cuoi; //doc so canh
		g.m[dau][cuoi] = 1; //di tu dau den cuoi
		if (g.flag == 0)
		{
			g.m[cuoi][dau] = 1; //di tu cuoi den dau
		}
	}
	file.close();
	return true;
}
void xuat_do_thi(graph g)
{
	if (g.flag == -1)
	{
		cout << "\nkhong phai do thi";
		return;
	}
	cout << "so dinh: " << g.n;
	if (g.flag == 0)
		cout << "do thi vo huong";
	else if (g.flag == 1)
	{
		cout << "do thi co huong";
	}
	cout << "\nDANH SACH CANH : \n";
	for (int i = 0; i < g.n; i++)
	{
		for (int j = 0; j < g.n; j++)
		{
			cout << g.m[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	graph g;
	char filename[] = "input_dsc_03.txt";
	doc_danh_sach_canh(filename, g);
	xuat_do_thi(g);
}