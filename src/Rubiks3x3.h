class cube {
public:
	char r[3][3]={{'b','b','b'},{'b','b','b'},{'b','b','b'}};
	char l[3][3]={{'g','g','g'},{'g','g','g'},{'g','g','g'}};
	char f[3][3]={{'r','r','r'},{'r','r','r'},{'r','r','r'}};
	char b[3][3]={{'o','o','o'},{'o','o','o'},{'o','o','o'}};
	char d[3][3]={{'y','y','y'},{'y','y','y'},{'y','y','y'}};
	char u[3][3]={{'w','w','w'},{'w','w','w'},{'w','w','w'}};

	void fillFace(char col, char arr[][3])
	{
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				arr[i][j]=col;
	}
 
	void resetCube()
	{
		fillFace('b',r);
		fillFace('g',l);
		fillFace('r',f);
		fillFace('o',b);
		fillFace('y',d);
		fillFace('w',u);
	};  

	void rotateFace(char arr[][3])
	{
		int x = arr[0][0];
		arr[0][0] = arr[2][0];
		arr[2][0] = arr[2][2];
		arr[2][2] = arr[0][2];
		arr[0][2] = x;

		x = arr[1][0];
		arr[1][0] = arr[2][1];
		arr[2][1] = arr[1][2];
		arr[1][2] = arr[0][1];
		arr[0][1] = x;
	}
	void R_move()
	{
		int x,y,z;
		x = f[0][2];
		y = f[1][2];
		z = f[2][2];

		f[0][2] = d[0][2];
		f[1][2] = d[1][2];
		f[2][2] = d[2][2];

		d[0][2] = b[2][0];
		d[1][2] = b[1][0];
		d[2][2] = b[0][0];

		b[2][0] = u[0][2];
	  b[1][0] = u[1][2];
		b[0][0] = u[2][2];

		u[0][2] = x;
		u[1][2] = y;
		u[2][2] = z;

		rotateFace(r);
	}
	void U_move()
	{
		int x,y,z;
		x = f[0][0];
		y = f[0][1];
		z = f[0][2];

		f[0][0] = r[0][0];
		f[0][1] = r[0][1];
		f[0][2] = r[0][2];

		r[0][0] = b[0][0];
		r[0][1] = b[0][1];
		r[0][2] = b[0][2];

		b[0][0] = l[0][0];
		b[0][1] = l[0][1];
		b[0][2] = l[0][2];

		l[0][0] = x;
		l[0][1] = y;
		l[0][2] = z;

		rotateFace(u);
	}
	void F_move()
	{
		int x,y,z;

		x = l[0][2];
		y =	l[1][2];
		z	=	l[2][2];


		l[0][2] = d[0][0];
		l[1][2] = d[0][1];
		l[2][2] = d[0][2];

		d[0][0] = r[2][0];
		d[0][1] = r[1][0];
		d[0][2] = r[0][0];

		r[0][0] = u[2][0];
		r[1][0] = u[2][1];
		r[2][0] = u[2][2];

		u[2][0] = z;
		u[2][1] = y;
		u[2][2] = x;

		rotateFace(f);
	}
	void M_move()
	{
		int x,y,z;
		x = f[0][1];
		y = f[1][1];
		z = f[2][1];

		f[0][1] = u[0][1];
		f[1][1] = u[1][1];
		f[2][1] = u[2][1];

		u[0][1] = b[2][1];
		u[1][1] = b[1][1];
		u[2][1] = b[0][1];

		b[2][1] = d[0][1];
		b[1][1] = d[1][1];
		b[0][1] = d[2][1];

		d[0][1] = x;
		d[1][1] = y;
		d[2][1] = z;
	}
	void E_move()
	{
		int x,y,z;
		x = f[1][0];
		y = f[1][1];
		z = f[1][2];

		f[1][0] = l[1][0];
		f[1][1] = l[1][1];
		f[1][2] = l[1][2];

		l[1][0] = b[1][0];
		l[1][1] = b[1][1];
		l[1][2] = b[1][2];

		b[1][0] = r[1][0];
	 	b[1][1] = r[1][1];
		b[1][2] = r[1][2];

		r[1][0] = x;
		r[1][1] = y;
		r[1][2] = z;
	}
	void S_move()
	{
		int x,y,z;
		x = u[1][0];
		y = u[1][1];
		z = u[1][2];

		u[1][0] = l[2][1];
		u[1][1] = l[1][1];
		u[1][2] = l[0][1];

		l[2][1] = d[1][2];
		l[1][1] = d[1][1];
		l[0][1] = d[1][0];

		d[1][2] = r[0][1];
		d[1][1] = r[1][1];
		d[1][0] = r[2][1];

		r[0][1] = x;
		r[1][1] = y;
		r[2][1] = z;
	}
	void copyFace(char x[][3],char y[][3])
	{
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
					x[i][j] = y[i][j];
	}
	void Y_rotation()
	{
		char arr[3][3];
			copyFace(arr,f);
			copyFace(f,r);
			copyFace(r,b);
			copyFace(b,l);
			copyFace(l,arr);
			rotateFace(u);
			for(int i=0;i<3;i++)
			rotateFace(d);
	}
	void X_rotation()
	{
		R_move();
		for(int i=0;i<3;i++)
			M_move();
		for(int i=0;i<2;i++)
			Y_rotation();
		for(int i=0;i<3;i++)
			R_move();
		for(int i=0;i<2;i++)
			Y_rotation();
	}
	void Z_rotation()
	{
		for(int i=0;i<2;i++)
			Y_rotation();
		for(int i=0;i<3;i++)
			F_move();
		for(int i=0;i<2;i++)
			Y_rotation();
			S_move();
			F_move();
	}
	void L_move()
	{
		Y_rotation();
		Y_rotation();
		R_move();
		Y_rotation();
		Y_rotation();
	}
	void B_move()
	{
		Y_rotation();
		R_move();
		for(int i=0;i<3;i++)
			Y_rotation();
	}
	void D_move()
	{
		X_rotation();
		F_move();
		for(int i=0;i<3;i++)
		X_rotation();
	}
	bool faceSolved(char arr[][3])
	{
		char x = arr[0][0];
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				if(arr[i][j]!=x)
					return false;
		return true;
	}
	bool isSolved()
	{
		if(!faceSolved(r))
			return false;
		if(!faceSolved(l))
			return false;
		if(!faceSolved(u))
			return false;
		if(!faceSolved(d))
			return false;
		if(!faceSolved(f))
			return false;
		if(!faceSolved(b))
			return false;
			return true;
	}
	void moveCube(int times,char mv)
	{
	  for(int i=0;i<times;i++)
	  {
	    if(mv == 'R')
	      R_move();
	    else if(mv == 'L')
	      L_move();
	    else if(mv == 'U')
	      U_move();
	    else if(mv == 'B')
	      B_move();
	    else if(mv == 'F')
	      F_move();
	    else if(mv == 'D')
	      D_move();
	    else if(mv == 'Y')
	      Y_rotation();
	    else if(mv == 'X')
	      X_rotation();
	    else if(mv == 'Z')
	      Z_rotation();
	    else if(mv == 'M')
	      M_move();
	    else if(mv == 'E')
	      E_move();
	    else if(mv == 'S')
	      S_move();
	  }
	}
};
