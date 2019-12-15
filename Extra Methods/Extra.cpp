//
// Created by idan on 15/12/2019.
//

#include "Extra.h"
map<int,string*> Extra::initializeDirectories() {
    map<int,string*>* directories = new map<int,string*>;
    string* dir;
    int index = 0;

    // airspeed-indicator_indicated-speed-kt
    dir =new string("/instrumentation/airspeed-indicator"
                    "/indicated-speed-kt");
    directories->insert({index, dir});
    index++;

    // altimeter_indicated-altitude-ft
    dir = new string("/instrumentation/altimeter/indicated-altitude-ft");
    directories->insert({index, dir});
    index++;

    // altimeter_pressure-alt-ft
    dir = new string("/instrumentation/altimeter/pressure-alt-ft");
    directories->insert({index, dir});
    index++;

    // attitude-indicator_indicated-pitch-deg
    dir = new string("/instrumentation/attitude-indicator/indicated-pitch-deg");
    directories->insert({index, dir});
    index++;

    // attitude-indicator_indicated-roll-deg
    dir = new string("/instrumentation/attitude-indicator/indicated-roll-deg");
    directories->insert({index, dir});
    index++;

    // attitude-indicator_internal-pitch-deg
    dir = new string("/instrumentation/attitude-indicator/internal-pitch-deg");
    directories->insert({index, dir});
    index++;

    // attitude-indicator_internal-roll-deg
    dir = new string("/instrumentation/attitude-indicator/internal-roll-deg");
    directories->insert({index, dir});
    index++;

    // encoder_indicated-altitude-ft
    dir = new string("/instrumentation/encoder/indicated-altitude-ft");
    directories->insert({index, dir});
    index++;

    // encoder_pressure-alt-ft
    dir = new string("/instrumentation/encoder/pressure-alt-ft");
    directories->insert({index, dir});
    index++;

    // gps_indicated-altitude-ft
    dir = new string("/instrumentation/gps/indicated-altitude-ft");
    directories->insert({index, dir});
    index++;

    // gps_indicated-ground-speed-kt
    dir = new string("/instrumentation/gps/indicated-ground-speed-kt");
    directories->insert({index, dir});
    index++;

    // gps_indicated-vertical-speed
    dir = new string("/instrumentation/gps/indicated-vertical-speed");
    directories->insert({index, dir});
    index++;

    // indicated-heading-deg
    dir = new string("/instrumentation/heading-indicator/indicated-heading"
                     "-deg");
    directories->insert({index, dir});
    index++;


    // magnetic-compass_indicated-heading-deg
    dir = new string("/instrumentation/magnetic-compass/indicated-heading-deg");
    directories->insert({index, dir});
    index++;

    // slip-skid-ball_indicated-slip-skid
    dir = new string("/instrumentation/slip-skid-ball/indicated-slip-skid");
    directories->insert({index, dir});
    index++;

    // turn-indicator_indicated-turn-rate
    dir = new string("/instrumentation/turn-indicator/indicated-turn-rate");
    directories->insert({index, dir});
    index++;

    // vertical-speed-indicator_indicated-speed-fpm
    dir = new string("/instrumentation/vertical-speed-indicator/indicated"
                     "-speed-fpm");
    directories->insert({index, dir});
    index++;

    // flight_aileron
    dir = new string("/controls/flight/aileron");
            directories->insert({index, dir});
    index++;

    // flight_elevator
    dir = new string("/controls/flight/elevator");
    directories->insert({index, dir});
    index++;

    // flight_rudder
    dir = new string("/controls/flight/rudder");
    directories->insert({index, dir});
    index++;

    // flight_flaps
    dir = new string("/controls/flight/flaps");
    directories->insert({index, dir});
    index++;

    // engine_throttle
    dir = new string("/controls/engines/engine/throttle");
    directories->insert({index, dir});
    index++;

    // engine_rpm
    dir = new string("/engines/engine/rpm");
    directories->insert({index, dir});
    index++;
}