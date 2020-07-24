package com.example.speed_indicator;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;

public class DataService extends Service {

    private Command command = new Command();

    @Override
    public IBinder onBind(Intent intent) {
        return command;
    }

    private static class Command extends ICommand.Stub {
        private boolean direction = true;
        private double value = 0;

        @Override
        public double getCurrentSpeed() {
            if (direction) {
                value += 0.1;
            }
            else {
                value -= 0.1;
            }

            if (value >= 220) {
                direction = false;
            }
            else if (value <= 0) {
                direction = true;
            }

            return value;
        }
    }
}
