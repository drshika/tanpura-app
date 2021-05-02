#pragma once

#include "cinder/audio/audio.h"
#include "cinder/audio/Source.h"
#import "tanpura_string.h"

#include <map>
#include <string>
#include <vector>

namespace tanpura {
    //Stores the device master output
    auto ctx;
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
            void Play(const TanpuraString& string);
            /**
             * Pauses tanpura playback
             */
            void Pause(const TanpuraString& string);
        private:
            //map of file paths to pitches
            map<string,TanpuraString::Pitch> pitch_files_;
            
            //map of TanpuraStrings
            map<string, TanpuraString> pitches_;
        };
}