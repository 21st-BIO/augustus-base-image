// Generated by Bisonc++ V2.09.03 on Wed, 14 Mar 2012 11:03:11 +0100

// $insert class.ih
#include "parser.ih"

// The FIRST element of SR arrays shown below uses `d_type', defining the
// state's type, and `d_lastIdx' containing the last element's index. If
// d_lastIdx contains the REQ_TOKEN bitflag (see below) then the state needs
// a token: if in this state d_token__ is _UNDETERMINED_, nextToken() will be
// called

// The LAST element of SR arrays uses `d_token' containing the last retrieved
// token to speed up the (linear) seach.  Except for the first element of SR
// arrays, the field `d_action' is used to determine what to do next. If
// positive, it represents the next state (used with SHIFT); if zero, it
// indicates `ACCEPT', if negative, -d_action represents the number of the
// rule to reduce to.

// `lookup()' tries to find d_token__ in the current SR array. If it fails, and
// there is no default reduction UNEXPECTED_TOKEN__ is thrown, which is then
// caught by the error-recovery function.

// The error-recovery function will pop elements off the stack until a state
// having bit flag ERR_ITEM is found. This state has a transition on _error_
// which is applied. In this _error_ state, while the current token is not a
// proper continuation, new tokens are obtained by nextToken(). If such a
// token is found, error recovery is successful and the token is
// handled according to the error state's SR table and parsing continues.
// During error recovery semantic actions are ignored.

// A state flagged with the DEF_RED flag will perform a default
// reduction if no other continuations are available for the current token.

// The ACCEPT STATE never shows a default reduction: when it is reached the
// parser returns ACCEPT(). During the grammar
// analysis phase a default reduction may have been defined, but it is
// removed during the state-definition phase.

// So:
//      s_x[] = 
//      {
//                  [_field_1_]         [_field_2_]
//
// First element:   {state-type,        idx of last element},
// Other elements:  {required token,    action to perform},
//                                      ( < 0: reduce, 
//                                          0: ACCEPT,
//                                        > 0: next state)
// Last element:    {set to d_token__,    action to perform}
//      }

// When the --thread-safe option is specified, all static data are defined as
// const. If --thread-safe is not provided, the state-tables are not defined
// as const, since the lookup() function below will modify them

// $insert debugincludes
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <iomanip>

namespace // anonymous
{
    char const author[] = "Frank B. Brokken (f.b.brokken@rug.nl)";

    enum 
    {
        STACK_EXPANSION = 5     // size to expand the state-stack with when
                                // full
    };

    enum ReservedTokens
    {
        PARSE_ACCEPT     = 0,   // `ACCEPT' TRANSITION
        _UNDETERMINED_   = -2,
        _EOF_            = -1,
        _error_          = 256
    };
    enum StateType       // modify statetype/data.cc when this enum changes
    {
        NORMAL,
        ERR_ITEM,
        REQ_TOKEN,
        ERR_REQ,    // ERR_ITEM | REQ_TOKEN
        DEF_RED,    // state having default reduction
        ERR_DEF,    // ERR_ITEM | DEF_RED
        REQ_DEF,    // REQ_TOKEN | DEF_RED
        ERR_REQ_DEF // ERR_ITEM | REQ_TOKEN | DEF_RED
    };    
    struct PI__     // Production Info
    {
        size_t d_nonTerm; // identification number of this production's
                            // non-terminal 
        size_t d_size;    // number of elements in this production 
    };

    struct SR__     // Shift Reduce info, see its description above
    {
        union
        {
            int _field_1_;      // initializer, allowing initializations 
                                // of the SR s_[] arrays
            int d_type;
            int d_token;
        };
        union
        {
            int _field_2_;

            int d_lastIdx;          // if negative, the state uses SHIFT
            int d_action;           // may be negative (reduce), 
                                    // postive (shift), or 0 (accept)
            size_t d_errorState;    // used with Error states
        };
    };

    // $insert staticdata
    
// Productions Info Records:
PI__ const s_productionInfo[] = 
{
     {0, 0}, // not used: reduction values are negative
     {264, 2}, // 1: tree (';') ->  subtree ';'
     {265, 1}, // 2: subtree ->  leaf
     {265, 3}, // 3: subtree ('(') ->  '(' branchset ')'
     {266, 1}, // 4: leaf (SPECIES) ->  SPECIES
     {267, 1}, // 5: branchset ->  branch
     {267, 3}, // 6: branchset (',') ->  branchset ',' branch
     {268, 3}, // 7: branch (':') ->  subtree ':' DISTANCE
     {269, 1}, // 8: tree_$ ->  tree
};

// State info and SR__ transitions for each state.


SR__ s_0[] =
{
    { { REQ_TOKEN}, { 6} },           
    { {       264}, { 1} }, // tree   
    { {       265}, { 2} }, // subtree
    { {       266}, { 3} }, // leaf   
    { {        40}, { 4} }, // '('    
    { {       258}, { 5} }, // SPECIES
    { {         0}, { 0} },           
};

SR__ s_1[] =
{
    { { REQ_TOKEN}, {            2} }, 
    { {     _EOF_}, { PARSE_ACCEPT} }, 
    { {         0}, {            0} }, 
};

SR__ s_2[] =
{
    { { REQ_TOKEN}, { 2} },       
    { {        59}, { 6} }, // ';'
    { {         0}, { 0} },       
};

SR__ s_3[] =
{
    { { DEF_RED}, {  1} }, 
    { {       0}, { -2} }, 
};

SR__ s_4[] =
{
    { { REQ_TOKEN}, { 7} },             
    { {       267}, { 7} }, // branchset
    { {       268}, { 8} }, // branch   
    { {       265}, { 9} }, // subtree  
    { {       266}, { 3} }, // leaf     
    { {        40}, { 4} }, // '('      
    { {       258}, { 5} }, // SPECIES  
    { {         0}, { 0} },             
};

SR__ s_5[] =
{
    { { DEF_RED}, {  1} }, 
    { {       0}, { -4} }, 
};

SR__ s_6[] =
{
    { { DEF_RED}, {  1} }, 
    { {       0}, { -1} }, 
};

SR__ s_7[] =
{
    { { REQ_TOKEN}, {  3} },       
    { {        41}, { 10} }, // ')'
    { {        44}, { 11} }, // ','
    { {         0}, {  0} },       
};

SR__ s_8[] =
{
    { { DEF_RED}, {  1} }, 
    { {       0}, { -5} }, 
};

SR__ s_9[] =
{
    { { REQ_TOKEN}, {  2} },       
    { {        58}, { 12} }, // ':'
    { {         0}, {  0} },       
};

SR__ s_10[] =
{
    { { DEF_RED}, {  1} }, 
    { {       0}, { -3} }, 
};

SR__ s_11[] =
{
    { { REQ_TOKEN}, {  6} },           
    { {       268}, { 13} }, // branch 
    { {       265}, {  9} }, // subtree
    { {       266}, {  3} }, // leaf   
    { {        40}, {  4} }, // '('    
    { {       258}, {  5} }, // SPECIES
    { {         0}, {  0} },           
};

SR__ s_12[] =
{
    { { REQ_TOKEN}, {  2} },            
    { {       257}, { 14} }, // DISTANCE
    { {         0}, {  0} },            
};

SR__ s_13[] =
{
    { { DEF_RED}, {  1} }, 
    { {       0}, { -6} }, 
};

SR__ s_14[] =
{
    { { DEF_RED}, {  1} }, 
    { {       0}, { -7} }, 
};


// State array:
SR__ *s_state[] =
{
  s_0,  s_1,  s_2,  s_3,  s_4,  s_5,  s_6,  s_7,  s_8,  s_9,
  s_10,  s_11,  s_12,  s_13,  s_14,
};

typedef std::map<int, char const *> SMap;
typedef SMap::value_type SMapVal;

SMapVal s_symArr[] =
{
    SMapVal(-2, "_UNDETERMINED_"),  // predefined symbols
    SMapVal(-1, "_EOF_"),
    SMapVal(256, "_error_"),

    SMapVal(257, "DISTANCE"),
    SMapVal(258, "SPECIES"),
    SMapVal(264, "tree"),
    SMapVal(265, "subtree"),
    SMapVal(266, "leaf"),
    SMapVal(267, "branchset"),
    SMapVal(268, "branch"),
    SMapVal(269, "tree_$"),
};

SMap s_symbol
(
    s_symArr, s_symArr + sizeof(s_symArr) / sizeof(SMapVal)
);

} // anonymous namespace ends



// If the parsing function call uses arguments, then provide an overloaded
// function.  The code below doesn't rely on parameters, so no arguments are
// required.  Furthermore, parse uses a function try block to allow us to do
// ACCEPT and ABORT from anywhere, even from within members called by actions,
// simply throwing the appropriate exceptions.

ParserBase::ParserBase()
:
    d_stackIdx__(-1),
    // $insert debuginit
    d_debug__(true),
    d_nErrors__(0),
    // $insert requiredtokens
    d_requiredTokens__(0),
    d_acceptedTokens__(d_requiredTokens__),
    d_token__(_UNDETERMINED_),
    d_nextToken__(_UNDETERMINED_)
{}

// $insert debugfunctions

std::ostringstream ParserBase::s_out__;

std::ostream &ParserBase::dflush__(std::ostream &out)
{
    std::ostringstream &s_out__ = dynamic_cast<std::ostringstream &>(out);

    std::cout << "    " << s_out__.str() << std::flush;
    s_out__.clear();
    s_out__.str("");
    return out;
}

std::string ParserBase::stype__(char const *pre, STYPE__ const &semVal, char const *post) const
{
    return "";
}
std::string ParserBase::symbol__(int value) const
{
    using namespace std;
    ostringstream ostr;
    SMap::const_iterator it = s_symbol.find(value);
    if (it != s_symbol.end())
        ostr << "`" << it->second << "'";
    else if (isprint(value))
        ostr << "`" << static_cast<char>(value) << "' (" << value << ")";
    else
        ostr << "'\\x" << setfill('0') << hex << setw(2) << value << "'";
    return ostr.str();
}


void ParserBase::clearin()
{
    d_token__ = d_nextToken__ = _UNDETERMINED_;
}

void ParserBase::push__(size_t state)
{
    if (static_cast<size_t>(d_stackIdx__ + 1) == d_stateStack__.size())
    {
        size_t newSize = d_stackIdx__ + STACK_EXPANSION;
        d_stateStack__.resize(newSize);
        d_valueStack__.resize(newSize);
    }
    ++d_stackIdx__;
    d_stateStack__[d_stackIdx__] = d_state__ = state;
    *(d_vsp__ = &d_valueStack__[d_stackIdx__]) = d_val__;
    // $insert debug
    if (d_debug__)
        s_out__ <<   "push(state " << state << stype__(", semantic TOS = ", d_val__, ")") << ')' << "\n" << dflush__;
}

void ParserBase::popToken__()
{
    d_token__ = d_nextToken__;

    d_val__ = d_nextVal__;
    d_nextVal__ = STYPE__();

    d_nextToken__ = _UNDETERMINED_;
}
     
void ParserBase::pushToken__(int token)
{
    d_nextToken__ = d_token__;
    d_nextVal__ = d_val__;
    d_token__ = token;
}
     
void ParserBase::pop__(size_t count)
{
    // $insert debug
    if (d_debug__)
        s_out__ <<  "pop(" << count << ") from stack having size " << (d_stackIdx__ + 1) << "\n" << dflush__;
    if (d_stackIdx__ < static_cast<int>(count))
    {
        // $insert debug
        if (d_debug__)
            s_out__ <<  "Terminating parse(): unrecoverable input error at token " << symbol__(d_token__) << "\n" << dflush__;
        ABORT();
    }

    d_stackIdx__ -= count;
    d_state__ = d_stateStack__[d_stackIdx__];
    d_vsp__ = &d_valueStack__[d_stackIdx__];
    // $insert debug
    if (d_debug__)
        s_out__ <<  "pop(): next state: " << d_state__ << ", token: " << symbol__(d_token__) ;
    // $insert debug
    if (d_debug__)
        s_out__ <<  stype__("semantic: ", d_val__) << "\n" << dflush__;
}

inline size_t ParserBase::top__() const
{
    return d_stateStack__[d_stackIdx__];
}

void Parser::executeAction(int production)
{
    if (d_token__ != _UNDETERMINED_)
        pushToken__(d_token__);     // save an already available token

                                    // save default non-nested block $$
    if (int size = s_productionInfo[production].d_size)
        d_val__ = d_vsp__[1 - size];

    // $insert debug
    if (d_debug__)
        s_out__ <<  "executeAction(): of rule " << production ;
    // $insert debug
    if (d_debug__)
        s_out__ <<   stype__(", semantic [TOS]: ", d_val__) << " ..." << "\n" << dflush__;
    switch (production)
    {
        // $insert actioncases
        
        case 1:
#line 42 "grammar"
        {
         d_val__.nodeptr = d_vsp__[-1].nodeptr;
         }
        break;

        case 2:
#line 49 "grammar"
        { 
         d_val__.nodeptr = d_vsp__[0].nodeptr;
         }
        break;

        case 3:
#line 56 "grammar"
        { 
         d_val__.nodeptr = d_vsp__[-1].nodeptr;
         }
        break;

        case 4:
#line 63 "grammar"
        {
         Treenode *temp = new Treenode(*d_vsp__[0].spec);
         ptree->treenodes.push_back(temp);
         ptree->leaves.push_back(temp);
         d_val__.nodeptr = temp;
         }
        break;

        case 5:
#line 73 "grammar"
        {
         Treenode *temp = new Treenode;
         temp->addChild(d_vsp__[0].nodeptr);
         d_val__.nodeptr = temp;
         }
        break;

        case 6:
#line 82 "grammar"
        {
         d_vsp__[-2].nodeptr->addChild(d_vsp__[0].nodeptr);
         ptree->treenodes.push_back(d_vsp__[-2].nodeptr);
         d_val__.nodeptr = d_vsp__[-2].nodeptr;
         }
        break;

        case 7:
#line 93 "grammar"
        { 
         d_vsp__[-2].nodeptr->addDistance(d_vsp__[0].dist);
         d_val__.nodeptr=d_vsp__[-2].nodeptr;
         
         }
        break;

    }
    // $insert debug
    if (d_debug__)
        s_out__ <<  "... action of rule " << production << " completed" ;
    // $insert debug
    if (d_debug__)
        s_out__ <<   stype__(", semantic: ", d_val__) << "\n" << dflush__;
}

inline void ParserBase::reduce__(PI__ const &pi)
{
    d_token__ = pi.d_nonTerm;
    pop__(pi.d_size);

    // $insert debug
    if (d_debug__)
        s_out__ <<  "reduce(): by rule " << (&pi - s_productionInfo) ;
    // $insert debug
    if (d_debug__)
        s_out__ <<  " to N-terminal " << symbol__(d_token__) << stype__(", semantic = ", d_val__) << "\n" << dflush__;
}

// If d_token__ is _UNDETERMINED_ then if d_nextToken__ is _UNDETERMINED_ another
// token is obtained from lex(). Then d_nextToken__ is assigned to d_token__.
void Parser::nextToken()
{
    if (d_token__ != _UNDETERMINED_)        // no need for a token: got one
        return;                             // already

    if (d_nextToken__ != _UNDETERMINED_)
    {
        popToken__();                       // consume pending token
        // $insert debug
        if (d_debug__)
            s_out__ <<  "nextToken(): popped " << symbol__(d_token__) << stype__(", semantic = ", d_val__) << "\n" << dflush__;
    }
    else
    {
        ++d_acceptedTokens__;               // accept another token (see
                                            // errorRecover())
        d_token__ = lex();
        if (d_token__ <= 0)
            d_token__ = _EOF_;
    }
    print();
    // $insert debug
    if (d_debug__)
        s_out__ <<  "nextToken(): using " << symbol__(d_token__) << stype__(", semantic = ", d_val__) << "\n" << dflush__;
}

// if the final transition is negative, then we should reduce by the rule
// given by its positive value. Note that the `recovery' parameter is only
// used with the --debug option
int Parser::lookup(bool recovery)
{
    // $insert threading
    SR__ *sr = s_state[d_state__];        // get the appropriate state-table
    int lastIdx = sr->d_lastIdx;        // sentinel-index in the SR__ array

    SR__ *lastElementPtr = sr + lastIdx;
    SR__ *elementPtr = sr + 1;            // start the search at s_xx[1]

    lastElementPtr->d_token = d_token__;// set search-token

    while (elementPtr->d_token != d_token__)
        ++elementPtr;

    if (elementPtr == lastElementPtr)   // reached the last element
    {
        if (elementPtr->d_action < 0)   // default reduction
        {
        // $insert debug
        if (d_debug__)
            s_out__ <<  "lookup(" << d_state__ << ", " << symbol__(d_token__) ;
        // $insert debug
        if (d_debug__)
            s_out__ <<  "): default reduction by rule " << -elementPtr->d_action << "\n" << dflush__;
            return elementPtr->d_action;                
        }
        // $insert debug
        if (d_debug__)
            s_out__ <<  "lookup(" << d_state__ << ", " << symbol__(d_token__) << "): Not " ;
        // $insert debug
        if (d_debug__)
            s_out__ <<  "found. " << (recovery ? "Continue" : "Start") << " error recovery."  << "\n" << dflush__;

        // No default reduction, so token not found, so error.
        throw UNEXPECTED_TOKEN__;
    }

    // not at the last element: inspect the nature of the action
    // (< 0: reduce, 0: ACCEPT, > 0: shift)

    int action = elementPtr->d_action;

// $insert debuglookup
    if (d_debug__)
    {
        s_out__ <<  "lookup(" << d_state__ << ", " << symbol__(d_token__);

        if (action < 0)             // a reduction is found
            s_out__ << "): reduce by rule " << -action;
        else if (action == 0)
            s_out__ <<  "): ACCEPT";
        else 
            s_out__ <<  "): shift " << action << " (" << symbol__(d_token__) << 
                        " processed)";

        s_out__ << "\n" << dflush__;
    }

    return action;
}

    // When an error has occurred, pop elements off the stack until the top
    // state has an error-item. If none is found, the default recovery
    // mode (which is to abort) is activated. 
    //
    // If EOF is encountered without being appropriate for the current state,
    // then the error recovery will fall back to the default recovery mode.
    // (i.e., parsing terminates)
void Parser::errorRecovery()
try
{
    if (d_acceptedTokens__ >= d_requiredTokens__)// only generate an error-
    {                                           // message if enough tokens 
        ++d_nErrors__;                          // were accepted. Otherwise
        error("Syntax error");                  // simply skip input

    }

    // $insert debug
    if (d_debug__)
        s_out__ <<  "errorRecovery(): " << d_nErrors__ << " error(s) so far. State = " << top__() << "\n" << dflush__;

    // get the error state
    while (not (s_state[top__()][0].d_type & ERR_ITEM))
    {
        // $insert debug
        if (d_debug__)
            s_out__ <<  "errorRecovery(): pop state " << top__() << "\n" << dflush__;
        pop__();
    }
    // $insert debug
    if (d_debug__)
        s_out__ <<  "errorRecovery(): state " << top__() << " is an ERROR state" << "\n" << dflush__;

    // In the error state, lookup a token allowing us to proceed.
    // Continuation may be possible following multiple reductions,
    // but eventuall a shift will be used, requiring the retrieval of
    // a terminal token. If a retrieved token doesn't match, the catch below 
    // will ensure the next token is requested in the while(true) block
    // implemented below:

    int lastToken = d_token__;                  // give the unexpected token a
                                                // chance to be processed
                                                // again.

    pushToken__(_error_);                       // specify _error_ as next token
    push__(lookup(true));                       // push the error state

    d_token__ = lastToken;                      // reactivate the unexpected
                                                // token (we're now in an
                                                // ERROR state).

    bool gotToken = true;                       // the next token is a terminal

    while (true)
    {
        try
        {
            if (s_state[d_state__]->d_type & REQ_TOKEN)
            {
                gotToken = d_token__ == _UNDETERMINED_;
                nextToken();                    // obtain next token
            }
            
            int action = lookup(true);

            if (action > 0)                 // push a new state
            {
                push__(action);
                popToken__();
                // $insert debug
                if (d_debug__)
                    s_out__ <<  "errorRecovery() SHIFT state " << action ;
                // $insert debug
                if (d_debug__)
                    s_out__ <<  ", continue with " << symbol__(d_token__) << "\n" << dflush__;

                if (gotToken)
                {
                    // $insert debug
                    if (d_debug__)
                        s_out__ <<  "errorRecovery() COMPLETED: next state " ;
                    // $insert debug
                    if (d_debug__)
                        s_out__ <<  action << ", no token yet" << "\n" << dflush__;

                    d_acceptedTokens__ = 0;
                    return;
                }
            }
            else if (action < 0)
            {
                // no actions executed on recovery but save an already 
                // available token:
                if (d_token__ != _UNDETERMINED_)
                    pushToken__(d_token__);
 
                                            // next token is the rule's LHS
                reduce__(s_productionInfo[-action]); 
                // $insert debug
                if (d_debug__)
                    s_out__ <<  "errorRecovery() REDUCE by rule " << -action ;
                // $insert debug
                if (d_debug__)
                    s_out__ <<  ", token = " << symbol__(d_token__) << "\n" << dflush__;
            }
            else
                ABORT();                    // abort when accepting during
                                            // error recovery
        }
        catch (...)
        {
            if (d_token__ == _EOF_)
                ABORT();                    // saw inappropriate _EOF_
                      
            popToken__();                   // failing token now skipped
        }
    }
}
catch (ErrorRecovery__)       // This is: DEFAULT_RECOVERY_MODE
{
    ABORT();
}

    // The parsing algorithm:
    // Initially, state 0 is pushed on the stack, and d_token__ as well as
    // d_nextToken__ are initialized to _UNDETERMINED_. 
    //
    // Then, in an eternal loop:
    //
    //  1. If a state does not have REQ_TOKEN no token is assigned to
    //     d_token__. If the state has REQ_TOKEN, nextToken() is called to
    //      determine d_nextToken__ and d_token__ is set to
    //     d_nextToken__. nextToken() will not call lex() unless d_nextToken__ is 
    //     _UNDETERMINED_. 
    //
    //  2. lookup() is called: 
    //     d_token__ is stored in the final element's d_token field of the
    //     state's SR_ array. 
    //
    //  3. The current token is looked up in the state's SR_ array
    //
    //  4. Depending on the result of the lookup() function the next state is
    //     shifted on the parser's stack, a reduction by some rule is applied,
    //     or the parsing function returns ACCEPT(). When a reduction is
    //     called for, any action that may have been defined for that
    //     reduction is executed.
    //
    //  5. An error occurs if d_token__ is not found, and the state has no
    //     default reduction. Error handling was described at the top of this
    //     file.

int Parser::parse()
try 
{
    // $insert debug
    if (d_debug__)
        s_out__ <<  "parse(): Parsing starts" << "\n" << dflush__;
    push__(0);                              // initial state
    clearin();                              // clear the tokens.

    while (true)
    {
        // $insert debug
        if (d_debug__)
            s_out__ <<  "==" << "\n" << dflush__;
        try
        {
            if (s_state[d_state__]->d_type & REQ_TOKEN)
                nextToken();                // obtain next token


            int action = lookup(false);     // lookup d_token__ in d_state__

            if (action > 0)                 // SHIFT: push a new state
            {
                push__(action);
                popToken__();               // token processed
            }
            else if (action < 0)            // REDUCE: execute and pop.
            {
                executeAction(-action);
                                            // next token is the rule's LHS
                reduce__(s_productionInfo[-action]); 
            }
            else 
                ACCEPT();
        }
        catch (ErrorRecovery__)
        {
            errorRecovery();
        }
    }
}
catch (Return__ retValue)
{
    // $insert debug
    if (d_debug__)
        s_out__ <<  "parse(): returns " << retValue << "\n" << dflush__;
    return retValue;
}
