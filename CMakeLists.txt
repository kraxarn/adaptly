cmake_minimum_required(VERSION 3.16)
project(adaptly VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.7 REQUIRED COMPONENTS Core Gui Quick QuickControls2)

qt_standard_project_setup(
	REQUIRES 6.7
)

qt_add_executable(${PROJECT_NAME})

add_subdirectory(src)
include(QmlModule.cmake)

target_include_directories(${PROJECT_NAME} PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/src"
	# QML requires headers in root
	"${CMAKE_CURRENT_SOURCE_DIR}/src/qml"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/entity"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/model"
)

target_compile_definitions(${PROJECT_NAME} PRIVATE APP_NAME="${PROJECT_NAME}")
target_compile_definitions(${PROJECT_NAME} PRIVATE APP_VERSION="v${PROJECT_VERSION}")
target_compile_definitions(${PROJECT_NAME} PRIVATE ORG_NAME="${PROJECT_NAME}")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	target_compile_definitions(${PROJECT_NAME} PRIVATE QT_QML_DEBUG)
endif ()

include(cmake/AndroidVersionCode.cmake)
android_version_code(ANDROID_VERSION_CODE)

set_target_properties(${PROJECT_NAME} PROPERTIES
	WIN32_EXECUTABLE TRUE
	MACOSX_BUNDLE TRUE
	QT_ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/res/app/android"
	QT_ANDROID_VERSION_NAME ${PROJECT_VERSION}
	QT_ANDROID_VERSION_CODE ${ANDROID_VERSION_CODE}
	QT_ANDROID_PACKAGE_NAME "com.kraxarn.${PROJECT_NAME}"
	QT_ANDROID_APP_NAME "Adaptly"
	QT_ANDROID_APP_ICON "@mipmap/ic_launcher"
	QT_ENABLE_VERBOSE_DEPLOYMENT TRUE
)

target_link_libraries(${PROJECT_NAME} PRIVATE
	Qt6::Core
	Qt6::Gui
	Qt6::Quick
	Qt6::QuickControls2
)