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
        "\t (1) - list - List all concerts. \n" <<
        "\t (2) - details - List details of a concert. \n" <<
        "\t (3) - insert - Insert concert. \n" <<
        "\t (4) - update - Update concert. \n" <<
        "\t (5) - delete - Delete concert. \n" <<
        "\t (6) - star - Add prefered concert. \n"<<
        "\t (7) - unstar - Remove prefered concert. \n" <<
        "\t (8) - listar - List all prefered concerts. \n"
        "\t (9) - exit - Close the app. \n" ;

        std::cout << "Please enter your choice: ";

        std::cin >> input;
        in = std::string(input);

        if (in == "list" || in == "1") {
            std::cout << "\t (1) - List all concerts. \n";
            user->listConcerts();
        } 
        else if (in == "details" || in == "2") {
           std::cout << "\t (2) - List details of a concert. \n";   
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
          
        } 
        else if (in == "insert" || in == "3") {
            std::cout << "\t (3) - Insert concert. \n";         
            user->insertConcert();
        } 
        else if (in == "update" || in == "4") {
            std::cout << "\t (4) - Update concert. \n";
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
        } 
        else if (in == "delete" || in == "5") {
            std::cout << "\t (5) - Delete concert. \n";
            
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
            }
        } 
        else if (in == "star" || in == "6") {
            std::cout << "\t (6) - Add prefered concert. \n";
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
        } 
        else if (in == "unstar" || in == "7") {
            std::cout << "\t (7) - Remove prefered concert. \n";
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
        } 
        else if (in == "listar" || in == "8") {
            std::cout << "\t (8) - List all prefered concerts. \n";
            user->listPreferredConcerts();
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
