#ifndef WOB_ENVIRONEMENTOBJECT_H
#define WOB_ENVIRONEMENTOBJECT_H


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

#endif // WOB_ENVIRONEMENTOBJECT_H
