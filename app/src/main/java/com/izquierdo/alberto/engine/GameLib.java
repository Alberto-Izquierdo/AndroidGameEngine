package com.izquierdo.alberto.engine;


public class GameLib {
    private static TextureLoader textureLoader;

    static{
        System.loadLibrary("native-lib");
    }

    public static native void init();
    public static native void update();
    public static int[] LoadTexture(String path)
    {
        return textureLoader.LoadTexture(path);
    }
    public static native void screenPressed(int _x, int _y);
    public static native void screenReleased(int _x, int _y);
    public static native void screenDragged(int _x, int _y);

    public static void SetTextureLoader(TextureLoader texLoader)
    {
        textureLoader = texLoader;
    }
}
