#define _CRT_SECURE_NO_WARNINGS
#define Max 99999 //khai báo 1 số để gán thành giá trị vô cực
#include <stdio.h>
#include <iostream>
struct Graph
{
	int n;
	int MatrixD[100][100], MatrixQ[100][100];
};
void Xuat(Graph graph);
void DocFile(Graph& graph);
void Xuli(Graph& graph, int flag);
void Floyed();
void Find(Graph graph);
int main() 
{
	Floyed();
	Graph graph;
	Find(graph);
	system("pause");
	return 0;
}
void Floyed()
{
	Graph graph;
	//đọc file mảng D và mảng Q
	DocFile(graph);
	Xuat(graph);
	//chạy đủ n lần mảng Q và D
	for (int i = 1; i <= graph.n; i++)
	{
		Xuli(graph, i);
	}
	int index = 0;
	int sum = 99999999;
	for (int i = 1; i <= graph.n; i++)
	{
		int tong = 0;
		for (int j = 1; j <= graph.n; j++)
		{
			tong += graph.MatrixD[i][j];
		}
		if (tong < sum)
		{
			index = i;
			sum = tong;
		}
	}
	printf("%d\n%d", index, sum);
}
void DocFile(Graph& graph)
{
	FILE* L = fopen("MARKET.txt", "r");
	fscanf(L, "%d\n", &graph.n);
	for (int i = 1; i <= graph.n; i++)
	{
		for (int j = 1; j <= graph.n; j++)
		{
			fscanf(L, "%d", &graph.MatrixD[i][j]);
			//nếu mà nó là 0 và khác đường chéo chính => đó là giá trị vô cực
			if (graph.MatrixD[i][j] == 0 && i != j)
			{
				graph.MatrixD[i][j] = Max;
			}
		}
	}
	for (int i = 1; i <= graph.n; i++)
	{
		for (int j = 1; j <= graph.n; j++)
		{
			//nếu mà nó là đường chéo chính và là giá trị vô cực thì ko cần cập nhật mặc định sẽ là 0
			if (i == j || graph.MatrixQ[i][j] == Max) {
				graph.MatrixQ[i][j] = 0;
				continue;
			}
			graph.MatrixQ[i][j] = j;
		}
	}
}
void Xuat(Graph graph) 
{
	for (int i = 1; i <= graph.n; i++)
	{
		for (int j = 1; j <= graph.n; j++)
		{
			//in ra giá trị vô cực
			if (graph.MatrixD[i][j] == Max)
				printf("%5s", "oo");
			else 
				printf("%5d", graph.MatrixD[i][j]);
		}
		printf("\n");
	}
}
void Xuli(Graph& graph, int flag) {

	for (int i = 1; i <= graph.n; i++)
	{
		//nếu mà là cột và hàng đánh dấu thì bỏ qua
		if (i == flag)
			continue;
		for (int j = 1; j <= graph.n; j++)
		{
			if (j == flag || i == j)
				continue;
			int sum = (graph.MatrixD[i][flag] + graph.MatrixD[flag][j]);
			if (sum < graph.MatrixD[i][j]) {
				graph.MatrixD[i][j] = (graph.MatrixD[i][flag] + graph.MatrixD[flag][j]);
				//lúc này đường đi sẽ bằng đường đi từ i đến flag
				graph.MatrixQ[i][j] = graph.MatrixQ[i][flag];
			}
		}
	}
}
void Find(Graph graph) {
	int begin, end;
	printf("nhap diem khoi dau: ");
	scanf("%d", &begin);
	printf("nhap diem ket thuc: ");
	scanf("%d", &end);
	int i = begin;
	//nếu ko có đường đi thì sẽ return 
	if (graph.MatrixQ[i][end] == 0) {
		printf("ko co duong di");
		return;
	}
	while (true)
	{
		printf("%d -> ", i);
		i = graph.MatrixQ[i][end];
		if (i == 0) {
			printf("Null");
			printf("\ncan %d de di\n", graph.MatrixD[begin][end]);
			break;
		}
	}
}