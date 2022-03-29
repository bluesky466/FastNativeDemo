package me.linjw.demo.ndk;

import android.os.Bundle;
import android.util.Log;
import android.view.View;

import androidx.appcompat.app.AppCompatActivity;

import dalvik.annotation.optimization.CriticalNative;
import dalvik.annotation.optimization.FastNative;
import me.linjw.demo.ndk.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {
    private static final long REPEAT_TIME = 999999;

    static {
        System.loadLibrary("ndk");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
    }

    @FastNative
    public static native int intFromFastJNI();

    @CriticalNative
    public static native int intFromCriticalJNI();

    public static native int intFromNormalJNI();

    public void onCritical(View view) {
        long time = System.nanoTime();
        for (long i = 0; i < REPEAT_TIME; i++) {
            intFromCriticalJNI();
        }
        Log.d("testtest", "intFromCriticalJNI : " + (System.nanoTime() - time));
    }
    public void onNormal(View view) {
        long time = System.nanoTime();
        for (long i = 0; i < REPEAT_TIME; i++) {
            intFromNormalJNI();
        }
        Log.d("testtest", "intFromNormalJNI   : " + (System.nanoTime() - time));
    }

    public void onFastJni(View view) {
        long time = System.nanoTime();
        for (long i = 0; i < REPEAT_TIME; i++) {
            intFromFastJNI();
        }
        Log.d("testtest", "intFromFastJNI     : " + (System.nanoTime() - time));
    }
}