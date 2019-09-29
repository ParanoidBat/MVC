#ifndef CREW_H_INCLUDED
#define CREW_H_INCLUDED
#include <string>
#include <vector>
using std::string; using std::vector;

class Crew{
    string producer, director, writer, production_designer, costume_designer,
    set_decorator, editor;
    vector<string> cast;

public:

    Crew(){}

    Crew(const Crew&); //copy constructor

    void operator= (const Crew&);

    void setData(string, string, string, string, string, string, string,
                 vector<string>);

    void setProducer(string);

    void setDirector(string);

    void setWriter(string);

    void setProductionDesigner(string);

    void setCostumeDesigner(string);

    void setSetDecorator(string);

    void setEditor(string);

    void setCast(vector<string>);

    string getProducer();

    string getDirector();

    string getWriter();

    string getProductionDesigner();

    string getCostumeDesigner();

    string getSetDecorator();

    string getEditor();

    vector<string> getCast();
};

#endif // CREW_H_INCLUDED
