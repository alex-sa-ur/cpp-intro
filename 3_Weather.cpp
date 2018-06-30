#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

//2
void Greet(string name){
    
    cout << "Hello <<" << name << ">>\n";
}

//3
string Reverse (string &a, string &b){
    string c;
    char hold;
    for (int i = 0; i < (b.size())/2 ; i++){
        hold = b[i];
        b[i] = b[b.size()-(i+1)];
        b[b.size()-(i+1)] = hold;
    }
    c = a + b;
    return c;
}

//4
string Mask(string &a){
    for (int i = 0; i < a.size(); i++){
        a[i]= '*';
    }
    return a;
}

//5
struct Weather{
    int day, month, year;
    float temp;
    string city;
};

void read(vector <Weather> &vweather){
    ifstream fin;
    fin.open("weatherfile_unsorted.txt");
    while (!fin.eof()){
        Weather weather;
        fin >> weather.month
            >> weather.day
            >> weather.year
            >> weather.temp
            >> weather.city;
        vweather.push_back(weather);
    }
}

void swap(vector <Weather> &vweather, int swapLoc1, int swapLoc2){
    Weather temp;
    temp = vweather[swapLoc1];
    vweather[swapLoc1] = vweather[swapLoc2];
    vweather[swapLoc2] = temp;
}

void sort(vector <Weather> &vweather){
    ofstream fout;
    fout.open("weatherfile_sorted.txt");
    int locLowest = 0;
    for (int i = 0; i < vweather.size(); i++){
        locLowest = i;
        for (int j = i + 1; j < vweather.size(); j++){
            if(vweather[locLowest].temp > vweather[j].temp){
                locLowest = j;
            }
        }
        if (locLowest != i){
            swap(vweather, locLowest, i);
        }
        fout << vweather[i].month << "\t"
             << vweather[i].day << "\t"
             << vweather[i].year << "\t"
             << fixed << setprecision(1) << vweather[i].temp << "\t"
             << vweather[i].city << endl;
    }
    cout << "The highest temperature recorded was: "
         << vweather[vweather.size()-1].temp
         << " in "
         << vweather[vweather.size()-1].city
         << " on "
         << vweather[vweather.size()-1].month << "/"
         << vweather[vweather.size()-1].day << "/"
         << vweather[vweather.size()-1].year << endl;
}

int main() {
    
    //1
    cout << "Hello, World!\n";
   
    //2
    string name;
    cout << "What is your name?\n";
    cin >> name;
    Greet(name);
    
    //3
    string a = "Alejandro" , b = "Sanchez";
    cout << "Original input: a = " << a << " b = " << b << endl;
    cout << "Concatenation: " << Reverse(a, b) << endl << "Reversed 'b': "<< b << endl;
    
    //4
    string m = "Mask";
    cout << "Original input: " << m << endl;
    cout << "Masked: " << Mask(m) << endl;
    
    
    //5
    vector <Weather> vweather;
    read(vweather);
    sort(vweather);
    
    return 0;
}
