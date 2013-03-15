
#ifndef __CCCALL_LAMBDA_H__
#define __CCCALL_LAMBDA_H__

#include "CCActionInstant.h"
#include <functional>

NS_CC_BEGIN

/** @brief Calls a c++11 lambda function
 */
class CC_DLL CCCallLambda : public CCActionInstant {
protected:
    
    std::function<void(void)> mFunction;
    
public:
    
    CCCallLambda(void)             = default;
    virtual ~CCCallLambda(void)    = default;
    
    static CCCallLambda* create(const std::function<void(void)>& func);
    virtual bool initWithLambda(const std::function<void(void)>& func);
    virtual CCObject* copyWithZone(CCZone *pZone);
    virtual void update(float time);
};

NS_CC_END

#endif
