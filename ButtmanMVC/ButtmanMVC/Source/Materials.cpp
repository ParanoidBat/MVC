#include "Materials.h"

Materials::Materials(){
    blueray= new BlueRay; blueray= NULL;
    vhs= new VHS; vhs= NULL;
    single_dvd= new SingleSDVD; single_dvd= NULL;
    double_dvd= new DoubleSDVD; double_dvd= NULL;
    combo_box= new ComboBox; combo_box= NULL;
}

Materials::Materials(const Materials& materials2){ //deep copy
	blueray = new BlueRay; blueray = materials2.blueray;
    vhs= new VHS; vhs= materials2.vhs;
    single_dvd= new SingleSDVD; single_dvd= materials2.single_dvd;
    double_dvd= new DoubleSDVD; double_dvd= materials2.double_dvd;
    combo_box= new ComboBox; combo_box= materials2.combo_box;
}

void Materials::operator=(const Materials &materials2){

    blueray= materials2.blueray;
    vhs= materials2.vhs;
    single_dvd= materials2.single_dvd;
    double_dvd= materials2.double_dvd;
    combo_box= materials2.combo_box;
}

void Materials::setData(BlueRay *blue_ray, VHS *vhs, SingleSDVD *single_dvd,
                        DoubleSDVD *double_dvd, ComboBox *combo_box){
	this->blueray = blue_ray;
	this->vhs = vhs;
	this->single_dvd = single_dvd;
	this->double_dvd = double_dvd;
	this->combo_box = combo_box;
}


void Materials::setBlueRay(BlueRay *blue_ray){ this->blueray= blue_ray;}

void Materials::setVHS(VHS *vhs){ this->vhs= vhs;}

void Materials::setSingleDVD(SingleSDVD *single_dvd){ this->single_dvd= single_dvd;}

void Materials::setDoubleDVD(DoubleSDVD *double_dvd){ this->double_dvd= double_dvd;}

void Materials::setComboBox(ComboBox *combo_box){ this->combo_box= combo_box;}

BlueRay* Materials::getBlueRay(){ return blueray;}

VHS* Materials::getVHS(){ return vhs;}

SingleSDVD* Materials::getSingleDVD(){ return single_dvd;}

DoubleSDVD* Materials::getDoubleDVD(){ return double_dvd;}

ComboBox* Materials::getComboBox(){ return combo_box;}
