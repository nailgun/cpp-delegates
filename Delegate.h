#ifndef DELEGATE_H_
#define DELEGATE_H_

template<class Return, class Arg1=void, class Arg2=void, class Arg3=void>
class Delegate
{
public:
    virtual ~Delegate() {}
    virtual Return call(Arg1 arg1, Arg2 arg2, Arg3 arg3) = 0;
};

template<class Return, class Arg1, class Arg2>
class Delegate<Return,Arg1,Arg2,void>
{
public:
    virtual ~Delegate() {}
    virtual Return call(Arg1 arg1, Arg2 arg2) = 0;
};

template<class Return, class Arg1>
class Delegate<Return,Arg1,void,void>
{
public:
    virtual ~Delegate() {}
    virtual Return call(Arg1 arg1) = 0;
};

template<class Return>
class Delegate<Return,void,void,void>
{
public:
    virtual ~Delegate() {}
    virtual Return call() = 0;
};

#include "StaticDelegate.h"
#include "MethodDelegate.h"
#include "BinderDelegate.h"

#endif /* DELEGATE_H_ */
