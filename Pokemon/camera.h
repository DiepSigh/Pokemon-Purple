#ifndef CAMERA_H
#define CAMERA_H

class Camera {
public:
	static Camera* Instance();	
	void Update();
	void Release();

	float GetXPos() { return mPosX; }
	void SetXPos(float newxpos) { mPosX = newxpos; }
	float GetYPos() { return mPosY; }
	void SetYPos(float newypos) { mPosY = newypos; }

	float GetSpeed() { return Speed; }
	void SetSpeed(float s) { Speed = s; }

	float GetVel() { return Vel; }
	void SetVel(float vel) { Vel = vel; }
	
private:
	static Camera* sInstance;
	float mPosX;
	float mPosY;
	float Speed;
	float Vel;
	static float SreenWidth;
	static float SreenHeight;
	Camera();
	~Camera();

};

#endif // !CAMERA_H

