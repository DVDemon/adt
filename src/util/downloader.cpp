#include "downloader.h"
#include <curl/curl.h>
#include <iostream>
#include <cstring>

namespace util
{
    long Downloader::sync_get_as_string(const std::string &url, std::string &out, const std::string &identity)
    {
        CURL *curl;

        curl = curl_easy_init();
        if (curl)
        {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            if (!identity.empty())
                curl_easy_setopt(curl, CURLOPT_USERPWD, identity.c_str()); // user:pass
            curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
            curl_easy_setopt(curl, CURLOPT_FORBID_REUSE, 1L);
            curl_easy_setopt(curl, CURLOPT_CAINFO, "rootcert.pem");
            curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);

            static auto callback = [](void *contents, size_t size, size_t nmemb, void *userp)
            {
                ((std::string *)userp)->append((char *)contents, size * nmemb);
                return size * nmemb;
            };
            using func_ptr = size_t (*)(void *, size_t, size_t, void *);

            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, (func_ptr)callback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);

            curl_easy_perform(curl);
            long code{};
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &code);
            // char *ct;
            // curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);
            // result.content_type = ct;
            // result.result = response_string;

            curl_easy_cleanup(curl);
            curl_global_cleanup();

            return code;
        }
        else
            throw std::logic_error("unable to start curl");
    }

    long Downloader::sync_post_json(const std::string &url, const std::string &json, std::string &out, const std::string &identity)
    {
        CURL *curl;

        curl = curl_easy_init();
        if (curl)
        {
            struct curl_slist *slist = nullptr;

            slist = curl_slist_append(slist, "Content-Type: application/json");

            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            if (!identity.empty())
                curl_easy_setopt(curl, CURLOPT_USERPWD, identity.c_str()); // user:pass
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json.c_str());
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, slist);
            curl_easy_setopt(curl, CURLOPT_FORBID_REUSE, 1L);
            curl_easy_setopt(curl, CURLOPT_CAINFO, "rootcert.pem");
            curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);

            static auto callback2 = [](void *contents, size_t size, size_t nmemb, void *userp)
            {
                ((std::string *)userp)->append((char *)contents, size * nmemb);
                return size * nmemb;
            };
            using func_ptr = size_t (*)(void *, size_t, size_t, void *);

            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, (func_ptr)callback2);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);

            curl_easy_perform(curl);
            long code{};
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &code);
            // char *ct;
            // curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);
            // result.content_type = ct;
            // result.result = response_string;

            curl_easy_cleanup(curl);
            curl_global_cleanup();
            curl_slist_free_all(slist);

            return code;
        }
        else
            throw std::logic_error("unable to start curl");
    }

    long Downloader::sync_get_as_binary(const std::string &url, std::vector<uint8_t> &out, const std::string &identity)
    {
        CURL *curl;

        curl = curl_easy_init();
        if (curl)
        {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            if (!identity.empty())
                curl_easy_setopt(curl, CURLOPT_USERPWD, identity.c_str()); // user:pass
            curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
            curl_easy_setopt(curl, CURLOPT_FORBID_REUSE, 1L);
            curl_easy_setopt(curl, CURLOPT_CAINFO, "rootcert.pem");
            curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);

            static auto callback = [](void *contents, size_t size, size_t nmemb, void *userp)
            {
                ((std::vector<uint8_t> *)userp)->insert(std::end(*((std::vector<uint8_t> *)userp)), (uint8_t *)contents, (uint8_t *)contents + size * nmemb);

                return size * nmemb;
            };
            using func_ptr = size_t (*)(void *, size_t, size_t, void *);

            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, (func_ptr)callback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);

            curl_easy_perform(curl);
            long code{};
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &code);
            // char *ct;
            // curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);
            // result.content_type = ct;
            // result.result = response_string;

            curl_easy_cleanup(curl);
            curl_global_cleanup();

            return code;
        }
        else
            throw std::logic_error("unable to start curl");
    }
}