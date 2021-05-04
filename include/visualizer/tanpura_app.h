#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h

#include "cinder/audio/Voice.h"
#include "cinder/audio/Source.h"

namespace tanpura {
public:
    TanpuraApp();
private:
    const int kWindowSize = 875;
}