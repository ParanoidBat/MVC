#ifndef BLUERAY_H_INCLUDED
#define BLUERAY_H_INCLUDED
#include <string>
#include <vector>
using std::string;
using std::vector;

class BlueRay{
protected:

    string title, Id, format, audio_format, frame_aspect;
    const string PACKAGING= "PlasticBox7x10";
    vector<string> language, subs;
    short run_time;
    float retail_price;
    bool bonus_features;

public:
    BlueRay(){}

    BlueRay(const BlueRay&); //copy constructor

    void operator= (const BlueRay&);

    void setData(string, string, string, string, string, vector<string>, vector<string>,
                 short, float, bool);

    void setTitle(string);

    void setFormat(string);

    void setAudioFormat(string);

    void setFrameAspect(string);

    void setLanguage(vector<string>);

    void setSubs(vector<string>);

    void setRetailPrice(float);

    void setBonusFeatures(bool);

    string getTitle();

    string getID();

    string getFormat();

    string getAudioFormat();

    string getFrameAspect();

    string getPackaging();

    vector<string> getLanguage();

    vector<string> getSubs();

    short getRunTime();

    float getRetailPrice();

    bool hasBonusFeatures();
};

#endif // BLUERAY_H_INCLUDED
