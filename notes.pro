QT += core gui widgets

SOURCES += $$files($$PWD/source/*.cpp)

HEADERS += $$files($$PWD/headers/*.h)

INCLUDEPATH += $$PWD/headers \
               $$PWD/source