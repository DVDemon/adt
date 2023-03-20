#pragma once
#include <string>
#include <optional>
#include <vector>

namespace util{
    struct Downloader{
        static long sync_get_as_string(const std::string &url,std::string &out,const std::string &identity);
        static long sync_post_json(const std::string &url,const std::string &json,std::string &out,const std::string &identity);
        static long sync_get_as_binary(const std::string &url,std::vector<uint8_t> &out,const std::string &identity);
    };
}