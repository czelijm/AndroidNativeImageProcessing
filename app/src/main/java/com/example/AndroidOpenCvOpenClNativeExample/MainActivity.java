package com.example.AndroidOpenCvOpenClNativeExample;

import android.Manifest;
import android.app.Activity;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.system.ErrnoException;
import android.system.Os;
import android.util.Log;
import android.view.SurfaceView;
import android.view.WindowManager;
import android.widget.Toast;

import androidx.core.app.ActivityCompat;

import com.example.AndroidOpencvNativeExample.R;

import org.jetbrains.annotations.NotNull;
import org.opencv.android.BaseLoaderCallback;
import org.opencv.android.CameraBridgeViewBase;
import org.opencv.android.CameraBridgeViewBase.CvCameraViewFrame;
import org.opencv.android.CameraBridgeViewBase.CvCameraViewListener2;
import org.opencv.android.LoaderCallbackInterface;
import org.opencv.android.OpenCVLoader;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import org.opencv.core.Scalar;
import org.opencv.imgproc.Imgproc;

import java.io.File;

import static android.os.Environment.getExternalStorageDirectory;

public class MainActivity extends Activity implements CvCameraViewListener2 {
    private static final String TAG = "MainActivity";
    private static final int CAMERA_PERMISSION_REQUEST = 1;
    private static final int READ_EXTERNAL_STORAGE_PERMISSION_REQUEST = 1;


    private CameraBridgeViewBase mOpenCvCameraView;
    private NAFFD naffd;


    File SDCardDir = getExternalStorageDirectory();
//    private static Context mContext;


    private BaseLoaderCallback mLoaderCallback = new BaseLoaderCallback(this) {
        @Override
        public void onManagerConnected(int status) {
            if (status == LoaderCallbackInterface.SUCCESS) {
                Log.i(TAG, "OpenCV loaded successfully");
//                File[] files = SDCardDir.listFiles();
//                Runtime.getRuntime().loadLibrary("OpenCL");
                File file = new File(SDCardDir.toString()+"/IRgByModel/");
//                System.out.println("ISSSS GRATED"+(ContextCompat.checkSelfPermission(MainActivity.super.getApplicationContext(), Manifest.permission.READ_EXTERNAL_STORAGE) == PackageManager.PERMISSION_GRANTED));
//                if (ContextCompat.checkSelfPermission(MainActivity.super.getApplicationContext(), Manifest.permission.READ_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED){
//                    if (ActivityCompat.shouldShowRequestPermissionRationale(MainActivity.this,
//                            Manifest.permission.READ_EXTERNAL_STORAGE)) {
//                        // Show an explanation to the user *asynchronously* -- don't block
//                        // this thread waiting for the user's response! After the user
//                        // sees the explanation, try again to request the permission.
//                    } else {
//                        // No explanation needed; request the permission
//                        ActivityCompat.requestPermissions(MainActivity.this,
//                                new String[]{Manifest.permission.READ_EXTERNAL_STORAGE},
//                                999);
//
//                        // MY_PERMISSIONS_REQUEST_READ_CONTACTS is an
//                        // app-defined int constant. The callback method gets the
//                        // result of the request.
//                    }
//
//                }
//                for (File f: files
//                     ) {
//                    System.out.println(f);
//
//                }

//                System.out.println("ISSSS GRATED"+(ContextCompat.checkSelfPermission(MainActivity.super.getApplicationContext(), Manifest.permission.READ_EXTERNAL_STORAGE) == PackageManager.PERMISSION_GRANTED));


//                System.out.println("FILE DIRRRR!!!"+SDCardDir);
//                System.out.println("FILE EXISSSTTTTTT!!!"+file.exists());
                // Load native library after(!) OpenCV initialization
                System.loadLibrary("native-lib");

                mOpenCvCameraView.setMaxFrameSize(480,320);

                mOpenCvCameraView.enableView();
//                System.out.println("INIT RUN!!!");
                naffd = new NAFFD(320,480,3,8,0.009,0.5,0); //0.005:0.008 //0.0075
                naffd.getInstanceOfEnvRun();
            } else {
                super.onManagerConnected(status);
            }
        }
    };

    @Override
    public void onCreate(Bundle savedInstanceState) {
        Log.i(TAG, "called onCreate");
        super.onCreate(savedInstanceState);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        int permissions_code = 42;
        String[] permissions = {
//                Manifest.permission.ACCESS_CACHE_FILESYSTEM,
//                Manifest.permission.ACCESS_CHECKIN_PROPERTIES,
//                Manifest.permission.ACCESS_COARSE_LOCATION,
//                Manifest.permission.ACCESS_CONTENT_PROVIDERS_EXTERNALLY,
//                Manifest.permission.ACCESS_DRM_CERTIFICATES,
//                Manifest.permission.ACCESS_FINE_LOCATION,
//                Manifest.permission.ACCESS_FM_RADIO,
//                Manifest.permission.ACCESS_IMS_CALL_SERVICE,
//                Manifest.permission.ACCESS_INPUT_FLINGER,
//                Manifest.permission.ACCESS_KEYGUARD_SECURE_STORAGE,
//                Manifest.permission.ACCESS_LOCATION_EXTRA_COMMANDS,
//                Manifest.permission.ACCESS_MOCK_LOCATION,
//                Manifest.permission.ACCESS_MTP,
//                Manifest.permission.ACCESS_NETWORK_CONDITIONS,
//                Manifest.permission.ACCESS_NETWORK_STATE,
//                Manifest.permission.ACCESS_NOTIFICATIONS,
//                Manifest.permission.ACCESS_NOTIFICATION_POLICY,
//                Manifest.permission.ACCESS_PDB_STATE,
//                Manifest.permission.ACCESS_SURFACE_FLINGER,
//                Manifest.permission.ACCESS_VOICE_INTERACTION_SERVICE,
//                Manifest.permission.ACCESS_WIFI_STATE,
//                Manifest.permission.ACCESS_WIMAX_STATE,
//                Manifest.permission.ACCOUNT_MANAGER,
//                Manifest.permission.ADD_VOICEMAIL,
//                Manifest.permission.ALLOW_ANY_CODEC_FOR_PLAYBACK,
//                Manifest.permission.ASEC_ACCESS,
//                Manifest.permission.ASEC_CREATE,
//                Manifest.permission.ASEC_DESTROY,
//                Manifest.permission.ASEC_MOUNT_UNMOUNT,
//                Manifest.permission.ASEC_RENAME,
//                Manifest.permission.BACKUP,
//                Manifest.permission.BATTERY_STATS,
//                Manifest.permission.BIND_ACCESSIBILITY_SERVICE,
//                Manifest.permission.BIND_APPWIDGET,
//                Manifest.permission.BIND_CARRIER_MESSAGING_SERVICE,
//                Manifest.permission.BIND_CARRIER_SERVICES,
//                Manifest.permission.BIND_CHOOSER_TARGET_SERVICE,
//                Manifest.permission.BIND_CONDITION_PROVIDER_SERVICE,
//                Manifest.permission.BIND_CONNECTION_SERVICE,
//                Manifest.permission.BIND_DEVICE_ADMIN,
//                Manifest.permission.BIND_DIRECTORY_SEARCH,
//                Manifest.permission.BIND_DREAM_SERVICE,
//                Manifest.permission.BIND_INCALL_SERVICE,
//                Manifest.permission.BIND_INPUT_METHOD,
//                Manifest.permission.BIND_INTENT_FILTER_VERIFIER,
//                Manifest.permission.BIND_JOB_SERVICE,
//                Manifest.permission.BIND_KEYGUARD_APPWIDGET,
//                Manifest.permission.BIND_MIDI_DEVICE_SERVICE,
//                Manifest.permission.BIND_NFC_SERVICE,
//                Manifest.permission.BIND_NOTIFICATION_LISTENER_SERVICE,
//                Manifest.permission.BIND_PACKAGE_VERIFIER,
//                Manifest.permission.BIND_PRINT_SERVICE,
//                Manifest.permission.BIND_PRINT_SPOOLER_SERVICE,
//                Manifest.permission.BIND_REMOTEVIEWS,
//                Manifest.permission.BIND_REMOTE_DISPLAY,
//                Manifest.permission.BIND_ROUTE_PROVIDER,
//                Manifest.permission.BIND_TELECOM_CONNECTION_SERVICE,
//                Manifest.permission.BIND_TEXT_SERVICE,
//                Manifest.permission.BIND_TRUST_AGENT,
//                Manifest.permission.BIND_TV_INPUT,
//                Manifest.permission.BIND_VOICE_INTERACTION,
//                Manifest.permission.BIND_VPN_SERVICE,
//                Manifest.permission.BIND_WALLPAPER,
//                Manifest.permission.BLUETOOTH,
//                Manifest.permission.BLUETOOTH_ADMIN,
//                Manifest.permission.BLUETOOTH_MAP,
//                Manifest.permission.BLUETOOTH_PRIVILEGED,
//                Manifest.permission.BLUETOOTH_STACK,
//                Manifest.permission.BODY_SENSORS,
//                Manifest.permission.BRICK,
//                Manifest.permission.BROADCAST_NETWORK_PRIVILEGED,
//                Manifest.permission.BROADCAST_PACKAGE_REMOVED,
//                Manifest.permission.BROADCAST_SMS,
//                Manifest.permission.BROADCAST_STICKY,
//                Manifest.permission.BROADCAST_WAP_PUSH,
//                Manifest.permission.C2D_MESSAGE,
//                Manifest.permission.CALL_PHONE,
//                Manifest.permission.CALL_PRIVILEGED,
                Manifest.permission.CAMERA,
//                Manifest.permission.CAMERA_DISABLE_TRANSMIT_LED,
//                Manifest.permission.CAMERA_SEND_SYSTEM_EVENTS,
//                Manifest.permission.CAPTURE_AUDIO_HOTWORD,
//                Manifest.permission.CAPTURE_AUDIO_OUTPUT,
//                Manifest.permission.CAPTURE_SECURE_VIDEO_OUTPUT,
//                Manifest.permission.CAPTURE_TV_INPUT,
//                Manifest.permission.CAPTURE_VIDEO_OUTPUT,
//                Manifest.permission.CARRIER_FILTER_SMS,
//                Manifest.permission.CHANGE_APP_IDLE_STATE,
//                Manifest.permission.CHANGE_BACKGROUND_DATA_SETTING,
//                Manifest.permission.CHANGE_COMPONENT_ENABLED_STATE,
//                Manifest.permission.CHANGE_CONFIGURATION,
//                Manifest.permission.CHANGE_DEVICE_IDLE_TEMP_WHITELIST,
//                Manifest.permission.CHANGE_NETWORK_STATE,
//                Manifest.permission.CHANGE_WIFI_MULTICAST_STATE,
//                Manifest.permission.CHANGE_WIFI_STATE,
//                Manifest.permission.CHANGE_WIMAX_STATE,
//                Manifest.permission.CLEAR_APP_CACHE,
//                Manifest.permission.CLEAR_APP_USER_DATA,
//                Manifest.permission.CONFIGURE_WIFI_DISPLAY,
//                Manifest.permission.CONFIRM_FULL_BACKUP,
//                Manifest.permission.CONNECTIVITY_INTERNAL,
//                Manifest.permission.CONTROL_INCALL_EXPERIENCE,
//                Manifest.permission.CONTROL_KEYGUARD,
//                Manifest.permission.CONTROL_LOCATION_UPDATES,
//                Manifest.permission.CONTROL_VPN,
//                Manifest.permission.CONTROL_WIFI_DISPLAY,
//                Manifest.permission.COPY_PROTECTED_DATA,
//                Manifest.permission.CRYPT_KEEPER,
//                Manifest.permission.DELETE_CACHE_FILES,
//                Manifest.permission.DELETE_PACKAGES,
//                Manifest.permission.DEVICE_POWER,
//                Manifest.permission.DIAGNOSTIC,
//                Manifest.permission.DISABLE_KEYGUARD,
//                Manifest.permission.DISPATCH_NFC_MESSAGE,
//                Manifest.permission.DUMP,
//                Manifest.permission.DVB_DEVICE,
//                Manifest.permission.EXPAND_STATUS_BAR,
//                Manifest.permission.FACTORY_TEST,
//                Manifest.permission.FILTER_EVENTS,
//                Manifest.permission.FLASHLIGHT,
//                Manifest.permission.FORCE_BACK,
//                Manifest.permission.FORCE_STOP_PACKAGES,
//                Manifest.permission.FRAME_STATS,
//                Manifest.permission.FREEZE_SCREEN,
//                Manifest.permission.GET_ACCOUNTS,
//                Manifest.permission.GET_ACCOUNTS_PRIVILEGED,
//                Manifest.permission.GET_APP_OPS_STATS,
//                Manifest.permission.GET_DETAILED_TASKS,
//                Manifest.permission.GET_PACKAGE_IMPORTANCE,
//                Manifest.permission.GET_PACKAGE_SIZE,
//                Manifest.permission.GET_TASKS,
//                Manifest.permission.GET_TOP_ACTIVITY_INFO,
//                Manifest.permission.GLOBAL_SEARCH,
//                Manifest.permission.GLOBAL_SEARCH_CONTROL,
//                Manifest.permission.GRANT_RUNTIME_PERMISSIONS,
//                Manifest.permission.HARDWARE_TEST,
//                Manifest.permission.HDMI_CEC,
//                Manifest.permission.INJECT_EVENTS,
//                Manifest.permission.INSTALL_GRANT_RUNTIME_PERMISSIONS,
//                Manifest.permission.INSTALL_LOCATION_PROVIDER,
//                Manifest.permission.INSTALL_PACKAGES,
//                Manifest.permission.INSTALL_SHORTCUT,
//                Manifest.permission.INTENT_FILTER_VERIFICATION_AGENT,
//                Manifest.permission.INTERACT_ACROSS_USERS,
//                Manifest.permission.INTERACT_ACROSS_USERS_FULL,
//                Manifest.permission.INTERNAL_SYSTEM_WINDOW,
//                Manifest.permission.INTERNET,
//                Manifest.permission.INVOKE_CARRIER_SETUP,
//                Manifest.permission.KILL_BACKGROUND_PROCESSES,
//                Manifest.permission.KILL_UID,
//                Manifest.permission.LAUNCH_TRUST_AGENT_SETTINGS,
//                Manifest.permission.LOCAL_MAC_ADDRESS,
//                Manifest.permission.LOCATION_HARDWARE,
//                Manifest.permission.LOOP_RADIO,
//                Manifest.permission.MANAGE_ACTIVITY_STACKS,
//                Manifest.permission.MANAGE_APP_TOKENS,
//                Manifest.permission.MANAGE_CA_CERTIFICATES,
//                Manifest.permission.MANAGE_DEVICE_ADMINS,
//                Manifest.permission.MANAGE_DOCUMENTS,
//                Manifest.permission.MANAGE_FINGERPRINT,
//                Manifest.permission.MANAGE_MEDIA_PROJECTION,
//                Manifest.permission.MANAGE_NETWORK_POLICY,
//                Manifest.permission.MANAGE_PROFILE_AND_DEVICE_OWNERS,
//                Manifest.permission.MANAGE_USB,
//                Manifest.permission.MANAGE_USERS,
//                Manifest.permission.MANAGE_VOICE_KEYPHRASES,
//                Manifest.permission.MASTER_CLEAR,
//                Manifest.permission.MEDIA_CONTENT_CONTROL,
//                Manifest.permission.MODIFY_APPWIDGET_BIND_PERMISSIONS,
//                Manifest.permission.MODIFY_AUDIO_ROUTING,
//                Manifest.permission.MODIFY_AUDIO_SETTINGS,
//                Manifest.permission.MODIFY_NETWORK_ACCOUNTING,
//                Manifest.permission.MODIFY_PARENTAL_CONTROLS,
//                Manifest.permission.MODIFY_PHONE_STATE,
//                Manifest.permission.MOUNT_FORMAT_FILESYSTEMS,
//                Manifest.permission.MOUNT_UNMOUNT_FILESYSTEMS,
//                Manifest.permission.MOVE_PACKAGE,
//                Manifest.permission.NET_ADMIN,
//                Manifest.permission.NET_TUNNELING,
//                Manifest.permission.NFC,
//                Manifest.permission.NFC_HANDOVER_STATUS,
//                Manifest.permission.NOTIFY_PENDING_SYSTEM_UPDATE,
//                Manifest.permission.OBSERVE_GRANT_REVOKE_PERMISSIONS,
//                Manifest.permission.OEM_UNLOCK_STATE,
//                Manifest.permission.OVERRIDE_WIFI_CONFIG,
//                Manifest.permission.PACKAGE_USAGE_STATS,
//                Manifest.permission.PACKAGE_VERIFICATION_AGENT,
//                Manifest.permission.PEERS_MAC_ADDRESS,
//                Manifest.permission.PERFORM_CDMA_PROVISIONING,
//                Manifest.permission.PERFORM_SIM_ACTIVATION,
//                Manifest.permission.PERSISTENT_ACTIVITY,
//                Manifest.permission.PROCESS_OUTGOING_CALLS,
//                Manifest.permission.PROVIDE_TRUST_AGENT,
//                Manifest.permission.QUERY_DO_NOT_ASK_CREDENTIALS_ON_BOOT,
//                Manifest.permission.READ_CALENDAR,
//                Manifest.permission.READ_CALL_LOG,
//                Manifest.permission.READ_CELL_BROADCASTS,
//                Manifest.permission.READ_CONTACTS,
//                Manifest.permission.READ_DREAM_STATE,
                Manifest.permission.READ_EXTERNAL_STORAGE,
//                Manifest.permission.READ_FRAME_BUFFER,
//                Manifest.permission.READ_INPUT_STATE,
//                Manifest.permission.READ_INSTALL_SESSIONS,
//                Manifest.permission.READ_LOGS,
//                Manifest.permission.READ_NETWORK_USAGE_HISTORY,
//                Manifest.permission.READ_PHONE_STATE,
//                Manifest.permission.READ_PRECISE_PHONE_STATE,
//                Manifest.permission.READ_PRIVILEGED_PHONE_STATE,
//                Manifest.permission.READ_PROFILE,
//                Manifest.permission.READ_SEARCH_INDEXABLES,
//                Manifest.permission.READ_SMS,
//                Manifest.permission.READ_SOCIAL_STREAM,
//                Manifest.permission.READ_SYNC_SETTINGS,
//                Manifest.permission.READ_SYNC_STATS,
//                Manifest.permission.READ_USER_DICTIONARY,
//                Manifest.permission.READ_VOICEMAIL,
//                Manifest.permission.READ_WIFI_CREDENTIAL,
//                Manifest.permission.REAL_GET_TASKS,
//                Manifest.permission.REBOOT,
//                Manifest.permission.RECEIVE_BLUETOOTH_MAP,
//                Manifest.permission.RECEIVE_BOOT_COMPLETED,
//                Manifest.permission.RECEIVE_DATA_ACTIVITY_CHANGE,
//                Manifest.permission.RECEIVE_EMERGENCY_BROADCAST,
//                Manifest.permission.RECEIVE_MMS,
//                Manifest.permission.RECEIVE_SMS,
//                Manifest.permission.RECEIVE_STK_COMMANDS,
//                Manifest.permission.RECEIVE_WAP_PUSH,
//                Manifest.permission.RECEIVE_WIFI_CREDENTIAL_CHANGE,
//                Manifest.permission.RECORD_AUDIO,
//                Manifest.permission.RECOVERY,
//                Manifest.permission.REGISTER_CALL_PROVIDER,
//                Manifest.permission.REGISTER_CONNECTION_MANAGER,
//                Manifest.permission.REGISTER_SIM_SUBSCRIPTION,
//                Manifest.permission.REMOTE_AUDIO_PLAYBACK,
//                Manifest.permission.REMOVE_DRM_CERTIFICATES,
//                Manifest.permission.REMOVE_TASKS,
//                Manifest.permission.REORDER_TASKS,
//                Manifest.permission.REQUEST_IGNORE_BATTERY_OPTIMIZATIONS,
//                Manifest.permission.REQUEST_INSTALL_PACKAGES,
//                Manifest.permission.RESTART_PACKAGES,
//                Manifest.permission.RETRIEVE_WINDOW_CONTENT,
//                Manifest.permission.RETRIEVE_WINDOW_TOKEN,
//                Manifest.permission.REVOKE_RUNTIME_PERMISSIONS,
//                Manifest.permission.SCORE_NETWORKS,
//                Manifest.permission.SEND_RESPOND_VIA_MESSAGE,
//                Manifest.permission.SEND_SMS,
//                Manifest.permission.SERIAL_PORT,
//                Manifest.permission.SET_ACTIVITY_WATCHER,
//                Manifest.permission.SET_ALARM,
//                Manifest.permission.SET_ALWAYS_FINISH,
//                Manifest.permission.SET_ANIMATION_SCALE,
//                Manifest.permission.SET_DEBUG_APP,
//                Manifest.permission.SET_INPUT_CALIBRATION,
//                Manifest.permission.SET_KEYBOARD_LAYOUT,
//                Manifest.permission.SET_ORIENTATION,
//                Manifest.permission.SET_POINTER_SPEED,
//                Manifest.permission.SET_PREFERRED_APPLICATIONS,
//                Manifest.permission.SET_PROCESS_LIMIT,
//                Manifest.permission.SET_SCREEN_COMPATIBILITY,
//                Manifest.permission.SET_TIME,
//                Manifest.permission.SET_TIME_ZONE,
//                Manifest.permission.SET_WALLPAPER,
//                Manifest.permission.SET_WALLPAPER_COMPONENT,
//                Manifest.permission.SET_WALLPAPER_HINTS,
//                Manifest.permission.SHUTDOWN,
//                Manifest.permission.SIGNAL_PERSISTENT_PROCESSES,
//                Manifest.permission.START_ANY_ACTIVITY,
//                Manifest.permission.START_TASKS_FROM_RECENTS,
//                Manifest.permission.STATUS_BAR,
//                Manifest.permission.STATUS_BAR_SERVICE,
//                Manifest.permission.STOP_APP_SWITCHES,
//                Manifest.permission.SYSTEM_ALERT_WINDOW,
//                Manifest.permission.TEMPORARY_ENABLE_ACCESSIBILITY,
//                Manifest.permission.TRANSMIT_IR,
//                Manifest.permission.TRUST_LISTENER,
//                Manifest.permission.TV_INPUT_HARDWARE,
//                Manifest.permission.UNINSTALL_SHORTCUT,
//                Manifest.permission.UPDATE_APP_OPS_STATS,
//                Manifest.permission.UPDATE_CONFIG,
//                Manifest.permission.UPDATE_DEVICE_STATS,
//                Manifest.permission.UPDATE_LOCK,
//                Manifest.permission.USER_ACTIVITY,
//                Manifest.permission.USE_FINGERPRINT,
//                Manifest.permission.USE_SIP,
//                Manifest.permission.VIBRATE,
//                Manifest.permission.WAKE_LOCK,
//                Manifest.permission.WRITE_APN_SETTINGS,
//                Manifest.permission.WRITE_CALENDAR,
//                Manifest.permission.WRITE_CALL_LOG,
//                Manifest.permission.WRITE_CONTACTS,
//                Manifest.permission.WRITE_DREAM_STATE
        };

        // Permissions for Android 6+
        ActivityCompat.requestPermissions(
                this,
                new String[]{Manifest.permission.CAMERA},
                CAMERA_PERMISSION_REQUEST
        );

        try {
            Os.setenv("GPU_FORCE_64BIT_PTR", "1", true);
            Os.setenv("GPU_USE_SYNC_OBJECTS", "1", true);
            Os.setenv("GPU_MAX_ALLOC_PERCENT", "100", true);
            Os.setenv("GPU_GPU_SINGLE_ALLOC_PERCENT", "100", true);
            Os.setenv("GPU_MAX_HEAP_SIZE", "100", true);

        } catch (ErrnoException e) {
            e.printStackTrace();
        }

        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        getWindow().setFlags(
                WindowManager.LayoutParams.FLAG_HARDWARE_ACCELERATED,
                WindowManager.LayoutParams.FLAG_HARDWARE_ACCELERATED);

        setContentView(R.layout.activity_main);

        mOpenCvCameraView = findViewById(R.id.main_surface);

        mOpenCvCameraView.setVisibility(SurfaceView.VISIBLE);

        mOpenCvCameraView.setCvCameraViewListener(this);

        mLoaderCallback.onManagerConnected(LoaderCallbackInterface.SUCCESS);


//        if (ContextCompat.checkSelfPermission(MainActivity.super.getApplicationContext(), Manifest.permission.READ_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED){
//            if (ActivityCompat.shouldShowRequestPermissionRationale(this,
//                    Manifest.permission.READ_EXTERNAL_STORAGE)) {
//                // Show an explanation to the user *asynchronously* -- don't block
//                // this thread waiting for the user's response! After the user
//                // sees the explanation, try again to request the permission.
//            } else {
//                // No explanation needed; request the permission
//                ActivityCompat.requestPermissions(this,
//                        new String[]{Manifest.permission.READ_EXTERNAL_STORAGE},
//                        READ_EXTERNAL_STORAGE_PERMISSION_REQUEST);
//
//                // MY_PERMISSIONS_REQUEST_READ_CONTACTS is an
//                // app-defined int constant. The callback method gets the
//                // result of the request.
//            }
//
//        }
//



        //==============================================================
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NotNull String[] permissions, @NotNull int[] grantResults) {
        if (requestCode == CAMERA_PERMISSION_REQUEST) {
            if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                mOpenCvCameraView.setCameraPermissionGranted();
            } else {
                String message = "Camera permission was not granted";
                Log.e(TAG, message);
                Toast.makeText(this, message, Toast.LENGTH_LONG).show();
            }
        } else {
            Log.e(TAG, "Unexpected permission request");
        }
    }

    @Override
    public void onPause() {
        super.onPause();
        if (mOpenCvCameraView != null)
            mOpenCvCameraView.disableView();
    }

    @Override
    public void onResume() {
        super.onResume();
        if (!OpenCVLoader.initDebug()) {
            Log.d(TAG, "Internal OpenCV library not found. Using OpenCV Manager for initialization");
            OpenCVLoader.initAsync(OpenCVLoader.OPENCV_VERSION, this, mLoaderCallback);
        } else {
            Log.d(TAG, "OpenCV library found inside package. Using it!");
            mLoaderCallback.onManagerConnected(LoaderCallbackInterface.SUCCESS);
        }
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        if (mOpenCvCameraView != null)
            mOpenCvCameraView.disableView();
    }

    @Override
    public void onCameraViewStarted(int width, int height) {
        naffd.setHeight(height);
        naffd.setWidth(width);
    }

    @Override
    public void onCameraViewStopped() {
    }

    @Override
    public Mat onCameraFrame(CvCameraViewFrame frame) {
        // get current camera frame as OpenCV Mat object
//        Mat mat = frame.gray();
//        if (frame != null) {
            Mat mat = frame.rgba();
//            Mat matBGR
//            if (mat != null && !mat.empty()) {
                Mat matBGR = new Mat(mat.rows(), mat.cols(), CvType.CV_8U, new Scalar(3));
                Imgproc.cvtColor(mat,matBGR,Imgproc.COLOR_RGBA2BGR);
                naffd.processFrameRun(matBGR.getNativeObjAddr());
                Imgproc.cvtColor(matBGR,mat,Imgproc.COLOR_BGR2RGBA);
//                return matBGR;
//            }
            return mat;
//        }

        // native call to process current camera frame
//        adaptiveThresholdFromJNI(mat.getNativeObjAddr());
//        System.out.println("SSS"+naffd.getResizedFactor());
//        naffd.getInstanceOfEnvRun();
//        getInstaceOfEnvJNI();
//        naffd.processFrameRun();

        // return processed frame for live preview
//        return frame.rgba();
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
//    private native void adaptiveThresholdFromJNI(long mat);
//    private native void getInstaceOfEnvJNI();

}
