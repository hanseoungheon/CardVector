#pragma once
#include<Windows.h>

class Input
{
	struct KeyState
	{
		//���� �����ӿ� Ű�� ���ȴ��� ����
		bool isKeyDown = false;

		//���� �����ӿ� Ű�� ���ȴ��� ����
		bool previouseKeyDown = false;
	};

public:

	Input();

	//Ű Ȯ�� �Լ�
	bool GetKey(int KeyCode);
	bool GetKeyDown(int KeyCode);
	bool GetKeyUp(int KeyCode);


	static Input& Get();

public:
	void ProcessInput();
	void SavePreviouseKeyStates();

	//Ű �Է� ���� ���� ����
	KeyState keyStates[255] = { };

	static Input* instance;
};