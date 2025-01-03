#include<iostream>
#include<cstring>
#include<cstdlib>
#define ROW 3
#define COLUMN 3

using namespace std;

void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void drawLine(){
    cout << "---|-----|---" << endl;
}

void drawGrid(char (&grid)[ROW][COLUMN], int &p1Score, int &p2Score, string p1N, string p2N){
    clearScreen();
    cout << "X-X-X-X-X-X TIC TAC TOE X-X-X-X-X-X";
    cout << endl << endl;

    int pos = 1;

    cout << endl << endl;
    cout << p1N << ": " << p1Score << endl;
    cout << p2N << ": " << p2Score << endl << endl;

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

void getRowColumn(int pos, int &row, int &col){
    row = (pos - 1) / 3;
    col = (pos - 1) % 3;
}

bool playX(string p1N, string p2N, int p1Score, int p2Score, char (&grid)[ROW][COLUMN]){
    int p1;
    int row, column;
    cout << p1N << " Enter position of X: ";
    cin >> p1;
    if(p1<0 || p1>9){
        cout << "Enter Position within 1-9" << endl;
        return false;
    }
    
    getRowColumn(p1, row, column);

    if(grid[row][column]!='O'){
        grid[row][column] = 'X';
    } else {
        cout << endl << "O already present there" << endl;
        return false;
    }

    drawGrid(grid, p1Score, p2Score, p1N, p2N);
    return true;
}

bool playO(string p1N, string p2N, int p1Score, int p2Score, char (&grid)[ROW][COLUMN]){
    int p2;
    int row, column;
    cout << p2N << " Enter position of O: ";
    cin >> p2;
    if(p2<0 || p2>9){
        cout << "Enter Position within 1-9" << endl;
        return false;
    }
    
    getRowColumn(p2, row, column);

    if(grid[row][column]!='X'){
        grid[row][column] = 'O';
    } else {
        cout << "X is already present there" << endl;
        return false;
    }

    drawGrid(grid, p1Score, p2Score, p1N, p2N);
    return true;
}

bool winner(char (&grid)[ROW][COLUMN]){
    for(int i=0;i<ROW;i++){
        if((grid[i][0]!='z') && (grid[i][0] == grid[i][1]) && (grid[i][1] == grid[i][2])){
            return true;
        }
    }

    for(int j=0;j<COLUMN;j++){
        if((grid[0][j]!='z') && (grid[0][j] == grid[1][j]) && (grid[1][j] == grid[2][j])){
            return true;
        }
    }

    if((grid[0][0]!='z') && (grid[0][0] == grid[1][1]) && (grid[1][1] == grid[2][2])){
        return true;
    }

    if((grid[0][2]!='z') && (grid[0][2] == grid[1][1]) && (grid[1][1] == grid[2][0])){
        return true;
    }

    return false;
}

bool isTie(char (&grid)[ROW][COLUMN]){
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COLUMN;j++){
            if(grid[i][j]=='z'){
                return false;
            }
        }
    }

    return true;
}

int main(){

    string p1N, p2N;
    char grid[ROW][COLUMN];

    int p1Score = 0, p2Score = 0;

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

    drawGrid(grid, p1Score, p2Score, p1N, p2N);

    while(true){
        
        while(true){
            if(playX(p1N, p2N, p1Score, p2Score, grid)==true){
                break;
            }
        }
        
        if(winner(grid)==true){
            cout << p1N << " won the game." << endl << "CONGRATULATIONS" << endl;
            p1Score++;

            cout << "Do you want to play again? (Y/N): ";
            char choice;
            cin >> choice;
            
            if(choice=='n' || choice =='N'){
                cout << endl;
                cout << p1N << ": " << p1Score << endl;
                cout << p2N << ": " << p2Score << endl;
                return 0;
            } else {
                memset(grid, 'z', sizeof(grid));
                drawGrid(grid, p1Score, p2Score, p1N, p2N);
            }
        }

        if(isTie(grid)){
            cout << "Game Is A Tie." << endl;

            cout << "Do you want to play again? (Y/N): ";
            char choice;
            cin >> choice;
            
            if(choice=='n' || choice =='N'){
                cout << endl;
                cout << p1N << ": " << p1Score << endl;
                cout << p2N << ": " << p2Score << endl;
                return 0;
            } else {
                memset(grid, 'z', sizeof(grid));
                drawGrid(grid, p1Score, p2Score, p1N, p2N);
            }            
        }

        while(true){
            if(playO(p1N, p2N, p1Score, p2Score, grid)==true){
                break;
            }
        }

        if(winner(grid)==true){
            cout << p2N << " won the game." << endl << "CONGRATULATIONS" << endl;
            p2Score++;
            cout << "Do you want to play again? (Y/N): ";
            char choice;
            cin >> choice;
            
            if(choice=='n' || choice =='N'){
                cout << endl;
                cout << p1N << ": " << p1Score << endl;
                cout << p2N << ": " << p2Score << endl;
                return 0;
            } else {
                memset(grid, 'z', sizeof(grid));
                drawGrid(grid, p1Score, p2Score, p1N, p2N);
            }
        }

        if(isTie(grid)){
            cout << "Game Is A Tie." << endl;

            cout << "Do you want to play again? (Y/N): ";
            char choice;
            cin >> choice;
            
            if(choice=='n' || choice =='N'){
                cout << endl;
                cout << p1N << ": " << p1Score << endl;
                cout << p2N << ": " << p2Score << endl;
                return 0;
            } else {
                memset(grid, 'z', sizeof(grid));
                drawGrid(grid, p1Score, p2Score, p1N, p2N);
            }            
        }
    }
}