#ifndef METHOD_DELEGATE_H_
#define METHOD_DELEGATE_H_

#include "Delegate.h"

template<class Class, class Return, class Arg1=void, class Arg2=void, class Arg3=void>
class MethodDelegate : public Delegate<Return,Arg1,Arg2,Arg3>
{
public:
    typedef Return (Class::*Signature)(Arg1,Arg2,Arg3);
    MethodDelegate(Class* obj, Signature m);
    virtual Return call(Arg1 arg1, Arg2 arg2, Arg3 arg3) const;
    virtual Delegate<Return,Arg1,Arg2,Arg3>* copy() const;

private:
    Class* 		object_;
    Signature	method_;
};

template<class Class, class Return, class Arg1, class Arg2>
class MethodDelegate<Class,Return,Arg1,Arg2,void> : public Delegate<Return,Arg1,Arg2>
{
public:
    typedef Return (Class::*Signature)(Arg1,Arg2);
    MethodDelegate(Class* obj, Signature m);
    virtual Return call(Arg1 arg1, Arg2 arg2) const;
    virtual Delegate<Return,Arg1,Arg2>* copy() const;

private:
    Class* 		object_;
    Signature	method_;
};

template<class Class, class Return, class Arg1>
class MethodDelegate<Class,Return,Arg1,void,void> : public Delegate<Return,Arg1>
{
public:
    typedef Return (Class::*Signature)(Arg1);
    MethodDelegate(Class* obj, Signature m);
    virtual Return call(Arg1 arg1) const;
    virtual Delegate<Return,Arg1>* copy() const;

private:
    Class* 		object_;
    Signature	method_;
};

template<class Class, class Return>
class MethodDelegate<Class,Return,void,void,void> : public Delegate<Return>
{
public:
    typedef Return (Class::*Signature)();
    MethodDelegate(Class* obj, Signature m);
    virtual Return call() const;
    virtual Delegate<Return>* copy() const;

private:
    Class* 		object_;
    Signature	method_;
};

template<class Class, class Return, class Arg1=void, class Arg2=void, class Arg3=void>
class ConstMethodDelegate : public Delegate<Return,Arg1,Arg2,Arg3>
{
public:
    typedef Return (Class::*Signature)(Arg1,Arg2,Arg3) const;
    ConstMethodDelegate(const Class* obj, Signature m);
    virtual Return call(Arg1 arg1, Arg2 arg2, Arg3 arg3) const;
    virtual Delegate<Return,Arg1,Arg2,Arg3>* copy() const;

private:
    const Class* 	object_;
    Signature		method_;
};

template<class Class, class Return, class Arg1, class Arg2>
class ConstMethodDelegate<Class,Return,Arg1,Arg2,void> : public Delegate<Return,Arg1,Arg2>
{
public:
    typedef Return (Class::*Signature)(Arg1,Arg2) const;
    ConstMethodDelegate(const Class* obj, Signature m);
    virtual Return call(Arg1 arg1, Arg2 arg2) const;
    virtual Delegate<Return,Arg1,Arg2>* copy() const;

private:
    const Class* 	object_;
    Signature		method_;
};

template<class Class, class Return, class Arg1>
class ConstMethodDelegate<Class,Return,Arg1,void,void> : public Delegate<Return,Arg1>
{
public:
    typedef Return (Class::*Signature)(Arg1) const;
    ConstMethodDelegate(const Class* obj, Signature m);
    virtual Return call(Arg1 arg1) const;
    virtual Delegate<Return,Arg1>* copy() const;

private:
    const Class* 	object_;
    Signature		method_;
};

template<class Class, class Return>
class ConstMethodDelegate<Class,Return,void,void,void> : public Delegate<Return>
{
public:
    typedef Return (Class::*Signature)() const;
    ConstMethodDelegate(const Class* obj, Signature m);
    virtual Return call() const;
    virtual Delegate<Return>* copy() const;
private:
    const Class* 	object_;
    Signature		method_;
};

template<class Class, class Return, class Arg1, class Arg2, class Arg3>
inline MethodDelegate<Class,Return,Arg1,Arg2,Arg3>::MethodDelegate(Class* obj, Signature m)
    : object_(obj), method_(m)
{
}

template<class Class, class Return, class Arg1, class Arg2, class Arg3>
inline Return MethodDelegate<Class,Return,Arg1,Arg2,Arg3>::call(Arg1 arg1, Arg2 arg2, Arg3 arg3) const
{
    return (object_->*method_)(arg1,arg2,arg3);
}

template<class Class, class Return, class Arg1, class Arg2, class Arg3>
inline Delegate<Return,Arg1,Arg2,Arg3>* MethodDelegate<Class,Return,Arg1,Arg2,Arg3>::copy() const
{
    return new MethodDelegate<Class,Return,Arg1,Arg2,Arg3>(*this);
}

template<class Class, class Return, class Arg1, class Arg2>
inline MethodDelegate<Class,Return,Arg1,Arg2,void>::MethodDelegate(Class* obj, Signature m)
    : object_(obj), method_(m)
{
}

template<class Class, class Return, class Arg1, class Arg2>
inline Return MethodDelegate<Class,Return,Arg1,Arg2,void>::call(Arg1 arg1, Arg2 arg2) const
{
    return (object_->*method_)(arg1,arg2);
}

template<class Class, class Return, class Arg1, class Arg2>
inline Delegate<Return,Arg1,Arg2>* MethodDelegate<Class,Return,Arg1,Arg2>::copy() const
{
    return new MethodDelegate<Class,Return,Arg1,Arg2>(*this);
}

template<class Class, class Return, class Arg1>
inline MethodDelegate<Class,Return,Arg1,void,void>::MethodDelegate(Class* obj, Signature m)
    : object_(obj), method_(m)
{
}

template<class Class, class Return, class Arg1>
inline Return MethodDelegate<Class,Return,Arg1,void,void>::call(Arg1 arg1) const
{
    return (object_->*method_)(arg1);
}

template<class Class, class Return, class Arg1>
inline Delegate<Return,Arg1>* MethodDelegate<Class,Return,Arg1>::copy() const
{
    return new MethodDelegate<Class,Return,Arg1>(*this);
}

template<class Class, class Return>
inline MethodDelegate<Class,Return,void,void,void>::MethodDelegate(Class* obj, Signature m)
    : object_(obj), method_(m)
{
}

template<class Class, class Return>
inline Return MethodDelegate<Class,Return,void,void,void>::call() const
{
    return (object_->*method_)();
}

template<class Class, class Return>
inline Delegate<Return>* MethodDelegate<Class,Return>::copy() const
{
    return new MethodDelegate<Class,Return>(*this);
}

template<class Class, class Return, class Arg1, class Arg2, class Arg3>
inline ConstMethodDelegate<Class,Return,Arg1,Arg2,Arg3>::ConstMethodDelegate(const Class* obj, Signature m)
    : object_(obj), method_(m)
{
}

template<class Class, class Return, class Arg1, class Arg2, class Arg3>
inline Return ConstMethodDelegate<Class,Return,Arg1,Arg2,Arg3>::call(Arg1 arg1, Arg2 arg2, Arg3 arg3) const
{
    return (object_->*method_)(arg1,arg2,arg3);
}

template<class Class, class Return, class Arg1, class Arg2, class Arg3>
inline Delegate<Return,Arg1,Arg2,Arg3>* ConstMethodDelegate<Class,Return,Arg1,Arg2,Arg3>::copy() const
{
    return new ConstMethodDelegate<Class,Return,Arg1,Arg2,Arg3>(*this);
}

template<class Class, class Return, class Arg1, class Arg2>
inline ConstMethodDelegate<Class,Return,Arg1,Arg2,void>::ConstMethodDelegate(const Class* obj, Signature m)
    : object_(obj), method_(m)
{
}

template<class Class, class Return, class Arg1, class Arg2>
inline Return ConstMethodDelegate<Class,Return,Arg1,Arg2,void>::call(Arg1 arg1, Arg2 arg2) const
{
    return (object_->*method_)(arg1,arg2);
}

template<class Class, class Return, class Arg1, class Arg2>
inline Delegate<Return,Arg1,Arg2>* ConstMethodDelegate<Class,Return,Arg1,Arg2>::copy() const
{
    return new ConstMethodDelegate<Class,Return,Arg1,Arg2>(*this);
}

template<class Class, class Return, class Arg1>
inline ConstMethodDelegate<Class,Return,Arg1,void,void>::ConstMethodDelegate(const Class* obj, Signature m)
    : object_(obj), method_(m)
{
}

template<class Class, class Return, class Arg1>
inline Return ConstMethodDelegate<Class,Return,Arg1,void,void>::call(Arg1 arg1) const
{
    return (object_->*method_)(arg1);
}

template<class Class, class Return, class Arg1>
inline Delegate<Return,Arg1>* ConstMethodDelegate<Class,Return,Arg1>::copy() const
{
    return new ConstMethodDelegate<Class,Return,Arg1>(*this);
}

template<class Class, class Return>
inline ConstMethodDelegate<Class,Return,void,void,void>::ConstMethodDelegate(const Class* obj, Signature m)
    : object_(obj), method_(m)
{
}

template<class Class, class Return>
inline Return ConstMethodDelegate<Class,Return,void,void,void>::call() const
{
    return (object_->*method_)();
}

template<class Class, class Return>
inline Delegate<Return>* ConstMethodDelegate<Class,Return>::copy() const
{
    return new ConstMethodDelegate<Class,Return>(*this);
}


template<class Class, class Return, class Arg1, class Arg2, class Arg3>
inline MethodDelegate<Class,Return,Arg1,Arg2,Arg3>
delegate(Class* obj, Return (Class::*m)(Arg1,Arg2,Arg3))
{
    return MethodDelegate<Class,Return,Arg1,Arg2,Arg3>(obj, m);
}

template<class Class, class Return, class Arg1, class Arg2>
inline MethodDelegate<Class,Return,Arg1,Arg2>
delegate(Class* obj, Return (Class::*m)(Arg1,Arg2))
{
    return MethodDelegate<Class,Return,Arg1,Arg2>(obj, m);
}

template<class Class, class Return, class Arg1>
inline MethodDelegate<Class,Return,Arg1>
delegate(Class* obj, Return (Class::*m)(Arg1))
{
    return MethodDelegate<Class,Return,Arg1>(obj, m);
}

template<class Class, class Return>
inline MethodDelegate<Class,Return>
delegate(Class* obj, Return (Class::*m)())
{
    return MethodDelegate<Class,Return>(obj, m);
}

template<class Class, class Return, class Arg1, class Arg2, class Arg3>
inline ConstMethodDelegate<Class,Return,Arg1,Arg2,Arg3>
delegate(Class* obj, Return (Class::*m)(Arg1,Arg2,Arg3) const)
{
    return ConstMethodDelegate<Class,Return,Arg1,Arg2,Arg3>(obj, m);
}

template<class Class, class Return, class Arg1, class Arg2>
inline ConstMethodDelegate<Class,Return,Arg1,Arg2>
delegate(Class* obj, Return (Class::*m)(Arg1,Arg2) const)
{
    return ConstMethodDelegate<Class,Return,Arg1,Arg2>(obj, m);
}

template<class Class, class Return, class Arg1>
inline ConstMethodDelegate<Class,Return,Arg1>
delegate(Class* obj, Return (Class::*m)(Arg1) const)
{
    return ConstMethodDelegate<Class,Return,Arg1>(obj, m);
}

template<class Class, class Return>
inline ConstMethodDelegate<Class,Return>
delegate(Class* obj, Return (Class::*m)() const)
{
    return ConstMethodDelegate<Class,Return>(obj, m);
}

#if defined(DELEGATE_DEFINE_SLOTS)

template<class Class, class Arg1, class Arg2, class Arg3>
inline MethodDelegate<Class,void,Arg1,Arg2,Arg3>
slot(Class* obj, void (Class::*m)(Arg1,Arg2,Arg3))
{
    return MethodDelegate<Class,void,Arg1,Arg2,Arg3>(obj, m);
}

template<class Class, class Arg1, class Arg2>
inline MethodDelegate<Class,void,Arg1,Arg2>
slot(Class* obj, void (Class::*m)(Arg1,Arg2))
{
    return MethodDelegate<Class,void,Arg1,Arg2>(obj, m);
}

template<class Class, class Arg1>
inline MethodDelegate<Class,void,Arg1>
slot(Class* obj, void (Class::*m)(Arg1))
{
    return MethodDelegate<Class,void,Arg1>(obj, m);
}

template<class Class>
inline MethodDelegate<Class,void>
slot(Class* obj, void (Class::*m)())
{
    return MethodDelegate<Class,void>(obj, m);
}

template<class Class, class Arg1, class Arg2, class Arg3>
inline ConstMethodDelegate<Class,void,Arg1,Arg2,Arg3>
slot(const Class* obj, void (Class::*m)(Arg1,Arg2,Arg3) const)
{
    return ConstMethodDelegate<Class,void,Arg1,Arg2,Arg3>(obj, m);
}

template<class Class, class Arg1, class Arg2>
inline ConstMethodDelegate<Class,void,Arg1,Arg2>
slot(const Class* obj, void (Class::*m)(Arg1,Arg2) const)
{
    return ConstMethodDelegate<Class,void,Arg1,Arg2>(obj, m);
}

template<class Class, class Arg1>
inline ConstMethodDelegate<Class,void,Arg1>
slot(const Class* obj, void (Class::*m)(Arg1) const)
{
    return ConstMethodDelegate<Class,void,Arg1>(obj, m);
}

template<class Class>
inline ConstMethodDelegate<Class,void>
slot(const Class* obj, void (Class::*m)() const)
{
    return ConstMethodDelegate<Class,void>(obj, m);
}

#endif // defined(DELEGATE_DEFINE_SLOTS)

#endif /* METHOD_DELEGATE_H_ */
