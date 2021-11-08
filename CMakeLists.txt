cmake_minimum_required(VERSION 3.16)
project(Project-2-CS1D)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_PREFIX_PATH "~/Qt/6.1.2/gcc_64/lib/cmake")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets Sql)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Sql)

add_executable(Project-2-CS1D
        main.cpp
        mainwindow.cpp mainwindow.h  mainwindow.ui
        db.cpp db.h
        display_team.cpp display_team.h display_team.ui display_teams.ui
        login.cpp login.h login.ui
        trip.cpp trip.h trip.h
        )

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
