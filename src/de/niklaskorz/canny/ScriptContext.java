package de.niklaskorz.canny;

public class ScriptContext {
    private long nativeContext;

    private static native long createNativeContext();

    public ScriptContext() {
        nativeContext = createNativeContext();
    }

    public native void eval(String code);

    static {
        System.loadLibrary("canny");
    }
}
