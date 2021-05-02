#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Color.h"

#include "cinder/audio/Voice.h"
#include "cinder/audio/Source.h"

namespace tanpura {
    
    class TanpuraApp : public ci::app::App {
    public:
        TanpuraApp();

        /**
          * Sets up the application to its default state
          */
        void setup() override;

        /**
         * Draws all the components of the app on a window on the computer screen
         */
        void draw() override;
    private:
        //Window and Element positioning
        const int kWindowSize = 875;
        const int kTopPadding = 50;
        const double kTextHeight = 75;
        const glm::vec2 kImagePosition = {-80, 180};
        
        //Colors
        const ci::Color kBackgroundColor = ci::Color::hex(0xEDE1D1);
        const ci::Color kTextColor = ci::Color::hex(0x2f2d29);
        
        //Fonts
        const std::string kMainFontName = "Georgia";
        const std::string kTitleText = "Tanpura App";
        
        std::string pitch_name;
        cinder::gl::Texture2dRef mImage;
    };
}