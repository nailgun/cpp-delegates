#ifndef STATIC_DELEGATE_H_
#define STATIC_DELEGATE_H_

#include "Delegate.h"

template<class Return, class Arg1=void, class Arg2=void, class Arg3=void>
class StaticDelegate : public Delegate<Return,Arg1,Arg2,Arg3>
{
public:
    typedef Return (*Signature)(Arg1,Arg2,Arg3);
    StaticDelegate(Signature f);
    virtual Return operator()(Arg1 arg1, Arg2 arg2, Arg3 arg3) const;
    virtual Delegate<Return,Arg1,Arg2,Arg3>* copy() const;

private:
    Signature	func;
};

template<class Return, class Arg1, class Arg2>
class StaticDelegate<Return,Arg1,Arg2,void> : public Delegate<Return,Arg1,Arg2>
{
public:
    typedef Return (*Signature)(Arg1,Arg2);
    StaticDelegate(Signature f);
    virtual Return operator()(Arg1 arg1, Arg2 arg2) const;
    virtual Delegate<Return,Arg1,Arg2>* copy() const;

private:
    Signature	func;
};

template<class Return, class Arg1>
class StaticDelegate<Return,Arg1,void,void> : public Delegate<Return,Arg1>
{
public:
    typedef Return (*Signature)(Arg1);
    StaticDelegate(Signature f);
    virtual Return operator()(Arg1 arg1) const;
    virtual Delegate<Return,Arg1>* copy() const;

private:
    Signature	func;
};

template<class Return>
class StaticDelegate<Return,void,void,void> : public Delegate<Return>
{
public:
    typedef Return (*Signature)();
    StaticDelegate(Signature f);
    virtual Return operator()() const;
    virtual Delegate<Return>* copy() const;

private:
    Signature	func;
};

template<class Return, class Arg1, class Arg2, class Arg3>
inline StaticDelegate<Return,Arg1,Arg2,Arg3>::StaticDelegate(Signature f)
{
    func = f;
}

template<class Return, class Arg1, class Arg2, class Arg3>
inline Return StaticDelegate<Return,Arg1,Arg2,Arg3>::operator()(Arg1 arg1, Arg2 arg2, Arg3 arg3) const
{
    return (*func)(arg1,arg2,arg3);
}

template<class Return, class Arg1, class Arg2, class Arg3>
inline Delegate<Return,Arg1,Arg2,Arg3>* StaticDelegate<Return,Arg1,Arg2,Arg3>::copy() const
{
    return new StaticDelegate<Return,Arg1,Arg2,Arg3>(*this);
}

template<class Return, class Arg1, class Arg2>
inline StaticDelegate<Return,Arg1,Arg2,void>::StaticDelegate(Signature f)
{
    func = f;
}

template<class Return, class Arg1, class Arg2>
inline Return StaticDelegate<Return,Arg1,Arg2,void>::operator()(Arg1 arg1, Arg2 arg2) const
{
    return (*func)(arg1,arg2);
}

template<class Return, class Arg1, class Arg2>
inline Delegate<Return,Arg1,Arg2>* StaticDelegate<Return,Arg1,Arg2>::copy() const
{
    return new StaticDelegate<Return,Arg1,Arg2>(*this);
}

template<class Return, class Arg1>
inline StaticDelegate<Return,Arg1,void,void>::StaticDelegate(Signature f)
{
    func = f;
}

template<class Return, class Arg1>
inline Return StaticDelegate<Return,Arg1,void,void>::operator()(Arg1 arg1) const
{
    return (*func)(arg1);
}

template<class Return, class Arg1>
inline Delegate<Return,Arg1>* StaticDelegate<Return,Arg1>::copy() const
{
    return new StaticDelegate<Return,Arg1>(*this);
}

template<class Return>
inline StaticDelegate<Return,void,void,void>::StaticDelegate(Signature f)
{
    func = f;
}

template<class Return>
inline Return StaticDelegate<Return,void,void,void>::operator()() const
{
    return (*func)();
}

template<class Return>
inline Delegate<Return>* StaticDelegate<Return>::copy() const
{
    return new StaticDelegate<Return>(*this);
}


template<class Return, class Arg1, class Arg2, class Arg3>
inline StaticDelegate<Return,Arg1,Arg2,Arg3>
delegate(Return (*f)(Arg1,Arg2,Arg3))
{
    return StaticDelegate<Return,Arg1,Arg2,Arg3>(f);
}

template<class Return, class Arg1, class Arg2>
inline StaticDelegate<Return,Arg1,Arg2>
delegate(Return (*f)(Arg1,Arg2))
{
    return StaticDelegate<Return,Arg1,Arg2>(f);
}

template<class Return, class Arg1>
inline StaticDelegate<Return,Arg1>
delegate(Return (*f)(Arg1))
{
    return StaticDelegate<Return,Arg1>(f);
}

template<class Return>
inline StaticDelegate<Return>
delegate(Return (*f)())
{
    return StaticDelegate<Return>(f);
}

template<class Arg1, class Arg2, class Arg3>
inline StaticDelegate<void,Arg1,Arg2,Arg3>
slot(void (*f)(Arg1,Arg2,Arg3))
{
    return StaticDelegate<void,Arg1,Arg2,Arg3>(f);
}

template<class Arg1, class Arg2>
inline StaticDelegate<void,Arg1,Arg2>
slot(void (*f)(Arg1,Arg2))
{
    return StaticDelegate<void,Arg1,Arg2>(f);
}

template<class Arg1>
inline StaticDelegate<void,Arg1>
slot(void (*f)(Arg1))
{
    return StaticDelegate<void,Arg1>(f);
}

inline StaticDelegate<void>
slot(void (*f)())
{
    return StaticDelegate<void>(f);
}

#endif /* STATIC_DELEGATE_H_ */
