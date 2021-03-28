# dpse_recording_service
Example configuration showing the use of RTI Recording Service with Micro applications and static endpoint discovery

# Generate type support files 
```
$RTIMEHOME/rtiddsgen/scripts/rtiddsgen -micro -language C -update typefiles ./Pose.idl
```

# Build the example
```
$RTIMEHOME/resource/scripts/rtime-make --config Release --build --name $RTIMEARCH --target Linux --source-dir . -G "Unix Makefiles" --delete
```