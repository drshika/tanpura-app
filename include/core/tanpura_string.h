#pragma once

#include <map>
#include <string>
#include <vector>
#include "cinder/app/App.h"

#include "cinder/audio/audio.h"
#include "cinder/audio/Source.h"

using namespace ci;
using namespace std;
using namespace ci::app;

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
        
        TanpuraString();
        
        /**
         * Constructor for a Tanpura String Object
         * @param pitch pitch that the sound file is
         * @param source_file_ the source file to create a buffer from
         */
        TanpuraString(string source_file_path, Pitch pitch);

        /**
         * Getter for mBufferPlayer
         * @return mBufferPlayer
         */
        const audio::BufferPlayerNodeRef &GetMBufferPlayer() const;

        /**
         * Getter for Gain Node
         * @return gain_
         */
        const audio::GainNodeRef &GetGain() const;

        /**
         * Getter for Pitch Name
         * @return gain_
         */
        const string &GetPitchName() const;
        
        /**
         * Getter for is_playing_
         * @return is_playing_
         */
        bool GetIsPlaying() const;
        
        /**
         * Setter for is_playing_
         * @param isPlaying what to set it to
         */
        void SetIsPlaying(bool isPlaying);
        
        /**
         * Setter for pitch
         * @return pitch_
         */
        Pitch GetPitch() const;

    private:
        Pitch pitch_;
        
        string pitch_name_;

        audio::BufferPlayerNodeRef mBufferPlayer_;
        audio::SourceFileRef source_file_;
        audio::GainNodeRef gain_;   

        bool is_playing_;
        
        int pitch_name_position = 8;
    };
}