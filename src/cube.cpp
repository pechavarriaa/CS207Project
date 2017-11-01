//#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int f[2][2], r[2][2], l[2][2], d[2][2], b[2][2], u[2][2];
const char color[6] = { 'w','y','b','g','r','o' };
//color reference 0:w,1:y,2:b,3:g,4:r,5:o
void fill(int col, int arr[][2])
{
	for (int i = 0;i<2;i++)
		for (int j = 0;j<2;j++)
			arr[i][j] = col;
}
void reset()
{
	fill(0, u);
	fill(1, d);
	fill(2, r);
	fill(3, l);
	fill(4, f);
	fill(5, b);
}
void pFace(int arr[][2])
{
	for (int i = 0;i<2;i++) {
		for (int j = 0;j<2;j++)
			printf("%c ", color[arr[i][j]]);
		printf("\n");
	}
}
void pCube()
{
	printf("Up:\n");
	pFace(u);
	printf("\n");

	printf("Front:\n");
	pFace(f);
	printf("\n");

	printf("Right:\n");
	pFace(r);
	printf("\n");

	printf("Down:\n");
	pFace(d);
	printf("\n");

	printf("Back:\n");
	pFace(b);
	printf("\n");

	printf("Left:\n");
	pFace(l);
}
void turnFace(int arr[][2])
{
	int x = arr[0][0];
	arr[0][0] = arr[1][0];
	arr[1][0] = arr[1][1];
	arr[1][1] = arr[0][1];
	arr[0][1] = x;
}
void turnR()
{
	turnFace(r);
	//turn on right face

	int x = f[0][1];
	int y = f[1][1];

	f[0][1] = d[0][1];
	f[1][1] = d[1][1];

	d[0][1] = b[0][1];
	d[1][1] = b[1][1];

	b[0][1] = u[0][1];
	b[1][1] = u[1][1];

	u[0][1] = x;
	u[1][1] = y;
}
void turnU() {

	turnFace(u);
	int x ,y;


}
int main()
{
	reset();
	for (int i = 0;i<4;i++)
	{
		printf("\nTurn No. %d\n", i + 1);
		turnR();
		pCube();
	}
}