#ifndef CANNY_LOG_H
#define CANNY_LOG_H

#include <android/log.h>

#define LOG_TAG "canny"

#define LOG_FORMAT(prio, ...) ((void)__android_log_print(prio, LOG_TAG, __VA_ARGS__))
#define LOG(prio, text) ((void)__android_log_write(prio, LOG_TAG, text))

#define LOGFF(...) LOG_FORMAT(ANDROID_LOG_FATAL, __VA_ARGS__)
#define LOGDF(...) LOG_FORMAT(ANDROID_LOG_DEBUG, __VA_ARGS__)
#define LOGEF(...) LOG_FORMAT(ANDROID_LOG_ERROR, __VA_ARGS__)
#define LOGIF(...) LOG_FORMAT(ANDROID_LOG_INFO, __VA_ARGS__)
#define LOGVF(...) LOG_FORMAT(ANDROID_LOG_VERBOSE, __VA_ARGS__)
#define LOGWF(...) LOG_FORMAT(ANDROID_LOG_INFO, __VA_ARGS__)

#define LOGF(text) LOG(ANDROID_LOG_FATAL, text)
#define LOGD(text) LOG(ANDROID_LOG_DEBUG, text)
#define LOGE(text) LOG(ANDROID_LOG_ERROR, text)
#define LOGI(text) LOG(ANDROID_LOG_INFO, text)
#define LOGV(text) LOG(ANDROID_LOG_VERBOSE, text)
#define LOGW(text) LOG(ANDROID_LOG_INFO, text)

#endif /* CANNY_LOG_H */
