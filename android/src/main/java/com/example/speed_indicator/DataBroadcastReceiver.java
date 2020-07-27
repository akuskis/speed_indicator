package com.example.speed_indicator;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;


public class DataBroadcastReceiver extends BroadcastReceiver {

    @Override
    public void onReceive(Context context, Intent intent) {
        State.setCurrentSpeed(intent.getDoubleExtra("value", -1));
    }
}
