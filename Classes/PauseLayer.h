#include "cocos2d.h"
#include "ui/CocosGUI.h"

class PauseLayer : public cocos2d::Layer {

public:

    bool init() override;

    CREATE_FUNC(PauseLayer);

    void setButtonCallback(const std::function< void(Ref *)>& callback);

private:

    cocos2d::MenuItem* _bResume;

    cocos2d::Menu* _menu;
};
