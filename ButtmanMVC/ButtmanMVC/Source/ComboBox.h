#ifndef COMBOBOX_H_INCLUDED
#define COMBOBOX_H_INCLUDED
#include <string>
using std::string;

//instead of copying the actual objects of dvd classes, we keep a track of number of dvds in combobox to save memory and better performance

class ComboBox{
    int sDVDs;
    int dDVDs;
    const string PACKAGING= "CardBox";

public:

    ComboBox();

    ComboBox(const ComboBox&); //copy constructor

    void operator= (const ComboBox&);

    void setSDvds(int pieces);

    void setDDvds(int pieces);

    bool hasSDVDs();

    bool hasDDVDs();

    int getsDVDs();

    int getdDVDs();

    string getPackaging();
};

#endif // COMBOBOX_H_INCLUDED
