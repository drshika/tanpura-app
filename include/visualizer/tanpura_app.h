#pragma once

#include "core/player.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Color.h"

#include "cinder/audio/Voice.h"
#include "cinder/audio/Source.h"
#include "../core/tanpura_string.h"
#include "../core/player.h"

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

        void keyDown(KeyEvent event) override;
    private:
        //Window and Element positioning
        const int kWindowSize = 875;
        const int kTopPadding = 50;
        const glm::vec2 kImagePosition = {-80, 180};
        const glm::vec2 kTitleTextPosition = {kWindowSize / 2, kTopPadding};
        const glm::vec2 kPitchTextPosition = {kWindowSize * 2 / 3, kWindowSize * 1 / 3};
        const Rectf kPitchBox = Rectf(523, 252, 646, 375);
        
        //Colors
        const ci::Color kBackgroundColor = ci::Color::hex(0xEDE1D1);
        const ci::Color kTextColor = ci::Color::hex(0x2f2d29);
        const ci::Color kBoxColor = ci::Color::hex(0xe3b981);
        const ci::Color kBoxOutlineColor = ci::Color::hex(0x5f4d35);
        
        //Fonts and Text
        const std::string kTitleFontName = "Georgia";
        const std::string kTitleText = "Tanpura App";
        const double kTitleTextHeight = 75;
        
        const std::string kToolTipFontName = "Avenir";
        const std::string kToolTipTitle = "Key";
        const std::string kToolTipPtOne = "[Major keys] Same letter as the key name. Eg: C='c'";
        const std::string kToolTipPtTwo = "[Tivra/Sharp keys] A#='q' C#='w' D#='u' F#='r' G#='t'";
        const std::string kToolTipPtThree = "[Volume] Use arrow keys to increase '▲' or decrease '▼' volume";
        const double kTTTextHeight = 45;
        const double kTextHeight = 17;

        const double kIncrementVolume = 0.05;
        
        std::string pitch_name;
        cinder::gl::Texture2dRef mImage;
        
        Player player_;
        TanpuraString current_string_;
        
        /**
         * Helper for switching the playing string.
         * @param new_string the string you want to switch to.
         */
        void SwitchPlayingString(TanpuraString::Pitch new_pitch);
    };
}