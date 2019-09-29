#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED
#include "Controller.h"

class Tests{
        Model m;
        View v;
        Controller *c;

        bool test1();
        bool test2();
        bool test3();
        bool test4();

    public:
        Tests();

        bool run(); //run all the tests
};

#endif // TESTS_H_INCLUDED
