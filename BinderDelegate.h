#ifndef BINDER_DELEGATE_H_
#define BINDER_DELEGATE_H_

#include "Delegate.h"
#include <memory>

template<class Return, class Arg1=void, class Arg2=void, class Arg3=void>
class Binder1stDelegate : public Delegate<Return,Arg2,Arg3>
{
public:
    Binder1stDelegate(std::auto_ptr< Delegate<Return,Arg1,Arg2,Arg3> > d, Arg1 arg1)
        : callee_(d), arg1_(arg1)
    {
    }

    virtual Return call(Arg2 arg2, Arg3 arg3)
    {
        return callee_->call(arg1_, arg2, arg3);
    }

public:
    std::auto_ptr< Delegate<Return,Arg1,Arg2,Arg3> > callee_;
    Arg1 arg1_;
};

template<class Return, class Arg1, class Arg2>
class Binder1stDelegate<Return,Arg1,Arg2,void> : public Delegate<Return,Arg2>
{
public:
    Binder1stDelegate(std::auto_ptr< Delegate<Return,Arg1,Arg2> > d, Arg1 arg1)
        : callee_(d), arg1_(arg1)
    {
    }

    virtual Return call(Arg2 arg2)
    {
        return callee_->call(arg1_, arg2);
    }

public:
    std::auto_ptr< Delegate<Return,Arg1,Arg2> > callee_;
    Arg1 arg1_;
};

template<class Return, class Arg1>
class Binder1stDelegate<Return,Arg1,void,void> : public Delegate<Return>
{
public:
    Binder1stDelegate(std::auto_ptr< Delegate<Return,Arg1> > d, Arg1 arg1)
        : callee_(d), arg1_(arg1)
    {
    }

    virtual Return call()
    {
        return callee_->call(arg1_);
    }

public:
    std::auto_ptr< Delegate<Return,Arg1> > callee_;
    Arg1 arg1_;
};

template<class Return, class Arg1=void, class Arg2=void, class Arg3=void>
class Binder2ndDelegate : public Delegate<Return,Arg1,Arg3>
{
public:
    Binder2ndDelegate(std::auto_ptr< Delegate<Return,Arg1,Arg2,Arg3> > d, Arg2 arg2)
        : callee_(d), arg2_(arg2)
    {
    }

    virtual Return call(Arg1 arg1, Arg3 arg3)
    {
        return callee_->call(arg1, arg2_, arg3);
    }

public:
    std::auto_ptr< Delegate<Return,Arg1,Arg2,Arg3> > callee_;
    Arg2 arg2_;
};

template<class Return, class Arg1, class Arg2>
class Binder2ndDelegate<Return,Arg1,Arg2,void> : public Delegate<Return,Arg1>
{
public:
    Binder2ndDelegate(std::auto_ptr< Delegate<Return,Arg1,Arg2> > d, Arg2 arg2)
        : callee_(d), arg2_(arg2)
    {
    }

    virtual Return call(Arg1 arg1)
    {
        return callee_->call(arg1, arg2_);
    }

public:
    std::auto_ptr< Delegate<Return,Arg1,Arg2> > callee_;
    Arg2 arg2_;
};

template<class Return, class Arg1=void, class Arg2=void, class Arg3=void>
class Binder3rdDelegate : public Delegate<Return,Arg1,Arg2>
{
public:
    Binder3rdDelegate(std::auto_ptr< Delegate<Return,Arg1,Arg2,Arg3> > d, Arg3 arg3)
        : callee_(d), arg3_(arg3)
    {
    }

    virtual Return call(Arg1 arg1, Arg2 arg2)
    {
        return callee_->call(arg1, arg2, arg3_);
    }

public:
    std::auto_ptr< Delegate<Return,Arg1,Arg2,Arg3> > callee_;
    Arg3 arg3_;
};


template<class Return, class Arg1, class Arg2, class Arg3>
inline std::auto_ptr< Delegate<Return,Arg2,Arg3> >
bind(std::auto_ptr< Delegate<Return,Arg1,Arg2,Arg3> > d, Arg1 arg1)
{
    return std::auto_ptr< Delegate<Return,Arg2,Arg3> >(new Binder1stDelegate<Return,Arg1,Arg2,Arg3>(d, arg1));
}

template<class Return, class Arg1, class Arg2>
inline std::auto_ptr< Delegate<Return,Arg2> >
bind(std::auto_ptr< Delegate<Return,Arg1,Arg2> > d, Arg1 arg1)
{
    return std::auto_ptr< Delegate<Return,Arg2> >(new Binder1stDelegate<Return,Arg1,Arg2>(d, arg1));
}

template<class Return, class Arg1>
inline std::auto_ptr< Delegate<Return> >
bind(std::auto_ptr< Delegate<Return,Arg1> > d, Arg1 arg1)
{
    return std::auto_ptr< Delegate<Return> >(new Binder1stDelegate<Return,Arg1>(d, arg1));
}

template<class Return, class Arg1, class Arg2, class Arg3>
inline std::auto_ptr< Delegate<Return,Arg3> >
bind(std::auto_ptr< Delegate<Return,Arg1,Arg2,Arg3> > d, Arg1 arg1, Arg2 arg2)
{
    return bind(bind(d, arg1), arg2);
}

template<class Return, class Arg1, class Arg2>
inline std::auto_ptr< Delegate<Return> >
bind(std::auto_ptr< Delegate<Return,Arg1,Arg2> > d, Arg1 arg1, Arg2 arg2)
{
    return bind(bind(d, arg1), arg2);
}

template<class Return, class Arg1, class Arg2, class Arg3>
inline std::auto_ptr< Delegate<Return> >
bind(std::auto_ptr< Delegate<Return,Arg1,Arg2,Arg3> > d, Arg1 arg1, Arg2 arg2, Arg3 arg3)
{
    return bind(bind(bind(d, arg1), arg2), arg3);
}

template<class Return, class Arg1, class Arg2, class Arg3>
inline std::auto_ptr< Delegate<Return,Arg1,Arg3> >
bind2nd(std::auto_ptr< Delegate<Return,Arg1,Arg2,Arg3> > d, Arg2 arg2)
{
    return std::auto_ptr< Delegate<Return,Arg1,Arg3> >(new Binder2ndDelegate<Return,Arg1,Arg2,Arg3>(d, arg2));
}

template<class Return, class Arg1, class Arg2>
inline std::auto_ptr< Delegate<Return,Arg1> >
bind2nd(std::auto_ptr< Delegate<Return,Arg1,Arg2> > d, Arg2 arg2)
{
    return std::auto_ptr< Delegate<Return,Arg1> >(new Binder2ndDelegate<Return,Arg1,Arg2>(d, arg2));
}

template<class Return, class Arg1, class Arg2, class Arg3>
inline std::auto_ptr< Delegate<Return,Arg1,Arg2> >
bind3rd(std::auto_ptr< Delegate<Return,Arg1,Arg2,Arg3> > d, Arg3 arg3)
{
    return std::auto_ptr< Delegate<Return,Arg1,Arg2> >(new Binder3rdDelegate<Return,Arg1,Arg2,Arg3>(d, arg3));
}

#endif /* BINDER_DELEGATE_H_ */
