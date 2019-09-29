#include "View.h"

void View::showFullProjectDetails(string title, string genre, string summary,
                        string language, string status, string release_date,
                        vector<string> locations, vector<string> keywords,
                        short run_time, int weekly_sale= 0){

        cout<<"Title: "<<title<<"\nGenre: "<<genre<<"\nSummary: "<<summary
        <<"\nLanguage: "<<language<<"\nStatus: "<<status<<"\nRelease: "<<release_date
        <<"\nLocations: ";

        for(int i=0; i<locations.size(); i++){
            cout<<locations[i]<<", ";
        }

        cout<<"\nKeywords: ";
        for(int i=0; i<keywords.size(); i++){
            cout<<keywords[i]<<", ";
        }

        cout<<"\nRuntime: "<<run_time;
        cout<<"\nWeekly Ticket Sale: "<<weekly_sale<<endl;
}

void View::showCrew(string producer, string director, string writer,
                    string production_designer, string costume_designer,
                    string set_decorator, string editor, vector<string> cast){

        cout<<"Producer: "<<producer<<"\nDirector: "<<director<<"\nWriter: "<<writer
        <<"\nProduction Designer: "<<production_designer<<"\nCostume Designer: "
        <<costume_designer<<"\nSet Decorator: "<<set_decorator<<"\nEditor: "<<editor
        <<"\nCast: ";

        for(int i =0; i<cast.size(); i++)
            cout<<cast[i]<<", ";

        cout<<endl;
}

void View::showBlueRay(string title, string Id, string format,
                                  string audio, string frame, string packaging,
                                  vector<string> language, vector<string> subs,
                                  short run, float price, bool bonus_features){

        cout<<"BlueRay:\nTitle: "<<title<<"\nId: "<<Id<<"\nFormat: "<<format
        <<"\nAudio Format: "<<audio<<"\nFrame Aspect: "<<frame<<"\nPackaging: "<<packaging
        <<"\nLanguage: ";
        for(int i=0; i<language.size(); i++)
            cout<<language[i]<<", ";

        cout<<"\nSubs: ";
        for(int i=0; i <subs.size(); i++)
            cout<<subs[i]<<", ";

        cout<<"\nRun Time: "<<run<<"\nPrice: "<<price<<"\nBonus Features: "<<bonus_features
        <<endl;
}

void View::showSingleDVD(string title, string Id, string format,
                                  string audio, string frame, string packaging,
                                  vector<string> language, vector<string> subs,
                                  short run, float price, bool bonus_features){

        cout<<"SingleDVD:\nTitle: "<<title<<"\nId: "<<Id<<"\nFormat: "<<format
        <<"\nAudio Format: "<<audio<<"\nFrame Aspect: "<<frame<<"\nPackaging: "<<packaging
        <<"\nLanguage: ";
        for(int i=0; i<language.size(); i++)
            cout<<language[i]<<", ";

        cout<<"\nSubs: ";
        for(int i=0; i <subs.size(); i++)
            cout<<subs[i]<<", ";

        cout<<"\nRun Time: "<<run<<"\nPrice: "<<price<<"\nBonus Features: "<<bonus_features
        <<endl;
}

void View::showDoubleDVD(string title, string Id, string format,
                         string audio, string frame, string packaging,
                         vector<string> language, vector<string> subs, string side1,
                         string side2, short run, float price, bool bonus_features){

        cout<<"Double DVD:\nTitle: "<<title<<"\nId: "<<Id<<"\nFormat: "<<format
        <<"\nAudio Format: "<<audio<<"\nFrame Aspect: "<<frame<<"\nPackaging: "<<packaging
        <<"\nLanguage: ";
        for(int i=0; i<language.size(); i++)
            cout<<language[i]<<", ";

        cout<<"\nSubs: ";
        for(int i=0; i <subs.size(); i++)
            cout<<subs[i]<<", ";

        cout<<"\nSide1: "<<side1<<"Side2: "<<side2<<"\nRun Time: "<<run<<"\nPrice: "
        <<price<<"\nBonus Features: "<<bonus_features<<endl;
}

void View::showVHS(string title, string Id, string format, string audio, string frame,
                   string packaging, string language, string subs, short run, float price){

        cout<<"VHS:\nTitle: "<<title<<"\nId: "<<Id<<"\nFormat: "<<format
        <<"\nAudio Format: "<<audio<<"\nFrame Aspect: "<<frame<<"\nPackaging: "<<packaging
        <<"\nLanguage: "<<language<<"\nSubs: "<<subs<<"\nRun Time: "<<run
        <<"\nPrice: "<<price<<endl;
}

void View::showMaterialSummary(bool bluray, bool single, bool double_, bool vhs, bool combo){
    cout<<"Available in:";

    if(bluray) cout<<" BlueRay";
    if(single) cout<<" Single";
    if(double_) cout<<" Double";
    if(vhs) cout<<" VHS";
    if(combo) cout<<" Combo Box";
    cout<<endl;
}

void View::printStatement(string statement){
    cout<<statement<<endl;
}

void View::showPackaging(string packaging){
    cout<<"Packaging: "<<packaging<<endl;
}

void View::menuMain(){
    cout<<"\t\t\tMovie Manager\n\n";

    cout<<"1. Display Catalog\n2. Create New Project\n3. Search Project By Title(Material Detail)\n"
    <<"4. Search Project By Title(Material Summary)\n5. Search Projects By Cast\n"
    <<"6. Update Project\n7. Remove Project\n0. Exit\n";
}

void View::menuUpdateProject(){
    cout<<"\t\t\tUpdate Project\n\n";
    cout<<"1. Edit Existing Information\n2. Update Status\n3. Update Weekly Ticket Sale\n4. Update Materials\n0. Exit\n";
}

void View::menuUpdateMaterials(){
    cout<<"\t\t\tUpdate Materials\n\n";
    cout<<"1. Add Materials\n2. Remove Materials \n3. Update Materials\n0. Exit\n";
}
