#ifndef DELEGATE_H_
#define DELEGATE_H_

template<class Return, class Arg1=void, class Arg2=void, class Arg3=void>
class Delegate
{
public:
    virtual Return operator()(Arg1 arg1, Arg2 arg2, Arg3 arg3) const = 0;
    virtual Delegate<Return,Arg1,Arg2,Arg3>* copy() const = 0;
};

template<class Return, class Arg1, class Arg2>
class Delegate<Return,Arg1,Arg2,void>
{
public:
    virtual Return operator()(Arg1 arg1, Arg2 arg2) const = 0;
    virtual Delegate<Return,Arg1,Arg2>* copy() const = 0;
};

template<class Return, class Arg1>
class Delegate<Return,Arg1,void,void>
{
public:
    virtual Return operator()(Arg1 arg1) const = 0;
    virtual Delegate<Return,Arg1>* copy() const = 0;
};

template<class Return>
class Delegate<Return,void,void,void>
{
public:
    virtual Return operator()() const = 0;
    virtual Delegate<Return>* copy() const = 0;
};

#endif /* DELEGATE_H_ */
