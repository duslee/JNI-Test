package com.jeff.customjnitest;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("jni-test");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView textView = (TextView) findViewById(R.id.textView);
        textView.setText(get());
        set("Hello world from JniTestApp!");

        TextView textView2 = (TextView) findViewById(R.id.textView2);
        textView2.setText(get2());
    }

    public static void methodCalledByJni(String msgFromJni) {
        Log.d("test", "MainActivity methodCalledByJni msg: " + msgFromJni);
    }

    public native String get();

    public native String get2();

    public native void set(String str);

}
