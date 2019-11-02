//
// Created by liuningning on 2019-11-02.
//


#ifndef VOICECHANGE_ANDROIDLOG_H
#define VOICECHANGE_ANDROIDLOG_H

#include "android/log.h"

#define  TAG "voice"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG,__VA_ARGS__)

#endif //VOICECHANGE_ANDROIDLOG_H
