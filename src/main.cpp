#include "Mission.h"
#include <iostream>

int main() {
    Mission mission;
    mission.initGlut();
    mission.run();
    std::cout << "Fin de la simulación" << std::endl;
    return 0;
}
