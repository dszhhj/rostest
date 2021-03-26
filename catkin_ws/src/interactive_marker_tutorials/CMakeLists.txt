cmake_minimum_required(VERSION 3.0.2)
project(interactive_marker_tutorials)

find_package(catkin REQUIRED COMPONENTS interactive_markers roscpp visualization_msgs tf)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  CATKIN_DEPENDS markers roscpp visualization_msgs tf
)

###########
## Build ##
###########

include_directories(include
  ${catkin_INCLUDE_DIRS}
)

add_executable(basic_controls src/basic_controls.cpp)
target_link_libraries(basic_controls
   ${catkin_LIBRARIES}
)

add_executable(sun src/sunmarker.cpp)
target_link_libraries(sun
   ${catkin_LIBRARIES}
)

add_executable(earth src/earthmarker.cpp)
target_link_libraries(earth
   ${catkin_LIBRARIES}
)

add_executable(moon src/moonmarker.cpp)
target_link_libraries(moon
   ${catkin_LIBRARIES}
)

add_executable(showpath src/earthpoint.cpp)
target_link_libraries(showpath
   ${catkin_LIBRARIES}
)
#############
## Install ##
#############

catkin_install_python(PROGRAMS
  scripts/basic_controls.py
  scripts/cube.py
  scripts/menu.py
  scripts/simple_marker.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Mark executables and/or libraries for installation
install(TARGETS
  moon
  basic_controls
  earth
  sun
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
