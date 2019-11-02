package me.liuningning.voicechange;

import android.content.Context;

import org.fmod.FMOD;

/**
 * @author liuningning
 * @date 2019-11-02 17:12
 * @modify 2019-11-02 17:12
 * @description 类描述
 */
public class VoiceChange {

    /**
     * 普通声音
     */
    public static final int MODE_NORMAL = 0;
    /**
     * 萝莉声音
     */
    public static final int MODE_LOLITA = 1;
    /**
     * 大叔声音
     */
    public static final int MODE_UNCLE = 2;
    /**
     * 惊悚声音
     */
    public static final int MODE_PANIC = 3;
    /**
     * 搞怪声音
     */
    public static final int MODE_FUNNY = 4;
    /**
     * 空灵声音
     */
    public static final int MODE_ARTISTIC = 5;

    static {
        System.loadLibrary("voice");
    }

    public void init(Context context) {
        FMOD.init(context);
    }


    public void play(String path, int mode) {
        nativePlay(path, mode);
    }

    public void release() {
        FMOD.close();

    }

    private native void nativePlay(String path, int mode);

}
