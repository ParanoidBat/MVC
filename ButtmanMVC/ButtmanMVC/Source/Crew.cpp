#include "Crew.h"

Crew::Crew(const Crew& crw2){
    producer= crw2.producer;
    director= crw2.director;
    writer= crw2.writer;
    production_designer= crw2.production_designer;
    costume_designer= crw2.costume_designer;
    set_decorator= crw2.set_decorator;
    editor= crw2.editor;
    cast= crw2.cast;
}

void Crew::operator= (const Crew& crw2){
    producer= crw2.producer;
    director= crw2.director;
    writer= crw2.writer;
    production_designer= crw2.production_designer;
    costume_designer= crw2.costume_designer;
    set_decorator= crw2.set_decorator;
    editor= crw2.editor;
    cast= crw2.cast;
}

void Crew:: setData(string producer, string director, string writer,
                    string production_designer, string costume_designer,
                    string set_decorator, string editor, vector<string> cast){

                     this->producer= producer;
                     this->director= director;
                     this->writer= writer;
                     this->production_designer= production_designer;
                     this->costume_designer= costume_designer;
                     this->set_decorator= set_decorator;
                     this->editor= editor;
                     this->cast= cast;
}

void Crew::setProducer(string producer){ this->producer= producer;}

void Crew::setDirector(string director){ this->director= director;}

void Crew::setWriter(string writer){ this->writer= writer;}

void Crew::setProductionDesigner(string production_designer){
    this->production_designer= production_designer;
}

void Crew::setCostumeDesigner(string costume_designer){
    this->costume_designer= costume_designer;
}

void Crew::setSetDecorator(string set_decorator){
    this->set_decorator= set_decorator;
}

void Crew::setEditor(string editor){ this->editor= editor;}

void Crew::setCast(vector<string> cast){ this->cast= cast;}

string Crew::getProducer(){return producer;}

string Crew::getDirector(){ return director;}

string Crew::getWriter(){ return writer;}

string Crew::getProductionDesigner(){ return production_designer;}

string Crew::getCostumeDesigner(){return costume_designer;}

string Crew::getSetDecorator(){ return set_decorator;}

string Crew::getEditor(){ return editor;}

vector<string> Crew::getCast(){ return cast;}
