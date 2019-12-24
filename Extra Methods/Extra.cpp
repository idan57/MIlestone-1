//
// Created by idan on 15/12/2019.
//

#include "Extra.h"
map<string,int>* Extra::initializeDirectories() {
    map<string*,int>* directories = new map<string*,int>;
    string* dir;
    int index = 0;

    // airspeed-indicator_indicated-speed-kt
    dir = new string("/instrumentation/airspeed-indicator"
                    "/indicated-speed-kt");
    directories->insert({dir, index});
    index++;

    // time_warp
    dir = new string("/sim/time/warp");
    directories->insert({dir, index});
    index++;

    // switches_magnetos
    dir = new string("/controls/switches/magnetos");
    directories->insert({dir, index});
    index++;

    // heading-indicator_offset-deg
    dir = new string("/instrumentation/heading-indicator/offset-deg");
    directories->insert({dir, index});
    index++;

    // altimeter_indicated-altitude-ft
    dir = new string("/instrumentation/altimeter/indicated-altitude-ft");
    directories->insert({dir, index});
    index++;

    // altimeter_pressure-alt-ft
    dir = new string("/instrumentation/altimeter/pressure-alt-ft");
    directories->insert({dir, index});
    index++;

    // attitude-indicator_indicated-pitch-deg
    dir = new string("/instrumentation/attitude-indicator/indicated-pitch-deg");
    directories->insert({dir, index});
    index++;

    // attitude-indicator_indicated-roll-deg
    dir = new string("/instrumentation/attitude-indicator/indicated-roll-deg");
    directories->insert({dir, index});
    index++;

    // attitude-indicator_internal-pitch-deg
    dir = new string("/instrumentation/attitude-indicator/internal-pitch-deg");
    directories->insert({dir, index});
    index++;

    // attitude-indicator_internal-roll-deg
    dir = new string("/instrumentation/attitude-indicator/internal-roll-deg");
    directories->insert({dir, index});
    index++;

    // encoder_indicated-altitude-ft
    dir = new string("/instrumentation/encoder/indicated-altitude-ft");
    directories->insert({dir, index});
    index++;

    // encoder_pressure-alt-ft
    dir = new string("/instrumentation/encoder/pressure-alt-ft");
    directories->insert({dir, index});
    index++;

    // gps_indicated-altitude-ft
    dir = new string("/instrumentation/gps/indicated-altitude-ft");
    directories->insert({dir, index});
    index++;

    // gps_indicated-ground-speed-kt
    dir = new string("/instrumentation/gps/indicated-ground-speed-kt");
    directories->insert({dir, index});
    index++;

    // gps_indicated-vertical-speed
    dir = new string("/instrumentation/gps/indicated-vertical-speed");
    directories->insert({dir, index});
    index++;

    // indicated-heading-deg
    dir = new string("/instrumentation/heading-indicator/indicated-heading"
                     "-deg");
    directories->insert({dir, index});
    index++;

    // magnetic-compass_indicated-heading-deg
    dir = new string("/instrumentation/magnetic-compass/indicated-heading-deg");
    directories->insert({dir, index});
    index++;

    // slip-skid-ball_indicated-slip-skid
    dir = new string("/instrumentation/slip-skid-ball/indicated-slip-skid");
    directories->insert({dir, index});
    index++;

    // turn-indicator_indicated-turn-rate
    dir = new string("/instrumentation/turn-indicator/indicated-turn-rate");
    directories->insert({dir, index});
    index++;

    // vertical-speed-indicator_indicated-speed-fpm
    dir = new string("/instrumentation/vertical-speed-indicator/indicated"
                     "-speed-fpm");
    directories->insert({dir, index});
    index++;

    // flight_aileron
    dir = new string("/controls/flight/aileron");
            directories->insert({dir, index});
    index++;

    // flight_elevator
    dir = new string("/controls/flight/elevator");
    directories->insert({dir, index});
    index++;

    // flight_rudder
    dir = new string("/controls/flight/rudder");
    directories->insert({dir, index});
    index++;

    // flight_flaps
    dir = new string("/controls/flight/flaps");
    directories->insert({dir, index});
    index++;

    // engine_throttle
    dir = new string("/controls/engines/engine/throttle");
    directories->insert({dir, index});
    index++;

    // current-engine_throttle
    dir = new string("/controls/engines/current-engine/throttle");
    directories->insert({dir, index});
    index++;

    // switches_master-avionics
    dir = new string("/controls/switches/master-avionics");
    directories->insert({dir, index});
    index++;

    // switches_starter
    dir = new string("/controls/switches/starter");
    directories->insert({dir, index});
    index++;

    // active-engine_auto-start
    dir = new string("/engines/active-engine/auto-start");
    directories->insert({dir, index});
    index++;

    // flight_speedbrake
    dir = new string("/controls/flight/speedbrake");
    directories->insert({dir, index});
    index++;

    // c172p_brake-parking
    dir = new string("/sim/model/c172p/brake-parking");
    directories->insert({dir, index});
    index++;

    // engine_primer
    dir = new string("/controls/engines/engine/primer");
    directories->insert({dir, index});
    index++;

    // current-engine_mixture
    dir = new string("/controls/engines/current-engine/mixture");
    directories->insert({dir, index});
    index++;

    // switches_master-bat
    dir = new string("/controls/switches/master-bat");
    directories->insert({dir, index});
    index++;

    // switches_master-alt
    dir = new string("/controls/switches/master-alt");
    directories->insert({dir, index});
    index++;

    // engine_rpm
    dir = new string("/engines/engine/rpm");
    directories->insert({dir, index});
    index++;
}