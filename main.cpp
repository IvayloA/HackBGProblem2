#include <iostream>
#include <string>
using namespace std;
/*
 * Filling the array with characters from the keyboard .
 */
 int row;
 int col;
void fillMasive(char **matrix,int N,int M)
{
	char b;
	cout<<"Enter " << N * M << " letters to the string:";
        for(int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin>>b;
			matrix[i][j]=b;
		}
	}
}
/*
 * Printing the array.
 */
void printM(char **matrix,int N,int M)
{
	for (int i = 0; i < N; i++)
	{cout<<endl;
		for (int j = 0; j < M; j++)
		{
			cout<<matrix[i][j]<<' ';
		}
	}
}
int count = 0;

int check(char **matrix, int x, int y, int dx, int dy,string word) {
    int k;
    for(k=0; k<word.size(); k++) {
            if(x < 0) {
                return 0;
            }
            if(y < 0) {
                return 0;
            }
            if(x >= row) {
                return 0;
            }
            if(y >= col) {
                return 0;
            }

            if(word[k] != matrix[x][y]) {
                return 0;
            }

            x = x + dx;
            y = y + dy;
    }

    return 1;
}

int main()

{
	string Sentence;
	int counter=0;
	/*
     *-----create matrix---------
	 */
	cout<<"Input matrix" << endl <<" Row: ";
	cin>>row;
	cout<<"Column: ";
	cin>>col;

	char **matrix=new char*[row];
	/*
	 * Filling the array with chars
	 */
	for (int i = 0; i < row; i++)
	{
		matrix[i]=new char[col];
	}
      fillMasive(matrix,row,col);
      printM(matrix,row,col);
	  cout<<endl<<"Input word: ";cin>>Sentence;
	  cout<<endl;
      for(int i=0; i<col; i++) {
        for(int j=0; j<row; j++) {

                /*Up.*/
                counter = counter + check(matrix,i, j, 0, -1,Sentence);

                /*Down.*/
                counter = counter + check(matrix,i, j, 0, +1,Sentence);

                /*Left.*/
                counter = counter + check(matrix,i, j, -1, 0,Sentence);

                /*Right.*/
                counter = counter + check(matrix,i, j, +1, 0,Sentence);

                /*Up Right.*/
                counter = counter + check(matrix,i, j, +1, -1,Sentence);

                /*Down Right.*/
                counter = counter + check(matrix,i, j, +1, +1,Sentence);

                /*Up Left.*/
                counter = counter + check(matrix,i, j, -1, -1,Sentence);

                /*Down Left.*/
                counter = counter + check(matrix,i, j, -1, +1,Sentence);
        }
    }
     if((counter==0)||(counter>1)){
	 cout<<endl<<Sentence<<"is found "<<counter<<" times in the table";
     } else if(counter=1){
     cout<<endl<<Sentence<<"is found "<<counter<<" time in the table";
     }

	return 0;
}
