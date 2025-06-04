#include"Collision.h"
#include <math.h>

Collision::Collision() :
	is_blocking(false),
	box_size(0.0f),
	pivot(0.0f),
	object_type(eObjectType::eNone),
	hit_object_type()
{

}

Collision::~Collision()
{
	hit_object_type.clear();
}

bool Collision::IsCheckHitTarget(eObjectType hit_object) const
{
	for (eObjectType type : hit_object_type)
	{
		if (type == hit_object)
		{
			return true;
		}
	}

	return false;
}