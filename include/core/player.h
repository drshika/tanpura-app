#pragma once

#include <map>
#include <string>
#include <vector>

#include "cinder/audio/audio.h"
#include "cinder/audio/Source.h"

namespace tanpura {
    //using ci::audio;
    namespace audio {
        class Player {
        public:
            /**
             * Constructs an empty player object.
             */
            Player();
            /**
             * Starts tanpura playback
             */
            void Play();
            /**
             * Pauses tanpura playbac
             */
            void Pause();
            
            /**
             * Declaring the voice variable
             */
            cinder::audio::VoiceRef mVoice;
        private:
            
        };
    }
}