TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        bayes_filter.cpp \
        bayes_filter_data.cpp \
        bayes_filter_initialize.cpp \
        bayes_filter_terminate.cpp \
        conv2stateno.cpp \
        fileManager.cpp \
        pch.cpp \
        system_od_bayes.cpp

HEADERS += \
    bayes_filter.h \
    bayes_filter_data.h \
    bayes_filter_initialize.h \
    bayes_filter_terminate.h \
    bayes_filter_types.h \
    coder_array.h \
    conv2stateno.h \
    fileManager.h \
    main.h \
    pch.h \
    rtwtypes.h \
    tmwtypes.h
