#ifndef LOG_H_INCLUDED
#define LOG_H_INCLUDED
#include <iostream>
using std::cout;
using std::endl;

class Log{
    int psize= 0; //size at time of loading data from db
    int nsize= 0; //size at time of writing data to db
    int diff= 0; //difference b/w 2 sizes
    const int SALE_BENCHMARK= 200; //projects with specific amount of total earnings
    int calcDifference();

public:

    void setPSize(int);

    void setNSize(int);

    int getPSize();

    int getNSize();

    void projectCount();

    bool projectsEarning(int); //see if a projects meets high earnings criteria
};

#endif // LOG_H_INCLUDED
