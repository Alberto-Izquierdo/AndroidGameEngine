#pragma once

enum StateID
{
	INVALID,
};

template <class T>
class State
{
public:
	State() {};
	virtual ~State() {}; 

	virtual void update(T* _pObject, float _fDelta) = 0;
	virtual void render(T* _pObject) {};
	StateID getStateID() const { return m_eStateID; };

	virtual void onEnter(T* _pObject) = 0;
	virtual void onExit(T* _pObject) = 0;

	virtual void screenPressed(T* _pObject, int _iX, int _iY) {};
	virtual void screenReleased(T* _pObject) {};
	virtual void screenDragged(T* _pObject, int _iX, int _iY) {};

protected:
	StateID m_eStateID;
};


