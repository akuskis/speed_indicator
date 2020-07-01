package com.example.throttle;

import org.libsdl.app.SDLActivity;

public class Activity extends SDLActivity {
    @Override
    protected String[] getLibraries() {
        return new String[]{
                "hidapi",
                "SDL2",
                "throttle_core"
        };
    }
}
