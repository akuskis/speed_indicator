package com.example.speed_indicator.service;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;


public class DataService extends Service {

    DataServiceThread thread = new DataServiceThread(this);

    @Override
    public void onDestroy() {
        thread.interrupt();

        super.onDestroy();
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        thread.start();

        return super.onStartCommand(intent, flags, startId);
    }

    @Override
    public IBinder onBind(Intent intent) {
        throw new UnsupportedOperationException();
    }
}
