#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void showImage(const bool image[][M]) {
    for (int i = 0; i < M + 2; ++i) cout << "-";
    cout << endl; 
    for (int i = 0; i < N; ++i) {
        cout << "|";
        for (int j = 0; j < M; ++j) {
            if (image[i][j]) cout << "*";
            else cout << " ";
        }
        cout << "|\n";
    }
    for (int i = 0; i < M + 2; ++i) cout << "-" ;
    cout << endl;
}

void updateImage(bool image[][M], int s, int x, int y) {
    int minRow = max(0, x - s);
    int maxRow = min(N - 1, x + s);
    int minCol = max(0, y - s);
    int maxCol = min(M - 1, y + s);

    for (int i = minRow; i <= maxRow; ++i) {
        for (int j = minCol; j <= maxCol; ++j) {
            if (sqrt(pow(i - x, 2) + pow(j - y, 2)) <= s) {
                image[i][j] = true;
            }
        }
    }
}