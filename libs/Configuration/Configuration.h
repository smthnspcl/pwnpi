//
// Created by insane on 17.01.19.
//

#ifndef PWNPI_CONFIGURATION_H
#define PWNPI_CONFIGURATION_H

#include <string>
#include <vector>
#include <unistd.h>
#include "../Json/json.hpp"

using nlohmann::json;


namespace bc {
    struct BluetoothConfiguration {
        std::string interface;
    };

    inline void to_json(json& j, const bc::BluetoothConfiguration& d){
        j = json{{"interface", d.interface}, {}, {}};
    }

    inline void from_json(const json& j, bc::BluetoothConfiguration& d){
        d.interface = j.at("interface");
    }
}

namespace wc {
    struct WifiConfiguration {
        bool promiscuous;
        std::string interface;
    };

    inline void to_json(json& j, const wc::WifiConfiguration& d){
        j = json{{"promiscuous", d.promiscuous}, {"interface", d.interface}, {}};
    }

    inline void from_json(const json& j, wc::WifiConfiguration& d){
        d.promiscuous = j.at("promiscuous");
        d.interface = j.at("interface");
    }
}

namespace gc {
    struct GPSConfiguration {

    };

    inline void to_json(json& j, const gc::GPSConfiguration& d){
        j = json{{}, {}, {}};
    }

    inline void from_json(const json& j, gc::GPSConfiguration& d){

    }
}

namespace db {
    struct DatabaseConfiguration {
        std::string file;
    };

    inline void to_json(json& j, const db::DatabaseConfiguration& d){
        j = json{{"file", d.file}, {}, {}};
    }

    inline void from_json(const json& j, db::DatabaseConfiguration& d){
        d.file = j.at("file");
    }
}

namespace sc {
    struct SystemConfiguration {
        bool lipo = false;
        bool debug = false;
        bool verbose = false;
    };

    inline void to_json(json& j, const sc::SystemConfiguration& d){
        j = json{{"lipo", d.lipo}, {"debug", d.debug}, {"verbose", d.verbose}};
    }

    inline void from_json(const json& j, sc::SystemConfiguration& d){
        d.lipo = j.at("lipo");
        d.debug = j.at("debug");
        d.verbose = j.at("verbose");
    }
}


class Configuration {
private:
    bool debug = false;
    bool verbose = false;
    bool lipo = false;

    bc::BluetoothConfiguration bluetoothConfiguration;
    wc::WifiConfiguration wifiConfiguration;
    gc::GPSConfiguration gpsConfiguration;
    db::DatabaseConfiguration databaseConfiguration;
    sc::SystemConfiguration systemConfiguration;

    static bool in_array(std::string key, std::vector<std::string> array);
    static void help();

public:
    static Configuration* parse_arguments(int argc, char** argv);

    Configuration();

    bc::BluetoothConfiguration getBluetoothConfiguration();
    wc::WifiConfiguration getWifiConfiguration();
    gc::GPSConfiguration getGPSConfiguration();
    db::DatabaseConfiguration getDatabaseConfiguration();
    sc::SystemConfiguration getSystemConfiguration();
};


#endif //PWNPI_CONFIGURATION_H