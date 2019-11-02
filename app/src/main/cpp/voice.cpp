#include <jni.h>
#include <string>
#include <unistd.h>
#include "fmod.hpp"
#include "androidlog.h"

using namespace FMOD;


//普通声音
#define MODE_NORMAL  0
//萝莉声音
#define  MODE_LOLITA 1
//大叔声音
#define MODE_UNCLE 2
//惊悚声音
#define MODE_PANIC 3
//搞怪声音
#define MODE_FUNNY 4
// 空灵声音
#define MODE_ARTISTIC  5


extern "C"
JNIEXPORT void JNICALL
Java_me_liuningning_voicechange_VoiceChange_nativePlay(JNIEnv *env, jobject thiz, jstring path,
                                                       jint mode) {


    FMOD_RESULT result;

    System *system;
    Sound *sound;
    Channel *channel;
    DSP *dsp;
    bool playing = true;

    const char *voicePath = env->GetStringUTFChars(path, 0);

    //create system
    result = System_Create(&system);

    if (result != FMOD_OK) {
        LOGW("create system failed result:%d",result);
        goto release;
    }
    result = system->init(32, FMOD_INIT_NORMAL, NULL);
    if (result != FMOD_OK) {
        LOGW("init system failed result:%d",result);
        goto release;
    }

    result = system->createSound(voicePath, FMOD_DEFAULT, 0, &sound);
    if (result != FMOD_OK) {
        LOGW("init sound failed result:%d",result);
        goto release;
    }

    try {
        switch (mode) {
            case MODE_NORMAL:
                system->playSound(sound, 0, false, &channel);
                break;
            case MODE_LOLITA:

                system->playSound(sound, 0, false, &channel);

                system->createDSPByType(FMOD_DSP_TYPE_PITCHSHIFT, &dsp);
                dsp->setParameterFloat(FMOD_DSP_PITCHSHIFT_PITCH, 1.5F);
                channel->addDSP(0, dsp);


                break;
            case MODE_UNCLE:
                system->playSound(sound, 0, false, &channel);

                system->createDSPByType(FMOD_DSP_TYPE_PITCHSHIFT, &dsp);
                dsp->setParameterFloat(FMOD_DSP_PITCHSHIFT_PITCH, 0.8F);
                channel->addDSP(0, dsp);


                break;
            case MODE_PANIC:
                system->playSound(sound, 0, false, &channel);
                system->createDSPByType(FMOD_DSP_TYPE_TREMOLO, &dsp);
                dsp->setParameterFloat(FMOD_DSP_TREMOLO_SKEW, 0.5);
                channel->addDSP(0, dsp);

                break;
            case MODE_FUNNY:
                system->playSound(sound, 0, false, &channel);

                float frequency;
                channel->getFrequency(&frequency);
                channel->setFrequency(frequency * 1.5F);

                break;
            case MODE_ARTISTIC:
                system->playSound(sound, 0, false, &channel);

                system->createDSPByType(FMOD_DSP_TYPE_ECHO, &dsp);
                dsp->setParameterFloat(FMOD_DSP_ECHO_DELAY, 200);
                dsp->setParameterFloat(FMOD_DSP_ECHO_FEEDBACK, 20);
                channel->addDSP(0, dsp);
                break;
            default:
                break;
        }


    } catch (...) {
        LOGW("add dsp exception");
        goto release;
    }

    system->update();

    while (playing) {
        channel->isPlaying(&playing);
        usleep(1000 * 1000);
    }

    release:
    {
        //release resource
        if (sound != NULL) {
            sound->release();
        }
        if (system != NULL) {
            system->close();
            system->release();
        }

        env->ReleaseStringUTFChars(path, voicePath);
    }


}