# A CMake build file for GraphViz. This has been heavily based on the work of
# Gordon Smith at
# https://github.com/hpcc-systems/GraphControl/tree/master/libs/graphlayout.

cmake_minimum_required (VERSION 3.15)

project(GraphViz C CXX)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY  "${CMAKE_BINARY_DIR}/lib")

set(CMAKE_C_FLAGS_DEBUG "-g -gdwarf-2")
set(CMAKE_C_FLAGS_PROFILE "-O1 -g")
set(CMAKE_C_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_DEBUG "-g -gdwarf-2")
set(CMAKE_CXX_FLAGS_PROFILE "-O2 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

#ADD_DEFINITIONS( -DHAVE_CONFIG_H -DHAVE_SETMODE -DMSWIN32)

set(GRAPHVIZ_CMAKE_DIR "${GraphViz_SOURCE_DIR}/CMake")
set(GRAPHVIZ_SRC_DIR "${GraphViz_SOURCE_DIR}")
set(LIB_GRAPHVIZ "graphviz")
set(GRAPHVIZ_LIB_PREFIX "graphviz_lib_")
set(GRAPHVIZ_PLUGIN_PREFIX "graphviz_plugin_")

set(LIB_CDT ${GRAPHVIZ_LIB_PREFIX}cdt)
set(LIB_CIRCOGEN ${GRAPHVIZ_LIB_PREFIX}circogen)
set(LIB_COMMON ${GRAPHVIZ_LIB_PREFIX}common)
set(LIB_DOTGEN ${GRAPHVIZ_LIB_PREFIX}dotgen)
set(LIB_FDPGEN ${GRAPHVIZ_LIB_PREFIX}fdpgen)
set(LIB_GRAPH ${GRAPHVIZ_LIB_PREFIX}graph)
set(LIB_GVC ${GRAPHVIZ_LIB_PREFIX}gvc)
set(LIB_NEATOGEN ${GRAPHVIZ_LIB_PREFIX}neatogen)
set(LIB_ORTHO ${GRAPHVIZ_LIB_PREFIX}ortho)
set(LIB_OSAGE ${GRAPHVIZ_LIB_PREFIX}osage)
set(LIB_PACK ${GRAPHVIZ_LIB_PREFIX}pack)
set(LIB_PATCHWORK ${GRAPHVIZ_LIB_PREFIX}patchwork)
set(LIB_PATHPLAN ${GRAPHVIZ_LIB_PREFIX}pathplan)
set(LIB_SFDPGEN ${GRAPHVIZ_LIB_PREFIX}sfdpgen)
set(LIB_SPARSE ${GRAPHVIZ_LIB_PREFIX}sparse)
set(LIB_TWOPIGEN ${GRAPHVIZ_LIB_PREFIX}twopigen)
set(LIB_XDOT ${GRAPHVIZ_LIB_PREFIX}xdot)
set(LIB_VPSC ${GRAPHVIZ_LIB_PREFIX}vpsc)

set(LIB_PLUGIN_CORE ${GRAPHVIZ_PLUGIN_PREFIX}core)
set(LIB_PLUGIN_DOT_LAYOUT ${GRAPHVIZ_PLUGIN_PREFIX}dot_layout)
set(LIB_PLUGIN_NEATO_LAYOUT ${GRAPHVIZ_PLUGIN_PREFIX}neato_layout)

include_directories (
    ${GRAPHVIZ_SRC_DIR}/lib/graph
    ${GRAPHVIZ_SRC_DIR}/lib/pathplan
    ${GRAPHVIZ_SRC_DIR}/lib/common
    ${GRAPHVIZ_SRC_DIR}/lib/gvc
    ${GRAPHVIZ_SRC_DIR}/lib/dotgen
    ${GRAPHVIZ_SRC_DIR}/lib/neatogen
    ${GRAPHVIZ_SRC_DIR}/lib/fdpgen
    ${GRAPHVIZ_SRC_DIR}/lib/sfdpgen
    ${GRAPHVIZ_SRC_DIR}/lib/cdt
    ${GRAPHVIZ_SRC_DIR}/lib/twopigen
    ${GRAPHVIZ_SRC_DIR}/lib/circogen
    ${GRAPHVIZ_SRC_DIR}/lib/patchwork
    ${GRAPHVIZ_SRC_DIR}/lib/sfdpgen
    ${GRAPHVIZ_SRC_DIR}/lib/sparse
    ${GRAPHVIZ_SRC_DIR}/lib/xdot
    ${GRAPHVIZ_SRC_DIR}/lib/gd
    ${GRAPHVIZ_SRC_DIR}/lib/ortho
    ${GRAPHVIZ_SRC_DIR}/lib/vpsc
    ${GRAPHVIZ_SRC_DIR}/lib/pack
    ${GRAPHVIZ_SRC_DIR}
)

add_definitions(-DHAVE_CONFIG_H -DHAVE_SETMODE)

add_subdirectory(${GRAPHVIZ_CMAKE_DIR}/lib/cdt)
add_subdirectory(${GRAPHVIZ_CMAKE_DIR}/lib/circogen)
add_subdirectory(${GRAPHVIZ_CMAKE_DIR}/lib/common)
add_subdirectory(${GRAPHVIZ_CMAKE_DIR}/lib/dotgen)
add_subdirectory(${GRAPHVIZ_CMAKE_DIR}/lib/fdpgen)
add_subdirectory(${GRAPHVIZ_CMAKE_DIR}/lib/graph)
add_subdirectory(${GRAPHVIZ_CMAKE_DIR}/lib/gvc)
add_subdirectory(${GRAPHVIZ_CMAKE_DIR}/lib/neatogen)
add_subdirectory(${GRAPHVIZ_CMAKE_DIR}/lib/osage)
add_subdirectory(${GRAPHVIZ_CMAKE_DIR}/lib/ortho)
add_subdirectory(${GRAPHVIZ_CMAKE_DIR}/lib/pack)
add_subdirectory(${GRAPHVIZ_CMAKE_DIR}/lib/patchwork)
add_subdirectory(${GRAPHVIZ_CMAKE_DIR}/lib/pathplan)
add_subdirectory(${GRAPHVIZ_CMAKE_DIR}/lib/sfdpgen)
add_subdirectory(${GRAPHVIZ_CMAKE_DIR}/lib/sparse)
add_subdirectory(${GRAPHVIZ_CMAKE_DIR}/lib/twopigen)
add_subdirectory(${GRAPHVIZ_CMAKE_DIR}/lib/xdot)
add_subdirectory(${GRAPHVIZ_CMAKE_DIR}/lib/vpsc)

add_subdirectory(${GRAPHVIZ_CMAKE_DIR}/plugin/core)
add_subdirectory(${GRAPHVIZ_CMAKE_DIR}/plugin/dot_layout)
add_subdirectory(${GRAPHVIZ_CMAKE_DIR}/plugin/neato_layout)

add_library(
    ${LIB_GRAPHVIZ}
    ${GRAPHVIZ_CMAKE_DIR}/graphviz-static.c
)

target_link_libraries(${LIB_GRAPHVIZ}
    ${LIB_PLUGIN_CORE}
    ${LIB_PLUGIN_DOT_LAYOUT}
    ${LIB_PLUGIN_NEATO_LAYOUT}
)


add_library(graphviz::cdt       ALIAS ${LIB_CDT})
add_library(graphviz::circogen  ALIAS ${LIB_CIRCOGEN})
add_library(graphviz::common    ALIAS ${LIB_COMMON})
add_library(graphviz::dotgen    ALIAS ${LIB_DOTGEN})
add_library(graphviz::fdpgen    ALIAS ${LIB_FDPGEN})
add_library(graphviz::graph     ALIAS ${LIB_GRAPH})
add_library(graphviz::gvc       ALIAS ${LIB_GVC})
add_library(graphviz::neatogen  ALIAS ${LIB_NEATOGEN})
add_library(graphviz::ortho     ALIAS ${LIB_ORTHO})
add_library(graphviz::osage     ALIAS ${LIB_OSAGE})
add_library(graphviz::pack      ALIAS ${LIB_PACK})
add_library(graphviz::patchwork ALIAS ${LIB_PATCHWORK})
add_library(graphviz::pathplan  ALIAS ${LIB_PATHPLAN})
add_library(graphviz::sfdgen    ALIAS ${LIB_SFDPGEN})
add_library(graphviz::sparse    ALIAS ${LIB_SPARSE})
add_library(graphviz::twopigen  ALIAS ${LIB_TWOPIGEN})
add_library(graphviz::xdot      ALIAS ${LIB_XDOT})
add_library(graphviz::vpsc      ALIAS ${LIB_VPSC})

add_library(graphviz::plugin_core ALIAS ${LIB_PLUGIN_CORE})
add_library(graphviz::plugin_dot_layout ALIAS ${LIB_PLUGIN_DOT_LAYOUT})
add_library(graphviz::plugin_neato_layout ALIAS ${LIB_PLUGIN_NEATO_LAYOUT})

add_library(graphviz::graphviz ALIAS ${LIB_GRAPHVIZ})


# dd

target_include_directories(${LIB_CDT}        PUBLIC  ${GRAPHVIZ_SRC_DIR}/lib/cdt          )
target_include_directories(${LIB_CIRCOGEN}   PUBLIC  ${GRAPHVIZ_SRC_DIR}/lib/circogen          )
target_include_directories(${LIB_COMMON}     PUBLIC  ${GRAPHVIZ_SRC_DIR}/lib/common          )
target_include_directories(${LIB_DOTGEN}     PUBLIC  ${GRAPHVIZ_SRC_DIR}/lib/dotgen          )
target_include_directories(${LIB_FDPGEN}     PUBLIC  ${GRAPHVIZ_SRC_DIR}/lib/fdpgen          )
target_include_directories(${LIB_GRAPH}      PUBLIC  ${GRAPHVIZ_SRC_DIR}/lib/graph          )
target_include_directories(${LIB_GVC}        PUBLIC  ${GRAPHVIZ_SRC_DIR}/lib/gvc          )
target_include_directories(${LIB_NEATOGEN}   PUBLIC  ${GRAPHVIZ_SRC_DIR}/lib/neatogen          )
target_include_directories(${LIB_ORTHO}      PUBLIC  ${GRAPHVIZ_SRC_DIR}/lib/ortho          )
target_include_directories(${LIB_OSAGE}      PUBLIC  ${GRAPHVIZ_SRC_DIR}/lib/osage          )
target_include_directories(${LIB_PACK}       PUBLIC  ${GRAPHVIZ_SRC_DIR}/lib/pack          )
target_include_directories(${LIB_PATCHWORK}  PUBLIC  ${GRAPHVIZ_SRC_DIR}/lib/patchwork          )
target_include_directories(${LIB_PATHPLAN}   PUBLIC  ${GRAPHVIZ_SRC_DIR}/lib/pathplan          )
target_include_directories(${LIB_SFDPGEN}    PUBLIC  ${GRAPHVIZ_SRC_DIR}/lib/sfdgen          )
target_include_directories(${LIB_SPARSE}     PUBLIC  ${GRAPHVIZ_SRC_DIR}/lib/sparse          )
target_include_directories(${LIB_TWOPIGEN}   PUBLIC  ${GRAPHVIZ_SRC_DIR}/lib/twopigen          )
target_include_directories(${LIB_XDOT}       PUBLIC  ${GRAPHVIZ_SRC_DIR}/lib/xdot          )
target_include_directories(${LIB_VPSC}       PUBLIC  ${GRAPHVIZ_SRC_DIR}/lib/vpsc          )

target_include_directories(${LIB_PLUGIN_CORE}         PUBLIC ${GRAPHVIZ_SRC_DIR}/plugin/core)
target_include_directories(${LIB_PLUGIN_DOT_LAYOUT}   PUBLIC ${GRAPHVIZ_SRC_DIR}/plugin/dot_layout)
target_include_directories(${LIB_PLUGIN_NEATO_LAYOUT} PUBLIC ${GRAPHVIZ_SRC_DIR}/plugin/neato_layout)

target_include_directories(${LIB_GRAPHVIZ}            PUBLIC ${GRAPHVIZ_SRC_DIR} ${GRAPHVIZ_CMAKE_DIR})

