#include <core/player.h>
#include "cinder/gl/gl.h"
#include "visualizer/tanpura_app.h"

using namespace ci;
using namespace std;
using namespace ci::app;

namespace tanpura {

    TanpuraApp::TanpuraApp() {
        ci::app::setWindowSize((int) kWindowWidth, (int) kWindowHeight);
        player_ = Player();
        player_.SetUpVoices();
        current_string_ = player_.GetPitches()[TanpuraString::Pitch::C];
    }

    void TanpuraApp::setup() {
        auto img = loadImage(loadAsset("tanpuraimg.png"));
        mImage = cinder::gl::Texture2d::create(img);
    }

    void TanpuraApp::draw() {
        ci::Color8u background_color(kBackgroundColor);
        ci::gl::clear(background_color);

        // Draw Title Text
        ci::gl::drawStringCentered(
                kTitleText, kTitleTextPosition, kTextColor,
                ci::Font(kTitleFontName, kTitleTextHeight));
        ci::gl::color(ci::Color("White"));
        cinder::gl::draw(mImage, kImagePosition);

        // Draw Pitch Name
        pitch_name = current_string_.GetPitchName();
        ci::gl::color(kBoxColor);
        ci::gl::drawSolidRect(kPitchBox);
        ci::gl::color(kBoxOutlineColor);
        ci::gl::drawStrokedRect(kPitchBox, 5.00);
        ci::gl::drawStringCentered(
                pitch_name, kPitchTextPosition, kTextColor,
                ci::Font(kTitleFontName, kTitleTextHeight));
        
        //Draw Tooltip
        ci::gl::drawStringCentered(kToolTipTitle, kToolTipTitleCenter, kTextColor,
                                   ci::Font(kTitleFontName, kTTTextHeight));
        ci::gl::drawStringCentered(kToolTipPtOne, kToolTipTextCenter, kTextColor,
                                   ci::Font(kToolTipFontName, kTextHeight));
        ci::gl::drawStringCentered(kToolTipPtTwo, toolTipTextBody2, kTextColor,
                                   ci::Font(kToolTipFontName, kTextHeight));
        ci::gl::drawStringCentered(kToolTipPtThree, toolTipTextBody3, kTextColor,
                                   ci::Font(kToolTipFontName, kTextHeight));
    }

    void TanpuraApp::keyDown(ci::app::KeyEvent event) {
        //Handles Play and Pause
        if (event.getCode() == ci::app::KeyEvent::KEY_SPACE) {
            if (!(current_string_.GetIsPlaying())) {
                current_string_.SetIsPlaying(true);
                player_.Play(current_string_);
            } else {
                current_string_.SetIsPlaying(false);
                player_.Pause(current_string_);
            }
        }

        //Handles Increase/Decrease volume, keypress to change pitches
        switch (event.getCode()) {
            case ci::app::KeyEvent::KEY_DOWN:
                player_.IncrementVolume(current_string_, -kIncrementVolume);
                break;
            case ci::app::KeyEvent::KEY_UP:
                player_.IncrementVolume(current_string_, kIncrementVolume);
                break;
            case ci::app::KeyEvent::KEY_a:
                SwitchPlayingString(TanpuraString::Pitch::A);
                break;
            case ci::app::KeyEvent::KEY_b:
                SwitchPlayingString(TanpuraString::Pitch::B);
                break;
            case ci::app::KeyEvent::KEY_c:
                SwitchPlayingString(TanpuraString::Pitch::C);
                break;
            case ci::app::KeyEvent::KEY_d:
                SwitchPlayingString(TanpuraString::Pitch::D);
                break;
            case ci::app::KeyEvent::KEY_e:
                SwitchPlayingString(TanpuraString::Pitch::E);
                break;
            case ci::app::KeyEvent::KEY_f:
                SwitchPlayingString(TanpuraString::Pitch::F);
                break;
            case ci::app::KeyEvent::KEY_g:
                SwitchPlayingString(TanpuraString::Pitch::G);
                break;
            case ci::app::KeyEvent::KEY_q:
                SwitchPlayingString(TanpuraString::Pitch::As); //TODO: Add tooltip for sharp notes in UI
                break;
            case ci::app::KeyEvent::KEY_w:
                SwitchPlayingString(TanpuraString::Pitch::Cs);
                break;
            case ci::app::KeyEvent::KEY_u:
                SwitchPlayingString(TanpuraString::Pitch::Ds);
                break;
            case ci::app::KeyEvent::KEY_r:
                SwitchPlayingString(TanpuraString::Pitch::Fs);
                break;
            case ci::app::KeyEvent::KEY_t:
                SwitchPlayingString(TanpuraString::Pitch::Gs);
                break;
        }
    }

    void TanpuraApp::SwitchPlayingString(TanpuraString::Pitch new_pitch) {
        current_string_.SetIsPlaying(false);
        player_.Pause(current_string_);
        
        current_string_ = player_.GetPitches()[new_pitch];
        player_.Play(current_string_);
        current_string_.SetIsPlaying(true);
    }
}