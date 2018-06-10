#pragma once

class InputManager
{
public:
	static InputManager &instance();

	void screenPressed(int _x, int _y);
	void screenReleased(int _x, int _y);
	void screenDragged(int _x, int _y);

private:
	bool m_screenBeingPressed;
	int m_initialX, m_initialY;
	InputManager();
	~InputManager();
};
