// Symmetric, Skew Symmetric, Diagonal, Identity 

#include<iostream>
using namespace std;

void isSymmetric(int mat[10][10], int N)
{
    bool flag=false;
    for (int i = 0;i < N; i++)
    {
        for (int j = 0;j < N; j++)
        {
            if (mat[i][j] == mat[j][i])
            {
                flag = true;
            }
            else
            { 
                flag = false;
            }
        }
    }
    if(flag==true){
        cout<<"Symetric";
    }
    else{
        cout<<"Not Symetric";
    }
}

void isSkewSymmetric(int mat[10][10], int N)
{
    bool flag=false;
    for (int i = 0;i < N; i++)
    {
        for (int j = 0;j < N; j++)
        {
            if (mat[i][j] == -mat[j][i])
            {
                flag = true;
            }
            else
            {
                flag = false;
            }
        }
    }
    if(flag==true){
        cout<<"Skew Symetric";
    }
    else{
        cout<<"Not Skew Symetric";
    }
}

void isIdentity(int mat[10][10], int N)
{
    bool flag=false;
    for (int i = 0;i < N; i++)
    {
        for (int j = 0;j < N; j++)
        {
            if (i==j && mat[i][j] == 1)
            {
                flag=true;
            }
            else
            {
                flag=false;
            }
        }
 
    }
    if(flag==true){
        cout<<"Identity";
    }
    else{
        cout<<"Not Identity";
    }
    //return 0;
}

void isDiagonal(int mat[10][10], int N)
{
    bool flag=false;
    for (int i = 0;i < N; i++)
    {
        for (int j = 0;j < N; j++)
        {
            if ((i==j && mat[i][j]!=1)||(i!=j && mat[i][j]==0))
            // if ((i==j && mat[i][j]!=1)||(i!=j && mat[i][j]!=0))
            {
                flag=true;
            }
            else
            {
                flag=false;
            }
        }
    }
    if(flag==true){
        cout<<"Diagonal";
    }
    else{
        cout<<"Not Diagonal";
    }
}

int main()
{
    int mat[10][10];
    int i, j, N, ch;
    char chs = 'y';
    cout << "Enter number of rows and columns : ";
    cin >> N;
    cout << "Enter the elements : ";
    for (i = 0;i < N; i++)
        for (j = 0;j < N; j++)
            cin >> mat[i][j];
    // cout << "1. Symmetric\n2. Skew Symmetric\n3. Identity\n4. Diagonal\nEnter your Choice : ";
    // cin >> ch;
    
    // while (chs = 'y')
    // {
    //     switch(ch)
    //     {   
    //         case 1 : isSymmetric(mat,N);
    //                  break;
    //         case 2 : isSkewSymmetric(mat,N);
    //                  break;
    //         case 3 : isIdentity(mat,N);
    //                  break;
    //         case 4 : isDiagonal(mat,N);
    //                  break;
    //         default: cout << "Invalid";
    //                  break;
    //     }
    // }
    // cout << "Do you want to continue ? " << endl;
    // cin >> chs;
    isSymmetric(mat,N);
    isSkewSymmetric(mat,N);
    isIdentity(mat,N);
    isDiagonal(mat,N);
}