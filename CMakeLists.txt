# (c) Copyright, Real-Time Innovations, 2021.  All rights reserved.
# RTI grants Licensee a license to use, modify, compile, and create derivative
# works of the software solely for use with RTI Connext DDS. Licensee may
# redistribute copies of the software provided that all such copies are subject
# to this license. The software is provided "as is", with no warranty of any
# type, including any warranty for fitness for any purpose. RTI is under no
# obligation to maintain or support the software. RTI shall not be liable for
# any incidental or consequential damages arising out of the use or inability
# to use the software.

cmake_minimum_required(VERSION 3.1)

PROJECT(dpse_recording_service C)
set(SOURCE_EXTENSION_C c)

set_property(GLOBAL PROPERTY RULE_MESSAGES OFF)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/objs/${RTIME_TARGET_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/objs/${RTIME_TARGET_NAME})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/objs/${RTIME_TARGET_NAME})

set(RTI_LIB_PREFIX rti_me)
set(RTI_LIB_SUFFIX)

if (NOT (DEFINED RTI_SHARED_LIB))
    if (${CMAKE_BUILD_TYPE} MATCHES "[Rr]elease")
        set(RTI_LIB_SUFFIX "z")
        set(RTI_DEBUG_BUILD FALSE)
        add_definitions(-DNDEBUG)
    else()
        set(RTI_LIB_SUFFIX "zd")
        set(RTI_DEBUG_BUILD TRUE)
    endif()
else()
    if(${CMAKE_BUILD_TYPE} MATCHES "[Rr]elease")
        set(RTI_LIB_SUFFIX "")
        set(RTI_DEBUG_BUILD FALSE)
        ADD_DEFINITIONS(-DNDEBUG)
    else()
        set(RTI_LIB_SUFFIX "d")
        set(RTI_DEBUG_BUILD TRUE)
    endif()
endif()

set(IDL_GEN_C
    ${CMAKE_CURRENT_SOURCE_DIR}/Pose.${SOURCE_EXTENSION_C}
    ${CMAKE_CURRENT_SOURCE_DIR}/PosePlugin.${SOURCE_EXTENSION_C}
    ${CMAKE_CURRENT_SOURCE_DIR}/PoseSupport.${SOURCE_EXTENSION_C}
)
set(IDL_GEN_H
    ${CMAKE_CURRENT_SOURCE_DIR}/Pose.h
    ${CMAKE_CURRENT_SOURCE_DIR}/PosePlugin.h
    ${CMAKE_CURRENT_SOURCE_DIR}/PoseSupport.h
)

set(MICRO_C_LIBS 
    rti_me_rhsm${RTI_LIB_SUFFIX} 
    rti_me_whsm${RTI_LIB_SUFFIX} 
    rti_me_discdpse${RTI_LIB_SUFFIX} 
    rti_me${RTI_LIB_SUFFIX}
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    $ENV{RTIMEHOME}/include 
)

link_directories($ENV{RTIMEHOME}/lib/${RTIME_TARGET_NAME})

################################################################################
# location_publisher_1
################################################################################
add_executable(location_publisher_1
    ${CMAKE_CURRENT_SOURCE_DIR}/location_publisher_1.${SOURCE_EXTENSION_C}
    ${IDL_GEN_C}
    ${IDL_GEN_H}
)
target_link_libraries(location_publisher_1 ${MICRO_C_LIBS} ${PLATFORM_LIBS})

################################################################################
# location_publisher_2
################################################################################
add_executable(location_publisher_2
    ${CMAKE_CURRENT_SOURCE_DIR}/location_publisher_2.${SOURCE_EXTENSION_C}
    ${IDL_GEN_C}
    ${IDL_GEN_H}
)
target_link_libraries(location_publisher_2 ${MICRO_C_LIBS} ${PLATFORM_LIBS})

################################################################################
# subscriber
################################################################################
add_executable(location_subscriber 
    ${CMAKE_CURRENT_SOURCE_DIR}/location_subscriber.${SOURCE_EXTENSION_C}
    ${IDL_GEN_C}
    ${IDL_GEN_H}
)
target_link_libraries(location_subscriber ${MICRO_C_LIBS} ${PLATFORM_LIBS})


