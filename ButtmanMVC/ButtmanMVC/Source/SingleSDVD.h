#ifndef SINGLESDVD_H_INCLUDED
#define SINGLESDVD_H_INCLUDED
#include "Blueray.h"

class SingleSDVD: public BlueRay{
    const string PACKAGING= "PlasticBox5x10";

public:
    SingleSDVD(){}

    SingleSDVD(const SingleSDVD&);

    void operator= (const SingleSDVD&);

    string getPackaging();
};

#endif // SINGLESDVD_H_INCLUDED
