package com.example.speed_indicator;

import android.app.Activity;
import android.content.Intent;
import android.content.IntentFilter;

import com.example.speed_indicator.service.DataService;


public class State {

    private double speed = -1;
    private static State instance;
    private static final Object speedKey = new Object();

    public static synchronized State getInstance() {
        if (instance == null) {
            instance = new State();
        }

        return instance;
    }

    public static double getCurrentSpeed() {
        synchronized (speedKey) {
            return getInstance().speed;
        }
    }

    public static void setCurrentSpeed(double value) {
        synchronized (speedKey) {
            getInstance().speed = value;
        }
    }

    public void setup(Activity activity) {
        Intent intent = new Intent(activity, DataService.class);
        activity.startService(intent);

        activity.registerReceiver(new DataBroadcastReceiver(), new IntentFilter("com.example.speed_indicator.NEW_SPEED_VALUE"));
    }
}
