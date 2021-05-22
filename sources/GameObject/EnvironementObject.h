#ifndef ENVIRONEMENTOBJECT_H
#define ENVIRONEMENTOBJECT_H


enum class EnvObjTypes
{
    Tree,
    Rock
};

class EnvironementObject
{
public:
    EnvironementObject(Vector2 p_texturePosition, std::string p_textureID);
    ~EnvironementObject();
private:
    EnvObjTypes m_envObjType;
};

#endif // ENVIRONEMENTOBJECT_H
