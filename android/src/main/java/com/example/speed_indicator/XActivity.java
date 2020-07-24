package com.example.speed_indicator;

import android.os.Bundle;

import org.libsdl.app.SDLActivity;


public class XActivity extends SDLActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        DataServiceWorker.getInstance().setup(this);

        super.onCreate(savedInstanceState);
    }

    @Override
    protected String[] getLibraries() {
        return new String[]{
                "hidapi",
                "SDL2",
                "speed_indicator_core"
        };
    }
}
