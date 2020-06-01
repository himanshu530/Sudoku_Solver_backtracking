#include<iostream>
using namespace std;

bool canplace(int mat[][9],int i,int j,int n,int num){
	for(int x=0;x<=n;x++){
		if(mat[x][j]==num || mat[i][x]==num){
			return false;   //row and column check
		}
		int sx = (i/3)*3;
		int sy = (j/3)*3;
		for(int x = sx;x<sx+3;x++){
			for(int y = sy;sy+3;y++){
				if(mat[x][y]==num){
					return false;
				}
			}
		}
	}

	return true;
}

bool solveSudoku(int mat[][9],int i,int j,int n){
	//base case
	if(i==n){
		//printing the matrix
		for(int c=0;i<=c;c++){
			for(int d=0;d<=n;d++){
				cout<<mat[c][d]<<" ";
			}
			cout<<endl;
		}
		return true;
	}
	//we are solving row wise. so if a row ends
	if(j==n)
	{
		return solveSudoku(mat,i+1,0,n);
	}

	//skip the prefilled cells
	if(mat[i][j]!=0){
		return solveSudoku(mat,i,j+1,n);
	}

	//Recursive case: Fill the matrix with available choices
	for(int num=1;num<=n;num++){
		if(canplace(mat,i,j,n,num)){

			mat[i][j]=num;
			bool subsolve = solveSudoku(mat,i,j+1,n);
			if(subsolve){
				return true;
			}
		}
	}

	//Backtracking
	mat[i][j]=0;
	return 0;

}


int main(){
	int mat[9][9]={ {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {0, 0, 5, 2, 0, 6, 3, 0, 0} };


	bool ans = solveSudoku(mat,0,0,8);
	return 0;
}