#include <core/player.h>
#include <cinder/app/App.h>

namespace tanpura {
    Player::Player() {
        cinder::audio::SourceFileRef sourceFile = ci::audio::load(ci::app::loadAsset("../assets/tanpura_C.mp3"));
        mVoice = cinder::audio::Voice::create( sourceFile );
    }

    void Player::Play() {
        mVoice->start();
    }

    void Player::Pause() {
        mVoice->pause();
    }

}