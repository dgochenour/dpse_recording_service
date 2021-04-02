# Configuring RTI Recording and Replay Services for use with Connext DDS Cert

## Background

A number of useful tools are included with a Connext DDS Professional installation; two of these are RTI Recording Service and RTI Replay Service.

- Recording Service can be configured to record DDS traffic (including discovery traffic) to a SQLite database.
- Replay Service can play this recording back, simulating the original data source.

In the most common case, DDS applications (including Recording and Replay Services) use dynamic discovery, allowing applications to "automatically" find and match with each other. However, most safety-certified systems use static discovery configurations that-- while requiring more pre-configuration-- allow for a more deterministic system. 

This example demonstrates how to configure Recording Service, Replay Service, and simple DDS applications to work together in a static discovery configuration. This example is based on Connext DDS Micro 2.4.12 because it similar in functionality to Connext DDS Cert.

## Micro applications

Building this project results in three Micro-based applications:

- `location_publisher_1`
- `location_publisher_2`
- `location_subscriber`

All three applications interact with the "`Object Location`" Topic, which is of type `Pose` (defined in `Pose.idl`.)

## Prepare the Micro environment

### Linux
```
$ export RTIMEHOME=/path/to/rti_connext_dds_micro-2.4.12
$ export RTIMEARCH=x64Linux5gcc9.3.0
$ export PATH=$RTIMEHOME/rtiddsgen/scripts:$RTIMEHOME/lib/$RTIMEARCH:$PATH
```
### Windows

- Add the equivalent to that shown above for Linux in the Windows System Environment Variables section.

## Generate type support files 

### Linux
```
$ $RTIMEHOME/rtiddsgen/scripts/rtiddsgen -micro -language C -update typefiles ./Pose.idl
```

### Windows
```
> %RTIMEHOME%\rtiddsgen\scripts\rtiddsgen -micro -language C -create typefiles Pose.idl
```
## Build the Micro example applications

### Linux
```
$ cd your/project/directory
$ $RTIMEHOME/resource/scripts/rtime-make --config Release --build --name $RTIMEARCH --target Linux --source-dir . -G "Unix Makefiles" --delete
```

### Windows
```
> cd your\project\directory 
> %RTIMEHOME%\resource\scripts\rtime-make --config Release --build --name x64Win64VS2017 --target Windows --source-dir . -G "Visual Studio 15 2017 Win64" --delete
```

## Running Recording Service
```
$NDDSHOME/bin/rtirecordingservice -cfgName UserRecordingServiceJson -cfgFile ~/work/dpse_recording_service/cfg/DPSE_RecordingService.xml
```

## Running Replay Service

(From the same directory where the Recording was made.)
```
$NDDSHOME/bin/rtireplayservice -cfgName UserReplayServiceJson -cfgFile ~/work/dpse_recording_service/cfg/DPSE_ReplayService.xml
```
