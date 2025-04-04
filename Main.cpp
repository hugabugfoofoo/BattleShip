#include <iostream>
#include <ctime>
using namespace std;

const int rows =5;
const int elements =5;
int maxships = 5;
int matrix[rows][elements];
const int prows=5;
const int pelements=5;
int pmatrix[prows][pelements];

void Clear() {
    for ( int i=0; i < rows; i++) {
        for ( int j=0; j < elements; j++) {
            matrix[i][j] = 0;
        }
    }
}
void Clearpl() {
    for ( int i=0; i < prows; i++) {
        for ( int j=0; j < pelements; j++) {
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

void Showpl() {
    for ( int i=0; i < prows; i++) {
        for ( int j=0; j < pelements; j++) {
            cout << pmatrix[i][j] << " ";
        }
        cout << endl;
    }
}
void SetShipspl() {
    int s=0;
    while (s< maxships) {
        int x =rand() % prows;
        int y = rand() % pelements;
        if (pmatrix[x][y] != 1) {
            s++;
            pmatrix[x][y] = 1;
        }
    }
}
bool PAttack(int x, int y) {
if (pmatrix[x][y] == 1) {
    pmatrix[x][y] = 0;
return true;
}
return false;
}
bool Attack(int x, int y) {
    if (matrix[x][y] == 1){
        matrix[x][y] = 0;
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
int PNumberOfShips() {
    int c=0;
    for ( int i=0; i < prows; i++) {
        for ( int j=0; j < pelements; j++) {
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
    Clearpl();
    SetShips();
    //Show();
    SetShipspl();
    cout<<"Your Ships:"<< endl;
    Showpl();

    int pos1, pos2;
    char prompt;

    while (1) {
        cout <<"Please input attack coordinates:";
        cin >> pos1 >> pos2;
        if (Attack(pos1,pos2)) {
            cout <<"Hit!" << endl;
            cout << "Enemy ships left: " << NumberOfShips() << endl;
        }else {
            cout <<"Miss" << endl;
            cout << "Enemy ships left: " << NumberOfShips() << endl;
            cout << "do you want to surrender(y/n)?";
            cin >> prompt;
        }
        if (prompt == 'y') {
            cout << "Game Over!" << endl;
            Show();
            break;
        }
           if (PAttack(rand()%prows,rand()%pelements)) {
               cout<<"You've been hit!"<<endl;
               cout << "Ships left: " << PNumberOfShips() << endl;
               Showpl();
           } else {
               cout<<"The enemy missed!"<<endl;
               cout << "Ships left: " << PNumberOfShips() << endl;
           }
        int loose = PNumberOfShips();
        int win = NumberOfShips();
        if (win==0) {
            cout<<"YOU WIN!"<<endl;
            break;

        }
        if (loose==0) {
            cout<<"YOU LOSE!"<<endl;
            break;
        }
        }
    }

