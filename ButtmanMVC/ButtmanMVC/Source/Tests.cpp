#include "Tests.h"

Tests::Tests(){
    c= new Controller(m,v);
}

bool Tests::test1(){ return c->readData();}

bool Tests::test2(){ return c->showProjectByTitleAndDetail("batman");}

bool Tests::test3(){ return c->showProjectByTitleAndSummary("hotchpotch");}

bool Tests::test4(){ return c->writeData();}

bool Tests::run(){ //if all tests are successful, return true
    try{
        if(!test1()) throw 0;
        if(!test2()) throw 0;
        if(!test3()) throw 0;
        if(!test4()) throw 0;

        return true;
    }
    catch(int x){
        cerr<<"Test failed\n";
        return false;
    }
}
