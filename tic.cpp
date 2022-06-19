#include <iostream>

using namespace std;

bool win_condition(int sumrow[], int sumcol[], int sumdia, int sumrdia, int n)
{
    for(int i = 0; i<n; i++)
    {
        if(sumrow[i] == n || sumrow[i] == -n || sumdia == n || sumrdia == -n || sumcol[i] == n || sumcol[i] == -n )
            return true;
        else
            return false;
    }
    return false;
}

bool valid_move(int row, int col, int n)
{
    if ((row > n-1 || row < 0) || (col > n -1 || col < 0))
    {
        return false;
    }
    else
    {
        return true;
    }
}


int main()
{
    int n = 0;

    cout<<"Enter the grid size: ";
    while(n<=1)
        {cin>>n;}

    char board[n][n];
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            board[i][j] = '-';
        }
    }

    int player_1 = 1;
    int player_2 = -1;
    int row;
    int col;
    int sumrow[n];
    int sumcol[n];
    for(int i = 0; i<n; i++)
    {
        sumrow[i] = 0;
        sumcol[i] = 0;
    }
    int sumdia = 0;
    int sumrdia = 0;

    for(int i =0; i<n*n; i++)
    {
        system("clear");
        for(int k = 0; k<n; k++)
        {
            cout<<"| ";
            for(int j = 0; j<n; j++)
            {
                cout<<board[k][j]<<" | ";
            }
            cout<<endl;
        }
        bool move_check = false;
        if(i%2==0)
        {
            while(move_check == false)
            {
                cout<<"Player 1 Enter Row: ";
                cin>>row;
                row=row-1;
                cout<<"Player 1 Enter Column: ";
                cin>>col;
                col=col-1;
                if(valid_move(row, col, n) && board[row][col] == '-')
                    move_check = true;
                else
                    cout<<"Invalid Move, enter again"<<endl;
            }
            board[row][col] = 'O';
            if(row == col)
                sumdia = sumdia+player_1;
            if(col == n - row - 1)
                sumrdia = sumrdia+player_1;
            sumrow[row] = sumrow[row] + player_1;
            sumcol[col] = sumcol[col] + player_1;

            
            system("clear");
            for(int i = 0; i<n; i++)
            {
                cout<<"| ";
                for(int j = 0; j<n; j++)
                {
                    cout<<board[i][j]<<" | ";
                }
                cout<<endl;
            }
            if(win_condition(sumrow, sumcol, sumdia, sumrdia, n))
            {
                cout<<"Player 1 Wins!";
                break;
            } 
        }
        else
        {
            system("clear");
            for(int i = 0; i<n; i++)
            {
                cout<<"| ";
                for(int j = 0; j<n; j++)
                {
                    cout<<board[i][j]<<" | ";
                }
                cout<<endl;
            }
            while(move_check == false)
            {
                cout<<"Player 2 Enter Row: ";
                cin>>row;
                row-=1;
                cout<<"Player 2 Enter Column: ";
                cin>>col;
                col-=1;
                if(valid_move(row, col, n))
                    move_check = true;
                else
                    cout<<"Invalid Move, enter again"<<endl;
            }
            board[row][col] = 'X';
            if(row == col)
                sumdia = sumdia + player_2;
            if(col == n - row - 1)
                sumrdia = sumrdia+player_2;
            sumrow[row] = sumrow[row] + player_2;
            sumcol[col] = sumcol[col] + player_2;
            system("clear");
            for(int i = 0; i<n; i++)
            {
                cout<<"| ";
                for(int j = 0; j<n; j++)
                {
                    cout<<board[i][j]<<" | ";
                }
                cout<<endl;
            }
            if(win_condition(sumrow, sumcol, sumdia, sumrdia, n))
            {
                cout<<endl<<"Player 2 Wins!";
                break;
            }
        }


    }
    return 0;
}
