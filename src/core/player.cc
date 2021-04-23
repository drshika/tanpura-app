#include <core/player.h>
#include <cinder/app/App.h>

namespace tanpura {
    using cinder::audio::Voice;
    audio::Player::Player() {
        cinder::audio::SourceFileRef sourceFile = ci::audio::load(ci::app::loadAsset("../assets/tanpura_C.mp3"));
        mVoice = Voice::create( sourceFile );
    }

    void audio::Player::Play() {
        mVoice->start();
    }

    void audio::Player::Pause() {
        mVoice->pause();
    }

}