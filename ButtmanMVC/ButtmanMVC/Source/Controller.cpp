#include "Controller.h"

Controller::Controller(Model model, View view){
    this->model= model;
    this->view= view;
}

bool Controller::showProjectByTitleAndSummary(string title){
    node *tmp= new node;
    tmp= q.searchByTitle(title, q.head); //returns a node who's model's project's title matches the param

    if(tmp == NULL){
        cerr<<"Error: Title not found"<<endl;
        return false;
    }

    Model m= tmp->model;
    view.showFullProjectDetails(m.getTitle(), m.getGenre(), m.getSummary(),
                         m.getLanguage(), m.getStatus(), m.getReleaseDate(),
                         m.getLocations(), m.getKeywords(), m.getRunTime(), m.getWeeklyTicketSale());

    Crew crew= m.getCrew();

    view.showCrew(crew.getProducer(), crew.getDirector(), crew.getWriter(),
                  crew.getProductionDesigner(), crew.getCostumeDesigner(),
                  crew.getSetDecorator(), crew.getEditor(), crew.getCast());

    Materials *mtrls= m.getMaterials();
    if(mtrls != NULL){
        bool flags[5]; //check which materials are available and show them only
                (mtrls->getBlueRay() != NULL)?   flags[0]= 1: flags[0]= 0;
                (mtrls->getSingleDVD() != NULL)? flags[1]= 1: flags[1]= 0;
                (mtrls->getDoubleDVD() != NULL)? flags[2]= 1: flags[2]= 0;
                (mtrls->getVHS() != NULL)?       flags[3]= 1: flags[3]= 0;
                (mtrls->getComboBox() != NULL)?  flags[4]= 1: flags[4]= 0;

                view.showMaterialSummary(flags[0], flags[1], flags[2], flags[3], flags[4]);
    }

    return true;
}

bool Controller::showProjectByTitleAndDetail(string title){
    node *tmp= new node;
    tmp= q.searchByTitle(title, q.head);

    if(tmp == NULL){
        cerr<<"Error: Title not found"<<endl;
        return false;
    }

    Model m= tmp->model;
    view.showFullProjectDetails(m.getTitle(), m.getGenre(), m.getSummary(),
                         m.getLanguage(), m.getStatus(), m.getReleaseDate(),
                         m.getLocations(), m.getKeywords(), m.getRunTime(), m.getWeeklyTicketSale());

    Crew crew= m.getCrew();

    view.showCrew(crew.getProducer(), crew.getDirector(), crew.getWriter(),
                  crew.getProductionDesigner(), crew.getCostumeDesigner(),
                  crew.getSetDecorator(), crew.getEditor(), crew.getCast());

    Materials *mtrls= m.getMaterials();
    if(mtrls != NULL)
        showMaterials(mtrls);

    return true;
}

void Controller::showProjectsByCast(string cast, node *n){ //pass head
    node *iterate= n;
    node *tmp= NULL;
    Model model;

        for (int i= 0; i < q.size; i++){
            tmp= q.searchByCast(cast, iterate); //return node with required cast name

            if(tmp != NULL){ //if cast exists
                string title= tmp->model.getTitle();
                view.printStatement(title);

                tmp= NULL;
            }
            iterate= iterate->next;
        }
        view.printStatement("\n0. Exit");
        cin>>cast; //for wait
}

void Controller::showMaterials(Materials *materials){
    if(materials->getBlueRay() != NULL){
        BlueRay blueray= *(materials->getBlueRay()); //de-refer blueray

        view.showBlueRay(blueray.getTitle(), blueray.getID(), blueray.getFormat(),
                         blueray.getAudioFormat(), blueray.getFrameAspect(),
                         blueray.getPackaging(), blueray.getLanguage(), blueray.getSubs(),
                         blueray.getRunTime(), blueray.getRetailPrice(),
                         blueray.hasBonusFeatures());
    }

    if(materials->getVHS() != NULL){
        VHS vhs= *(materials->getVHS());

        view.showVHS(vhs.getTitle(), vhs.getID(), vhs.getFormat(), vhs.getAudioFormat(),
                     vhs.getFrameAspect(), vhs.getPackaging(), vhs.getLanguage(),
                     vhs.getSubs(), vhs.getRunTime(), vhs.getRetailPrice());
    }

    if(materials->getSingleDVD() != NULL){
        SingleSDVD sdvd= *(materials->getSingleDVD());

        view.showSingleDVD(sdvd.getTitle(), sdvd.getID(), sdvd.getFormat(),
                           sdvd.getAudioFormat(), sdvd.getFrameAspect(),
                           sdvd.getPackaging(), sdvd.getLanguage(), sdvd.getSubs(),
                           sdvd.getRunTime(), sdvd.getRetailPrice(), sdvd.hasBonusFeatures());
    }

    if(materials->getDoubleDVD() != NULL){
        DoubleSDVD ddvd= *(materials->getDoubleDVD());

        view.showDoubleDVD(ddvd.getTitle(), ddvd.getID(), ddvd.getFormat(),
                           ddvd.getAudioFormat(), ddvd.getFrameAspect(),
                           ddvd.getPackaging(), ddvd.getLanguage(), ddvd.getSubs(),
                           ddvd.getSide1(), ddvd.getSide2(), ddvd.getRunTime(),
                           ddvd.getRetailPrice(), ddvd.hasBonusFeatures());
    }

    if(materials->getComboBox() != NULL){
        ComboBox cmbx= *(materials->getComboBox());

        view.printStatement("Combo Box: ");
        if(cmbx.hasSDVDs()){ //if dvd exists in combo box
            //if a specific type of dvd doesn't exist but combo box shows that it does, it's a discrepancy
            //that'll crash the software. We thus check if the dvd actually exists in the materials.
            try{
                SingleSDVD *sdvd= materials->getSingleDVD();
                if(sdvd == NULL) throw 0;

                for(int i=0 ;i<cmbx.getsDVDs();i++){
                    view.showSingleDVD(sdvd->getTitle(), sdvd->getID(), sdvd->getFormat(),
                               sdvd->getAudioFormat(), sdvd->getFrameAspect(),
                               sdvd->getPackaging(), sdvd->getLanguage(), sdvd->getSubs(),
                               sdvd->getRunTime(), sdvd->getRetailPrice(),
                               sdvd->hasBonusFeatures());
                }
            }
            catch(int e) {}
        }

        if(cmbx.hasDDVDs()){
            try{
                DoubleSDVD *ddvd= materials->getDoubleDVD();
                if(ddvd == NULL) throw 0;

                for(int i=0; i<cmbx.getdDVDs(); i++){
                    view.showDoubleDVD(ddvd->getTitle(), ddvd->getID(), ddvd->getFormat(),
                                   ddvd->getAudioFormat(), ddvd->getFrameAspect(),
                                   ddvd->getPackaging(), ddvd->getLanguage(), ddvd->getSubs(),
                                   ddvd->getSide1(), ddvd->getSide2(), ddvd->getRunTime(),
                                   ddvd->getRetailPrice(), ddvd->hasBonusFeatures());
                }
            }
            catch(int e) {}
        }
        view.showPackaging(cmbx.getPackaging());
    }
}

bool Controller::writeData(){
    ofstream file("data.txt");
    Model obj;
    node* iterate= q.head;
    vector<string> locs;

    if(!file.is_open()){
        cerr<<"Error: File couldn't be opened\n";
        return false;
    }

    for (int i= 0; i < q.size; i++){
        obj= iterate->model;

        if(log.projectsEarning(obj.getWeeklyTicketSale())){
            cout<<obj.getTitle()<<" has $20,000+ box-office earnings\n"; //assumption: each ticket costs $100
        }

        file<<"Title: "<<obj.getTitle()<<"\tGenre: "<<obj.getGenre()<<"\tSummary: "<<obj.getSummary()
        <<"\tLanguage: "<<obj.getLanguage()<<"\tStatus: "<<obj.getStatus()<<"\tRelease: "<<obj.getReleaseDate()
        <<"\tLocations: ";

        locs= obj.getLocations();
        for(int i=0; i<locs.size(); i++){
            file<<locs[i]<<" ";
        }

        locs.clear(); locs.resize(0); locs.shrink_to_fit(); //empty and shrink the vector before proceeding

        locs= obj.getKeywords();
        file<<"\tKeywords: ";
        for(int i=0; i<locs.size(); i++){
            file<<locs[i]<<" ";
        }

        locs.clear(); locs.resize(0); locs.shrink_to_fit();

        file<<"\tRuntime: "<<obj.getRunTime();

        Crew obj2= obj.getCrew();
        file<<"\tProducer: "<<obj2.getProducer()
        <<"\tDirector: "<<obj2.getDirector()<<"\tWriter: "<<obj2.getWriter()
        <<"\tProductionDes: "<<obj2.getProductionDesigner()
        <<"\tCostumeDes: "<<obj2.getCostumeDesigner()<<"\tSetDecorator: "<<obj2.getSetDecorator()
        <<"\tEditor: "<<obj2.getEditor()<<"\tCast: ";

        locs= obj2.getCast();
        for(int i=0; i<locs.size(); i++){
            file<<locs[i]<<" ";
        }

        locs.clear(); locs.resize(0); locs.shrink_to_fit();

        file<<"\tWeeklySale: "<<obj.getWeeklyTicketSale();

        if(obj.getMaterials()!= NULL){ //if materials exist
            Materials *mtrls= obj.getMaterials();
            file<<"\tMaterials: ";
            if(mtrls->getBlueRay()!= NULL){ //if blueray exists
                BlueRay br= *(mtrls->getBlueRay()); //derefer blueray

                file<<"BlueRay: ";
                file<<"Title: "<<br.getTitle()<<"\tId: "<<br.getID()
                <<"\tFormat: "<<br.getFormat()<<"\tAudio: "<<br.getAudioFormat()
                <<"\tFrame: "<<br.getFrameAspect()<<"\tLanguage: ";

                locs= br.getLanguage();
                for(int i=0; i<locs.size(); i++)
                    file<<locs[i]<<" ";

                locs.clear(); locs.resize(0); locs.shrink_to_fit();

                //subs
                locs= br.getSubs();
                file<<"Subs: ";
                for(int i=0; i<locs.size(); i++)
                    file<<locs[i]<<" ";

                locs.clear(); locs.resize(0); locs.shrink_to_fit();

                file<<"\tRuntime: "<<br.getRunTime()
                <<"\tPrice: "<<br.getRetailPrice()
                <<"\tBonus: "<<br.hasBonusFeatures();
            }
            if(mtrls->getSingleDVD()!= NULL){
                SingleSDVD sd= *(mtrls->getSingleDVD());

                file<<"\tSingleSDVD: ";
                file<<"Title: "<<sd.getTitle()<<"\tId: "<<sd.getID()
                <<"\tFormat: "<<sd.getFormat()<<"\tAudio: "<<sd.getAudioFormat()
                <<"\tFrame: "<<sd.getFrameAspect()<<"\tLanguage: ";

                locs= sd.getLanguage();
                for(int i=0; i<locs.size(); i++)
                    file<<locs[i]<<" ";

                locs.clear(); locs.resize(0); locs.shrink_to_fit();

                locs= sd.getSubs();
                file<<"Subs: ";
                for(int i=0; i<locs.size(); i++)
                    file<<locs[i]<<" ";

                locs.clear(); locs.resize(0); locs.shrink_to_fit();

                file<<"\tRuntime: "<<sd.getRunTime()
                <<"\tPrice: "<<sd.getRetailPrice()
                <<"\tBonus: "<<sd.hasBonusFeatures();
            }
            if(mtrls->getDoubleDVD() != NULL){
                DoubleSDVD dd= *(mtrls->getDoubleDVD());

                file<<"\tDoubleSDVD: ";
                file<<"Title: "<<dd.getTitle()<<"\tId: "<<dd.getID()
                <<"\tFormat: "<<dd.getFormat()<<"\tAudio: "<<dd.getAudioFormat()
                <<"\tFrame: "<<dd.getFrameAspect()<<"\tLanguage: ";

                locs= dd.getLanguage();
                for(int i=0; i<locs.size(); i++)
                    file<<locs[i]<<" ";

                locs.clear(); locs.resize(0); locs.shrink_to_fit();

                locs= dd.getSubs();
                file<<"Subs: ";
                for(int i=0; i<locs.size(); i++)
                    file<<locs[i]<<" ";

                locs.clear(); locs.resize(0); locs.shrink_to_fit();

                file<<"\tRuntime: "<<dd.getRunTime()
                <<"\tPrice: "<<dd.getRetailPrice()
                <<"\tBonus: "<<dd.hasBonusFeatures()
                <<"\tSide1: "<<dd.getSide1()
                <<"\tSide2: "<<dd.getSide2();
            }
            if(mtrls->getVHS()!= NULL){
                VHS vh= *(mtrls->getVHS());

                file<<"\tVHS: ";
                file<<"Title: "<<vh.getTitle()<<"\tId: "<<vh.getID()
                <<"\tFormat: "<<vh.getFormat()<<"\tAudio: "<<vh.getAudioFormat()
                <<"\tFrame: "<<vh.getFrameAspect()<<"\tLanguage: "<<vh.getLanguage()
                <<"\tSubs: "<<vh.getSubs()<<"\tRuntime: "<<vh.getRunTime()
                <<"\tPrice: "<<vh.getRetailPrice()
                <<"\tPackaging: "<<vh.getPackaging();
            }
            if(mtrls->getComboBox()!= NULL){
                ComboBox cb= *(mtrls->getComboBox());

                file<<"\tCombo: ";
                //just tell how many DVDs are there

                if(cb.hasSDVDs()){
                    file<<cb.getsDVDs()<<" ";
                }
                else file<<0<<" ";


                if(cb.hasDDVDs()){
                    file<<cb.getdDVDs()<<" ";
                }
                else file<<0;
            }
        }
        file<<endl;
        iterate= iterate->next;
    }
    file.close();
    return true;
}

bool Controller::readData(){
    ifstream file("data.txt");

    string title, genre, summary, language, status, release_date, producer, director,
    writer, production_designer, costume_designer, set_decorator, editor;
    vector<string> locations, keywords, cast;
    short run_time;
    int weekly_sale= 0;

    if(file.is_open()){

        string tmp="";
        bool isKey= 0; //to check if a key is present

        file>>tmp;
        if(tmp=="") return false;

        while(!file.eof()){
            //the first string is the key, we want value. So we store key in tmp
            file>>title>>tmp>>genre;

            //summary
            summary="";
            file>>tmp;
            while(tmp!= "Language:"){
                file>>tmp;
                if(tmp == "Language:") break; /*After reading the whole summary, the first thing read is
                "Language:"*/

                summary+=tmp;
            }

            file>>language>>tmp>>status>>tmp>>release_date>>tmp;

            //locations
            while(tmp!= "Keywords:"){
                file>>tmp;
                if(tmp == "Keywords:") break;

                locations.push_back(tmp);
            }

            //reading keywords. the key is already in tmp from previous iterations
            tmp="";
            while(tmp!= "Runtime:"){
                file>>tmp;
                if(tmp == "Runtime:") break;

                keywords.push_back(tmp);
            }

            file>>run_time;

            //crew
            file>>tmp>>producer>>tmp>>director>>tmp>>writer>>
            tmp>>production_designer>>tmp>>costume_designer>>
            tmp>>set_decorator>>tmp>>editor;

            file>>tmp>>tmp; /* reading Cast. Materials may or may not be there. Might be the last
            entry in the database */

            while(!file.eof()){
                //first cast member is already in tmp. else, the key or null would be push_backed
                cast.push_back(tmp);
                file>>tmp;
                if(tmp == "WeeklySale:"){
                    break;
                }
            }

            file>>weekly_sale>>tmp; //weekly sale
            if(tmp == "Materials:") isKey= 1;

            /*push data before proceeding to materials, they may or may not exist and have a different set method
             and set into the node directly, rather than the with the model*/
            Crew crew;
            crew.setData(producer, director, writer, production_designer, costume_designer,
                         set_decorator, editor, cast);

            setData(title, genre, summary, language, status, release_date,
                          locations, keywords, run_time, weekly_sale, crew);

            locations.clear(); locations.resize(0); locations.shrink_to_fit();
            keywords.clear(); keywords.resize(0); keywords.shrink_to_fit();
            cast.clear(); cast.resize(0); cast.shrink_to_fit();

            //materials
            if(isKey){
                string title_, Id, format, audio_format, frame_aspect, packaging, side1, side2;
                vector<string> language_, subs;
                short run_time_;
                float retail_price;
                bool bonus_features;

                Materials *mtrls= new Materials;
                int s= 0;// store size
                //reset
                isKey= 0;

                file>>tmp; //BlueRay or SingleSDVD or DoubleSDVD or VHS or ComboBox

                while(!file.eof()){
                    language_.clear(); language_.resize(0); language_.shrink_to_fit();
                    subs.clear(); subs.resize(0); subs.shrink_to_fit();

                    if(tmp== "Title:") break;

                    if(tmp== "BlueRay:"){
                         file>>tmp>>title_>>tmp>>Id>>tmp>>format>>tmp>>audio_format
                         >>tmp>>frame_aspect>>tmp;

                        //language
                         while(1){
                            file>>tmp;
                            if(tmp == "Subs:") break;
                            language_.push_back(tmp);
                         }
                         //subs
                         while(1){
                            file>>tmp;
                            if(tmp == "Runtime:") break;
                            subs.push_back(tmp);
                         }

                         file>>run_time_>>tmp>>retail_price>>tmp>>bonus_features>>tmp;

                         BlueRay *blue= new BlueRay;
                         blue->setData(title_, Id, format, audio_format, frame_aspect,
                                       language_, subs, run_time_, retail_price, bonus_features);

                         mtrls->setBlueRay(blue); /*set materials along way to be able to use same variables
                         for other variables*/
                    }

                    else if(tmp== "SingleSDVD:"){
                         file>>tmp>>title_>>tmp>>Id>>tmp>>format>>tmp>>audio_format
                         >>tmp>>frame_aspect>>tmp;

                        //language
                         while(tmp!= "Subs:"){
                            file>>tmp;
                            if(tmp == "Subs:") break;
                            language_.push_back(tmp);
                         }
                         //subs
                         while(tmp!= "Runtime:"){
                            file>>tmp;
                            if(tmp == "Runtime:") break;
                            subs.push_back(tmp);
                         }

                         file>>run_time_>>tmp>>retail_price>>tmp>>bonus_features>>tmp;

                         SingleSDVD *single= new SingleSDVD;
                         single->setData(title_, Id, format, audio_format, frame_aspect,
                                       language_, subs, run_time_, retail_price, bonus_features);

                         mtrls->setSingleDVD(single);
                     }
                     else if(tmp== "DoubleSDVD:"){

                         file>>tmp>>title_>>tmp>>Id>>tmp>>format>>tmp>>audio_format
                         >>tmp>>frame_aspect>>tmp;

                        //language
                         while(tmp!= "Subs:"){
                            file>>tmp;
                            if(tmp == "Subs:") break;
                            language_.push_back(tmp);
                         }
                         //subs
                         while(tmp!= "Runtime:"){
                            file>>tmp;
                            if(tmp == "Runtime:") break;
                            subs.push_back(tmp);
                         }

                         file>>run_time_>>tmp>>retail_price>>tmp>>bonus_features>>tmp>>side1>>tmp>>side2>>tmp;

                         DoubleSDVD *doubled= new DoubleSDVD;
                         doubled->setData(title_, Id, format, audio_format, frame_aspect,
                                       language_, subs, side1, side2, run_time_, retail_price, bonus_features);

                         mtrls->setDoubleDVD(doubled);
                     }
                     else if(tmp== "VHS:"){
                         string lang, sub;

                         file>>tmp>>title_>>tmp>>Id
                         >>tmp>>format>>tmp>>audio_format
                         >>tmp>>frame_aspect>>tmp>>lang
                         >>tmp>>sub>>tmp>>run_time_
                         >>tmp>>retail_price>>tmp>>packaging>>tmp;

                         VHS *vhs= new VHS;
                         vhs->setData(title_, Id, format, audio_format, frame_aspect,
                                       lang, sub, packaging, run_time_, retail_price);

                         mtrls->setVHS(vhs);
                     }
                     else if(tmp == "Combo:"){
                         file>>s;

                         ComboBox *cmbx= new ComboBox;
                         cmbx->setSDvds(s);

                         file>>s>>tmp;
                         cmbx->setDDvds(s);

                         mtrls->setComboBox(cmbx);
                     }

                }//while materials being read
                setMaterials(title, mtrls);
            }//if materials exist
        }//while(!file.eof())
    }//if file open

    else{
        cerr<<"Error: File could not be opened\n";
        return false;
    }
    file.close();
    return true;
}

void Controller::populateQueue(){ //insert data to queue. Only model inserted without ticket sale and materials
    q.insert(model, q.head);
}

void Controller::setData(string title, string genre, string summary, string language,
                    string status, string release_date, vector<string> locations,
                    vector<string> keywords, short run_time, int weekly_sale,
                    Crew crew){

    model.setTitle(title);
    model.setGenre(genre);
    model.setSummary(summary);
    model.setLanguage(language);
    model.setStatus(status);
    model.setReleaseDate(release_date);
    model.setLocations(locations);
    model.setKeywords(keywords);
    model.setRunTime(run_time);
    model.setCrew(crew);
    model.setWeeklyTicketSale(weekly_sale);

    populateQueue();
}

void Controller::removeProject(node *n, string title){
    node * tmp= q.searchByTitle(title, q.head);
    if (tmp == NULL){
        cerr<<"Error: No such project\n";
        return;
    }

    if(tmp == q.tail) q.remove(n); //if last node, call simple remove

    else if(tmp == n){ /*if node is head, make next one head, link it to the tail*/
        if(q.head->next == q.tail){ /* if there were only 2 nodes to begin with, then the remaining one, after
                removing a node, will be the head AND the tail*/
            q.head= q.tail;
            q.head->prev= q.tail;
            q.head->next= q.tail;

            q.tail->prev= q.tail;
            q.tail->next= q.tail;
        }

        q.head= q.head->next;
        q.head->prev= q.tail;

        delete tmp;
    }

    else{ //node is somewhere in between
        node *temp= new node;
        node *iterate= q.head;

        while(iterate->next != tmp) iterate= iterate->next; //node behind tmp

        temp= tmp->next; //node infront of tmp;

        iterate->next= temp;
        temp->prev= iterate;
    }
}

void Controller::inflateMenu(string menu){
    if(menu == "main")
        view.menuMain();

    else if(menu == "update_project")
        view.menuUpdateProject();

    else if(menu == "update_materials")
        view.menuUpdateMaterials();
}

void Controller::onLoad(){
    readData();
    log.setPSize(q.size);

    char choice;

    while(1){
        system("cls");
        inflateMenu("main");
        cin>>choice;

        if(choice == '1'){ //catalog
            int key;
			string title="";
            node *iterate= q.head;

            while(1){
                system("cls");
                view.printStatement("\t\t\tCatalog\n\n");
                view.printStatement("Press 'w' for next, press 'q' for previous\n");

				try {
					if (iterate == NULL) throw 0;
				}
				catch(int e){
					break;
				}

				title = iterate->model.getTitle();
                showProjectByTitleAndSummary(title);
                view.printStatement("\nPress 0 to exit");
                key= _getch();

                if(key == 119) iterate= iterate->next; // w

                else if(key == 113) iterate= iterate->prev; // q

                else if(key == 48) break; // 0
            }
        } //catalog

        else if(choice == '2'){ // create new project
            Crew crew;
            string title, genre, summary, language, release_date, producer, director,
            writer, production_designer, costume_designer, set_decorator, editor;
            vector<string> locations, keywords, cast;
            short run_time;

            cout<<"Enter Project Title: "; cin>>title;
            cout<<"Enter Project Genre: "; cin>>genre;
            cout<<"Enter Project Summary: "; cin.ignore(); std::getline(cin, summary);
            cout<<"Enter Project Language: "; cin>>language;
            cout<<"Enter Project Release Date: "; cin>>release_date;
            cout<<"Enter Project Locations (Enter 'e' To End): ";
            for(int i=0;;i++){
                string tmp;
                cin>>tmp;
                if(tmp != "e")
                    locations.push_back(tmp);
                else break;
            }

            cout<<"Enter Project Keywords (Enter 'e' To End): ";
            for(int i=0;;i++){
                string tmp;
                cin>>tmp;
                if(tmp != "e")
                    keywords.push_back(tmp);
                else break;
            }

            cout<<"Enter Project Run Time (mins): "; cin>>run_time;

            //crew
            cout<<"Enter Project Producer: "; cin>>producer;
            cout<<"Enter Project Director: "; cin>>director;
            cout<<"Enter Project Writer: "; cin>>writer;
            cout<<"Enter Project Production Designer: "; cin>>production_designer;
            cout<<"Enter Project Costume Designer: "; cin>>costume_designer;
            cout<<"Enter Project Set Decorator: "; cin>>set_decorator;
            cout<<"Enter Project Editor: "; cin>>editor;
            cout<<"Enter Project Cast(Enter 'e' To End): ";
            for(int i=0;;i++){
                string tmp;
                cin>>tmp;
                if(tmp != "e")
                    cast.push_back(tmp);
                else break;
            }
            crew.setData(producer, director, writer, production_designer, costume_designer,
                         set_decorator, editor, cast);

            setData(title, genre, summary, language, "unreleased", release_date, locations, //new project always unreleased
                    keywords, run_time, 0, crew);

            locations.clear(); locations.resize(0); locations.shrink_to_fit();
            keywords.clear(); keywords.resize(0); keywords.shrink_to_fit();
            cast.clear(); cast.resize(0); cast.shrink_to_fit();

        }// if new project

        else if(choice == '3'){ //project and material details
            string title;
            cout<<"Enter Project Name: "; cin>>title;
            showProjectByTitleAndDetail(title);

            cout<<"\n0. Exit\n";
            cin>>title; //wait
        } // project and material details

        else if(choice == '4'){ //project and materials summary
            string title;
            cout<<"Enter Project Name: "; cin>>title;
            showProjectByTitleAndSummary(title);

            cout<<"\n0. Exit\n";
            cin>>title; //wait
        } //project and materials summary

        else if( choice == '5'){ //search by cast
            string name;
            cout<<"Enter Cast Name: "; cin>>name;

            showProjectsByCast(name, q.head);
        } //search by cast

        else if(choice == '6'){ //update project
            updateProject();
        } //update project

        else if(choice == '7'){ //delete project
            string title;
            cout<<"Enter Project Name: "; cin>>title;

            removeProject(q.head, title);
        } //delete project

        else if(choice == '0'){ //exit
            log.setNSize(q.size); //set new size of queue

            log.projectCount();

            writeData(); //all the data changes are written at the moment of exit

            view.printStatement("Enter any key to continue");
            _getch();
            break;
        } //exit the program
    }
}

void Controller::setMaterials(string title, Materials * materials){ /* find the project in queue and set materials
    to it*/
    node *tmp= new node;
    tmp= q.searchByTitle(title, q.head);

    if(tmp == NULL){
        return;
    }

    //set only if project is released
    if(tmp->model.getStatus() != "released"){
        cerr<<"Project not released yet. Cannot set materials\n";
        return;
    }

    tmp->model.setMaterials(materials);
}

void Controller::updateProject(){
    string title;
    cout<<"Enter Project Name: "; cin>>title;

    node *tmp = new node;
    tmp= q.searchByTitle(title, q.head);

    if(!tmp) cerr<<"No such project\n";

    else{
        char choice;
        while(1){
            system("cls");
            inflateMenu("update_project");
            cin>>choice;

            if(choice == '1'){ //edit existing info

                string title, genre, summary, language, release_date, producer, director,
                writer, production_designer, costume_designer, set_decorator, editor;
                vector<string> locations, keywords, cast;
                short run_time;

                cout<<"Enter Project Title: "; cin>>title;
                cout<<"Enter Project Genre: "; cin>>genre;
                cout<<"Enter Project Summary: "; cin.ignore(); std::getline(cin, summary);
                cout<<"Enter Project Language: "; cin>>language;
                cout<<"Enter Project Release Date: "; cin>>release_date;
                cout<<"Enter Project Locations (Enter 'e' To End): ";
                for(int i=0;;i++){
                    string tmp;
                    cin>>tmp;
                    if(tmp != "e")
                        locations.push_back(tmp);
                    else break;
                }

                cout<<"Enter Project Keywords (Enter 'e' To End): ";
                for(int i=0;;i++){
                    string tmp;
                    cin>>tmp;
                    if(tmp != "e")
                        keywords.push_back(tmp);
                    else break;
                }

                cout<<"Enter Project Run Time (mins): "; cin>>run_time;

                //crew
                cout<<"Enter Project Producer: "; cin>>producer;
                cout<<"Enter Project Director: "; cin>>director;
                cout<<"Enter Project Writer: "; cin>>writer;
                cout<<"Enter Project Production Designer: "; cin>>production_designer;
                cout<<"Enter Project Costume Designer: "; cin>>costume_designer;
                cout<<"Enter Project Set Decorator: "; cin>>set_decorator;
                cout<<"Enter Project Editor: "; cin>>editor;
                cout<<"Enter Project Cast(Enter 'e' To End): ";
                for(int i=0;;i++){
                    string tmp;
                    cin>>tmp;
                    if(tmp != "e")
                        cast.push_back(tmp);
                    else break;
                }
                Crew crew;
                crew.setData(producer, director, writer, production_designer, costume_designer,
                             set_decorator, editor, cast);

                tmp->model.getLanguage().clear(); tmp->model.getLocations().clear();

                tmp->model.setData(title, genre, summary, language, release_date, locations, keywords, run_time, crew);

                locations.clear(); locations.resize(0); locations.shrink_to_fit();
                keywords.clear(); keywords.resize(0); keywords.shrink_to_fit();
                cast.clear(); cast.resize(0); cast.shrink_to_fit();
            } //edit project. Not materials, ticket sale or status

            else if(choice == '2'){ //edit status
                view.printStatement("Enter Status (unreleased, running, released): ");
                cin>>title;

                tmp->model.setStatus(title); //new status
            } //edit status

            else if(choice == '3'){ //edit sale
                if(tmp->model.getStatus() == "unreleased"){ //cant proceed if project is unreleased
                    cerr<<"Error: Project unreleased. Can't set ticket sale\n";

                    view.printStatement("0. Exit");
                    cin>>title;
                }
                else{
                    view.printStatement("Enter Sale: ");
                    int sale; cin>>sale;

                    tmp->model.setWeeklyTicketSale(sale);
                }
            } //edit sale

            else if(choice == '4'){ //update materials
                if(tmp->model.getStatus() != "released"){ //cant proceed if project not released
                    cerr<<"Error: Project not released. Can't update materials\n";

                    view.printStatement("0. Exit");
                    cin>>title;
                }

                else updateMaterials(tmp);
                } //update materials

            else if(choice == '0')
                break;
        } //exit project update menu into the main menu
    }
}

void Controller::updateMaterials(node * tmp){
    Materials *materials= new Materials;
    char choice;

    while(1){
        system("cls");
        inflateMenu("update_materials");
        cin>>choice;

        if(choice == '1'){ //add materials
            addMaterials(tmp);
        } // add materials

        else if(choice == '2'){ //remove materials
            materials->setBlueRay(NULL);
            materials->setSingleDVD(NULL);
            materials->setDoubleDVD(NULL);
            materials->setVHS(NULL);
            materials->setComboBox(NULL);

            tmp->model.setMaterials(NULL);
        }

        else if(choice == '3'){ //update materials. just delete previous materials and set new ones
            materials->setBlueRay(NULL);
            materials->setSingleDVD(NULL);
            materials->setDoubleDVD(NULL);
            materials->setVHS(NULL);
            materials->setComboBox(NULL);

            addMaterials(tmp);
        }

        else if(choice == '0') //exit into update project menu
            break;

    } //while true
}

void Controller::addMaterials(node *tmp){
    Materials *mtrls= new Materials;
    string temp, title_, Id, format, audio_format, frame_aspect, side1, side2, packaging;
    short run_time_;
    float retail_price;
    bool bonus_features;
    vector<string> language_, subs;

    bool exists[5];
    // ask user which materials exist and which not
            view.printStatement("Enter 1 if a material exists, 0 otherwise");

            cout<<"BlueRay?: ";    cin>>exists[0];
            cout<<"Single DVD?: "; cin>>exists[1];
            cout<<"Double DVD?: "; cin>>exists[2];
            cout<<"VHS?: ";        cin>>exists[3];
            cout<<"Combo Box?: ";  cin>>exists[4];

            if(exists[0]){ //blueray
                cout<<"Enter BlueRay Title: "; cin>>title_;
                cout<<"Enter ID: ";            cin>>Id;
                cout<<"Enter Format: ";        cin>>format;
                cout<<"Enter Audio Format: ";  cin>>audio_format;
                cout<<"Enter Frame Aspect: ";  cin>>frame_aspect;

                cout<<"Enter Languages (Enter 'e' To End): ";

                while(1){
                    cin>>temp;
                    if( temp != "e") language_.push_back(temp);
                    else break;
                }

                cout<<"Enter Subs (Enter 'e' To End): ";

                while(1){
                    cin>>temp;
                    if( temp != "e") subs.push_back(temp);
                    else break;
                }

                cout<<"Enter Runtime (mins): ";          cin>>run_time_;
                cout<<"Enter Retail Price: ";            cin>>retail_price;
                cout<<"Has Bonus Features?: (1 or 0): "; cin>>bonus_features;

                BlueRay *blue= new BlueRay;
                blue->setData(title_, Id, format, audio_format, frame_aspect, language_, subs, run_time_, retail_price,
                              bonus_features);

                mtrls->setBlueRay(blue);

                language_.clear(); language_.resize(0); language_.shrink_to_fit();
                subs.clear(); subs.resize(0); subs.shrink_to_fit();
            } //if blueray
            else mtrls->setBlueRay(NULL);

            if(exists[1]){ //Single dvd
                cout<<"Enter Single DVD Title: "; cin>>title_;
                cout<<"Enter ID: ";               cin>>Id;
                cout<<"Enter Format: ";           cin>>format;
                cout<<"Enter Audio Format: ";     cin>>audio_format;
                cout<<"Enter Frame Aspect: ";     cin>>frame_aspect;

                cout<<"Enter Languages (Enter 'e' To End): ";

                while(1){
                    cin>>temp;
                    if( temp != "e") language_.push_back(temp);
                    else break;
                }

                cout<<"Enter Subs (Enter 'e' To End): ";

                while(1){
                    cin>>temp;
                    if( temp != "e") subs.push_back(temp);
                    else break;
                }

                cout<<"Enter Runtime (mins): ";          cin>>run_time_;
                cout<<"Enter Retail Price: ";            cin>>retail_price;
                cout<<"Has Bonus Features?: (1 or 0): "; cin>>bonus_features;

                SingleSDVD *single= new SingleSDVD;
                single->setData(title_, Id, format, audio_format, frame_aspect, language_, subs, run_time_, retail_price,
                              bonus_features);

                mtrls->setSingleDVD(single);

                language_.clear(); language_.resize(0); language_.shrink_to_fit();
                subs.clear(); subs.resize(0); subs.shrink_to_fit();
            } // Single dvd
            else mtrls->setSingleDVD(NULL);

            if(exists[2]){ //Double dvd
                cout<<"Enter Double DVD Title: ";  cin>>title_;
                cout<<"Enter ID: ";                cin>>Id;
                cout<<"Enter Format: ";            cin>>format;
                cout<<"Enter Audio Format: ";      cin>>audio_format;
                cout<<"Enter Frame Aspect: ";      cin>>frame_aspect;

                cout<<"Enter Languages (Enter 'e' To End): ";

                while(1){
                    cin>>temp;
                    if( temp != "e") language_.push_back(temp);
                    else break;
                }

                cout<<"Enter Subs (Enter 'e' To End): ";

                while(1){
                    cin>>temp;
                    if(temp != "e") subs.push_back(temp);
                    else break;
                }

                cout<<"Enter Side 1 (movie, extra, empty): "; cin>>side1;
                cout<<"Enter Side 2 (movie, extra, empty): "; cin>>side2;
                cout<<"Enter Runtime (mins): ";               cin>>run_time_;
                cout<<"Enter Retail Price: ";                 cin>>retail_price;
                cout<<"Has Bonus Features?: (1 or 0): ";      cin>>bonus_features;

                DoubleSDVD *double_= new DoubleSDVD;
                double_->setData(title_, Id, format, audio_format, frame_aspect, language_, subs, side1, side2,
                                 run_time_, retail_price, bonus_features);

                mtrls->setDoubleDVD(double_);

                language_.clear(); language_.resize(0); language_.shrink_to_fit();
                subs.clear(); subs.resize(0); subs.shrink_to_fit();
            } //double dvd
            else mtrls->setDoubleDVD(NULL);

            if(exists[3]){ //vhs
                string lang, sub;

                cout<<"Enter VHS Title: ";     cin>>title_;
                cout<<"Enter ID: ";            cin>>Id;
                cout<<"Enter Format: ";        cin>>format;
                cout<<"Enter Audio Format: ";  cin>>audio_format;
                cout<<"Enter Frame Aspect: ";  cin>>frame_aspect;
                cout<<"Enter Language: ";      cin>>lang;
                cout<<"Enter Subs: ";          cin>>sub;
                cout<<"Enter Runtime (mins): ";cin>>run_time_;
                cout<<"Enter Retail Price: ";  cin>>retail_price;
                cout<<"Enter Packaging: ";     cin>>packaging;

                VHS *vhs= new VHS;
                vhs->setData(title_, Id, format, audio_format, frame_aspect, lang, sub, packaging, run_time_,
                             retail_price);

                mtrls->setVHS(vhs);
            } //vhs
            else mtrls->setVHS(NULL);

            if(exists[4]){ //combo box
                int sdvd, ddvd;
                cout<<"Enter Number of Single DVDs: "; cin>>sdvd;
                cout<<"Enter Number of Double DVDs: "; cin>>ddvd;

                ComboBox *cmbx= new ComboBox;
                cmbx->setSDvds(sdvd);
                cmbx->setDDvds(ddvd);

                mtrls->setComboBox(cmbx);
            } //combo box
            else mtrls->setComboBox(NULL);

            setMaterials(tmp->model.getTitle(), mtrls);
}
