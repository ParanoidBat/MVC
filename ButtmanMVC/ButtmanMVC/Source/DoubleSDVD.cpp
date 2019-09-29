#include "DoubleSDVD.h"

DoubleSDVD::DoubleSDVD(const DoubleSDVD& ddvd2){
    title= ddvd2.title;
    Id= ddvd2.Id;
    format= ddvd2.format;
    audio_format= ddvd2.audio_format;
    frame_aspect= ddvd2.frame_aspect;
    language= ddvd2.language;
    subs= ddvd2.subs;
    side1= ddvd2.side1;
    side2= ddvd2.side2;
    run_time= ddvd2.run_time;
    retail_price= ddvd2.retail_price;
    bonus_features= ddvd2.bonus_features;
}

void DoubleSDVD::operator =(const DoubleSDVD& ddvd2){
    title= ddvd2.title;
    Id= ddvd2.Id;
    format= ddvd2.format;
    audio_format= ddvd2.audio_format;
    frame_aspect= ddvd2.frame_aspect;
    language= ddvd2.language;
    subs= ddvd2.subs;
    side1= ddvd2.side1;
    side2= ddvd2.side2;
    run_time= ddvd2.run_time;
    retail_price= ddvd2.retail_price;
    bonus_features= ddvd2.bonus_features;
}

void DoubleSDVD::setData(string title, string Id, string format, string audio_format,
                         string frame_aspect, vector<string> language, vector<string> subs,
                         string side1, string side2, short run_time, float retail_price,
                         bool bonus_features){

                      this->title= title;
                      this->Id= Id;
                      this->format= format;
                      this->audio_format= audio_format;
                      this->frame_aspect= frame_aspect;
                      this->language= language;
                      this->subs= subs;
                      this->side1= side1;
                      this->side2= side2;
                      this->run_time= run_time;
                      this->retail_price= retail_price;
                      this->bonus_features= bonus_features;
}

void DoubleSDVD::setSides(string side1, string side2){
    this->side1= side1;
    this->side2= side2;
}

string DoubleSDVD::getSide1(){ return side1;}

string DoubleSDVD::getSide2(){ return side2;}
