#include <iostream>
#include "core/player.h"
#include "visualizer/tanpura_app.h"


using tanpura::TanpuraApp;

// using tanpura::Player;
//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    Player player = Player();
//    player.Play();
//    return 0;
//}

void prepareSettings(TanpuraApp::Settings* settings) {
    settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(TanpuraApp, ci::app::RendererGl, prepareSettings);