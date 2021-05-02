#pragma once

#include <map>
#include <string>
#include <vector>

#include "cinder/audio/audio.h"
#include "cinder/audio/Source.h"

namespace tanpura {
    class TanpuraString {
    public:
        //An enum to store the pitches available
        enum class Pitch {
            A,
            As,
            B,
            C,
            Cs,
            D,
            Ds,
            E,
            F,
            Fs,
            G,
            Gs,
        };
        
        /**
         * Constructor for a Tanpura String Object
         * @param pitch pitch that the sound file is
         * @param source_file_ the source file to create a buffer from
         */
        TanpuraString(const audio::SourceFileRef& source_file, Pitch pitch);

    private:
        Pitch pitch_;

        audio::BufferPlayerNodeRef mBufferPlayer_;
        audio::SourceFileRef source_file_;
        audio::GainNodeRef gain_;
    public:
        const audio::BufferPlayerNodeRef &GetMBufferPlayer() const;

        const audio::GainNodeRef &GetGain() const;
    };
}