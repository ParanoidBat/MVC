#ifndef VHS_H_INCLUDED
#define VHS_H_INCLUDED
#include "Blueray.h"
using std::string;

class VHS: public BlueRay{
    string language, subs, packaging;

public:

    VHS(){}

    VHS(const VHS&);

    void operator= (const VHS&);

    void setData(string, string, string, string, string, string, string, string,
                 short, float);

    void setPackaging(string);

    string getLanguage();

    string getSubs();

    string getPackaging();
};

#endif // VHS_H_INCLUDED
