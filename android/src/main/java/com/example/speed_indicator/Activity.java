package com.example.speed_indicator;

import org.libsdl.app.SDLActivity;

public class Activity extends SDLActivity {
    @Override
    protected String[] getLibraries() {
        return new String[]{
                "hidapi",
                "SDL2",
                "speed_indicator_core"
        };
    }
}
