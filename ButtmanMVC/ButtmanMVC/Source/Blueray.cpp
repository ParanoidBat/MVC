#include "Blueray.h"

BlueRay::BlueRay(const BlueRay& br2){
    title= br2.title;
    Id= br2.Id;
    format= br2.format;
    audio_format= br2.audio_format;
    frame_aspect= br2.frame_aspect;
    language= br2.language;
    subs= br2.subs;
    run_time= br2.run_time;
    retail_price= br2.retail_price;
    bonus_features= br2.bonus_features;
}

void BlueRay::operator=(const BlueRay& br2){
    title= br2.title;
    Id= br2.Id;
    format= br2.format;
    audio_format= br2.audio_format;
    frame_aspect= br2.frame_aspect;
    language= br2.language;
    subs= br2.subs;
    retail_price= br2.retail_price;
    bonus_features= br2.bonus_features;
}

void BlueRay::setData(string title, string Id, string format, string audio_format,
                      string frame_aspect, vector<string> language, vector<string> subs,
                      short run_time, float retail_price, bool bonus_features){

                      this->title= title;
                      this->Id= Id;
                      this->format= format;
                      this->audio_format= audio_format;
                      this->frame_aspect= frame_aspect;
                      this->language= language;
                      this->subs= subs;
                      this->run_time= run_time;
                      this->retail_price= retail_price;
                      this->bonus_features= bonus_features;
}

void BlueRay::setTitle(string title){ this->title= title;}

void BlueRay::setFormat(string format){ this->format;}

void BlueRay::setAudioFormat(string audio_format){ this->audio_format= audio_format;}

void BlueRay::setFrameAspect(string frame_aspect){ this->frame_aspect= frame_aspect;}

void BlueRay::setLanguage(vector<string> language){ this->language= language;}

void BlueRay::setSubs(vector<string> subs){ this->subs= subs;}

void BlueRay::setRetailPrice(float retail_price){ this->retail_price= retail_price;}

void BlueRay::setBonusFeatures(bool bonus_features){ this->bonus_features= bonus_features;}

string BlueRay::getTitle(){ return title;}

string BlueRay::getID(){ return Id;}

string BlueRay::getFormat(){ return format;}

string BlueRay::getAudioFormat(){ return audio_format;}

string BlueRay::getFrameAspect(){ return frame_aspect;}

string BlueRay::getPackaging(){ return PACKAGING;}

vector<string> BlueRay::getLanguage(){ return language;}

vector<string> BlueRay::getSubs(){ return subs;}

short BlueRay::getRunTime(){ return run_time;}

float BlueRay::getRetailPrice(){ return retail_price;}

bool BlueRay::hasBonusFeatures(){ return bonus_features;}
