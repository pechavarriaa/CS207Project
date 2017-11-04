#include <cstdio>
#include <iostream>
using namespace std;
class cube3 {
protected:
	char r[3][3] = { 'b','b','b','b','b','b', 'b','b', 'b' };
	char l[3][3] = { 'g','g','g','g','g','g', 'g','g', 'g' };
	char f[3][3] = { 'r','r','r','r','r','r', 'r','r', 'r' };
	char b[3][3] = { 'o','o','o','o','o','o', 'o','o','o' };
	char d[3][3] = { 'y','y','y','y','y','y', 'y','y','y' };
	char u[3][3] = { 'w','w','w','w','w','w', 'w','w', 'w'};
public:
	void reset();

	void Rmove();
	void Umove();
	void Fmove();
	void Ymove();

	void Lmove();
	void Bmove();
	void Dmove();
};
int main()
{

}