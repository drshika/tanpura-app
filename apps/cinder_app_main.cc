#include <iostream>
#include "core/player.h"

using tanpura::audio::Player;

int main() {
    std::cout << "Hello, World!" << std::endl;
    Player player = Player();
    player.Play();
    return 0;
}