//
// Created by idan on 15/12/2019.
//

#include "Extra.h"
map<string,int>* Extra::initializeDirectories() {
    map<string,int>* directories = new map<string,int>;
    string dir;
    int index = 0;

    // airspeed-indicator_indicated-speed-kt
    dir = string("/instrumentation/airspeed-indicator"
                    "/indicated-speed-kt");
    directories->insert({"/instrumentation/airspeed-indicator"
                         "/indicated-speed-kt", index});
    index++;

    // time_warp
    dir = string("/sim/time/warp");
    directories->insert({"/sim/time/warp", index});
    index++;

    // switches_magnetos
    dir = string("/controls/switches/magnetos");
    directories->insert({"/controls/switches/magnetos", index});
    index++;

    // heading-indicator_offset-deg
    dir = string("/instrumentation/heading-indicator/offset-deg");
    directories->insert({"/instrumentation/heading-indicator/offset-deg", index});
    index++;

    // altimeter_indicated-altitude-ft
    dir = string("/instrumentation/altimeter/indicated-altitude-ft");
    directories->insert({"/instrumentation/altimeter/indicated-altitude-ft", index});
    index++;

    // altimeter_pressure-alt-ft
    dir = string("/instrumentation/altimeter/pressure-alt-ft");
    directories->insert({"/instrumentation/altimeter/pressure-alt-ft", index});
    index++;

    // attitude-indicator_indicated-pitch-deg
    dir = string("/instrumentation/attitude-indicator/indicated-pitch-deg");
    directories->insert({"/instrumentation/attitude-indicator/indicated-pitch-deg", index});
    index++;

    // attitude-indicator_indicated-roll-deg
    dir = string("/instrumentation/attitude-indicator/indicated-roll-deg");
    directories->insert({"/instrumentation/attitude-indicator/indicated-roll-deg", index});
    index++;

    // attitude-indicator_internal-pitch-deg
    dir = string("/instrumentation/attitude-indicator/internal-pitch-deg");
    directories->insert({"/instrumentation/attitude-indicator/internal-pitch-deg", index});
    index++;

    // attitude-indicator_internal-roll-deg
    dir = string("/instrumentation/attitude-indicator/internal-roll-deg");
    directories->insert({"/instrumentation/attitude-indicator/internal-roll-deg", index});
    index++;

    // encoder_indicated-altitude-ft
    dir = string("/instrumentation/encoder/indicated-altitude-ft");
    directories->insert({"/instrumentation/encoder/indicated-altitude-ft", index});
    index++;

    // encoder_pressure-alt-ft
    dir = string("/instrumentation/encoder/pressure-alt-ft");
    directories->insert({"/instrumentation/encoder/pressure-alt-ft", index});
    index++;

    // gps_indicated-altitude-ft
    dir = string("/instrumentation/gps/indicated-altitude-ft");
    directories->insert({"/instrumentation/gps/indicated-altitude-ft", index});
    index++;

    // gps_indicated-ground-speed-kt
    dir = string("/instrumentation/gps/indicated-ground-speed-kt");
    directories->insert({"/instrumentation/gps/indicated-ground-speed-kt", index});
    index++;

    // gps_indicated-vertical-speed
    dir = string("/instrumentation/gps/indicated-vertical-speed");
    directories->insert({"/instrumentation/gps/indicated-vertical-speed", index});
    index++;

    // indicated-heading-deg
    dir = string("/instrumentation/heading-indicator/indicated-heading"
                     "-deg");
    directories->insert({"/instrumentation/heading-indicator/indicated-heading"
                         "-deg", index});
    index++;

    // magnetic-compass_indicated-heading-deg
    dir = string("/instrumentation/magnetic-compass/indicated-heading-deg");
    directories->insert({"/instrumentation/magnetic-compass/indicated-heading-deg", index});
    index++;

    // slip-skid-ball_indicated-slip-skid
    dir = string("/instrumentation/slip-skid-ball/indicated-slip-skid");
    directories->insert({"/instrumentation/slip-skid-ball/indicated-slip-skid", index});
    index++;

    // turn-indicator_indicated-turn-rate
    dir = string("/instrumentation/turn-indicator/indicated-turn-rate");
    directories->insert({"/instrumentation/turn-indicator/indicated-turn-rate", index});
    index++;

    // vertical-speed-indicator_indicated-speed-fpm
    dir = string("/instrumentation/vertical-speed-indicator/indicated"
                     "-speed-fpm");
    directories->insert({"/instrumentation/vertical-speed-indicator/indicated"
                         "-speed-fpm", index});
    index++;

    // flight_aileron
    dir = string("/controls/flight/aileron");
            directories->insert({"/controls/flight/aileron", index});
    index++;

    // flight_elevator
    dir = string("/controls/flight/elevator");
    directories->insert({"/controls/flight/elevator", index});
    index++;

    // flight_rudder
    dir = string("/controls/flight/rudder");
    directories->insert({"/controls/flight/rudder", index});
    index++;

    // flight_flaps
    dir = string("/controls/flight/flaps");
    directories->insert({"/controls/flight/flaps", index});
    index++;

    // engine_throttle
    dir = string("/controls/engines/engine/throttle");
    directories->insert({"/controls/engines/engine/throttle", index});
    index++;

    // current-engine_throttle
    dir = string("/controls/engines/current-engine/throttle");
    directories->insert({"/controls/engines/current-engine/throttle", index});
    index++;

    // switches_master-avionics
    dir = string("/controls/switches/master-avionics");
    directories->insert({"/controls/switches/master-avionics", index});
    index++;

    // switches_starter
    dir = string("/controls/switches/starter");
    directories->insert({"/controls/switches/starter", index});
    index++;

    // active-engine_auto-start
    dir = string("/engines/active-engine/auto-start");
    directories->insert({"/engines/active-engine/auto-start", index});
    index++;

    // flight_speedbrake
    dir = string("/controls/flight/speedbrake");
    directories->insert({"/controls/flight/speedbrake", index});
    index++;

    // c172p_brake-parking
    dir = string("/sim/model/c172p/brake-parking");
    directories->insert({"/sim/model/c172p/brake-parking", index});
    index++;

    // engine_primer
    dir = string("/controls/engines/engine/primer");
    directories->insert({"/controls/engines/engine/primer", index});
    index++;

    // current-engine_mixture
    dir = string("/controls/engines/current-engine/mixture");
    directories->insert({"/controls/engines/current-engine/mixture", index});
    index++;

    // switches_master-bat
    dir = string("/controls/switches/master-bat");
    directories->insert({"/controls/switches/master-bat", index});
    index++;

    // switches_master-alt
    dir = string("/controls/switches/master-alt");
    directories->insert({"/controls/switches/master-alt", index});
    index++;

    // engine_rpm
    dir = string("/engines/engine/rpm");
    directories->insert({"/engines/engine/rpm", index});
    index++;

    return directories;
}