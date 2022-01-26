#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct Point
// struct ini berisi koordinat x dan y yang menampung letak huruf yang telah ditemukan 
{
   int x, y;
};

vector< vector<char> > newMatrix(const char* filename) {
    // fungsi ini digunakan untuk membuat matrix sesuai input file user
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
    // fungsi ini digunakan untuk membuat vector dari kata kata yang akan dicari
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
    // fungsi ini digunakan pada saat testing agar dapat mengecek inputan matrix yang dibaca dari file yang diinput
    for (int i=0; i< mat.size(); i++){
        for (int j=0; j < mat[i].size(); j++){
            cout << mat[i][j] <<" ";
        }
        cout << "\n";
    }
}

void displayAnsMatrix(vector< vector<char> > mat, vector<Point> p){
    // fungsi ini digunakan untuk mendisplay matrix jawaban dari penyelesaian suatu kata
    vector< vector<char> > mAns;
    // membuat matrix berisikan "-"
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

vector<Point> findKata(vector< vector<char> > m,string kata, int* totalComp){
    // fungsi ini digunakan untuk melakukan pencarian koordinat letak suatu kata ditemukan
    int lenKata = kata.length();
    int idxMin = 0;
    int idxJMax = m[0].size();
    int idxIMax = m.size();
    int counter = 0;
    for (int i=0; i<m.size(); i++){
        for (int j=0; j<m[0].size();j++){
            counter++;
            // mengecek apakah elemen pertama dari kata yang dicari sesuai dengan elemen matrix
            if (m[i][j] == kata[0]){
                // mengecek lurus ke atas
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
                        *totalComp += counter;
                        cout <<"Number of Comparisons: "<<counter<<"\n";
                        return Points;
                    }
                }
                // mengecek lurus ke bawah
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
                        *totalComp += counter;
                        cout <<"Number of Comparisons: "<<counter<<"\n";
                        return Points;
                    }
                }
                // mengecek lurus ke kiri
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
                        *totalComp += counter;
                        cout <<"Number of Comparisons: "<<counter<<"\n";
                        return Points;
                    }
                }
                // mengecek lurus ke kanan
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
                        *totalComp += counter;
                        cout <<"Number of Comparisons: "<<counter<<"\n";
                        return Points;
                    }
                }
                // mengecek diagonal ke arah atas kiri
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
                        *totalComp += counter;
                        cout <<"Number of Comparisons: "<<counter<<"\n";
                        return Points;
                    }
                }
                // mengecek diagonal ke arah atas kanan
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
                        *totalComp += counter;
                        cout <<"Number of Comparisons: "<<counter<<"\n";
                        return Points;
                    }
                }
                // mengecek diagonal ke arah bawah kiri
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
                        *totalComp += counter;
                        cout <<"Number of Comparisons: "<<counter<<"\n";
                        return Points;
                    }
                }
                // mengecek diagonal ke arah bawah kanan
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
                        *totalComp += counter;
                        cout <<"Number of Comparisons: "<<counter<<"\n";
                        return Points;
                    }
                }
            }
        }
    }
    vector<Point> Points;
    return Points;
}

int main () {
    // variable file untuk menampung input user
    string file;

    cout <<"8   8  8                       8eeee8                              " <<endl; 
    cout <<"8   8  8 eeeee eeeee  eeeee    8      eeee eeeee eeeee  eeee e   e " <<endl; 
    cout <<"8e  8  8 8  88 8   8  8   8    8eeeee 8    8   8 8   8  8  8 8   8 " <<endl; 
    cout <<"88  8  8 8   8 8eee8e 8e  8        88 8eee 8eee8 8eee8e 8e   8eee8 " <<endl; 
    cout <<"88  8  8 8   8 88   8 88  8    e   88 88   88  8 88   8 88   88  8 " <<endl; 
    cout <<"88ee8ee8 8eee8 88   8 88ee8    8eee88 88ee 88  8 88   8 88e8 88  8 " <<endl; 

    // melakukan input nama file 
    cout << "\n";
    cout << "File Name Input (please include .txt when input) : "; cin >> file;
    cout << "\n";

    // penambahan directory terhadap input file
    string filename = "../test/" + file;

    // pembuatan matrix bernama PUZZLE sebagai matrix yang akan dicari
    vector< vector<char> > puzzle = newMatrix(filename.c_str());

    // pembuatan vector untuk kata-kata yang akan dicari
    vector<string> words = newWord(filename.c_str());

    //total comparison
    int totalComp = 0;

    // proses pencarian kata
    // assign variabel untuk waktu
    clock_t start, end;
    double totalTime;
    // mengiterate vector bernama WORDS agar mendapat vector POINTS, letak koordinat ditemukannya kata
    for (int i=0;i<words.size();i++){
        cout << i+1 <<". "<< words[i] << " ";
        cout << "\n";
        // waktu start untuk pencarian
        start = clock();
        // algoritma pencarian kata
        vector<Point> points = findKata(puzzle, words[i], &totalComp);
        // waktu stop pencarian
        end = clock();
        // pengurangan waktu akhir - waktu awal
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        // penambahan total waktu yang dibutuhkan
        totalTime+=time_taken;
        // display jawaban, jika tidak ditemukan print "word doesnt exist"
        if (points.size()!=0){
            displayAnsMatrix(puzzle, points);
        }else{
            cout << "Word doesn't exist\n";
        }
        cout << "\n";
    }
    // waktu selesai pencarian
    cout << "Time taken : " << fixed 
         << totalTime << setprecision(10);
    cout << "s " << endl;
    cout << "Total comparison: " << totalComp;
    return 0;
    
return 0;      
}