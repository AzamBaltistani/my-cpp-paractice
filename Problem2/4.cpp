#include <iostream>
using namespace std;

int main()
{
    int matrix1[3][2];// = {{2, 3},
//                         {4, 5},
//                         {7, 8}};
    int matrix2[3][2]; //= {{1, 5},
                      //   {7, 8},
                       //  {1, 0}};

    int sum[3][2];
    
    cout<<"Enter elements of matrix 1:"<<endl;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 2; col++)
        {
        	cout<<"Row: "<<row<<" Col: "<<col<<endl;
            cin >> matrix1[row][col];
        }

    }
    cout<<"Enter elements of matrix 2:"<<endl;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 2; col++)
        {
        	cout<<"Row: "<<row<<" Col: "<<col<<endl;
            cin >> matrix2[row][col];
        }

    }

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 2; col++)
        {
            sum[row][col] = matrix1[row][col] + matrix2[row][col];

            cout << sum[row][col] << " ";
        }

        cout << endl;
    }

    return 0;
}
