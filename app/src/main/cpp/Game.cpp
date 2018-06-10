#include "Game.h"
#include "InputManager.h"
#include "Sprite.h"
#include <memory>
#include <jni.h>

JNIEnv* m_env = nullptr;
jobject m_object = nullptr;
InputManager &m_inputManager = InputManager::instance();

namespace Game
{
Game::Game()
{
}
Game::~Game()
{
}

void Game::update(float _delta)
{
}
void Game::render()
{
}

void Game::touchScreen(int _x, int _y)
{
}

int Game::loadImage(const char *_filepath)
{
	jstring filename = m_env->NewStringUTF(_filepath);
	jclass clazz = m_env->FindClass("com/example/project/game/GameLib");
	jmethodID methodID = m_env->GetStaticMethodID(clazz, "LoadTexture", "(Ljava/lang/String;)I");
	jint out = m_env->CallStaticIntMethod(clazz, methodID, filename);
	return out;
}
}

std::unique_ptr<Game::Game> m_Game = nullptr;

extern "C" {
    JNIEXPORT void JNICALL Java_com_izquierdo_alberto_engine_GameLib_init(JNIEnv *env, jobject obj);
    JNIEXPORT void JNICALL Java_com_izquierdo_alberto_engine_GameLib_update(JNIEnv *env, jobject obj);
    JNIEXPORT void JNICALL Java_com_izquierdo_alberto_engine_GameLib_screenPressed(JNIEnv *env, jobject obj, jint _x, jint _y);
    JNIEXPORT void JNICALL Java_com_izquierdo_alberto_engine_GameLib_screenReleased(JNIEnv *env, jobject obj, jint _x, jint _y);
    JNIEXPORT void JNICALL Java_com_izquierdo_alberto_engine_GameLib_screenDragged(JNIEnv *env, jobject obj, jint _x, jint _y);
};

JNIEXPORT void JNICALL Java_com_izquierdo_alberto_engine_GameLib_init(JNIEnv *_env, jobject _obj)
{
	m_env = _env;
	m_object = _obj;
    m_Game = std::make_unique<Game::Game>();
}

unsigned int m_iLastFrameTimeMiliSecs = 0;

JNIEXPORT void JNICALL Java_com_izquierdo_alberto_engine_GameLib_update(JNIEnv *env, jobject obj)
{
	
    timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    unsigned int iNowMiliSecs = now.tv_sec * 1000 + now.tv_nsec / 1000000;

    if (m_iLastFrameTimeMiliSecs > 0)
    {
        float fDeltaTime = (float)(iNowMiliSecs - m_iLastFrameTimeMiliSecs) / 1000.f;
        (*m_Game).update(fDeltaTime);
        (*m_Game).render();
    }

	m_iLastFrameTimeMiliSecs = iNowMiliSecs;
}

JNIEXPORT void JNICALL Java_com_izquierdo_alberto_engine_GameLib_screenPressed(JNIEnv *env, jobject obj, jint _x, jint _y)
{
	m_inputManager.screenPressed(_x, _y);
}

JNIEXPORT void JNICALL Java_com_izquierdo_alberto_engine_GameLib_screenReleased(JNIEnv *env, jobject obj, jint _x, jint _y)
{
	m_inputManager.screenReleased(_x, _y);
}

JNIEXPORT void JNICALL Java_com_izquierdo_alberto_engine_GameLib_screenDragged(JNIEnv *env, jobject obj, jint _x, jint _y)
{
	m_inputManager.screenDragged(_x, _y);
}
