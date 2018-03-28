#ifndef CAMERA_H
#define CAMERA_H


class Camera {

private:
	static Camera* sInstance;
	static bool sInitialized;

public:
	static Camera* Instance();
	static bool Initialized();
	void UpdatePos();
	float GetPlayerXPos() { return mPlayerXPos; }
	float GetPlayerYPos() { return mPlayerYPos; }
	float GetCamXPos() { return mCamXPos; }
	float GetCamYPos() { return mCamYPos; }

private:
	Camera();
	~Camera();

	static Camera* sInstance;
	float mPlayerXPos;
	float mPlayerYPos;	
	float mCamXPos;
	float mCamYPos;
};


#endif // !CAMERA_H

