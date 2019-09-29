#ifndef DOUBLESDVD_H_INCLUDED
#define DOUBLESDVD_H_INCLUDED
#include "Blueray.h"
using std::string;

class DoubleSDVD: public BlueRay{ //most of the data is same as blueray, so inherit from it
    string side1, side2; //side might have movie, extras or be empty
    const string PACKAGING= "PlasticBox5x10";

public:

    DoubleSDVD(){}

    DoubleSDVD(const DoubleSDVD&);

    void operator= (const DoubleSDVD &);

    void setData(string, string, string, string, string, vector<string>, vector<string>,
                 string, string, short, float, bool);

    void setSides(string, string);

    string getSide1();

    string getSide2();
};

#endif // DOUBLESDVD_H_INCLUDED
