#pragma once

#include "cinder/audio/audio.h"
#include "cinder/audio/Source.h"
#include "tanpura_string.h"

#include <map>
#include <string>
#include <vector>

namespace tanpura {
    //Stores the device master output
    static audio::Context* ctx;
    
        class Player {
        public:
            /**
             * Constructs an empty player object.
             */
            Player();
            
            /**
             * Sets up the Map of pitches, initializes the BufferedPlayer.
             */
            void SetUpVoices();
            
            /**
             * Starts tanpura playback
             */
            void Play(TanpuraString string);
            
            /**
             * Pauses tanpura playback
             */
            void Pause(TanpuraString string);
            
            /**
             * 
             * @param string 
             * @param degree 
             */
            void IncrementVolume(const TanpuraString& string, double degree);
            
            /**
             * Getter for pitches
             * @return pitches_
             */
            map <TanpuraString::Pitch, TanpuraString> GetPitches();
        private:
            //map of file paths to pitches
            map<string,TanpuraString::Pitch> pitch_files_;
            
            //map of TanpuraStrings
            map<TanpuraString::Pitch, TanpuraString> pitches_;
        };
}