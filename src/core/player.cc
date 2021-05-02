#include <core/player.h>
#include <cinder/app/App.h>
#include "cinder/audio/audio.h"

using namespace ci;
using namespace ci::app;
using namespace std;

namespace tanpura {
    Player::Player() = default;

    void Player::SetUpVoices() {
        auto ctx = audio::Context::master();
        audio::SourceFileRef source_file = audio::load(loadAsset("tanpura_C.mp3"), 
                                                       ctx->getSampleRate());

        //create BufferPlayerNode from file
        audio::BufferPlayerNodeRef mBufferPlayer = ctx->makeNode(new audio::BufferPlayerNode());
        mBufferPlayer->loadBuffer(source_file);

        //create GainNode for volume control, set to max volume
        audio::GainNodeRef gain = ctx->makeNode(new audio::GainNode(1.0f));

        // Connect player components to audio graph
        mBufferPlayer >> gain >> ctx->getOutput();
        
        //enable context and start the buffer player
        ctx->enable();
        mBufferPlayer->start();
    }

    void Player::Play() {
//        mVoice->start();
//        if (!(is_playing_)) {
//            voice.is_playing_ = true;
//            ci::audio::GainNodeRef gain = voice.gain_;
//            gain->getParam()->setValue(1); // Turn gain/volume up all the way
//            buffer_player->start();
//        }
    }

    void Player::Pause() {
        //mVoice->pause();
    }

}