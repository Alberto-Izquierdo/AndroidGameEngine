package com.izquierdo.alberto.engine;

import android.app.Activity;
import android.content.Context;
import android.opengl.GLSurfaceView;
import android.view.MotionEvent;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class View extends GLSurfaceView {

    static{
        System.loadLibrary("game");
    }

    public View(Context context, Activity act) {
        super(context);
        setEGLConfigChooser(8, 8, 8, 0, 16, 0);
        setEGLContextClientVersion(2);
        setRenderer(new Renderer());
        GameLib.SetTextureLoader(new TextureLoader(act));
    }

    private static class Renderer implements GLSurfaceView.Renderer{

        @Override
        public void onSurfaceCreated(GL10 gl10, EGLConfig eglConfig) {
            GameLib.init();
        }

        @Override
        public void onSurfaceChanged(GL10 gl10, int width, int height) {
            //GameLib.resize(width, height);
        }

        @Override
        public void onDrawFrame(GL10 gl10) {
            GameLib.update();
        }

    }

    @Override
    public boolean onTouchEvent(MotionEvent e) {
        int action = e.getAction();
        if (action == MotionEvent.ACTION_DOWN)
        {
            GameLib.screenPressed((int)(e.getX()), (int)(e.getY()));
        }
        else if (action == MotionEvent.ACTION_UP)
        {
            GameLib.screenReleased((int)(e.getX()), (int)(e.getY()));
        }
        else if (action == MotionEvent.ACTION_MOVE)
        {
            GameLib.screenDragged((int)(e.getX()), (int)(e.getY()));
        }

        return true;
    }
}
