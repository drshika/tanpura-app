#include <catch2/catch.hpp>
#include "core/tanpura_string.h"

using tanpura::TanpuraString;

TEST_CASE("Constructor") {
    TanpuraString string = TanpuraString();
    TanpuraString string1 = TanpuraString("tanpura_A.mp3", TanpuraString::Pitch::A);
    TanpuraString string2 = TanpuraString("tanpura_Acis.mp3", TanpuraString::Pitch::As);

    SECTION("Default Constructor") {
        REQUIRE_FALSE(string.GetIsPlaying());
        REQUIRE(string.GetPitchName() == "C");
        REQUIRE(string.GetPitch() == TanpuraString::Pitch::C);
    }
    
    SECTION("Check the BufferPlayerNode initialization") {
        REQUIRE(string1.GetMBufferPlayer() != nullptr);
    }
    
    SECTION("Check the Gain initialization") {
        REQUIRE(string1.GetGain()->getValue() == 1.0f);
    }
    
    SECTION("Check pitch name") {
        REQUIRE(string1.GetPitchName() == "A");
        REQUIRE(string2.GetPitchName() == "A#");
    }

    SECTION("Check that is_playing_ is set to false") {
        REQUIRE_FALSE(string.GetIsPlaying());
    }
}

TEST_CASE("Set is_playing_") {
    TanpuraString string = TanpuraString();
    SECTION("Setting to true") {
        string.SetIsPlaying(true);
        REQUIRE(string.GetIsPlaying());
    }

    SECTION("Setting to false") {
        string.SetIsPlaying(false);
        REQUIRE_FALSE(string.GetIsPlaying());
    }
}