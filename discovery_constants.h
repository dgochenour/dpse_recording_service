/*
* (c) Copyright, Real-Time Innovations, 2021.  All rights reserved.
* RTI grants Licensee a license to use, modify, compile, and create derivative
* works of the software solely for use with RTI Connext DDS. Licensee may
* redistribute copies of the software provided that all such copies are subject
* to this license. The software is provided "as is", with no warranty of any
* type, including any warranty for fitness for any purpose. RTI is under no
* obligation to maintain or support the software. RTI shall not be liable for
* any incidental or consequential damages arising out of the use or inability
* to use the software.
*/

#ifndef DISCOVERY_CONSTANTS_H
#define DISCOVERY_CONSTANTS_H

static const char *k_PARTICIPANT01_NAME             = "location_publisher_1";
static const int k_OBJ_ID_PARTICIPANT01_DW01        = 100;

static const char *k_PARTICIPANT02_NAME             = "location_publisher_2";
static const int k_OBJ_ID_PARTICIPANT02_DW01        = 110;

static const char *k_PARTICIPANT03_NAME             = "location_subscriber";
static const int k_OBJ_ID_PARTICIPANT03_DR01        = 120;

// contants for Admin Console
static const char *k_PARTICIPANT_ADMINCONSOLE_NAME  = "Data Visualization";
static const int k_OBJ_ID_ADMINCONSOLE_DR01         = 200;

// constants for rti_recording_service
static const char *k_PARTICIPANT_RECORDING_NAME     = "rti_recording_service";
static const int k_OBJ_ID_RECORDING_DR01            = 300;

// constants for rti_replay_service
static const char *k_PARTICIPANT_REPLAY_NAME        = "rti_replay_service";
static const int k_OBJ_ID_REPLAY_DW01               = 310;

#endif