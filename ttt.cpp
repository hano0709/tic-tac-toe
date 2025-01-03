#include<iostream>
#include<cstring>
#define ROW 3
#define COLUMN 3

using namespace std;

void drawLine(){
    cout << "---|-----|---" << endl;
}

void drawGrid(char (&grid)[ROW][COLUMN]){
    
    int pos = 1;

    cout << endl << endl;

    for(int i=0;i<ROW;i++){
        if(i==1){
            drawLine();
        }
        for(int j=0;j<COLUMN;j++){
            if(grid[i][j]=='z'){
                cout << pos;
            } else {
                cout << grid[i][j];
            }
            pos++;
            if(j<2){
                cout << "  |  ";
            }
        }
        cout << endl;
        if(i==1){
            drawLine();
        }
    }

    cout << endl;
    
}

bool playX(string p1N, char (&grid)[ROW][COLUMN]){
    int p1;
    int row, column;
    cout << p1N << " Enter position of X: ";
    cin >> p1;
    if(p1>=1 && p1<=3){
        row = 0;
    } else if(p1<=6){
        row = 1;
    } else {
        row = 2;
    }

    if(p1%3 == 1){
        column = 0;
    } else if(p1%3 == 2){
        column = 1;
    } else {
        column = 2;
    }

    if(grid[row][column]!='O'){
        grid[row][column] = 'X';
    } else {
        cout << endl << "O already present there" << endl;
        return false;
    }

    drawGrid(grid);
    return true;
}

bool playO(string p2N, char (&grid)[ROW][COLUMN]){
    int p2;
    int row, column;
    cout << p2N << " Enter position of O: ";
    cin >> p2;
    if(p2>=1 && p2<=3){
        row = 0;
    } else if(p2<=6){
        row = 1;
    } else {
        row = 2;
    }

    if(p2%3 == 1){
        column = 0;
    } else if(p2%3 == 2){
        column = 1;
    } else {
        column = 2;
    }

    if(grid[row][column]!='X'){
        grid[row][column] = 'O';
    } else {
        cout << "X is already present there" << endl;
        return false;
    }

    drawGrid(grid);
    return true;
}

int main(){

    string p1N, p2N;
    char grid[ROW][COLUMN];

    memset(grid, 'z', sizeof(grid));

    cout << "X-X-X-X-X-X TIC TAC TOE X-X-X-X-X-X";
    cout << endl << endl;
    cout << "Enter Player 1 Details: \n";
    cout << "Enter Player 1 Name: ";
    cin >> p1N;

    cout << endl << endl;
    cout << "Enter Player 2 Details: \n";
    cout << "Enter Player 2 Name: ";
    cin >> p2N;

    drawGrid(grid);

    while(true){
        
        if(playX(p1N, grid)==false){
            playX(p1N, grid);
        }

        if(playO(p2N, grid)==false){
            playO(p2N, grid);
        }

    }
}