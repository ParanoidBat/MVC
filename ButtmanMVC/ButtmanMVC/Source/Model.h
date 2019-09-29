#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED
#include "Crew.h"
#include "Materials.h"

//New Project Class
class Model{

    string title, genre, summary, language, status, release_date;
    vector<string> locations, keywords;
    int weekly_ticket_sale;
    short run_time;
    Crew crew;
    Materials *materials; //may or may not exist. nullified if not

public:
    Model();

    void setData(string ,string, string, string, string, vector<string>, vector<string>, short, Crew);

    void setTitle(string);

    void setGenre(string);

    void setSummary(string);

    void setLanguage(string);

    void setStatus(string);

    void setReleaseDate(string);

    void setKeywords(vector<string>);

    void setLocations(vector<string>);

    void setWeeklyTicketSale(int);

    void setRunTime(short);

    void setCrew(Crew);

    void setMaterials(Materials*);

    string getTitle();

    string getGenre();

    string getSummary();

    string getLanguage();

    string getStatus();

    string getReleaseDate();

    vector<string> getKeywords();

    vector<string> getLocations();

    int getWeeklyTicketSale();

    short getRunTime();

    Crew getCrew();

    Materials* getMaterials();
};

#endif // MODEL_H_INCLUDED
