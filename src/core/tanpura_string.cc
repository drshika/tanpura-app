#include "cinder/audio/audio.h"
#include <core/tanpura_string.h>
#include <core/player.h>

using namespace ci;
using namespace std;

namespace tanpura {

    TanpuraString::TanpuraString(const audio::SourceFileRef& source_file, TanpuraString::Pitch pitch) {
        pitch_ = pitch;

        //create BufferPlayerNode from file
        mBufferPlayer_ = ctx->makeNode(new audio::BufferPlayerNode());
        mBufferPlayer_->loadBuffer(source_file);

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
}