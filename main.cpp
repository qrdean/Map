//Quinton Dean
//Lab 5 - Grades

/* This is a lab using the #include map library in C++
*/

#include <iostream>
#include <map>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    string section, junk;
    int id, grade;
    map<string, int> grade1;
    map<string, int> gradeCount;
    map<string, int>::iterator it;
    pair<string, int> gradePair;
    {
        string first;
        int second;
    };
    fstream grades;
    grades.open("grades.txt");
    if(!grades.is_open())
    {
        cout << "Cannot open file" << endl;
    }
    cout << '\n' << "Averages for COSC 2336 sections" << '\n' <<endl;
    cout << "ID" << setw(10) << "Section" << setw(10) << "Grade" << '\n' << endl;
    getline(grades, junk);
    grades >> id >> section >> grade;
    while(!grades.eof())
    {

        grade1[section]+=grade;
        gradeCount[section]++;

        cout << id << setw(10) <<  section << setw(10) << grade << endl;
        grades >> id >> section >> grade;
    }
    grades.close();
    cout << '\n' << '\n' << setw(10) <<"AVERAGES" << '\n' << endl;
    cout << "Section" << setw(10) << "Averages" << '\n' << endl;
    double gradeTotal;
    for(map<string, int>::iterator it=gradeCount.begin(); it!=gradeCount.end(); it++)
    {
        gradePair = (*it);
        gradeTotal = grade1[gradePair.first]/gradeCount[gradePair.first];
        cout << gradePair.first << setw(15) << fixed << setprecision(2) <<gradeTotal  << endl;


        //cout << grade1[gradePair.first] << endl;
        //cout << gradeCount[gradePair.first] << endl;
    }

}
