#!/bin/bash
ant build-native-extension -DExtension.ASC_VERSION=2
ant run-debug-swf
