#ifndef BIND_DELEGATE_H_
#define BIND_DELEGATE_H_

#include "Delegate.h"
#include <memory>

template<class Return, class Arg1=void, class Arg2=void, class Arg3=void>
class Binder1stDelegate : public Delegate<Return,Arg2,Arg3>
{
public:
    Binder1stDelegate(const Delegate<Return,Arg1,Arg2,Arg3>& d, Arg1 arg1);
    Binder1stDelegate(const Binder1stDelegate<Return,Arg1,Arg2,Arg3>& other);

    virtual Return call(Arg2 arg2, Arg3 arg3) const;
    virtual Delegate<Return,Arg1,Arg2>* copy() const;

public:
    std::auto_ptr<Delegate<Return,Arg1,Arg2,Arg3> > callee_;
    Arg1 arg1_;
};

template<class Return, class Arg1, class Arg2>
class Binder1stDelegate<Return,Arg1,Arg2,void> : public Delegate<Return,Arg2>
{
public:
    Binder1stDelegate(const Delegate<Return,Arg1,Arg2>& d, Arg1 arg1);
    Binder1stDelegate(const Binder1stDelegate<Return,Arg1,Arg2>& other);

    virtual Return call(Arg2 arg2) const;
    virtual Delegate<Return,Arg1>* copy() const;

public:
    std::auto_ptr<Delegate<Return,Arg1,Arg2> > callee_;
    Arg1 arg1_;
};

template<class Return, class Arg1>
class Binder1stDelegate<Return,Arg1,void,void> : public Delegate<Return>
{
public:
    Binder1stDelegate(const Delegate<Return,Arg1>& d, Arg1 arg1);
    Binder1stDelegate(const Binder1stDelegate<Return,Arg1>& other);

    virtual Return call() const;
    virtual Delegate<Return>* copy() const;

public:
    std::auto_ptr<Delegate<Return,Arg1> > callee_;
    Arg1 arg1_;
};

template<class Return, class Arg1=void, class Arg2=void, class Arg3=void>
class Binder2ndDelegate : public Delegate<Return,Arg1,Arg3>
{
public:
    Binder2ndDelegate(const Delegate<Return,Arg1,Arg2,Arg3>& d, Arg2 arg2);
    Binder2ndDelegate(const Binder2ndDelegate<Return,Arg1,Arg2,Arg3>& other);

    virtual Return call(Arg1 arg1, Arg3 arg3) const;
    virtual Delegate<Return,Arg1,Arg3>* copy() const;

public:
    std::auto_ptr<Delegate<Return,Arg1,Arg2,Arg3> > callee_;
    Arg2 arg2_;
};

template<class Return, class Arg1, class Arg2>
class Binder2ndDelegate<Return,Arg1,Arg2,void> : public Delegate<Return,Arg1>
{
public:
    Binder2ndDelegate(const Delegate<Return,Arg1,Arg2>& d, Arg2 arg2);
    Binder2ndDelegate(const Binder2ndDelegate<Return,Arg1,Arg2>& other);

    virtual Return call(Arg1 arg1) const;
    virtual Delegate<Return,Arg1>* copy() const;

public:
    std::auto_ptr<Delegate<Return,Arg1,Arg2> > callee_;
    Arg2 arg2_;
};

template<class Return, class Arg1=void, class Arg2=void, class Arg3=void>
class Binder3rdDelegate : public Delegate<Return,Arg1,Arg2>
{
public:
    Binder3rdDelegate(const Delegate<Return,Arg1,Arg2,Arg3>& d, Arg3 arg2);
    Binder3rdDelegate(const Binder3rdDelegate<Return,Arg1,Arg2,Arg3>& other);

    virtual Return call(Arg1 arg1, Arg2 arg2) const;
    virtual Delegate<Return,Arg1,Arg2>* copy() const;

public:
    std::auto_ptr<Delegate<Return,Arg1,Arg2,Arg3> > callee_;
    Arg3 arg3_;
};

template<class Return, class Arg1, class Arg2, class Arg3>
inline Binder1stDelegate<Return,Arg1,Arg2,Arg3>::Binder1stDelegate(const Delegate<Return,Arg1,Arg2,Arg3>& d, Arg1 arg1)
    : callee_(d.copy()), arg1_(arg1)
{
}

template<class Return, class Arg1, class Arg2, class Arg3>
inline Binder1stDelegate<Return,Arg1,Arg2,Arg3>::Binder1stDelegate(const Binder1stDelegate<Return,Arg1,Arg2,Arg3>& other)
    : callee_(other.callee_->copy()), arg1_(other.arg1_)
{
}

template<class Return, class Arg1, class Arg2, class Arg3>
inline Return Binder1stDelegate<Return,Arg1,Arg2,Arg3>::call(Arg2 arg2, Arg3 arg3) const
{
    return callee_->call(arg1_, arg2, arg3);
}

template<class Return, class Arg1, class Arg2, class Arg3>
inline Delegate<Return,Arg1,Arg2>* Binder1stDelegate<Return,Arg1,Arg2,Arg3>::copy() const
{
    return new Binder1stDelegate<Return,Arg1,Arg2,Arg3>(*this);
}

template<class Return, class Arg1, class Arg2>
inline Binder1stDelegate<Return,Arg1,Arg2>::Binder1stDelegate(const Delegate<Return,Arg1,Arg2>& d, Arg1 arg1)
    : callee_(d.copy), arg1_(arg1)
{
}

template<class Return, class Arg1, class Arg2>
inline Binder1stDelegate<Return,Arg1,Arg2>::Binder1stDelegate(const Binder1stDelegate<Return,Arg1,Arg2>& other)
    : callee_(other.callee_->copy()), arg1_(other.arg1_)
{
}

template<class Return, class Arg1, class Arg2>
inline Return Binder1stDelegate<Return,Arg1,Arg2>::call(Arg2 arg2) const
{
    return callee_->call(arg1_, arg2);
}

template<class Return, class Arg1, class Arg2>
inline Delegate<Return,Arg1>* Binder1stDelegate<Return,Arg1,Arg2>::copy() const
{
    return new Binder1stDelegate<Return,Arg1,Arg2>(*this);
}

template<class Return, class Arg1>
inline Binder1stDelegate<Return,Arg1>::Binder1stDelegate(const Delegate<Return,Arg1>& d, Arg1 arg1)
    : callee_(d.copy()), arg1_(arg1)
{
}

template<class Return, class Arg1>
inline Binder1stDelegate<Return,Arg1>::Binder1stDelegate(const Binder1stDelegate<Return,Arg1>& other)
    : callee_(other.callee_->copy()), arg1_(other.arg1_)
{
}

template<class Return, class Arg1>
inline Return Binder1stDelegate<Return,Arg1>::call() const
{
    return callee_->call(arg1_);
}

template<class Return, class Arg1>
inline Delegate<Return>* Binder1stDelegate<Return,Arg1>::copy() const
{
    return new Binder1stDelegate<Return,Arg1>(*this);
}

template<class Return, class Arg1, class Arg2, class Arg3>
inline Binder2ndDelegate<Return,Arg1,Arg2,Arg3>::Binder2ndDelegate(const Delegate<Return,Arg1,Arg2,Arg3>& d, Arg2 arg2)
    : callee_(d.copy()), arg2_(arg2)
{
}

template<class Return, class Arg1, class Arg2, class Arg3>
inline Binder2ndDelegate<Return,Arg1,Arg2,Arg3>::Binder2ndDelegate(const Binder2ndDelegate<Return,Arg1,Arg2,Arg3>& other)
    : callee_(other.callee_->copy()), arg2_(other.arg2_)
{
}

template<class Return, class Arg1, class Arg2, class Arg3>
inline Return Binder2ndDelegate<Return,Arg1,Arg2,Arg3>::call(Arg1 arg1, Arg3 arg3) const
{
    return callee_->call(arg1, arg2_, arg3);
}

template<class Return, class Arg1, class Arg2, class Arg3>
inline Delegate<Return,Arg1,Arg3>* Binder2ndDelegate<Return,Arg1,Arg2,Arg3>::copy() const
{
    return new Binder2ndDelegate<Return,Arg1,Arg2,Arg3>(*this);
}

template<class Return, class Arg1, class Arg2>
inline Binder2ndDelegate<Return,Arg1,Arg2>::Binder2ndDelegate(const Delegate<Return,Arg1,Arg2>& d, Arg2 arg2)
    : callee_(d.copy()), arg2_(arg2)
{
}

template<class Return, class Arg1, class Arg2>
inline Binder2ndDelegate<Return,Arg1,Arg2>::Binder2ndDelegate(const Binder2ndDelegate<Return,Arg1,Arg2>& other)
    : callee_(other.callee_->copy()), arg2_(other.arg2_)
{
}

template<class Return, class Arg1, class Arg2>
inline Return Binder2ndDelegate<Return,Arg1,Arg2>::call(Arg1 arg1) const
{
    return callee_->call(arg1, arg2_);
}

template<class Return, class Arg1, class Arg2>
inline Delegate<Return,Arg1>* Binder2ndDelegate<Return,Arg1,Arg2>::copy() const
{
    return new Binder2ndDelegate<Return,Arg1,Arg2>(*this);
}

template<class Return, class Arg1, class Arg2, class Arg3>
inline Binder3rdDelegate<Return,Arg1,Arg2,Arg3>::Binder3rdDelegate(const Delegate<Return,Arg1,Arg2,Arg3>& d, Arg3 arg3)
    : callee_(d.copy()), arg3_(arg3)
{
}

template<class Return, class Arg1, class Arg2, class Arg3>
inline Binder3rdDelegate<Return,Arg1,Arg2,Arg3>::Binder3rdDelegate(const Binder3rdDelegate<Return,Arg1,Arg2,Arg3>& other)
    : callee_(other.callee_->copy()), arg3_(other.arg3_)
{
}

template<class Return, class Arg1, class Arg2, class Arg3>
inline Return Binder3rdDelegate<Return,Arg1,Arg2,Arg3>::call(Arg1 arg1, Arg2 arg2) const
{
    return callee_->call(arg1, arg2, arg3_);
}

template<class Return, class Arg1, class Arg2, class Arg3>
inline Delegate<Return,Arg1,Arg2>* Binder3rdDelegate<Return,Arg1,Arg2,Arg3>::copy() const
{
    return new Binder3rdDelegate<Return,Arg1,Arg2,Arg3>(*this);
}

template<class Return, class Arg1, class Arg2, class Arg3>
inline Binder1stDelegate<Return,Arg1,Arg2,Arg3>
bind1st(const Delegate<Return,Arg1,Arg2,Arg3>& d, Arg1 arg1)
{
    return Binder1stDelegate<Return,Arg1,Arg2,Arg3>(d, arg1);
}

template<class Return, class Arg1, class Arg2>
inline Binder1stDelegate<Return,Arg1,Arg2>
bind1st(const Delegate<Return,Arg1,Arg2>& d, Arg1 arg1)
{
    return Binder1stDelegate<Return,Arg1,Arg2>(d, arg1);
}

template<class Return, class Arg1>
inline Binder1stDelegate<Return,Arg1>
bind1st(const Delegate<Return,Arg1>& d, Arg1 arg1)
{
    return Binder1stDelegate<Return,Arg1>(d, arg1);
}

template<class Return, class Arg1, class Arg2, class Arg3>
inline Binder2ndDelegate<Return,Arg1,Arg2,Arg3>
bind2nd(const Delegate<Return,Arg1,Arg2,Arg3>& d, Arg2 arg2)
{
    return Binder2ndDelegate<Return,Arg1,Arg2,Arg3>(d, arg2);
}

template<class Return, class Arg1, class Arg2>
inline Binder2ndDelegate<Return,Arg1,Arg2>
bind2nd(const Delegate<Return,Arg1,Arg2>& d, Arg2 arg2)
{
    return Binder2ndDelegate<Return,Arg1,Arg2>(d, arg2);
}

template<class Return, class Arg1, class Arg2, class Arg3>
inline Binder3rdDelegate<Return,Arg1,Arg2,Arg3>
bind3rd(const Delegate<Return,Arg1,Arg2,Arg3>& d, Arg3 arg3)
{
    return Binder3rdDelegate<Return,Arg1,Arg2,Arg3>(d, arg3);
}

#endif /* BIND_DELEGATE_H_ */
