#include "Log.h"

//logged to console every time software is exited
void Log::setNSize(int size){
    nsize= size;
}

void Log::setPSize(int size){
    psize= size;
}

int Log::getNSize(){ return nsize; }

int Log::getPSize(){ return psize; }

int Log::calcDifference(){
    return nsize - psize;
}

void Log::projectCount(){
    calcDifference();

    if(diff > 0){
        cout<<"New projects added: "<<diff<<endl;
    }
    else if(diff < 0){
        cout<<"Projects removed: "<<diff<<endl;
    }
}

bool Log::projectsEarning(int sale){
    if(sale >= SALE_BENCHMARK) return true;
    return false;
}
