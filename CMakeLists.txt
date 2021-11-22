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
        UI/mainwindow/mainwindow.cpp UI/mainwindow/mainwindow.h UI/mainwindow/mainwindow.ui
        Admin/admin.cpp Admin/admin.h Admin/admin.ui
        db.cpp db.h
        UI/display_team/display_team.cpp UI/display_team/display_team.h UI/display_team/display_team.ui UI/display_team/display_teams.ui
        UI/login/login.cpp UI/login/login.h UI/login/login.ui
        UI/trip/trip.cpp UI/trip/trip.h UI/trip/trip.ui
        UI/edit_teams/edit_teams.cpp UI/edit_teams/edit_teams.h UI/edit_teams/edit_teams.ui
        UI/edit_souvenirs/edit_souvenirs.cpp UI/edit_souvenirs/edit_souvenirs.h UI/edit_souvenirs/edit_souvenirs.ui
        main.cpp
        )

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
