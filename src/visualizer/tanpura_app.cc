#include <core/player.h>
#include "cinder/gl/gl.h"
#include "visualizer/tanpura_app.h"

using namespace ci;
using namespace std;
using namespace ci::app;

namespace tanpura {

    TanpuraApp::TanpuraApp() {
        ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
        player_ = Player();
        player_.SetUpVoices();
        current_string_ = player_.GetPitches()[TanpuraString::Pitch::C];
    }

    void TanpuraApp::setup() {
        auto img = loadImage(loadAsset("tanpuraimg.png"));
        mImage = cinder::gl::Texture2d::create(img);
//        player_ = Player();
//        player_.SetUpVoices();
//        current_string_ = player_.GetPitches()[TanpuraString::Pitch::C];
    }

    void TanpuraApp::draw() {
        ci::Color8u background_color(kBackgroundColor);
        ci::gl::clear(background_color);

        // Draw Title Text
        glm::dvec2 title_text_center(kWindowSize / 2, kTopPadding);
        ci::gl::drawStringCentered(
                kTitleText, title_text_center, kTextColor,
                ci::Font(kMainFontName, kTextHeight));
        cinder::gl::draw(mImage, kImagePosition);

        // Draw Pitch Name
        glm::dvec2 pitch_text_center(kWindowSize * 2 / 3, kWindowSize / 2);
        pitch_name = "C"; //TODO: Change to variable later
        ci::gl::drawStringCentered(
                pitch_name, pitch_text_center, kTextColor,
                ci::Font(kMainFontName, kTextHeight));
        }

    void TanpuraApp::keyDown(ci::app::KeyEvent event) {
        //Handles Play and Pause
        if (event.getCode() == ci::app::KeyEvent::KEY_SPACE) {
            if (current_string_.GetIsPlaying()) {
                player_.Pause(current_string_);
            } else {
                player_.Play(current_string_);
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
                current_string_ = player_.GetPitches()[TanpuraString::Pitch::A];
                break;
            case ci::app::KeyEvent::KEY_b:
                current_string_ = player_.GetPitches()[TanpuraString::Pitch::B];
                break;
            case ci::app::KeyEvent::KEY_c:
                current_string_ = player_.GetPitches()[TanpuraString::Pitch::C];
                break;
            case ci::app::KeyEvent::KEY_d:
                current_string_ = player_.GetPitches()[TanpuraString::Pitch::D];
                break;
            case ci::app::KeyEvent::KEY_e:
                current_string_ = player_.GetPitches()[TanpuraString::Pitch::E];
                break;
            case ci::app::KeyEvent::KEY_f:
                current_string_ = player_.GetPitches()[TanpuraString::Pitch::F];
                break;
            case ci::app::KeyEvent::KEY_g:
                current_string_ = player_.GetPitches()[TanpuraString::Pitch::G];
                break;
            case ci::app::KeyEvent::KEY_q:
                current_string_ = player_.GetPitches()[TanpuraString::Pitch::As]; //TODO: Add tooltip for sharp notes in UI
                break;
            case ci::app::KeyEvent::KEY_w:
                current_string_ = player_.GetPitches()[TanpuraString::Pitch::Cs];
                break;
            case ci::app::KeyEvent::KEY_u:
                current_string_ = player_.GetPitches()[TanpuraString::Pitch::Ds];
                break;
            case ci::app::KeyEvent::KEY_r:
                current_string_ = player_.GetPitches()[TanpuraString::Pitch::Fs];
                break;
            case ci::app::KeyEvent::KEY_t:
                current_string_ = player_.GetPitches()[TanpuraString::Pitch::Gs];
                break;
        }
    };
}