package com.izquierdo.alberto.engine;

import android.app.Activity;
import android.os.Bundle;

public class MainActivity extends Activity {

    View m_View;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        m_View = new View(getApplication(), this);
        setContentView(m_View);
    }

    @Override
    protected void onPause(){
        super.onPause();
        m_View.onPause();
    }

    @Override
    protected void onResume(){
        super.onResume();
        m_View.onResume();
    }
}
