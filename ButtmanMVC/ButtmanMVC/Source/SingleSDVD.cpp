#include "SingleSDVD.h"

SingleSDVD:: SingleSDVD(const SingleSDVD& sdvd2){
    title= sdvd2.title;
    Id= sdvd2.Id;
    format= sdvd2.format;
    audio_format= sdvd2.audio_format;
    frame_aspect= sdvd2.frame_aspect;
    language= sdvd2.language;
    subs= sdvd2.subs;
    run_time= sdvd2.run_time;
    retail_price= sdvd2.retail_price;
    bonus_features= sdvd2.bonus_features;
}

void SingleSDVD:: operator= (const SingleSDVD& sdvd2){
    title= sdvd2.title;
    Id= sdvd2.Id;
    format= sdvd2.format;
    audio_format= sdvd2.audio_format;
    frame_aspect= sdvd2.frame_aspect;
    language= sdvd2.language;
    subs= sdvd2.subs;
    run_time= sdvd2.run_time;
    retail_price= sdvd2.retail_price;
    bonus_features= sdvd2.bonus_features;
}

string SingleSDVD::getPackaging(){
    return PACKAGING;
}
