#include"Reflection.h"

IMPLEMENT_REFLECTION_PRIMITIVE(int, Int)
IMPLEMENT_REFLECTION_PRIMITIVE(float, Float)
IMPLEMENT_REFLECTION_PRIMITIVE(double, Double)
IMPLEMENT_REFLECTION_PRIMITIVE(char*, CString)
IMPLEMENT_REFLECTION_PRIMITIVE(std::string, StdString)