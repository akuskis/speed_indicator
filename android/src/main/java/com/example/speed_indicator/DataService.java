package com.example.speed_indicator;

import android.app.Service;
import android.content.Intent;
import android.os.Handler;
import android.os.IBinder;


public class DataService extends Service {
    Handler handler = new Handler();

    private Runnable periodicUpdate = new Runnable() {
        public static final String NEW_SPEED_VALUE = "com.example.speed_indicator.NEW_SPEED_VALUE";

        @Override
        public void run() {
            handler.postDelayed(periodicUpdate, 20);

            Intent intent = new Intent(NEW_SPEED_VALUE);
            intent.putExtra("value", 100.);

            sendBroadcast(intent);
        }
    };

    @Override
    public void onCreate() {
        super.onCreate();
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        handler.post(periodicUpdate);

        return super.onStartCommand(intent, flags, startId);
    }

    @Override
    public IBinder onBind(Intent intent) {
        throw new UnsupportedOperationException();
    }
}
