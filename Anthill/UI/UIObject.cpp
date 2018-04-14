#include "UIObject.h"



UIObject::~UIObject()
{

}

void UIObject::setParent(UIObject * obj)
{
	parent = obj;
}

void UIObject::hiddenUpdate()
{

}
