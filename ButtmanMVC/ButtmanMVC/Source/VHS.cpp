#include "VHS.h"

VHS::VHS(const VHS & vhs2){
    title= vhs2.title;
    Id= vhs2.Id;
    format= vhs2.format;
    audio_format= vhs2.audio_format;
    frame_aspect= vhs2.frame_aspect;
    language= vhs2.language;
    subs= vhs2.subs;
    packaging= vhs2.packaging;
}

void VHS::operator= (const VHS& vhs2){
    title= vhs2.title;
    Id= vhs2.Id;
    format= vhs2.format;
    audio_format= vhs2.audio_format;
    frame_aspect= vhs2.frame_aspect;
    language= vhs2.language;
    subs= vhs2.subs;
    packaging= vhs2.packaging;
}

void VHS::setData(string title, string Id, string format, string audio_format,
                  string frame_aspect, string language, string subs, string packaging,
                  short run_time, float retail_price){

                  this->title= title;
                  this->Id= Id;
                  this->format= format;
                  this->audio_format= audio_format;
                  this->frame_aspect= frame_aspect;
                  this->language= language;
                  this->subs= subs;
                  this->packaging= packaging;
                  this->run_time= run_time;
                  this->retail_price= retail_price;
}

void VHS::setPackaging(string packaging){ this->packaging= packaging;}

string VHS::getLanguage(){ return language;}

string VHS::getSubs(){ return subs;}

string VHS::getPackaging(){ return packaging;}
