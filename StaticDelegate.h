#ifndef STATIC_DELEGATE_H_
#define STATIC_DELEGATE_H_

#include "Delegate.h"
#include <memory>

template<class Return, class Arg1=void, class Arg2=void, class Arg3=void>
class StaticDelegate : public Delegate<Return,Arg1,Arg2,Arg3>
{
public:
    typedef Return (*Signature)(Arg1,Arg2,Arg3);

    StaticDelegate(Signature f)
        : func_(f)
    {
    }

    virtual Return call(Arg1 arg1, Arg2 arg2, Arg3 arg3)
    {
        return (*func_)(arg1,arg2,arg3);
    }

private:
    Signature   func_;
};

template<class Return, class Arg1, class Arg2>
class StaticDelegate<Return,Arg1,Arg2,void> : public Delegate<Return,Arg1,Arg2>
{
public:
    typedef Return (*Signature)(Arg1,Arg2);

    StaticDelegate(Signature f)
        : func_(f)
    {
    }

    virtual Return call(Arg1 arg1, Arg2 arg2)
    {
        return (*func_)(arg1,arg2);
    }

private:
    Signature   func_;
};

template<class Return, class Arg1>
class StaticDelegate<Return,Arg1,void,void> : public Delegate<Return,Arg1>
{
public:
    typedef Return (*Signature)(Arg1);

    StaticDelegate(Signature f)
        : func_(f)
    {
    }

    virtual Return call(Arg1 arg1)
    {
        return (*func_)(arg1);
    }

private:
    Signature   func_;
};

template<class Return>
class StaticDelegate<Return,void,void,void> : public Delegate<Return>
{
public:
    typedef Return (*Signature)();

    StaticDelegate(Signature f)
        : func_(f)
    {
    }

    virtual Return call()
    {
        return (*func_)();
    }

private:
    Signature   func_;
};


template<class Return, class Arg1, class Arg2, class Arg3>
inline std::auto_ptr< Delegate<Return,Arg1,Arg2,Arg3> >
delegate(Return (*f)(Arg1,Arg2,Arg3))
{
    return std::auto_ptr< Delegate<Return,Arg1,Arg2,Arg3> >(new StaticDelegate<Return,Arg1,Arg2,Arg3>(f));
}

template<class Return, class Arg1, class Arg2>
inline std::auto_ptr< Delegate<Return,Arg1,Arg2> >
delegate(Return (*f)(Arg1,Arg2))
{
    return std::auto_ptr< Delegate<Return,Arg1,Arg2> >(new StaticDelegate<Return,Arg1,Arg2>(f));
}

template<class Return, class Arg1>
inline std::auto_ptr< Delegate<Return,Arg1> >
delegate(Return (*f)(Arg1))
{
    return std::auto_ptr< Delegate<Return,Arg1> >(new StaticDelegate<Return,Arg1>(f));
}

template<class Return>
inline std::auto_ptr< Delegate<Return> >
delegate(Return (*f)())
{
    return std::auto_ptr< Delegate<Return> >(new StaticDelegate<Return>(f));
}

#if defined(DELEGATE_DEFINE_SLOTS)

template<class Arg1, class Arg2, class Arg3>
inline std::auto_ptr< Delegate<void,Arg1,Arg2,Arg3> >
slot(void (*f)(Arg1,Arg2,Arg3))
{
    return delegate(f);
}

template<class Arg1, class Arg2>
inline std::auto_ptr< Delegate<void,Arg1,Arg2> >
slot(void (*f)(Arg1,Arg2))
{
    return delegate(f);
}

template<class Arg1>
inline std::auto_ptr< Delegate<void,Arg1> >
slot(void (*f)(Arg1))
{
    return delegate(f);
}

inline std::auto_ptr< Delegate<void> >
slot(void (*f)())
{
    return delegate(f);
}

#endif // defined(DELEGATE_DEFINE_SLOTS)

#endif /* STATIC_DELEGATE_H_ */
