#include <iostream>
#include <ctime>
#include <cstdlib>
#include <array>

using namespace std;

const size_t rows = 15;
const size_t columns = 15;

int main() {
    int first_dot_index;
    int last_dot_index;
    srand(time(nullptr));
    array<array<char, columns>, rows> maze{};

    for(int i = 0; i < rows; i++) {
        int random = (rand() % 13) + 1;
        for (int j = 0; j < columns; j++) {
            if (j == 0 || j == columns - 1) {
                maze[i][j] = '#';
            } else if (i % 2 == 0 && j == random) {
                maze[i][j] = '.';
                if(i - 1 > 0) {
                    maze[i - 1][j] = '.';
                }
            } else if (i % 2 != 0 && maze[i - 1][j] == '.') {
                maze[i][j] = '.';
            } else {
                maze[i][j] = '#';
            }
        }
    }

    // Find the position of the first and last dot
    for(int i = 1; i < rows; i += 2) {
        for(int j = 0; j < columns; j++) {
            if(maze[i][j] == '.') {
                first_dot_index = j;
                break;
            }
        }
        for(int k = columns; k > 0; k--) {
            if(maze[i][k] == '.') {
                last_dot_index = k;
                break;
            }
        }
        // Connect the dot between first and last dot
        for(int l = first_dot_index + 1; l < last_dot_index; l++) {
            maze[i][l] = '.';
        }
    }

    // Add spaces
    for(int i = 1; i < rows - 1; i++) {
        for(int j = 1; j < columns - 1; j++) {
            if(maze[i + 1][j] != '.' && maze[i - 1][j] != '.' && rand() % 2 == 0 && maze[i][j] != '.') {
                maze[i][j] = ' ';
            }
        }
    }

    // Display the maze
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }

    return 0;
}
