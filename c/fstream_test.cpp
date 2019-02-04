
#include <iostream>
#include <fstream>
using namespace std;
/*
fstream library contains three classes:
  ofstream: Output file stream that creates and writes information to files.
  ifstream: Input file stream that reads information from files.
  fstream:  General file stream, with both ofstream and ifstream capabilities that allow it to create, read, and write information to files.
*/
int main () {

    //ofstream outfile;
    //outfile.open("file.dat", ios::out | ios::trunc );

    ofstream MyFile1("/tmp/test.txt");
    MyFile1 << "This is awesome! \n";
    MyFile1.close();

    ifstream MyFile("/tmp/test.txt");
    string line; while ( getline (MyFile, line) ) cout << line << '\n';   //This is awesome!
    MyFile.close();
}
