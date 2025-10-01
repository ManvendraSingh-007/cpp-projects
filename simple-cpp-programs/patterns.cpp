/*
 * Created: 1 Oct 25, This file contains all the patterns I solved
 * 
 * Lessons Learned:
 * - Loop control and nested loops
 * - Character arithmetic and ASCII manipulation  
 * - Mathematical pattern recognition, logical thinking
 * - Multiple approaches to the same problem
 * 
 */

#include <iostream>
using namespace std;

// ==================== PATTERN 1 ====================
void alphabetSquare(int n = 5) {
    cout << "\n Pattern 1: Alphabet Square" << endl;
    cout << "Expected:" << endl;
    cout << "A B C D E" << endl;
    cout << "B C D E F" << endl;
    cout << "C D E F G" << endl;
    cout << "D E F G H" << endl;
    cout << "E F G H I" << endl;
    cout << "\nMy Solution:" << endl;
    
    char alpha = 'A';
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << alpha << ' ';
            alpha++;
        }
        alpha = 'B' + i;
        cout << endl;
    }
}

// ==================== PATTERN 2 ====================
void continuousAlphabetTriangle(int n = 5) {
    cout << "\n Pattern 2: Continuous Alphabet Triangle" << endl;
    cout << "Expected:" << endl;
    cout << "A" << endl;
    cout << "B C" << endl; 
    cout << "D E F" << endl;
    cout << "G H I J" << endl;
    cout << "K L M N O" << endl;
    cout << "\nMy Solution:" << endl;
    
    char alpha = 'A';
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << alpha << ' ';
            alpha++;
        }
        cout << endl;
    }
}

// ==================== PATTERN 3 ====================
void sameRowAlphabetTriangle(int n = 5) {
    cout << "\n Pattern 3: Same Row Alphabet Triangle" << endl;
    cout << "Expected:" << endl;
    cout << "A" << endl;
    cout << "B B" << endl;
    cout << "C C C" << endl;
    cout << "D D D D" << endl;
    cout << "E E E E E" << endl;
    cout << "\nMy Solution:" << endl;
    
    char alpha = 'A';
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << alpha << ' ';
        }
        alpha++;
        cout << endl;
    }
}

// ==================== PATTERN 4 ====================
void alphabetPyramid(int n = 6) {
    cout << "\n Pattern 4: Alphabet Pyramid" << endl;
    cout << "Expected:" << endl;
    cout << "F" << endl;
    cout << "E F" << endl;
    cout << "D E F" << endl;
    cout << "C D E F" << endl;
    cout << "B C D E F" << endl;
    cout << "A B C D E F" << endl;
    cout << "\nMy Solution:" << endl;
    
    char alpha = 64 + n;
    int x = 0;
    for(int i = n; i > 0; i--) {
        for(int j = n; j >= i; j--) {
            cout << alpha << ' ';
            alpha++;
        }
        x++;
        alpha = 64 + n - x;
        cout << endl;
    }
}

// ==================== PATTERN 5 ====================
void rightAlignedStarPyramid(int n = 4) {
    cout << "\n Pattern 5: Right-Aligned Star Pyramid" << endl;
    cout << "Expected:" << endl;
    cout << "      *" << endl;
    cout << "    * *" << endl;
    cout << "  * * *" << endl;
    cout << "* * * *" << endl;
    cout << "\nMy Solution:" << endl;
    
    for(int i = 0; i < n; i++) {
        int space = n - (i + 1);
        for(int j = 0; j < space; j++) {
            cout << ' ' << ' ';
        }
        for(int k = 0; k < n - space; k++) {
            cout << '*' << ' ';
        }
        cout << endl;
    }
}

// ==================== PATTERN 6 ====================
void invertedStarTriangle(int n = 4) {
    cout << "\n Pattern 6: Inverted Star Triangle" << endl;
    cout << "Expected:" << endl;
    cout << "* * * *" << endl;
    cout << "* * *" << endl;
    cout << "* *" << endl;
    cout << "*" << endl;
    cout << "\nMy Solution:" << endl;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i; j++) {
            cout << '*' << ' ';
        }
        cout << endl;
    }
}

// ==================== PATTERN 7 ====================
void invertedRightAlignedStar(int n = 4) {
    cout << "\n Pattern 7: Inverted Right-Aligned Star" << endl;
    cout << "Expected:" << endl;
    cout << "* * * *" << endl;
    cout << "  * * *" << endl;
    cout << "    * *" << endl;
    cout << "      *" << endl;
    cout << "\nMy Solution:" << endl;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            cout << ' ' << ' ';
        }
        for(int k = 0; k < n - i; k++) {
            cout << '*' << ' ';
        }
        cout << endl;
    }
}

// ==================== PATTERN 8 ====================
void numberPyramid(int n = 4) {
    cout << "\n Pattern 8: Number Pyramid" << endl;
    cout << "Expected:" << endl;
    cout << "      1" << endl;
    cout << "    1 2 1" << endl;
    cout << "  1 2 3 2 1" << endl;
    cout << "1 2 3 4 3 2 1" << endl;
    cout << "\nMy Solution:" << endl;
    
    int x = 1;
    int y = 1;
    for(int i = 0; i < n; i++) {
        int space = n - i - 1;
        for(int j = 0; j < space; j++) {
            cout << ' ' << ' ';
        }
        for(int k = 0; k < n - space; k++) {
            cout << x << ' ';
            x++;
        }
        for(int l = 0; l < i; l++) {
            cout << y << ' ';
            y--;
        }
        cout << endl;
        y = x - 1;
        x = 1;
    }
}

// ==================== PATTERN 9 ====================
void numberDiamond(int n = 4) {
    cout << "\n Pattern 9: Number-Star Diamond" << endl;
    cout << "Expected:" << endl;
    cout << "1 2 3 4 5 5 4 3 2 1" << endl;
    cout << "1 2 3 4 * * 4 3 2 1" << endl;
    cout << "1 2 3 * * * * 3 2 1" << endl;
    cout << "1 2 * * * * * * 2 1" << endl;
    cout << "1 * * * * * * * * 1" << endl;
    cout << "\nMy Solution:" << endl;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i; j++) {
            cout << j + 1 << ' ';
        }
        for(int k = 0; k < i; k++) {
            cout << '*' << ' ';
        }
        for(int l = 0; l < i; l++) {
            cout << '*' << ' ';
        }
        for(int m = n - i; m > 0; m--) {
            cout << m << ' ';
        }
        cout << endl;
    }
}

// ==================== PATTERN 10 ====================
void increasingNumberTriangle(int n = 4) {
    cout << "\n Pattern 10: Increasing Number Triangle" << endl;
    cout << "Expected:" << endl;
    cout << "      1" << endl;
    cout << "    2 2" << endl;
    cout << "  3 3 3" << endl;
    cout << "4 4 4 4" << endl;
    cout << "\nMy Solution:" << endl;
    
    int x = 1;
    for(int i = 1; i <= n; i++) {
        int space = n - i;
        for(int j = 0; j < space; j++) {
            cout << ' ' << ' ';
        }
        for(int k = 0; k < n - space; k++) {
            cout << x << ' ';
        }
        cout << endl;
        x++;
    }
}

// ==================== MAIN FUNCTION ====================
int main() {
    

  // Calling all the patterns
    alphabetSquare();
    continuousAlphabetTriangle();
    sameRowAlphabetTriangle();
    alphabetPyramid();
    rightAlignedStarPyramid();
    invertedStarTriangle();
    invertedRightAlignedStar();
    numberPyramid();
    numberDiamond();
    increasingNumberTriangle();
    
    return 0;
}