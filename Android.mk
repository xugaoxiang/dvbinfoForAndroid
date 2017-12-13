LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)
LOCAL_SRC_FILES :=  buffer.c dvbinfo.c libdvbpsi.c tcp.c udp.c

LOCAL_MODULE := dvbinfo

LOCAL_C_INCLUDES := external/dvbinfo

LOCAL_CFLAGS := -O2 -std=gnu99 -g -W -Wall -D__ANDROID__
LOCAL_SYSTEM_SHARED_LIBRARIES := libc libdvbpsi

include $(BUILD_EXECUTABLE)
