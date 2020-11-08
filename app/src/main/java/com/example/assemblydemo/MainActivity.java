package com.example.assemblydemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv_add_test = findViewById(R.id.tv_add_test);
        tv_add_test.setText(addTest(3, 5));
        TextView tv_sub_test = findViewById(R.id.tv_sub_test);
        tv_sub_test.setText(subTest(3, 5));
        TextView tv_str_test = findViewById(R.id.tv_str_test);
        tv_str_test.setText(strTest());
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String addTest(int a, int b);

    public native String subTest(int a, int b);

    public native String strTest();
}
