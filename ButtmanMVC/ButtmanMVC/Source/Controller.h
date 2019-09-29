#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include "Log.h"
#include "View.h"
#include "Model.h"
#include "QProject.h"

using std::cin;
using std::cerr;
using std::ifstream;
using std::ofstream;

class Controller{
    Model model;
    View view;
    Log log;

    void populateQueue(); //private func to be used only within class

public:
    QProject q;

    Controller(Model, View); //bind model and view

    bool showProjectByTitleAndSummary(string); //material summary with project info

    bool showProjectByTitleAndDetail(string); //material details with project info

    void showProjectsByCast(string, node *);

    void showMaterials(Materials*);

    bool writeData(); //write data to db

    bool readData(); //read data from db

    void setData(string, string, string, string, string, string, vector<string>,
                    vector<string>, short, int,Crew); //set data to model

    void removeProject(node*, string);

    void inflateMenu(string);

    void onLoad(); //on application start

    void setMaterials(string, Materials*);

    void updateProject();

    void updateMaterials(node *);

    void addMaterials(node *);
};

#endif // CONTROLLER_H_INCLUDED
