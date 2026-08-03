package com.polymaster.editor;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.util.Log;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class MainActivity extends Activity {
    private static final String TAG = "PolyMaster";
    private GLSurfaceView glView;
    private NativeEngine engine;
    
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        Log.i(TAG, "MainActivity onCreate");
        
        engine = new NativeEngine();
        
        glView = new GLSurfaceView(this);
        glView.setRenderer(new GLSurfaceView.Renderer() {
            @Override
            public void onSurfaceCreated(GL10 gl, EGLConfig config) {
                Log.i(TAG, "Surface created");
                engine.init(1920, 1080);
            }
            
            @Override
            public void onSurfaceChanged(GL10 gl, int width, int height) {
                Log.i(TAG, "Surface changed: " + width + "x" + height);
            }
            
            @Override
            public void onDrawFrame(GL10 gl) {
                engine.update(0.016f);
                engine.render();
            }
        });
        
        setContentView(glView);
    }
    
    @Override
    protected void onDestroy() {
        super.onDestroy();
        Log.i(TAG, "MainActivity onDestroy");
        engine.shutdown();
    }
}
