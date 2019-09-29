#include "Tests.h" //class Controller.h is included in this file

int main (void){
    Model model;
    View view;
    Controller controller(model, view);

    cout<<"Reading Data...\n";
    controller.onLoad();

    //Run tests
//    Tests t;
//    if(t.run()){
//        system("cls");
//        cout<<"Tests Successful\n";
//    }
}
