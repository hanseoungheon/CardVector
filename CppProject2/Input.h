#pragma once
#include<Windows.h>

class Input
{
	struct KeyState
	{
		//현재 프레임에 키가 눌렸는지 여부
		bool isKeyDown = false;

		//이전 프레임에 키가 눌렸는지 여부
		bool previouseKeyDown = false;
	};

public:

	Input();

	//키 확인 함수
	bool GetKey(int KeyCode);
	bool GetKeyDown(int KeyCode);
	bool GetKeyUp(int KeyCode);


	static Input& Get();

public:
	void ProcessInput();
	void SavePreviouseKeyStates();

	//키 입력 정보 관리 변수
	KeyState keyStates[255] = { };

	static Input* instance;
};