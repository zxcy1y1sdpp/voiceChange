package me.liuningning.voicechange;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {
    private static final String TAG = "MainActivity";
    private VoiceChange mVoiceChange;
    private String mVoicePath;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        findViewById(R.id.btn_normal).setOnClickListener(this);
        findViewById(R.id.btn_lolita).setOnClickListener(this);
        findViewById(R.id.btn_uncle).setOnClickListener(this);
        findViewById(R.id.btn_panic).setOnClickListener(this);
        findViewById(R.id.btn_funny).setOnClickListener(this);
        findViewById(R.id.btn_artistic).setOnClickListener(this);

        mVoiceChange = new VoiceChange();
        mVoiceChange.init(this);
        mVoicePath = "file:///android_asset/he.m4a";


    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        mVoiceChange.release();

    }

    @Override
    public void onClick(View view) {
        Log.d(TAG,"onClick");
        switch (view.getId()) {
            case R.id.btn_normal:
                mVoiceChange.play(mVoicePath, VoiceChange.MODE_NORMAL);
                break;
            case R.id.btn_lolita:
                mVoiceChange.play(mVoicePath, VoiceChange.MODE_LOLITA);
                break;
            case R.id.btn_uncle:
                mVoiceChange.play(mVoicePath, VoiceChange.MODE_UNCLE);
                break;
            case R.id.btn_panic:
                mVoiceChange.play(mVoicePath, VoiceChange.MODE_PANIC);
                break;
            case R.id.btn_funny:
                mVoiceChange.play(mVoicePath, VoiceChange.MODE_FUNNY);
                break;
            case R.id.btn_artistic:
                mVoiceChange.play(mVoicePath, VoiceChange.MODE_ARTISTIC);
                break;
        }
    }
}
