cmake_minimum_required(VERSION 3.10)

# Project name
project(bot)

# Find CURL library
find_package(CURL REQUIRED)

# Add executable
add_executable(bot main.cpp request.cpp read.cpp randomline.cpp)

# Link curlpp and CURL
target_link_libraries(bot curlpp CURL::libcurl)

# Include nlohmann/json headers
target_include_directories(bot PRIVATE external/json/include )
