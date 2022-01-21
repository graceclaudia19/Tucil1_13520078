#include <bits/stdc++.h>
using namespace std;

struct Point
{
   int x, y;
};

vector< vector<char> > newMatrix(const char* filename) {
    vector< vector<char> > mat;
    string line;
    ifstream file;
    file.open(filename);
    if (file.is_open()) {
        getline(file, line);
        while(line != "") {
            vector<char> temp;
            for (int i = 0; i < line.length(); i+=2) {
                temp.push_back(line[i]);
            }
            mat.push_back(temp);
            getline(file,line);
        }
        file.close();
    } else {
        cout << "failed to open the file" << endl;
    }
    
    return mat;
}

vector<string> newWord(const char* filename) {
    vector<string> words;
    string line;
    ifstream file;
    file.open(filename);
    if (file.is_open()) {
        vector<char> temp;
        getline(file, line);
        while(line != "") {
            getline(file,line);
        }

        while(getline(file,line)) {
            words.push_back(line);
        }
        file.close();
    } else {
        cout << "failed to open the file" << endl;
    }

    return words;
}

void displayMatrix(vector< vector<char> > mat){
    for (int i=0; i< mat.size(); i++){
        for (int j=0; j < mat[i].size(); j++){
            cout << mat[i][j] <<" ";
        }
        cout << "\n";
    }
}

void displayAnsMatrix(vector< vector<char> > mat, vector<Point> p){
    
    vector< vector<char> > mAns;
    // make blank matrix
    for (int i=0; i< mat.size(); i++){
        vector<char> temp; 
        for (int j=0; j < mat[i].size(); j++){
            temp.push_back('-');
        }
        mAns.push_back(temp);
    }
    // memunculkan huruf yang ditemukan
    for (int i=0; i<p.size();i++){
        mAns[p[i].x][p[i].y] = mat[p[i].x][p[i].y];
    }

    displayMatrix(mAns);

}

vector<Point> findKata(vector< vector<char> > m,string kata){
    int lenKata = kata.length();
    int idxMin = 0;
    int idxJMax = m[0].size();
    int idxIMax = m.size();
    int counter = 0;
    for (int i=0; i<m.size(); i++){
        for (int j=0; j<m[0].size();j++){
            counter++;
            if (m[i][j] == kata[0]){
                // cek atas
                if (i-(lenKata-1)>=idxMin){
                    vector<Point> Points;
                    for(int x = 0; x<lenKata; x++) {
                        if (m[i-x][j] != kata[x]) {
                            break;
                        } else {
                            Point P;
                            P.x = i-x;
                            P.y = j;
                            Points.push_back(P);
                        }
                    }
                    if (Points.size() == lenKata) {
                        cout <<"Number of Comparisons: "<<counter<<"\n";
                        return Points;
                    }
                }
                // cek bawah
                if (i+(lenKata-1)<=idxIMax){
                    vector<Point> Points;
                    for(int x = 0; x<lenKata; x++) {
                        if (m[i+x][j] != kata[x]) {
                            break;
                        } else {
                            Point P;
                            P.x = i+x;
                            P.y = j;
                            Points.push_back(P);
                        }
                    }
                    if (Points.size() == lenKata) {
                        cout <<"Number of Comparisons: "<<counter<<"\n";
                        return Points;
                    }
                }
                // cek kiri
                if (j-(lenKata-1)>=idxMin){
                    vector<Point> Points;
                    for(int x = 0; x<lenKata; x++) {
                        if (m[i][j-x] != kata[x]) {
                            break;
                        } else {
                            Point P;
                            P.x = i;
                            P.y = j-x;
                            Points.push_back(P);
                        }
                    }
                    if (Points.size() == lenKata) {
                        cout <<"Number of Comparisons: "<<counter<<"\n";
                        return Points;
                    }
                }
                // cek kanan
                if (j+(lenKata-1)<=idxJMax){
                    vector<Point> Points;
                    for(int x = 0; x<lenKata; x++) {
                        if (m[i][j+x] != kata[x]) {
                            break;
                        } else {
                            Point P;
                            P.x = i;
                            P.y = j+x;
                            Points.push_back(P);
                        }
                    }
                    if (Points.size() == lenKata) {
                        cout <<"Number of Comparisons: "<<counter<<"\n";
                        return Points;
                    }
                }
                // cek atas kiri
                if (j-(lenKata-1)>=idxMin && i-(lenKata-1)>=idxMin){
                    vector<Point> Points;
                    for(int x = 0; x<lenKata; x++) {
                        if (m[i-x][j-x] != kata[x]) {
                            break;
                        } else {
                            Point P;
                            P.x = i-x;
                            P.y = j-x;
                            Points.push_back(P);
                        }
                    }
                    if (Points.size() == lenKata) {
                        cout <<"Number of Comparisons: "<<counter<<"\n";
                        return Points;
                    }
                }
                // cek atas kanan
                if (j+(lenKata-1)<=idxJMax && i-(lenKata-1)>=idxMin){
                    vector<Point> Points;
                    for(int x = 0; x<lenKata; x++) {
                        if (m[i-x][j+x] != kata[x]) {
                            break;
                        } else {
                            Point P;
                            P.x = i-x;
                            P.y = j+x;
                            Points.push_back(P);
                        }
                    }
                    if (Points.size() == lenKata) {
                        cout <<"Number of Comparisons: "<<counter<<"\n";
                        return Points;
                    }
                }
                // cek bawah kiri
                if (j-(lenKata-1)>=idxMin && i+(lenKata-1)<=idxIMax){
                    vector<Point> Points;
                    for(int x = 0; x<lenKata; x++) {
                        if (m[i+x][j-x] != kata[x]) {
                            break;
                        } else {
                            Point P;
                            P.x = i+x;
                            P.y = j-x;
                            Points.push_back(P);
                        }
                    }
                    if (Points.size() == lenKata) {
                        cout <<"Number of Comparisons: "<<counter<<"\n";
                        return Points;
                    }
                }
                // cek bawah kanan
                if (j+(lenKata-1)<=idxJMax && i+(lenKata-1)<=idxIMax){
                    vector<Point> Points;
                    for(int x = 0; x<lenKata; x++) {
                        if (m[i+x][j+x] != kata[x]) {
                            break;
                        } else {
                            Point P;
                            P.x = i+x;
                            P.y = j+x;
                            Points.push_back(P);
                        }
                    }
                    if (Points.size() == lenKata) {
                        cout <<"Number of Comparisons: "<<counter<<"\n";
                        return Points;
                    }
                }
            }
        }
    }
}

