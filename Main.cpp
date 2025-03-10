#include <iostream>
#include <ctime>
using namespace std;

const int rows =10;
const int elements =10;
int maxships =10;
int matrix[rows][elements];


void Clear() {
    for ( int i=0; i < rows; i++) {
        for ( int j=0; j < elements; j++) {
            matrix[i][j] = 0;
        }
    }
}

void Show() {
    for ( int i=0; i < rows; i++) {
        for ( int j=0; j < elements; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void SetShips() {
    int s=0;
    while (s< maxships) {
        int x =rand() % rows;
        int y = rand() % elements;
        if (matrix[x][y] != 1) {
            s++;
            matrix[x][y] = 1;
        }
    }
}

bool Attack(int x, int y) {
    if (matrix[x][y] == 1){
        matrix[x][y] = 2;
        return true;
    }
    return false;
}
int NumberOfShips() {
    int c=0;
    for ( int i=0; i < rows; i++) {
        for ( int j=0; j < elements; j++) {
            if (matrix[i][j]==1) {
                c++;
            }
        }
    }
    return c;
}


int main() {
    srand(time(NULL));
Clear();
    SetShips();
int pos1, pos2;
    char prompt;
    while (1) {
        cout <<"Please input attack coordinates:";
        cin >> pos1 >> pos2;
        if (Attack(pos1,pos2)) {
            cout <<"Hit!" << endl;
            cout << "Ships left: " << NumberOfShips() << endl;
        }else {
            cout <<"Miss" << endl;
            cout << "Ships left: " << NumberOfShips() << endl;
            cout << "do you want to surrender(y/n)?";
            cin >> prompt;
        }
if (prompt == 'y') {
    cout << "Game Over!" << endl;
        Show();
    break;

}

    }
    //system("pause");
    return 0;
}