package com.example.speed_indicator.service;


import android.app.Service;
import android.content.Intent;

public class DataServiceThread extends Thread {
    public native void startGenerator();

    public static final String NEW_SPEED_VALUE = "com.example.speed_indicator.NEW_SPEED_VALUE";
    private Service service;

    public DataServiceThread(Service s) {
        service = s;
        System.loadLibrary("data_generator");
    }

    public void run() {
        startGenerator();
    }

    public boolean isInterrupted() {
        return interrupted();
    }

    public void submitCurrentSpeed(double value) {
        Intent intent = new Intent(NEW_SPEED_VALUE);
        intent.putExtra("value", value);

        service.sendBroadcast(intent);
    }
}
