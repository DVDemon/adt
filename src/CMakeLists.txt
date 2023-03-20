cmake_minimum_required(VERSION 3.10)


SET(JIRA_IMPORTER jira_importer)
SET(CNF_PRODUCT_IMPORTER cnf_product_importer)
SET(CNF_ADR_IMPORTER cnf_adr_importer)
SET(CNF_TECHCOM_IMPORTER cnf_techcom_importer)
SET(GIT_ARCH_IMPORTER git_arch_importer)
SET(CNF_EXPORTER cnf_exporter)
SET(MAIL_EXPORTER mail_exporter)
SET(CORE_LOADER core_loader)
SET(UTIL util_library)
SET(TEST tests)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(REDISCPP_FLAGS "-DREDISCPP_HEADER_ONLY=ON")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall ${REDISCPP_FLAGS}")
SET(CMAKE_CXX_FLAGS_RELEASE "-O3 -g0 -std=${STD_CXX} -Wall -DNDEBUG ${REDISCPP_FLAGS}")

find_package(OpenSSL)
find_package(Threads)
find_package(ZLIB)
find_package(Poco REQUIRED COMPONENTS Foundation Util Net XML JSON Crypto NetSSL MongoDB Data)

include_directories(${Poco_INCLUDE_DIRS})

add_library(${UTIL} util/config.cpp util/downloader.cpp)
target_link_libraries(${UTIL} PRIVATE ${CMAKE_THREAD_LIBS_INIT} curl)  

add_executable(${JIRA_IMPORTER} tasks/jira_importer/main.cpp)
target_link_libraries(${JIRA_IMPORTER} PRIVATE ${UTIL} ${CMAKE_THREAD_LIBS_INIT} ${Poco_LIBRARIES} ZLIB::ZLIB OpenSSL::SSL OpenSSL::Crypto)                                   

add_executable(${CNF_PRODUCT_IMPORTER} tasks/cnf_product_importer/main.cpp)
target_link_libraries(${CNF_PRODUCT_IMPORTER} PRIVATE ${UTIL} ${CMAKE_THREAD_LIBS_INIT} ${Poco_LIBRARIES} ZLIB::ZLIB OpenSSL::SSL OpenSSL::Crypto)                                   

add_executable(${CNF_ADR_IMPORTER} tasks/cnf_adr_importer/main.cpp)
target_link_libraries(${CNF_ADR_IMPORTER} PRIVATE ${UTIL} ${CMAKE_THREAD_LIBS_INIT} ${Poco_LIBRARIES} ZLIB::ZLIB OpenSSL::SSL OpenSSL::Crypto)          

add_executable(${CNF_TECHCOM_IMPORTER} tasks/cnf_techcom_importer/main.cpp)
target_link_libraries(${CNF_TECHCOM_IMPORTER} PRIVATE ${UTIL} ${CMAKE_THREAD_LIBS_INIT} ${Poco_LIBRARIES} ZLIB::ZLIB OpenSSL::SSL OpenSSL::Crypto)          

add_executable(${GIT_ARCH_IMPORTER} tasks/git_arch_importer/main.cpp)
target_link_libraries(${GIT_ARCH_IMPORTER} PRIVATE ${UTIL} ${CMAKE_THREAD_LIBS_INIT} ${Poco_LIBRARIES} ZLIB::ZLIB OpenSSL::SSL OpenSSL::Crypto)          

add_executable(${CNF_EXPORTER} tasks/cnf_exporter/main.cpp)
target_link_libraries(${CNF_EXPORTER} PRIVATE ${UTIL} ${CMAKE_THREAD_LIBS_INIT} ${Poco_LIBRARIES} ZLIB::ZLIB OpenSSL::SSL OpenSSL::Crypto)          

add_executable(${MAIL_EXPORTER} tasks/mail_exporter/main.cpp)
target_link_libraries(${MAIL_EXPORTER} PRIVATE ${UTIL} ${CMAKE_THREAD_LIBS_INIT} ${Poco_LIBRARIES} ZLIB::ZLIB OpenSSL::SSL OpenSSL::Crypto)          

add_executable(${CORE_LOADER} tasks/core_loader/main.cpp)
target_link_libraries(${CORE_LOADER} PRIVATE ${UTIL} ${CMAKE_THREAD_LIBS_INIT} ${Poco_LIBRARIES} ZLIB::ZLIB OpenSSL::SSL OpenSSL::Crypto)          

add_executable(${TEST} tests/main.cpp)
target_link_libraries(${TEST} PRIVATE ${UTIL} ${CMAKE_THREAD_LIBS_INIT} ${Poco_LIBRARIES} ZLIB::ZLIB OpenSSL::SSL OpenSSL::Crypto)          
