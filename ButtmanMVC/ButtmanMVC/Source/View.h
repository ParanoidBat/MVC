#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED
#include<iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

struct View{
    void showFullProjectDetails(string, string, string, string, string, string, vector<string>,
                         vector<string>, short, int);

    void showCrew(string, string, string, string, string, string, string, vector<string>);

    void showBlueRay(string, string, string, string, string, string,
                                vector<string>, vector<string>, short, float, bool);

    void showSingleDVD(string, string, string, string, string, string,
                                vector<string>, vector<string>, short, float, bool);

    void showVHS(string, string, string, string, string, string, string, string,
                 short, float);

    void showDoubleDVD(string, string, string, string, string, string, vector<string>,
                     vector<string>, string, string, short, float, bool);

    void showMaterialSummary(bool, bool, bool, bool, bool); //whether some materials exist or not, show accordingly

    void printStatement(string);

    void showPackaging(string);

    void menuMain(); //main screen at app startup

    void menuUpdateProject();

    void menuUpdateMaterials();
};

#endif // VIEW_H_INCLUDED
