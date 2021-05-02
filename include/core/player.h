#pragma once

#include <map>
#include <string>
#include <vector>

#include "cinder/audio/audio.h"
#include "cinder/audio/Source.h"

namespace tanpura {
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
            void Play();
            /**
             * Pauses tanpura playback
             */
            void Pause();
        private:
            struct TanpuraVoice {
                ci::audio::GainNodeRef gain_;
                ci::audio::BufferPlayerNodeRef buffer_player_;
                bool is_playing_;
            };
            
            //map of file paths to pitches
            std::map<std::string, std::string> pitches;
        };
}