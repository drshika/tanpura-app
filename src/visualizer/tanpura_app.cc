#include <core/player.h>
#include "cinder/gl/gl.h"
#include "visualizer/tanpura_app.h"

namespace tanpura {

    TanpuraApp::TanpuraApp() {
        ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
    }

    void TanpuraApp::setup() {
        auto img = loadImage(loadAsset("tanpuraimg.png"));
        mImage = cinder::gl::Texture2d::create(img);
        Player player = Player();
        player.SetUpVoices();
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
}