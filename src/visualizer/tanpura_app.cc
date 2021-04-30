#include "cinder/gl/gl.h"
#include "visualizer/tanpura_app.h"

namespace tanpura {

    TanpuraApp::TanpuraApp() {
        ci::app::setWindowSize((int)kWindowSize, (int)kWindowSize);
    }

    void TanpuraApp::setup() {
        auto img = loadImage(loadAsset("../assets/tanpuraimg.png"));
        mImage = cinder::gl::Texture2d::create(img);
    }

    void TanpuraApp::draw() {
        ci::Color8u background_color(kBackgroundColor);
        ci::gl::clear(background_color);

        // Draw Title Text
        glm::dvec2 instrument_text_center(kWindowSize / 2, kTopPadding);
        ci::gl::drawStringCentered(
                kTitleText, instrument_text_center, kTextColor,
                ci::Font(kMainFontName, kTextHeight));
        cinder::gl::draw(mImage, kImagePosition);
    }
}