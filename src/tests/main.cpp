#include <iostream>
#include <string>
#include "../util/downloader.h"

#include <fstream>
#include <iostream>

auto main() -> int
{
    std::string content;
    long res = util::Downloader::sync_get_as_string("https://www.google.com/", content, "");
    std::cout << res << std::endl;
    std::cout << content << std::endl;

    std::vector<uint8_t> binary_content;
    res = util::Downloader::sync_get_as_binary("https://www.google.com/images/branding/googlelogo/2x/googlelogo_light_color_272x92dp.png", binary_content, "");
    std::cout << res << std::endl;

    std::ofstream os;
    os.open("some.png",std::ios_base::binary);
    os.write((const char*)binary_content.data(),binary_content.size());
    os.close();

    std::string json {"{\'aaa\':\'bbb\'}"};
    res = util::Downloader::sync_post_json("https://httpbin.org/post",json,content,"");
    std::cout << res << std::endl;
    std::cout << content << std::endl;
}