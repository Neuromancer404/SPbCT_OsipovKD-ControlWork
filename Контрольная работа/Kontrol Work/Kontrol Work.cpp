#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>  //Для контейнера vector
#include <stdlib.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    char cc[128];
    printf("Название файла: ");
    char* myfile = (char*)malloc(256);
    scanf("%s", myfile);
    FILE* fp = fopen(myfile, "r");
    if (fp == NULL)
    {
        printf("Unable to open file");
        return 0;
    }
    int ch = 0;  
    string s;  
    vector<string> v; 
    const char* FName = myfile;
    ifstream in(FName);
    while ((ch = in.get()) != EOF) {  
        if (char(ch) != '\n') s = s + char(ch);   
        else {
            v.push_back(s); 
            s.clear(); 
        }
    }    v.push_back(s); 
    in.close();
    fclose(fp);
    for (int i = 0; i < v.size(); i++)
        cout << v[i]+ " " << ' ';
    return 0;
}