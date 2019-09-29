#include "Model.h"
#include "QProject.h"

Model::Model(){
    title= "";
    genre= "";
    summary= "";
    language="";
    status= "";
    release_date= "";
    weekly_ticket_sale= 0;
    run_time= 0;
    materials= NULL;
}

void Model::setData(string title, string genre,string summary, string language, string release_date, vector<string> locations, vector<string> keywords, short run_time, Crew crew){

    this->title= title;
    this->genre= genre;
    this->summary= summary;
    this->language= language;
    this->release_date= release_date;
    this->locations= locations;
    this->keywords= keywords;
    this->run_time= run_time;
    this->crew= crew;
}

void Model::setTitle(string title){ this->title= title;}

void Model::setGenre(string genre){this->genre= genre;}

void Model::setSummary(string summary){this->summary= summary;}

void Model::setLanguage(string language){this->language= language;}

void Model::setStatus(string status){this->status= status;}

void Model::setReleaseDate(string release_date){this->release_date= release_date;}

void Model::setKeywords(vector<string> keywords){this->keywords= keywords;}

void Model::setLocations(vector<string> locations){this->locations= locations;}

void Model::setWeeklyTicketSale(int weekly_ticket_sale){this->weekly_ticket_sale= weekly_ticket_sale;}

void Model::setRunTime(short run_time){ this->run_time= run_time;}

void Model::setCrew(Crew crew){this->crew= crew;}

void Model::setMaterials(Materials *materials){this->materials= materials;}

string Model::getTitle(){return title;}

string Model::getGenre(){return genre;}

string Model::getSummary(){return summary;}

string Model::getLanguage(){return language;}

string Model::getStatus(){return status;}

string Model::getReleaseDate(){return release_date;}

vector<string> Model::getKeywords(){return keywords;}

vector<string> Model::getLocations(){return locations;}

int Model::getWeeklyTicketSale(){return weekly_ticket_sale;}

short Model::getRunTime(){return run_time;}

Crew Model::getCrew(){return crew;}

Materials *Model::getMaterials(){return materials;}
