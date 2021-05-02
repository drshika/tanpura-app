#include <iostream>
#include "core/player.h"
#include "visualizer/tanpura_app.h"
#include "cinder/audio/audio.h"

using namespace ci;
using namespace ci::app;
using namespace std;

using tanpura::TanpuraApp;

void prepareSettings(TanpuraApp::Settings* settings) {
    settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(TanpuraApp, ci::app::RendererGl, prepareSettings);