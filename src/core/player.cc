#include <core/player.h>
#include <cinder/app/App.h>
#include <core/tanpura_string.h>
#include "cinder/audio/audio.h"

using namespace ci;
using namespace std;
using namespace ci::app;

namespace tanpura {
    Player::Player() = default;

    void Player::SetUpVoices() {
        ctx = audio::Context::master();
        
        pitch_files_ = {
                {"tanpura_A.mp3", TanpuraString::Pitch::A},
                {"tanpura_Acis.mp3", TanpuraString::Pitch::As},
                {"tanpura_B.mp3", TanpuraString::Pitch::B},
                {"tanpura_C.mp3", TanpuraString::Pitch::C},
                {"tanpura_Ccis.mp3", TanpuraString::Pitch::Cs},
                {"tanpura_D.mp3", TanpuraString::Pitch::D},
                {"tanpura_Dcis.mp3", TanpuraString::Pitch::Ds},
                {"tanpura_E.mp3", TanpuraString::Pitch::E},
                {"tanpura_F.mp3", TanpuraString::Pitch::F},
                {"tanpura_Fcis.mp3", TanpuraString::Pitch::Fs},
                {"tanpura_G.mp3", TanpuraString::Pitch::G},
                {"tanpura_Gcis.mp3", TanpuraString::Pitch::Gs}
        };
        
        for (auto& x: pitch_files_) {
            TanpuraString str = TanpuraString(x.first, x.second);
            
            pitches_.insert(std::pair<TanpuraString::Pitch, TanpuraString>(x.second, str));
        }
        //enable context    
        ctx->enable();
    }

    void Player::Play(const TanpuraString& string) {
        string.GetGain()->getParam()->setValue(1.0f); // Turn gain/volume up all the way
        string.GetMBufferPlayer()->setLoopEnabled(true);
        string.GetMBufferPlayer()->start();
    }

    void Player::Pause(const TanpuraString& string) {
        string.GetGain()->getParam()->setValue(0.0f); // Turn gain/volume down all the way
        string.GetMBufferPlayer()->setLoopEnabled(false);
        string.GetMBufferPlayer()->stop();
    }

    void Player::IncrementVolume(const TanpuraString& string, double degree) {
        if (abs(degree) >= 1 && degree >= 0) {
            string.GetGain()->getParam()->setValue(1.0f);
        } else if (abs(degree) >= 1 && degree <= 0) {
            string.GetGain()->getParam()->setValue(0.0f);
        } else {
            string.GetGain()->getParam()->setValue(0.0 + degree);
        }
    }

    map<TanpuraString::Pitch, TanpuraString> Player::GetPitches() {
        return pitches_;
    }
}