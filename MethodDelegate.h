#ifndef METHOD_DELEGATE_H_
#define METHOD_DELEGATE_H_

#include "Delegate.h"
#include <memory>

template<class Class, class Return, class Arg1=void, class Arg2=void, class Arg3=void>
class MethodDelegate : public Delegate<Return,Arg1,Arg2,Arg3>
{
public:
    typedef Return (Class::*Signature)(Arg1,Arg2,Arg3);

    MethodDelegate(Class* obj, Signature m)
        : object_(obj), method_(m)
    {
    }

    virtual Return call(Arg1 arg1, Arg2 arg2, Arg3 arg3)
    {
        return (object_->*method_)(arg1,arg2,arg3);
    }

private:
    Class*              object_;
    Signature   method_;
};

template<class Class, class Return, class Arg1, class Arg2>
class MethodDelegate<Class,Return,Arg1,Arg2,void> : public Delegate<Return,Arg1,Arg2>
{
public:
    typedef Return (Class::*Signature)(Arg1,Arg2);

    MethodDelegate(Class* obj, Signature m)
        : object_(obj), method_(m)
    {
    }

    virtual Return call(Arg1 arg1, Arg2 arg2)
    {
        return (object_->*method_)(arg1,arg2);
    }

private:
    Class*              object_;
    Signature   method_;
};

template<class Class, class Return, class Arg1>
class MethodDelegate<Class,Return,Arg1,void,void> : public Delegate<Return,Arg1>
{
public:
    typedef Return (Class::*Signature)(Arg1);

    MethodDelegate(Class* obj, Signature m)
        : object_(obj), method_(m)
    {
    }

    virtual Return call(Arg1 arg1)
    {
        return (object_->*method_)(arg1);
    }

private:
    Class*              object_;
    Signature   method_;
};

template<class Class, class Return>
class MethodDelegate<Class,Return,void,void,void> : public Delegate<Return>
{
public:
    typedef Return (Class::*Signature)();

    MethodDelegate(Class* obj, Signature m)
        : object_(obj), method_(m)
    {
    }

    virtual Return call()
    {
        return (object_->*method_)();
    }

private:
    Class*              object_;
    Signature   method_;
};

template<class Class, class Return, class Arg1=void, class Arg2=void, class Arg3=void>
class ConstMethodDelegate : public Delegate<Return,Arg1,Arg2,Arg3>
{
public:
    typedef Return (Class::*Signature)(Arg1,Arg2,Arg3) const;

    ConstMethodDelegate(const Class* obj, Signature m)
        : object_(obj), method_(m)
    {
    }

    virtual Return call(Arg1 arg1, Arg2 arg2, Arg3 arg3)
    {
        return (object_->*method_)(arg1,arg2,arg3);
    }

private:
    const Class*        object_;
    Signature           method_;
};

template<class Class, class Return, class Arg1, class Arg2>
class ConstMethodDelegate<Class,Return,Arg1,Arg2,void> : public Delegate<Return,Arg1,Arg2>
{
public:
    typedef Return (Class::*Signature)(Arg1,Arg2) const;

    ConstMethodDelegate(const Class* obj, Signature m)
        : object_(obj), method_(m)
    {
    }

    virtual Return call(Arg1 arg1, Arg2 arg2)
    {
        return (object_->*method_)(arg1,arg2);
    }

private:
    const Class*        object_;
    Signature           method_;
};

template<class Class, class Return, class Arg1>
class ConstMethodDelegate<Class,Return,Arg1,void,void> : public Delegate<Return,Arg1>
{
public:
    typedef Return (Class::*Signature)(Arg1) const;

    ConstMethodDelegate(const Class* obj, Signature m)
        : object_(obj), method_(m)
    {
    }

    virtual Return call(Arg1 arg1)
    {
        return (object_->*method_)(arg1);
    }

private:
    const Class*        object_;
    Signature           method_;
};

template<class Class, class Return>
class ConstMethodDelegate<Class,Return,void,void,void> : public Delegate<Return>
{
public:
    typedef Return (Class::*Signature)() const;

    ConstMethodDelegate(const Class* obj, Signature m)    : object_(obj), method_(m)
    {
    }

    virtual Return call()
    {
        return (object_->*method_)();
    }

private:
    const Class*        object_;
    Signature           method_;
};


template<class Class, class Return, class Arg1, class Arg2, class Arg3>
inline std::auto_ptr< Delegate<Return,Arg1,Arg2,Arg3> >
delegate(Class* obj, Return (Class::*m)(Arg1,Arg2,Arg3))
{
    return std::auto_ptr< Delegate<Return,Arg1,Arg2,Arg3> >(new MethodDelegate<Class,Return,Arg1,Arg2,Arg3>(obj, m));
}

template<class Class, class Return, class Arg1, class Arg2>
inline std::auto_ptr< Delegate<Return,Arg1,Arg2> >
delegate(Class* obj, Return (Class::*m)(Arg1,Arg2))
{
    return std::auto_ptr< Delegate<Return,Arg1,Arg2> >(new MethodDelegate<Class,Return,Arg1,Arg2>(obj, m));
}

template<class Class, class Return, class Arg1>
inline std::auto_ptr< Delegate<Return,Arg1> >
delegate(Class* obj, Return (Class::*m)(Arg1))
{
    return std::auto_ptr< Delegate<Return,Arg1> >(new MethodDelegate<Class,Return,Arg1>(obj, m));
}

template<class Class, class Return>
inline std::auto_ptr< Delegate<Return> >
delegate(Class* obj, Return (Class::*m)())
{
    return std::auto_ptr< Delegate<Return> >(new MethodDelegate<Class,Return>(obj, m));
}

template<class Class, class Return, class Arg1, class Arg2, class Arg3>
inline std::auto_ptr< Delegate<Return,Arg1,Arg2,Arg3> >
delegate(const Class* obj, Return (Class::*m)(Arg1,Arg2,Arg3) const)
{
    return std::auto_ptr< Delegate<Return,Arg1,Arg2,Arg3> >(new ConstMethodDelegate<Class,Return,Arg1,Arg2,Arg3>(obj, m));
}

template<class Class, class Return, class Arg1, class Arg2>
inline std::auto_ptr< Delegate<Return,Arg1,Arg2> >
delegate(const Class* obj, Return (Class::*m)(Arg1,Arg2) const)
{
    return std::auto_ptr< Delegate<Return,Arg1,Arg2> >(new ConstMethodDelegate<Class,Return,Arg1,Arg2>(obj, m));
}

template<class Class, class Return, class Arg1>
inline std::auto_ptr< Delegate<Return,Arg1> >
delegate(const Class* obj, Return (Class::*m)(Arg1) const)
{
    return std::auto_ptr< Delegate<Return,Arg1> >(new ConstMethodDelegate<Class,Return,Arg1>(obj, m));
}

template<class Class, class Return>
inline std::auto_ptr< Delegate<Return> >
delegate(const Class* obj, Return (Class::*m)() const)
{
    return std::auto_ptr< Delegate<Return> >(new ConstMethodDelegate<Class,Return>(obj, m));
}

#if defined(DELEGATE_DEFINE_SLOTS)

template<class Class, class Arg1, class Arg2, class Arg3>
inline std::auto_ptr< Delegate<void,Arg1,Arg2,Arg3> >
slot(Class* obj, void (Class::*m)(Arg1,Arg2,Arg3))
{
    return delegate(obj, m);
}

template<class Class, class Arg1, class Arg2>
inline std::auto_ptr< Delegate<void,Arg1,Arg2> >
slot(Class* obj, void (Class::*m)(Arg1,Arg2))
{
    return delegate(obj, m);
}

template<class Class, class Arg1>
inline std::auto_ptr< Delegate<void,Arg1> >
slot(Class* obj, void (Class::*m)(Arg1))
{
    return delegate(obj, m);
}

template<class Class>
inline std::auto_ptr< Delegate<void> >
slot(Class* obj, void (Class::*m)())
{
    return delegate(obj, m);
}

template<class Class, class Arg1, class Arg2, class Arg3>
inline std::auto_ptr< Delegate<void,Arg1,Arg2,Arg3> >
slot(const Class* obj, void (Class::*m)(Arg1,Arg2,Arg3) const)
{
    return delegate(obj, m);
}

template<class Class, class Arg1, class Arg2>
inline std::auto_ptr< Delegate<void,Arg1,Arg2> >
slot(const Class* obj, void (Class::*m)(Arg1,Arg2) const)
{
    return delegate(obj, m);
}

template<class Class, class Arg1>
inline std::auto_ptr< Delegate<void,Arg1> >
slot(const Class* obj, void (Class::*m)(Arg1) const)
{
    return delegate(obj, m);
}

template<class Class>
inline std::auto_ptr< Delegate<void> >
slot(const Class* obj, void (Class::*m)() const)
{
    return delegate(obj, m);
}

#endif // defined(DELEGATE_DEFINE_SLOTS)

#endif /* METHOD_DELEGATE_H_ */
