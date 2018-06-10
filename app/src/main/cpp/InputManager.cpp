#include "InputManager.h"

InputManager &InputManager::instance()
{
	static InputManager inputManager;
	return inputManager;
}

void InputManager::screenPressed(int _x, int _y)
{
	m_screenBeingPressed = true;
	m_initialX = _x;
	m_initialY = _y;
}

void InputManager::screenReleased(int _x, int _y)
{
	m_screenBeingPressed = false;
}

void InputManager::screenDragged(int _x, int _y)
{
}

InputManager::InputManager()
	: m_screenBeingPressed(false)
	, m_initialX(0)
	, m_initialY(0)
{
}

InputManager::~InputManager()
{
}
