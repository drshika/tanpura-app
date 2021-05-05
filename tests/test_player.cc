#include <catch2/catch.hpp>
#include <string>
#include "core/player.h"

using tanpura::Player;
using tanpura::TanpuraString;
using std::map;

TEST_CASE("Set Up Voices") {
    Player player = Player();
    player.SetUpVoices();
    SECTION("Map of Pitches is Initialized Correctly") {
        TanpuraString t1 = TanpuraString("tanpura_A.mp3", TanpuraString::Pitch::A);
        TanpuraString t2 = TanpuraString("tanpura_Acis.mp3", TanpuraString::Pitch::As);
        TanpuraString t3 = TanpuraString("tanpura_B.mp3", TanpuraString::Pitch::B);
        TanpuraString t4 = TanpuraString("tanpura_C.mp3", TanpuraString::Pitch::C);
        TanpuraString t5 = TanpuraString("tanpura_Ccis.mp3", TanpuraString::Pitch::Cs);
        TanpuraString t6 = TanpuraString("tanpura_D.mp3", TanpuraString::Pitch::D);
        TanpuraString t7 = TanpuraString("tanpura_Dcis.mp3", TanpuraString::Pitch::Ds);
        TanpuraString t8 = TanpuraString("tanpura_E.mp3", TanpuraString::Pitch::E);
        TanpuraString t9 = TanpuraString("tanpura_F.mp3", TanpuraString::Pitch::F);
        TanpuraString t10 = TanpuraString("tanpura_Fcis.mp3", TanpuraString::Pitch::Fs);
        TanpuraString t11 = TanpuraString("tanpura_G.mp3", TanpuraString::Pitch::G);
        TanpuraString t12 = TanpuraString("tanpura_Gcis.mp3", TanpuraString::Pitch::Gs);

        map<TanpuraString::Pitch, TanpuraString> expected = {
                {TanpuraString::Pitch::A, t1},
                {TanpuraString::Pitch::As, t2},
                {TanpuraString::Pitch::B, t3},
                {TanpuraString::Pitch::C, t4},
                {TanpuraString::Pitch::Cs, t5},
                {TanpuraString::Pitch::D, t6},
                {TanpuraString::Pitch::Ds, t7},
                {TanpuraString::Pitch::E, t8},
                {TanpuraString::Pitch::F, t9},
                {TanpuraString::Pitch::Fs, t10},
                {TanpuraString::Pitch::G, t11},
                {TanpuraString::Pitch::Gs, t12},
        };

        REQUIRE(equal(expected.begin(), expected.end(), player.GetPitches().begin());
        REQUIRE(expected.size() == player.GetPitches().size());
    }
}

TEST_CASE("Play") {
    Player player = Player();
    player.SetUpVoices();
    TanpuraString current_string = player.GetPitches()[TanpuraString::Pitch::C];
    SECTION("Test Play when the string is already playing") {
        player.Play(current_string);
        player.Play(current_string);
        REQUIRE(current_string.GetGain()->getValue() == 1.0f);
        REQUIRE(current_string.GetMBufferPlayer()->isEnabled() == true);
    }
    SECTION("Test Play when the string is not playing") {
        player.Play(current_string);
        REQUIRE(current_string.GetGain()->getValue() == 1.0f);
        REQUIRE(current_string.GetMBufferPlayer()->isEnabled() == true);
    }
}

TEST_CASE("Pause") {
    Player player = Player();
    player.SetUpVoices();
    TanpuraString current_string = player.GetPitches()[TanpuraString::Pitch::C];
    SECTION("Test Pause when the string is already playing") {
        player.Play(current_string);
        player.Pause(current_string);
        REQUIRE(current_string.GetGain()->getValue() == 0.0f);
        REQUIRE(current_string.GetMBufferPlayer()->isEnabled() == false);
    }
    SECTION("Test Pause when the string is not playing") {
        player.Pause(current_string);
        REQUIRE(current_string.GetGain()->getValue() == 0.0f);
        REQUIRE(current_string.GetMBufferPlayer()->isEnabled() == false);
    }
}

TEST_CASE("Increase Volume") {
    Player player = Player();
    player.SetUpVoices();
    TanpuraString current_string = player.GetPitches()[TanpuraString::Pitch::C];
    current_string.GetGain()->setValue(0.0f);
    SECTION("Test normal amount") {
        player.IncrementVolume(current_string, .5f);
        REQUIRE(current_string.GetGain()->getValue() == 0.5f);
    }
    SECTION("Test very high value") {
        player.IncrementVolume(current_string, 3.00f);
        REQUIRE(current_string.GetGain()->getValue() == 1.00f);
    }
}

TEST_CASE("Decrease Volume") {
    Player player = Player();
    player.SetUpVoices();
    TanpuraString current_string = player.GetPitches()[TanpuraString::Pitch::C];
    SECTION("Test normal amount") {
        player.IncrementVolume(current_string, -.5f);
        REQUIRE(current_string.GetGain()->getValue() == 0.5f);
    }
    SECTION("Test very low value") {
        player.IncrementVolume(current_string, -1.5f);
        REQUIRE(current_string.GetGain()->getValue() == 0.0f);
    }
}