#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <time.h>

std::vector<std::pair<std::string, std::string> > allCards;

void init() {
    // Mexico
    allCards.push_back(std::make_pair("Mexico", "Mexico City"));

    // Central America
    allCards.push_back(std::make_pair("Belize", "Belmopan"));
    allCards.push_back(std::make_pair("Guatamala", "Guatamala City"));
    allCards.push_back(std::make_pair("Honduras", "Tegucigalpa"));
    allCards.push_back(std::make_pair("Nicaragua", "Managua"));
    allCards.push_back(std::make_pair("El Salvador", "San Salvador"));
    allCards.push_back(std::make_pair("Costa Rica", "San Jose"));
    allCards.push_back(std::make_pair("Panama", "Panama City"));

    // Greater Antilles
    allCards.push_back(std::make_pair("Cuba", "Havana"));
    allCards.push_back(std::make_pair("Haiti", "Port-au-Prince"));
    allCards.push_back(std::make_pair("Dominican Republic", "Santo Domingo"));
    allCards.push_back(std::make_pair("Puerto Rico", "San Juan"));
    allCards.push_back(std::make_pair("Jamaica", "Kingston"));

    // Andean Country
    allCards.push_back(std::make_pair("Columbia", "Bogata"));
    allCards.push_back(std::make_pair("Venezuela", "Caracas"));
    allCards.push_back(std::make_pair("Ecuador", "Quito"));
    allCards.push_back(std::make_pair("Peru", "Lima"));
    allCards.push_back(std::make_pair("Bolivia", "La Paz or Sucre"));

    // Southern Cone
    allCards.push_back(std::make_pair("Chile", "Santiago"));
    allCards.push_back(std::make_pair("Argentina", "Buenos Aires"));
    allCards.push_back(std::make_pair("Uruguay", "Montevideo"));
    allCards.push_back(std::make_pair("Paraguay", "Asuncion"));

    // Brazil
    allCards.push_back(std::make_pair("Brazil", "Brasilia"));

    // Guianas
    allCards.push_back(std::make_pair("French Guiana", "Cayenne"));
    allCards.push_back(std::make_pair("Suriname", "Paramaribo"));
    allCards.push_back(std::make_pair("Guyana", "Georgetown"));
}

std::queue<std::pair<std::string, std::string> > shuffleDeck(std::vector<std::pair<std::string, std::string> > allCards) {
    srand(time(0));
    std::queue<std::pair<std::string, std::string> > deck;
    while (allCards.size() > 0) {
        int index = rand() % allCards.size();
        deck.push(allCards[index]);
        allCards.erase(allCards.begin() + index);
    }
    return deck;
}

int main() {
    init();
    std::queue<std::pair<std::string, std::string> > deck = shuffleDeck(allCards);

    while(!deck.empty()) {

        std::string country = deck.front().first;
        std::string capital = deck.front().second;

        std::cout << country << "\n> ";
        std::string response;
        getline(std::cin, response);

        if(response != capital) {
            std::cout << "Wrong. The answer was " << capital << std::endl;
            deck.push(deck.front());
        }
        deck.pop();
        std::cout << std::endl;
    }
    std::cout << "Done!" << std::endl;
    return 0;
}


/*
Mexico - Mexico City
Belize - Belmopan
Guatamala - Guatamala City
Honduras - Tegucigalpa
Nicaragua - Managua
El Salvador - San Salvador
Costa Rica - San Jose
Panama - Panama City
Cuba - Havana
Haiti - Port-au-Prince
Dominican Republic - Santo Domingo
Puerto Rico - San Juan
Jamaica - Kingston
Columbia - Bogata
Venezuela - Caracas
Ecuador - Quito
Peru - Lima
Bolivia - La Paz or Sucre
Chile - Santiago
Argentina - Buenos Aires
Uruguay - Montevideo
Paraguay - Asuncion
Brazil - Brasilia
French Guiana - Cayenne
Suriname - Paramaribo
Guyana - Georgetown
*/