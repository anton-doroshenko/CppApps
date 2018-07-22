#pragma once
class BulletManager
{
public:
	BulletManager();
	~BulletManager();
	void Update(float time);
	void Fire(float pos, float dir, float speed, float time, float life_time);
};

