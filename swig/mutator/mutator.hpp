#ifndef MUTATOR_HPP_INCLUDED
#define MUTATOR_HPP_INCLUDED

//============================================================================
//============================================================================
// mutator
//============================================================================
//============================================================================

#define WITH_GETTER(TYPE, NAME) \
TYPE m_ ## NAME; \
public: \
const TYPE NAME() const { return m_ ## NAME;} \
private:

#define WITH_GETTER_REF(TYPE, NAME) \
TYPE m_ ## NAME; \
public: \
const TYPE & NAME() const { return m_ ## NAME;} \
private:

#define WITH_SETTER(TYPE, NAME) \
TYPE m_ ## NAME; \
public: \
const TYPE NAME() const { return m_ ## NAME;} \
void set_ ## NAME(const TYPE NAME) {m_ ## NAME = NAME;} \
private:

#define WITH_SETTER_REF(TYPE, NAME) \
TYPE m_ ## NAME; \
public: \
const TYPE & NAME() const { return m_ ## NAME;} \
void set_ ## NAME(const TYPE & NAME) {m_ ## NAME = NAME;} \
private:

#endif
