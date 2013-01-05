LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := v8_base
LOCAL_SRC_FILES := ../libs/libv8_base.a

include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE := v8_snapshot
LOCAL_SRC_FILES := ../libs/libv8_snapshot.a

include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE := canny
LOCAL_SRC_FILES := canny.cpp js/*.cpp
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../include
LOCAL_LDLIBS := -llog -landroid
LOCAL_STATIC_LIBRARIES := v8_base v8_snapshot

include $(BUILD_SHARED_LIBRARY)
