cmake_minimum_required(VERSION 3.0.0)
project(WindowsRichPresence VERSION 0.1.0)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# -- FETCH CPR --------------------------------------------------------------
set(CPR_BUILD_TESTS_SSL OFF)
set(CPR_BUILD_TESTS OFF)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG f4622efcb59d84071ae11404ae61bd821c1c344b) # the commit hash for 1.6.2
FetchContent_MakeAvailable(cpr)

# -- FETCH FTXUI --------------------------------------------------------------
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui GIT_TAG cecd54df42dd66fdf8386ed461e16b725bffc827)
 
FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

add_executable(WindowsRichPresence main.cpp)
target_link_libraries(
    ${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/RichPresence/libs/discord-rpc.lib" 
    PRIVATE cpr::cpr PRIVATE #ftxui::screen PRIVATE ftxui::dom
    )

