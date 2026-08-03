package com.polymaster.editor;

public class NativeEngine {
    static {
        System.loadLibrary("polymaster_native");
    }
    
    public native void init(int width, int height);
    public native void update(float deltaTime);
    public native void render();
    public native void shutdown();
}
