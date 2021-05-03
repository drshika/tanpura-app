#include "cinder/audio/audio.h"
#include <core/tanpura_string.h>
#include <core/player.h>
#include <cinder/app/AppBase.h>

using namespace ci;
using namespace std;
using namespace ci::app;

namespace tanpura {

    TanpuraString::TanpuraString(string source_file_path, TanpuraString::Pitch pitch) {
        audio::SourceFileRef sourceFile = audio::load(app::loadAsset(source_file_path));
        pitch_ = pitch;

        int pitch_len = source_file_path.first.substr(8).length();
        pitch_name_ = source_file_path.first.substr(8, 1);

        if (pitch_len == 8) {
            pitch_name_ += "#";
        }
        
        //create BufferPlayerNode from file
        mBufferPlayer_ = ctx->makeNode(new audio::BufferPlayerNode());
        mBufferPlayer_->loadBuffer(source_file_path);

        //create GainNode for volume control, set to max volume
        gain_ = ctx->makeNode(new audio::GainNode(1.0f));

        // Connect player components to audio graph
        mBufferPlayer_ >> gain_ >> ctx->getOutput();
    }

    const audio::BufferPlayerNodeRef &TanpuraString::GetMBufferPlayer() const {
        return mBufferPlayer_;
    }

    const audio::GainNodeRef &TanpuraString::GetGain() const {
        return gain_;
    }

    const string &TanpuraString::getPitchName() const {
        return pitch_name_;
    }

    bool TanpuraString::GetIsPlaying() const {
        return is_playing_;
    }

    void TanpuraString::setIsPlaying(bool isPlaying) {
        is_playing_ = isPlaying;
    }
}