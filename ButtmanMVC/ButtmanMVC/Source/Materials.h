#ifndef MATERIALS_H_INCLUDED
#define MATERIALS_H_INCLUDED
#include "Blueray.h"
#include "VHS.h"
#include "SingleSDVD.h"
#include "DoubleSDVD.h"
#include "ComboBox.h"

class Materials{ /*Some materials either exist or not. For the latter case, they will be nullified*/
    BlueRay *blueray;
    VHS *vhs;
    SingleSDVD *single_dvd;
    DoubleSDVD *double_dvd;
    ComboBox *combo_box;

public:
    Materials();

    Materials(const Materials&);

    void operator =(const Materials&);

    void setData(BlueRay*, VHS*, SingleSDVD*, DoubleSDVD*, ComboBox*);

    void setBlueRay(BlueRay*);

    void setVHS(VHS*);

    void setSingleDVD(SingleSDVD*);

    void setDoubleDVD(DoubleSDVD*);

    void setComboBox(ComboBox*);

    BlueRay *getBlueRay();

    VHS *getVHS();

    SingleSDVD *getSingleDVD();

    DoubleSDVD *getDoubleDVD();

    ComboBox *getComboBox();
};

#endif // MATERIALS_H_INCLUDED
