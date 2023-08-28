#include <iostream>
using namespace std;

int main()
{
    int matrix1[3][3] = {{2, 3, 5},
                         {4, 5, 7},
                         {7, 8, 11}};
                         
    int matrix2[3][3] = {{1, 5, -1},
                         {7, 8, 0},
                         {1, 9, 3}};

    int mult[3][3];

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
        	mult[row][col] = 0;
        	
        	for(int k =0; k<3; k++)
        	{
        		 mult[row][col] += matrix1[row][k] * matrix2[k][col];
			}
        }
    }
    
    cout<<"\nAnswer: \n";
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
        	cout<<mult[row][col]<<"             ";
        }
        cout<<endl;
    }

    return 0;
}
