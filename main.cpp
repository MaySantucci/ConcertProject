#include "HandleConcert.h"
#include "UserFunctions.h"
#include <iostream>

int main(int argc, char const *argv[])
{

    char input [100];
    std::string in;
    UserFunctions *user = new UserFunctions();

    while(true) {

        std::cout << "Hello, choose one of the following actions: \n" <<
        "\t (1) - list - List all events. \n" <<
        "\t (2) - details - List details of a event. \n" <<
        "\t (3) - insert - Insert event. \n" <<
        "\t (4) - update - Update event. \n" <<
        "\t (5) - delete - Delete event. \n" <<
        "\t (6) - star - Add preferred event. \n"<<
        "\t (7) - unstar - Remove preferred event. \n" <<
        "\t (8) - listar - List all preferred event. \n"
        "\t (9) - exit - Close the app. \n" ;

        std::cout << "Please enter your choice: ";

        std::cin >> input;
        in = std::string(input);

        if (in == "list" || in == "1") {
            std::cout << "\t (1) - List all events. \n";
            user->listEvents();
        } 
        else if (in == "details" || in == "2") {
           std::cout << "\t (2) - List details of a event. \n";  
            /*
             if(user->checkConcertsInit()){
                std::cout << "No concert stored. \n";
            } else {
                std::string id_sting;
                int id;
                std::cout << "Id: " ;
                std::cin >> id_sting;
                try {                    
                    id = stoi(id_sting);             
                    user->detailsConcert(id); 
                } catch (std::invalid_argument) {
                    std::cout << "Invalid id. Print a number. \n";
                }
           }
           */
          
        } 
        else if (in == "insert" || in == "3") {
            std::cout << "\t (3) - Insert event. \n";
            
    std::cout << "What kind of event do you want add? \n" <<
                "\t(a) - Show; \n" <<
                "\t(b) - Ballet; \n" <<
                "\t(c) - Concert. \n";   

                std::string kind_event;

                std::cin >> kind_event;

                if(kind_event == "a" || kind_event == "b" || kind_event == "c") {
                    user->insertEvent(kind_event);
                } else {
                    std::cout << "Kind of event not valid. \n";
                }
        } 
        else if (in == "update" || in == "4") {
            std::cout << "\t (4) - Update event. \n";
            /*
             if(user->checkConcertsInit()){
                std::cout << "No concert stored. \n";
           } else {
                std::string id_sting;
                int id;
                std::cout << "Id: " ;
                std::cin >> id_sting;
                try {                    
                    id = stoi(id_sting);             
                    user->updateConcert(id); 
                } catch (std::invalid_argument) {
                    std::cout << "Invalid id. Print a number. \n";
                }
           }
           */
        } 
        else if (in == "delete" || in == "5") {
            std::cout << "\t (5) - Delete event. \n";
            /*
            if (!(user->checkConcertsInit())) {
                std::string id_sting;
                int id;
                std::cout << "Id: " ;
                std::cin >> id_sting;
                try {                    
                    id = stoi(id_sting);      

                    user->deleteConcert(id);

                } catch (std::invalid_argument) {
                    std::cout << "Invalid id. Print a number. \n";
                }

            } else {
                std::cout << "No concerts. \n";
            } */
        } 
        else if (in == "star" || in == "6") {
            std::cout << "\t (6) - Add preferred event. \n";
            /*
            if (!(user->checkConcertsInit())) {
                std::string id_sting;
                int id;
                std::cout << "Id: " ;
                std::cin >> id_sting;
                try {                    
                    id = stoi(id_sting);          

                    user->insertPreferred(id);

                } catch (std::invalid_argument) {
                    std::cout << "Invalid id. Print a number. \n";
                }

            } else {
                std::cout << "No concerts. \n";
            }
            */
        } 
        else if (in == "unstar" || in == "7") {
            std::cout << "\t (7) - Remove preferred event. \n";
            /*
            if (!(user->checkPreferredInit())) {
                std::string id_sting;
                int id;
                std::cout << "Id: " ;
                std::cin >> id_sting;
                try {                    
                    id = stoi(id_sting);      

                    user->deletePreferred(id);

                } catch (std::invalid_argument) {
                    std::cout << "Invalid id. Print a number. \n";
                }

            } else {
                std::cout << "No concerts. \n";
            }
            */
        } 
        else if (in == "listar" || in == "8") {
            std::cout << "\t (8) - List all preferred event. \n";
           // user->listPreferredConcerts();
        } 
        else if (in == "exit" || in == "9") {
            std::cout << "\t (9) - Close the app. \n";
            break;
        } 
        else {
            std::cout << "\t Command not valid. \n";
        }
    }

    return 0;
}
