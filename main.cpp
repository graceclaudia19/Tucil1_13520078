#include <bits/stdc++.h>
#include "func.cpp"  
using namespace std;

int main () {
    // ganti nama file di sini
    const char* filename = "test/small3.txt";

    // ini puzzlenya
    vector< vector<char> > puzzle = newMatrix(filename);

    displayMatrix(puzzle);

    // ini kata buat dicari
    vector<string> words = newWord(filename);

    // proses pencarian kata
    clock_t start, end;
    start = clock();
    for (int i=0;i<words.size();i++){
        cout << words[i] << " ";
        cout << "\n";
        vector<Point> points = findKata(puzzle, words[i]);
        displayAnsMatrix(puzzle, points);
        cout << "\n";
    }
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;
    
return 0;      
}