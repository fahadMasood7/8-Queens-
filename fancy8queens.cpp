#include <cmath>
#include <iostream>
using namespace std;

bool ok(int q[], int c)
{
    for (int i = 0; i < c; i++) {
        if ((q[i] == q[c]) || (c - i) == abs(q[c] - q[i])) 
            return false; 
    }
    return true; 
}

void print(int q[]) {
    static int numSolutions = 0;
    cout << "Solution #" << ++numSolutions << ":\n";

    // Define the black and white queen representations
    const char *bq = "♛"; // Black Queen
    const char *wq = "♕"; // White Queen
    
    // Print the chessboard
    for (int i = 0; i < 8; i++) {
        cout << "+---+---+---+---+---+---+---+---+\n"; // Top border of the squares
        for (int j = 0; j < 8; j++) {
            cout << "| "; // Left border of each square

            // Check if a queen is present in the current column
            if (q[j] == i) {
                if ((i + j) % 2 == 0) {
                    cout << wq << " "; // White Queen on White square
                } else {
                    cout << bq << " "; // Black Queen on Black square
                }
            } else {
                // Print empty squares
                if ((i + j) % 2 == 0) {
                    cout << "  "; // White square
                } else {
                    cout << "  "; // Black square
                }
            }
        }
        cout << "|\n"; // Right border of the squares
    }
    cout << "+---+---+---+---+---+---+---+---+\n"; // Bottom border of the squares
    cout << endl; // Extra line after the board for spacing
}

int main(){
    int q[8]={0}, col = 0;
    q[0] = 0; 
    
    while(col >= 0){ //check the backtrack to determine when to stop
        col++; 
        
        if(col == 8){ //if we've moved beyond the last column print solution
            print(q);
            col--; //backtrack
        }
        
        else
            q[col] = -1; //reset the row behind the first row
            
        while(col >= 0){ //inner while loop, position check
            q[col]++; //go to the next row
            
            if(q[col] == 8) //if there are no more rows go to the previous col
                col--; 
                
            else if(ok(q, col)) //check position of a queen here is ok
                break; 
        }
    }
    return 0;
}

