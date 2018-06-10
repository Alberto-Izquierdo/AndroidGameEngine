#pragma once

#include <unordered_map>
#include "State.h"

template<class T>
class StateMachine
{
public:
	StateMachine<T>(T* _pObject);
	virtual ~StateMachine<T>();

	void Update(float _fDelta);
	void Render();

	virtual void SwitchState(StateID _eNextState);

	StateID GetCurrentStateID() const;
	StateID GetPreviousStateID() const;

	void CursorPressed(int _iX, int _iY);
	void CursorReleased();
	void CursorDragged(int _iX, int _iY);

protected:
	T* m_pObject;
	State<T>* m_pCurrentState;
	State<T>* m_pPreviousState;
	std::unordered_map<StateID, State<T>*> m_mStates;
};

template <class T>
StateMachine<T>::StateMachine(T* _pObject)
	: m_pObject(_pObject)
	, m_pCurrentState(nullptr)
	, m_pPreviousState(nullptr)
{
}

template <class T>
StateMachine<T>::~StateMachine()
{
	m_mStates.clear();
}

template <class T>
void StateMachine<T>::Update(float _fDelta)
{
	m_pCurrentState->Update(m_pObject, _fDelta);
}

template <class T>
void StateMachine<T>::Render()
{
	m_pCurrentState->Render(m_pObject);
}

template <class T>
void StateMachine<T>::SwitchState(StateID _eNextState)
{
	if (m_pCurrentState != nullptr)
	{
		m_pCurrentState->OnExit(m_pObject);
	}

	m_pPreviousState = m_pCurrentState;
	m_pCurrentState = m_mStates[_eNextState];
	m_pCurrentState->OnEnter(m_pObject);
}

template <class T>
StateID StateMachine<T>::GetCurrentStateID() const
{
	return m_pCurrentState->GetStateID();
}

template <class T>
StateID StateMachine<T>::GetPreviousStateID() const
{
	return m_pPreviousState->GetStateID();
}

template <class T>
void StateMachine<T>::CursorPressed(int _iX, int _iY)
{
	m_pCurrentState->CursorPressed(m_pObject, _iX, _iY);
}

template <class T>
void StateMachine<T>::CursorReleased()
{
	m_pCurrentState->CursorReleased(m_pObject);
}

template <class T>
void StateMachine<T>::CursorDragged(int _iX, int _iY)
{
	m_pCurrentState->CursorDragged(m_pObject, _iX, _iY);
}

