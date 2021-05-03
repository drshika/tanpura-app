#include <core/player.h>
#include "cinder/gl/gl.h"
#include "visualizer/tanpura_app.h"

using namespace ci;
using namespace std;
using namespace ci::app;

namespace tanpura {

    TanpuraApp::TanpuraApp() {
        ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
    }

    void TanpuraApp::setup() {
        auto img = loadImage(loadAsset("tanpuraimg.png"));
        mImage = cinder::gl::Texture2d::create(img);
        player_ = Player();
        player_.SetUpVoices();
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
    

    void TanpuraApp::keyDown(ci::app::KeyEvent event) {
        switch(event.code()) {
            case ci::app::KeyEvent::KEY_DOWN:
                player_.IncrementVolume(-kIncrementVolume);
                break;
            case ci::app::KeyEvent::KEY_UP:
                player_.IncrementVolume(kIncrementVolume);
                break;
            case ci::app::KeyEvent::KEY_a:
                current_string_ = player[TanpuraString::String::A];
                break;
            case ci::app::KeyEvent::KEY_b:
                current_string_ = player[TanpuraString::String::B];
                break;
            case ci::app::KeyEvent::KEY_c:
                current_string_ = player[TanpuraString::String::C];
                break;
            case ci::app::KeyEvent::KEY_d:
                current_string_ = player[TanpuraString::String::D];
                break;
            case ci::app::KeyEvent::KEY_e:
                current_string_ = player[TanpuraString::String::E];
                break;
            case ci::app::KeyEvent::KEY_f:
                current_string_ = player[TanpuraString::String::F];
                break;
            case ci::app::KeyEvent::KEY_g:
                current_string_ = player[TanpuraString::String::G];
                break;
            case ci::app::KeyEvent::KEY_q:
                current_string_ = player[TanpuraString::String::As]; //TODO: Add tooltip for sharp notes in UI
                break;
            case ci::app::KeyEvent::KEY_w:
                current_string_ = player[TanpuraString::String::Cs];
                break;
            case ci::app::KeyEvent::KEY_e:
                current_string_ = player[TanpuraString::String::Ds];
                break;
            case ci::app::KeyEvent::KEY_r:
                current_string_ = player[TanpuraString::String::Fs];
                break;
            case ci::app::KeyEvent::KEY_t:
                current_string_ = player[TanpuraString::String::Gs];
                break;
        }    
    }
}