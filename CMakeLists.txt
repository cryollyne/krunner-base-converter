cmake_minimum_required(VERSION 3.16)
project(Base-Converter-Runner)

set(KF6_MIN_VERSION "6.0.0")

find_package(ECM ${KF6_MIN_VERSION} REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR} ${CMAKE_MODULE_PATH})

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)
include(FeatureSummary)

find_package(KF6 ${KF6_MIN_VERSION} REQUIRED COMPONENTS I18n Config Runner)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

kcoreaddons_add_plugin(
    base_converter_runner
    SOURCES
        src/base_converter_runner.cpp
        src/base_converter_runner.hpp
    INSTALL_NAMESPACE "kf6/krunner"
)

target_link_libraries(base_converter_runner
    KF6::I18n
    KF6::ConfigCore
    KF6::Runner
    Qt6::Core
    Qt6::Widgets
)
