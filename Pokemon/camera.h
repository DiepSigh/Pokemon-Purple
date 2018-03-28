#ifndef CAMERA_H
#define CAMERA_H


class Camera {

private:
	static Camera* sInstance;
	static bool sInitialized;

public:
	static Camera* Instance();
	static bool Initialized();
	void Update();

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

