#include "ComboBox.h"

ComboBox::ComboBox(){
    sDVDs= 0;
    dDVDs= 0;
}

ComboBox::ComboBox(const ComboBox& cmb2){
    sDVDs= cmb2.sDVDs;
    dDVDs= cmb2.dDVDs;
}

void ComboBox::operator=(const ComboBox& cmb2){
    sDVDs= cmb2.sDVDs;
    dDVDs= cmb2.dDVDs;
}

void ComboBox::setSDvds(int pieces){
    sDVDs= pieces;
}

void ComboBox::setDDvds(int pieces){
    dDVDs= pieces;
}

bool ComboBox::hasSDVDs(){
    if(sDVDs == 0) return 0;
    else return 1;
}

bool ComboBox::hasDDVDs(){
    if(dDVDs == 0) return 0;
    else return 1;
}

int ComboBox::getsDVDs(){ return sDVDs;}

int ComboBox::getdDVDs(){ return dDVDs;}

string ComboBox::getPackaging(){ return PACKAGING;}
