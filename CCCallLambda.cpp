#include "CCCallLambda.h"
#include "CCZone.h"

NS_CC_BEGIN

CCCallLambda* CCCallLambda::create(const std::function<void(void)>& func) {
    
    CCCallLambda* pRet = new CCCallLambda();
    
    if (pRet && pRet->initWithLambda(func)) {
        pRet->autorelease();
        return pRet;
    }
    
    CC_SAFE_DELETE(pRet);
    return NULL;
}

bool CCCallLambda::initWithLambda(const std::function<void(void)>& func) {
    
    mFunction = func;
    
    return true;
}

CCObject* CCCallLambda::copyWithZone(CCZone *pZone) {
    
    CCZone* pNewZone    = nullptr;
    CCCallLambda* pRet  = nullptr;
    
    if (pZone && pZone->m_pCopyObject) {
        pRet = (CCCallLambda*) (pZone->m_pCopyObject);
    }
    else {
        pRet = new CCCallLambda();
        pZone = pNewZone = new CCZone(pRet);
    }
    
    CCActionInstant::copyWithZone(pZone);
    
    pRet->initWithLambda(mFunction);
    
    CC_SAFE_DELETE(pNewZone);
    return pRet;
}

void CCCallLambda::update(float time) {
    
    CCActionInstant::update(time);
    
    mFunction();
}

NS_CC_END
