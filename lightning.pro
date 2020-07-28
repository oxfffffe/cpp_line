TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -O2

SOURCES += \
        src/Lightning/Line/line.cpp             \
        src/Lightning/Regex/regex.cpp           \
        src/main.cpp

HEADERS += \
        src/Lightning/Allocator/allocator.hpp   \
        src/defines.hpp                         \
        src/Lightning/namespace/lightning.hpp   \
        src/Lightning/Line/line.hpp             \
        src/Lightning/Regex/regex.hpp
