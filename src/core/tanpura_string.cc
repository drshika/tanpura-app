#include "cinder/audio/audio.h"
#include <core/tanpura_string.h>
#include <core/player.h>
#include <cinder/app/AppBase.h>

using namespace ci;
using namespace std;
using namespace ci::app;

namespace tanpura {

    TanpuraString::TanpuraString(string source_file_path, TanpuraString::Pitch pitch) {
        ctx = audio::Context::master();
        audio::SourceFileRef sourceFile = audio::load(app::loadAsset(source_file_path));
        pitch_ = pitch;

        int pitch_len = source_file_path.substr(pitch_name_position).length();
        pitch_name_ = source_file_path.substr(pitch_name_position, 1);
        
        //adds a sharp to the pitch name if it has 'cis' added to it
        if (pitch_len == 8) {
            pitch_name_ += "#";
        }
        
        //create BufferPlayerNode from file
        mBufferPlayer_ = ctx->makeNode(new audio::BufferPlayerNode());
        mBufferPlayer_->loadBuffer(sourceFile);

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

    const string &TanpuraString::GetPitchName() const {
        return pitch_name_;
    }

    bool TanpuraString::GetIsPlaying() const {
        return is_playing_;
    }

    void TanpuraString::SetIsPlaying(bool isPlaying) {
        is_playing_ = isPlaying;
    }

    TanpuraString::TanpuraString() {
        pitch_ = Pitch::C;
        pitch_name_ = "C";
        is_playing_ = false;
    }

    TanpuraString::Pitch TanpuraString::GetPitch() const {
        return pitch_;
    }
}