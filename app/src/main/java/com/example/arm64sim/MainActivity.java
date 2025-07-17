package com.example.arm64sim;

import android.os.Bundle;
import android.util.Log;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    static {
        System.loadLibrary("native-lib");
    }

    public native void initSun();
    public native void useSun(int cost);
    public native int getSun();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        initSun();
        Log.i("Sim", "阳光初始值：" + getSun());
        useSun(250);
        Log.i("Sim", "阳光扣除250后：" + getSun());
        useSun(300);
        Log.i("Sim", "阳光扣除300后：" + getSun());
    }
}
