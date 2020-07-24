package com.example.speed_indicator;

import android.app.Activity;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.content.ComponentName;
import android.content.ServiceConnection;
import android.os.IBinder;
import android.os.RemoteException;

import java.util.List;

import static android.content.Context.BIND_AUTO_CREATE;


public class DataServiceWorker {

    private ICommand command;
    private static DataServiceWorker instance;

    public static synchronized DataServiceWorker getInstance() {
        if (instance == null) {
            instance = new DataServiceWorker();
        }

        return instance;
    }

    public static double getCurrentSpeed() {
        try {
            if (getInstance().command != null) {
                return getInstance().command.getCurrentSpeed();
            }
        } catch (RemoteException ignored) {
        }

        return -1;
    }

    public void setup(Activity activity) {
        DataServiceWorker instance = getInstance();
        instance.connect(activity);
    }

    private void connect(Activity activity) {
        Intent intent = new Intent("com.example.speed_indicator.AIDL");
        activity.bindService(convertIntentToExplicit(activity, intent), serviceConnection, BIND_AUTO_CREATE);
    }

    private ServiceConnection serviceConnection = new ServiceConnection() {
        @Override
        public void onServiceConnected(ComponentName componentName, IBinder iBinder) {
            command = ICommand.Stub.asInterface(iBinder);
        }

        @Override
        public void onServiceDisconnected(ComponentName componentName) {
        }
    };

    private Intent convertIntentToExplicit(Activity activity, Intent implicit) {
        PackageManager packageManager = activity.getPackageManager();
        List<ResolveInfo> resolveInfoList = packageManager.queryIntentServices(implicit, 0);

        if (resolveInfoList.size() != 1) {
            return null;
        }

        ResolveInfo serviceInfo = resolveInfoList.get(0);
        ComponentName componentName = new ComponentName(serviceInfo.serviceInfo.packageName, serviceInfo.serviceInfo.name);
        Intent explicit = new Intent(implicit);
        explicit.setComponent(componentName);

        return explicit;
    }
}
