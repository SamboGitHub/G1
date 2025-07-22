// C++ library headers
#include <iostream>
#include <stdio.h>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <cassert>
#include <iomanip>

#include <sstream>
#include <string>
#include <type_traits>
#include <utility>

// project headers
#include "ip4_address.h"
#include "tcp4_socket.h"

const char DEFAULT_PORT[] = "7000";

std::string escape_json(const std::string &s) {
    std::ostringstream o;
    for (auto c = s.cbegin(); c != s.cend(); c++) {
        switch (*c) {
        case '"': o << "\\\""; break;
        case '\\': o << "\\\\"; break;
        case '\b': o << "\\b"; break;
        case '\f': o << "\\f"; break;
        case '\n': o << "\\n"; break;
        case '\r': o << "\\r"; break;
        case '\t': o << "\\t"; break;
        default:
            if ('\x00' <= *c && *c <= '\x1f') {
                o << "\\u"
                  << std::hex << std::setw(4) << std::setfill('0') << static_cast<int>(*c);
            } else {
                o << *c;
            }
        }
    }
    return o.str();
};

int main(int argc, char **argv)
{
    // if (argc != 4)
    // {
    //     std::cerr << "usage: jsontest <ip-address>  <port> <json>" << std::endl;
    //     exit(-1);
    // }

    using json = nlohmann::json;
    std::string server_address_string(argv[1]);
    std::string server_port_string(argv[2]);
    std::string json_input(argv[3]);
    std::string json_output;
    // std::string json_data;
    json json_data;


printf(argv[1],"\n");
printf(argv[2],"\n");
printf(argv[3],"\n");
    //     // json_string = json(j.dump()).dump() << std::endl;
        json_output = escape_json(json_input);

        std::cout << json_output << "out \n";

    // try
    // {
    //     ip4_address_t server_address(server_address_string, server_port_string);
    //     tcp4_socket_t socket;
    //     socket.connect(server_address);

    //     // at this point, socket.stream() is a std::iostream suitable for



    //     // json_string = json(j.dump()).dump() << std::endl;
    //     json_output = escape_json(json_input);

    //     socket.stream() << json_output << "\r\n";

    //     // writing to and reading from the connected socket.

    //     while (!socket.stream().eof())
    //     {
    //         std::string line;
    //         std::getline(socket.stream(), line);
    //         std::cout << line << std::endl;

    //         printf("Begin Parsing\n");
    //         json_data = json::parse(line);

    //     }
    // }
    //     catch (const char *error_message)
    //     {
    //         std::cerr << error_message << std::endl;
    //         exit(-1);
    //     }



    }