#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

// check if a certain position on the board is occupied by a red or black piece
string checkPos(int x, int y, int red[][6], int black[][6])
{
    string str = "";
    if(red[x][y] != 0)
        if(red[x][y] == 1)
            str = "r1";
        else
            str = "r2";
    else if(black[x][y] != 0)
        if(black[x][y] == 1)
            str = "b1";
        else
            str = "b2";
    else
        str = "  ";

    return str;
}

//print board according to red and black arrays indicating positions on the board
void printBoard(int red[][6], int black[][6])
{
    cout << "\n";
    cout << "   ____ ____ ____ ____ ____ ____ " << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "5 | " << checkPos(0, 5, red, black) << " |    | " << checkPos(2, 5, red, black) << " |    | " << checkPos(4, 5, red, black) << " |    |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "4 |    | " << checkPos(1, 4, red, black) << " |    | " << checkPos(3, 4, red, black) << " |    | " << checkPos(5, 4, red, black) << " |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "3 | " << checkPos(0, 3, red, black) << " |    | " << checkPos(2, 3, red, black) << " |    | " << checkPos(4, 3, red, black) << " |    |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "2 |    | " << checkPos(1, 2, red, black) << " |    | " << checkPos(3, 2, red, black) << " |    | " << checkPos(5, 2, red, black) << " |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "1 | " << checkPos(0, 1, red, black) << " |    | " << checkPos(2, 1, red, black) << " |    | " << checkPos(4, 1, red, black) << " |    |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "0 |    | " << checkPos(1, 0, red, black) << " |    | " << checkPos(3, 0, red, black) << " |    | " << checkPos(5, 0, red, black) << " |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "    0    1    2    3    4    5   \n" << endl;
}

void initializePieces(int red[][6], int black[][6])
{
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
        {
            red[i][j] = 0;
            black[i][j] = 0;
        }
    red[0][1] = 1;
    red[1][0] = 2;
    red[2][1] = 1;
    red[3][0] = 2;
    red[4][1] = 1;
    red[5][0] = 2;

    black[0][5] = 2;
    black[1][4] = 1;
    black[2][5] = 2;
    black[3][4] = 1;
    black[4][5] = 2;
    black[5][4] = 1;

}

void playGame(int red[][6], int black[][6], int &redPoints, int &blackPoints)
{
    bool checkwinner = true;
do
{
    int x1,x2, y1 ,y2 =0;

    cout << "Red Player, select the piece you would like to move(x,y):";
    cin >> x1 >>  y1;

    while(black[x1][y1]==1 || black[x1][y1]==2||red[x1][y1]==0)//check the validity of the piece, cannot choose blank and black piece
            {

            cout << "Red Player, this is not a vaild piece to move" << endl;
            cout << "Red Player, select the piece you would like to move(x,y):";
            cin >> x1 >>  y1;
            cin.clear();
            }

    bool valid = true;

    cout << "Red player, select the place to move your piece(i.c. x y)(-1 -1 to pass):";
    cin >> x2 >> y2;

    do
    {
    if (x2 >5 || y2 >5 )
    {
        valid =false;
    }
    if((x1+1==x2 && y1+1==y2)||(x1-1==x2 && y1-1==y2)||(x1+1==x2&&y1-1==y2)||(x1-1==x2&&y1+1==y2))
    {
        if(black[x2][y2]==1 || black[x2][y2]==2||red[x2][y2]==1||red[x2][y2]==2 )//if single step move, cannot land on to other piece
        valid =false;
        else
        valid = true;

    }

    if((x1==x2 && y1+1==y2)||(x1==x2 && y1-1==y2)||(x1+1==x2&&y1==y2)||(x1-1==x2&&y1==y2))//need to move diagonal
    {
        valid =false;
    }

   if ((x1+2==x2 && y1+2==y2)||(x1-2==x2 && y1-2==y2)||(x1+2==x2&&y1-2==y2)||(x1-2==x2&&y1+2==y2))//chenk jump
    {
        if(black[x1+(x2-x1)/2][y1+(y2-y1)/2]!=red[x1][y1])//cannot jump through blank and not same number piece
        {
            valid =false ;
        }
        else
        {
            black[x1+(x2-x1)/2][y1+(y2-y1)/2]=0;//if jump is valid, need delete the piece jump through
            valid =true;
        }
    }


    if(!valid)
        {
            cout << "Red Player, this is not a vaild place to move! Remember, only pieces that are numbered the same can jumped each other" << endl;
            cout << "Red player, select the place to move your piece(i.c. x y)(-1 -1 to pass):";
            cin >> x2 >> y2;
        }
    }
    while(!valid);

    if(x2!=-1 && y2!=-1)//pass function
    {
        red [x2][y2]=red [x1][y1];
        red [x1][y1]=0;
    }


    printBoard(red,black);
    if((x1+2==x2 && y1+2==y2)||(x1-2==x2 && y1-2==y2)||(x1+2==x2&&y1-2==y2)||(x1-2==x2&&y1+2==y2))
    {
        redPoints +=1;
    }
    cout << "Red Points: " << redPoints <<endl;
    cout << "Black Points:" << blackPoints << endl;
    if(redPoints >=3)
    {
        cout << "GAME OVER! RED PLAYER WINS!";
        checkwinner = false;
        break;
    }

    int x3,x4,y3,y4=0;
    cout << "black player, select the piece you would like to move(x,y):";
    cin >> x3 >> y3;
    while(red[x3][y3]==1||red[x3][y3]==2||black[x3][y3]==0)//cannot choose red piece and blank
    {

        cout << "Black Player, this is not a vaild piece to move" << endl;
            cout << "Black Player, select the piece you would like to move(x,y):";
            cin >> x3 >>  y3;
            cin.clear();

    }
    cout << "black player, select the place to move your piece(i.c. x y)(-1 -1 to pass):";
    cin >> x4 >> y4;
    do{
        if((x3+1==x4 && y3+1==y4)||(x3-1==x4 && y3-1==y4)||(x3+1==x4&&y3-1==y4)||(x3-1==x4&&y3+1==y4))
        {
            if(red[x4][y4]==1||red[x4][y4]==2||black[x4][y4]==1||black[x4][y4]==2)
                valid = false;
            else
                valid =true;
        }
        if(x4> 5 || y4 > 5)
            valid = false;
        if((x3==x4 && y3+1==y4)||(x3==x4 && y3-1==y4)||(x3+1==x4&&y3==y4)||(x3-1==x4&&y3==y4))
        {
            valid =false;
        }
        if((x3+2==x4 && y3+2==y4)||(x3-2==x4 && y3-2==y4)||(x3+2==x4&&y3-2==y4)||(x3-2==x4&&y3+2==y4))
        {
            if(red[x3+(x4-x3)/2][y3+(y4-y3)/2]!=black[x3][y3])
            {
                valid =false ;
            }
            else
            {
                red[x3+(x4-x3)/2][y3+(y4-y3)/2]=0;
                valid =true;
            }

        }


        if(!valid)
        {
            cout << "Black Player, this is not a vaild place to move! Remember, only pieces that are numbered the same can jumped each other" << endl;
            cout << "Black player, select the place to move your piece(i.c. x y)(-1 -1 to pass):";
            cin >> x4 >> y4;
        }

    }
    while(!valid);

    if(x4!=-1 && y4!=-1)
    {

        black [x4][y4]=black [x3][y3];
        black[x3][y3]=0;
    }

    printBoard(red,black);
    if((x3+2==x4 && y3+2==y4)||(x3-2==x4 && y3-2==y4)||(x3+2==x4&&y3-2==y4)||(x3-2==x4&&y3+2==y4))
        blackPoints = blackPoints+1;
    cout << "Red Points: " << redPoints <<endl;
    cout << "Black Points:" << blackPoints << endl;
    if(blackPoints>=3)
    {
    cout << "GAME OVER! BLACK WINS!";
    checkwinner = false;
    break;
    }
}while(checkwinner);

}

int main()
{
    int red[6][6];
    int black[6][6];
    int redPoints = 0;
    int blackPoints = 0;
    initializePieces(red, black);
    printBoard(red, black);
    playGame(red, black, redPoints, blackPoints);
    return 0;
}
