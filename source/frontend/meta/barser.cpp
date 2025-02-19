// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "barser.hpp"


// Unqualified %code blocks.
#line 17 "meta/barser.y"

extern "C" pec::parser::symbol_type yylex(void*);
#include <iostream>

#line 51 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 8 "meta/barser.y"
namespace pec {
#line 144 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"

  /// Build a parser object.
  parser::parser (void* yyscanner_yyarg, std::vector<pec::Child<pec::Statement>>& ret_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      yyscanner (yyscanner_yyarg),
      ret (ret_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expression: // expression
        value.YY_MOVE_OR_COPY< Child<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
      case symbol_kind::S_general_pattern: // general_pattern
        value.YY_MOVE_OR_COPY< Child<Pattern> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
        value.YY_MOVE_OR_COPY< Child<Statement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type: // type
        value.YY_MOVE_OR_COPY< Child<Type> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern_list: // pattern_list
        value.YY_MOVE_OR_COPY< TuplePattern > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_TYPE: // "type identifier"
      case symbol_kind::S_CONSTANT: // "constant identifier"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_statement_list: // statement_list
        value.YY_MOVE_OR_COPY< std::vector<Child<Statement>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expression: // expression
        value.move< Child<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
      case symbol_kind::S_general_pattern: // general_pattern
        value.move< Child<Pattern> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
        value.move< Child<Statement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type: // type
        value.move< Child<Type> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern_list: // pattern_list
        value.move< TuplePattern > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_TYPE: // "type identifier"
      case symbol_kind::S_CONSTANT: // "constant identifier"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_statement_list: // statement_list
        value.move< std::vector<Child<Statement>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expression: // expression
        value.copy< Child<Expression> > (that.value);
        break;

      case symbol_kind::S_pattern: // pattern
      case symbol_kind::S_general_pattern: // general_pattern
        value.copy< Child<Pattern> > (that.value);
        break;

      case symbol_kind::S_statement: // statement
        value.copy< Child<Statement> > (that.value);
        break;

      case symbol_kind::S_type: // type
        value.copy< Child<Type> > (that.value);
        break;

      case symbol_kind::S_pattern_list: // pattern_list
        value.copy< TuplePattern > (that.value);
        break;

      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_TYPE: // "type identifier"
      case symbol_kind::S_CONSTANT: // "constant identifier"
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_statement_list: // statement_list
        value.copy< std::vector<Child<Statement>> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expression: // expression
        value.move< Child<Expression> > (that.value);
        break;

      case symbol_kind::S_pattern: // pattern
      case symbol_kind::S_general_pattern: // general_pattern
        value.move< Child<Pattern> > (that.value);
        break;

      case symbol_kind::S_statement: // statement
        value.move< Child<Statement> > (that.value);
        break;

      case symbol_kind::S_type: // type
        value.move< Child<Type> > (that.value);
        break;

      case symbol_kind::S_pattern_list: // pattern_list
        value.move< TuplePattern > (that.value);
        break;

      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_TYPE: // "type identifier"
      case symbol_kind::S_CONSTANT: // "constant identifier"
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_statement_list: // statement_list
        value.move< std::vector<Child<Statement>> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // Discard the LAC context in case there still is one left from a
    // previous invocation.
    yy_lac_discard_ ("init");

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (yyscanner));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;

        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    yy_lac_discard_ ("shift");
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_expression: // expression
        yylhs.value.emplace< Child<Expression> > ();
        break;

      case symbol_kind::S_pattern: // pattern
      case symbol_kind::S_general_pattern: // general_pattern
        yylhs.value.emplace< Child<Pattern> > ();
        break;

      case symbol_kind::S_statement: // statement
        yylhs.value.emplace< Child<Statement> > ();
        break;

      case symbol_kind::S_type: // type
        yylhs.value.emplace< Child<Type> > ();
        break;

      case symbol_kind::S_pattern_list: // pattern_list
        yylhs.value.emplace< TuplePattern > ();
        break;

      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_TYPE: // "type identifier"
      case symbol_kind::S_CONSTANT: // "constant identifier"
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_statement_list: // statement_list
        yylhs.value.emplace< std::vector<Child<Statement>> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: statement_list
#line 86 "meta/barser.y"
                                 { ret = std::move(yystack_[0].value.as < std::vector<Child<Statement>> > ()); }
#line 710 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 3: // pattern_list: pattern_list "," pattern
#line 90 "meta/barser.y"
                                          {
        yylhs.value.as < TuplePattern > () = std::move(yystack_[2].value.as < TuplePattern > ());
        yylhs.value.as < TuplePattern > ().elements.emplace_back(std::move(yystack_[0].value.as < Child<Pattern> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 721 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 4: // pattern_list: pattern
#line 96 "meta/barser.y"
                   {
        yylhs.value.as < TuplePattern > ().elements.emplace_back(std::move(yystack_[0].value.as < Child<Pattern> > ()));
        yylhs.location = yystack_[0].location;
    }
#line 730 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 5: // pattern: "identifier"
#line 103 "meta/barser.y"
             {
        yylhs.value.as < Child<Pattern> > () = make<IdentifierPattern>(nullptr, std::move(yystack_[0].value.as < std::string > ()));
        yylhs.location = yystack_[0].location;
    }
#line 739 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 6: // pattern: "constant identifier"
#line 107 "meta/barser.y"
                   {
        yylhs.value.as < Child<Pattern> > () = make<IdentifierPattern>(nullptr, std::move(yystack_[0].value.as < std::string > ()));
        yylhs.location = yystack_[0].location;
    }
#line 748 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 7: // pattern: "type identifier" "identifier"
#line 111 "meta/barser.y"
                                   {
        yylhs.value.as < Child<Pattern> > () = make<IdentifierPattern>(make<Type>(std::move(yystack_[1].value.as < std::string > ())), std::move(yystack_[0].value.as < std::string > ()));
        yylhs.location.begin = yystack_[1].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 758 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 8: // pattern: "(" pattern_list ")"
#line 116 "meta/barser.y"
                                 {
        yylhs.value.as < Child<Pattern> > () = make<TuplePattern>(std::move(yystack_[1].value.as < TuplePattern > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 768 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 9: // general_pattern: "identifier"
#line 124 "meta/barser.y"
             {
        yylhs.value.as < Child<Pattern> > () = make<IdentifierPattern>(nullptr, std::move(yystack_[0].value.as < std::string > ()));
        yylhs.location = yystack_[0].location;
    }
#line 777 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 10: // general_pattern: "constant identifier"
#line 128 "meta/barser.y"
                   {
        yylhs.value.as < Child<Pattern> > () = make<IdentifierPattern>(nullptr, std::move(yystack_[0].value.as < std::string > ()));
        yylhs.location = yystack_[0].location;
    }
#line 786 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 11: // general_pattern: "(" pattern_list ")"
#line 132 "meta/barser.y"
                                 {
        yylhs.value.as < Child<Pattern> > () = make<TuplePattern>(std::move(yystack_[1].value.as < TuplePattern > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 796 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 12: // type: "type identifier"
#line 140 "meta/barser.y"
                 {
        yylhs.value.as < Child<Type> > () = make<Type>(std::move(yystack_[0].value.as < std::string > ()));
        yylhs.location = yystack_[0].location;
    }
#line 805 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 13: // statement: expression ";"
#line 147 "meta/barser.y"
                           {
        yylhs.value.as < Child<Statement> > () = make<ExpressionStatement>(std::move(yystack_[1].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[1].location.begin;
        yylhs.location.end = yystack_[1].location.end;
    }
#line 815 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 14: // statement: "let" general_pattern "=" expression ";"
#line 152 "meta/barser.y"
                                                          {
        yylhs.value.as < Child<Statement> > () = make<VariableDefinition>(VariableDefinition::Mutability::Immutable, std::move(yystack_[3].value.as < Child<Pattern> > ()), std::move(yystack_[1].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[4].location.begin;
        yylhs.location.end = yystack_[1].location.end;
    }
#line 825 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 15: // statement: "var" general_pattern "=" expression ";"
#line 157 "meta/barser.y"
                                                          {
        yylhs.value.as < Child<Statement> > () = make<VariableDefinition>(VariableDefinition::Mutability::Mutable, std::move(yystack_[3].value.as < Child<Pattern> > ()), std::move(yystack_[1].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[4].location.begin;
        yylhs.location.end = yystack_[1].location.end;
    }
#line 835 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 16: // statement_list: statement_list statement
#line 165 "meta/barser.y"
                                           {
        yylhs.value.as < std::vector<Child<Statement>> > () = std::move(yystack_[1].value.as < std::vector<Child<Statement>> > ());
        yylhs.value.as < std::vector<Child<Statement>> > ().emplace_back(std::move(yystack_[0].value.as < Child<Statement> > ()));
        yylhs.location.begin = yystack_[1].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 846 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 17: // statement_list: %empty
#line 171 "meta/barser.y"
             {}
#line 852 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 18: // expression: expression "+" expression
#line 175 "meta/barser.y"
                                             {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Add, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 862 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 19: // expression: expression "*" expression
#line 180 "meta/barser.y"
                                             {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Multiply, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 872 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 20: // expression: expression "-" expression
#line 185 "meta/barser.y"
                                             {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Subtract, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 882 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 21: // expression: expression "/" expression
#line 190 "meta/barser.y"
                                             {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Divide, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 892 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 22: // expression: expression "==" expression
#line 195 "meta/barser.y"
                                              {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Equals, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 902 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 23: // expression: expression "<" expression
#line 200 "meta/barser.y"
                                             {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::LittleThan, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 912 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 24: // expression: expression ">" expression
#line 205 "meta/barser.y"
                                             {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::GreaterThan, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 922 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 25: // expression: expression "<=" expression
#line 210 "meta/barser.y"
                                              {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::LittleEquals, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 932 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 26: // expression: expression ">=" expression
#line 215 "meta/barser.y"
                                              {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::GreaterEquals, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 942 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 27: // expression: expression "!=" expression
#line 220 "meta/barser.y"
                                              {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::NotEquals, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 952 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 28: // expression: expression "and" expression
#line 225 "meta/barser.y"
                                               {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::And, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 962 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 29: // expression: expression "or" expression
#line 230 "meta/barser.y"
                                              {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Or, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 972 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 30: // expression: expression "&" expression
#line 235 "meta/barser.y"
                                             {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Band, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 982 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 31: // expression: expression "|" expression
#line 240 "meta/barser.y"
                                             {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Bor, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 992 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 32: // expression: expression "xor" expression
#line 245 "meta/barser.y"
                                               {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Xor, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1002 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 33: // expression: "-" expression
#line 250 "meta/barser.y"
                                       {
        yylhs.value.as < Child<Expression> > () = make<Unary>(Unary::Operator::Negate, std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[1].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1012 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 34: // expression: "not" expression
#line 255 "meta/barser.y"
                                         {
        yylhs.value.as < Child<Expression> > () = make<Unary>(Unary::Operator::Not, std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[1].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1022 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 35: // expression: "~" expression
#line 260 "meta/barser.y"
                                       {
        yylhs.value.as < Child<Expression> > () = make<Unary>(Unary::Operator::Bnot, std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[1].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1032 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 36: // expression: type expression
#line 265 "meta/barser.y"
                                          {
        yylhs.value.as < Child<Expression> > () = make<Cast>(std::move(yystack_[1].value.as < Child<Type> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[1].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1042 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 37: // expression: "identifier"
#line 270 "meta/barser.y"
              {
        yylhs.value.as < Child<Expression> > () = make<Identifier>(yystack_[0].value.as < std::string > ());
        yylhs.location = yystack_[0].location;
    }
#line 1051 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 38: // expression: "constant identifier"
#line 274 "meta/barser.y"
                    {
        yylhs.value.as < Child<Expression> > () = make<Identifier>(yystack_[0].value.as < std::string > ());
        yylhs.location = yystack_[0].location;
    }
#line 1060 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 39: // expression: "(" expression ")"
#line 278 "meta/barser.y"
                               {
        yylhs.value.as < Child<Expression> > () = std::move(yystack_[1].value.as < Child<Expression> > ());
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1070 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 40: // expression: "{" statement_list "}"
#line 283 "meta/barser.y"
                                         {
        yylhs.value.as < Child<Expression> > () = make<Block>(std::move(yystack_[1].value.as < std::vector<Child<Statement>> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1080 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;


#line 1084 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      yy_lac_discard_ ("error recovery");
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "identifier",
  "type identifier", "constant identifier", "*", "+", "-", "/", "==", "<",
  ">", "<=", ">=", "!=", "not", "and", "or", "&", "|", "xor", "~", "=",
  "(", ")", "[", "]", "{", "}", "let", "var", "const", ",", ";", "CAST",
  "UNARY", "$accept", "program", "pattern_list", "pattern",
  "general_pattern", "type", "statement", "statement_list", "expression", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

#if YYDEBUG
    // Execute LAC once. We don't care if it is successful, we
    // only do it for the sake of debugging output.
    if (!yyparser_.yy_lac_established_)
      yyparser_.yy_lac_check_ (yyla_.kind ());
#endif

    for (int yyx = 0; yyx < YYNTOKENS; ++yyx)
      {
        symbol_kind_type yysym = YY_CAST (symbol_kind_type, yyx);
        if (yysym != symbol_kind::S_YYerror
            && yysym != symbol_kind::S_YYUNDEF
            && yyparser_.yy_lac_check_ (yysym))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
      }
    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }




  bool
  parser::yy_lac_check_ (symbol_kind_type yytoken) const
  {
    // Logically, the yylac_stack's lifetime is confined to this function.
    // Clear it, to get rid of potential left-overs from previous call.
    yylac_stack_.clear ();
    // Reduce until we encounter a shift and thereby accept the token.
#if YYDEBUG
    YYCDEBUG << "LAC: checking lookahead " << symbol_name (yytoken) << ':';
#endif
    std::ptrdiff_t lac_top = 0;
    while (true)
      {
        state_type top_state = (yylac_stack_.empty ()
                                ? yystack_[lac_top].state
                                : yylac_stack_.back ());
        int yyrule = yypact_[+top_state];
        if (yy_pact_value_is_default_ (yyrule)
            || (yyrule += yytoken) < 0 || yylast_ < yyrule
            || yycheck_[yyrule] != yytoken)
          {
            // Use the default action.
            yyrule = yydefact_[+top_state];
            if (yyrule == 0)
              {
                YYCDEBUG << " Err\n";
                return false;
              }
          }
        else
          {
            // Use the action from yytable.
            yyrule = yytable_[yyrule];
            if (yy_table_value_is_error_ (yyrule))
              {
                YYCDEBUG << " Err\n";
                return false;
              }
            if (0 < yyrule)
              {
                YYCDEBUG << " S" << yyrule << '\n';
                return true;
              }
            yyrule = -yyrule;
          }
        // By now we know we have to simulate a reduce.
        YYCDEBUG << " R" << yyrule - 1;
        // Pop the corresponding number of values from the stack.
        {
          std::ptrdiff_t yylen = yyr2_[yyrule];
          // First pop from the LAC stack as many tokens as possible.
          std::ptrdiff_t lac_size = std::ptrdiff_t (yylac_stack_.size ());
          if (yylen < lac_size)
            {
              yylac_stack_.resize (std::size_t (lac_size - yylen));
              yylen = 0;
            }
          else if (lac_size)
            {
              yylac_stack_.clear ();
              yylen -= lac_size;
            }
          // Only afterwards look at the main stack.
          // We simulate popping elements by incrementing lac_top.
          lac_top += yylen;
        }
        // Keep top_state in sync with the updated stack.
        top_state = (yylac_stack_.empty ()
                     ? yystack_[lac_top].state
                     : yylac_stack_.back ());
        // Push the resulting state of the reduction.
        state_type state = yy_lr_goto_state_ (top_state, yyr1_[yyrule]);
        YYCDEBUG << " G" << int (state);
        yylac_stack_.push_back (state);
      }
  }

  // Establish the initial context if no initial context currently exists.
  bool
  parser::yy_lac_establish_ (symbol_kind_type yytoken)
  {
    /* Establish the initial context for the current lookahead if no initial
       context is currently established.

       We define a context as a snapshot of the parser stacks.  We define
       the initial context for a lookahead as the context in which the
       parser initially examines that lookahead in order to select a
       syntactic action.  Thus, if the lookahead eventually proves
       syntactically unacceptable (possibly in a later context reached via a
       series of reductions), the initial context can be used to determine
       the exact set of tokens that would be syntactically acceptable in the
       lookahead's place.  Moreover, it is the context after which any
       further semantic actions would be erroneous because they would be
       determined by a syntactically unacceptable token.

       yy_lac_establish_ should be invoked when a reduction is about to be
       performed in an inconsistent state (which, for the purposes of LAC,
       includes consistent states that don't know they're consistent because
       their default reductions have been disabled).

       For parse.lac=full, the implementation of yy_lac_establish_ is as
       follows.  If no initial context is currently established for the
       current lookahead, then check if that lookahead can eventually be
       shifted if syntactic actions continue from the current context.  */
    if (yy_lac_established_)
      return true;
    else
      {
#if YYDEBUG
        YYCDEBUG << "LAC: initial context established for "
                 << symbol_name (yytoken) << '\n';
#endif
        yy_lac_established_ = true;
        return yy_lac_check_ (yytoken);
      }
  }

  // Discard any previous initial lookahead context.
  void
  parser::yy_lac_discard_ (const char* event)
  {
   /* Discard any previous initial lookahead context because of Event,
      which may be a lookahead change or an invalidation of the currently
      established initial context for the current lookahead.

      The most common example of a lookahead change is a shift.  An example
      of both cases is syntax error recovery.  That is, a syntax error
      occurs when the lookahead is syntactically erroneous for the
      currently established initial context, so error recovery manipulates
      the parser stacks to try to find a new initial context in which the
      current lookahead is syntactically acceptable.  If it fails to find
      such a context, it discards the lookahead.  */
    if (yy_lac_established_)
      {
        YYCDEBUG << "LAC: initial context discarded due to "
                 << event << '\n';
        yy_lac_established_ = false;
      }
  }


  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
         In the first two cases, it might appear that the current syntax
         error should have been detected in the previous state when
         yy_lac_check was invoked.  However, at that time, there might
         have been a different syntax error that discarded a different
         initial context during error recovery, leaving behind the
         current lookahead.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -36;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     -36,     6,   125,   -36,   -36,   -36,   -36,   135,   135,   135,
     135,   -36,    15,    15,   135,   -36,    41,   -36,   -36,   -36,
     158,    96,   -36,   -36,    12,   -12,    -9,   178,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   -36,   -36,   -36,   -36,    16,   -36,    12,
     -21,   -36,   135,   135,   -11,   214,   214,   -11,   194,   194,
     194,   194,   194,   194,   198,   198,   -36,   -36,   -36,   -36,
     -20,   -36,    12,    59,    77,   -36,   -36,   -36,   -36
  };

  const signed char
  parser::yydefact_[] =
  {
      17,     0,     2,     1,    37,    12,    38,     0,     0,     0,
       0,    17,     0,     0,     0,    16,     0,    33,    34,    35,
       0,     0,     9,    10,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    39,    40,     5,     0,     6,     0,
       0,     4,     0,     0,    19,    18,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,     7,
       0,    11,     0,     0,     0,     8,     3,    14,    15
  };

  const signed char
  parser::yypgoto_[] =
  {
     -36,   -36,    -8,   -35,    25,   -36,   -36,    29,    -7
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     1,    50,    51,    25,    14,    15,     2,    16
  };

  const signed char
  parser::yytable_[] =
  {
      17,    18,    19,    20,    71,    75,     3,    27,    40,    41,
      42,    52,    72,    72,    53,    46,    47,    48,    22,    69,
      23,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    49,    76,    26,    24,
      21,    70,     0,     0,     0,    73,    74,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,     0,    38,    39,
      40,    41,    42,     0,     0,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    43,    38,    39,    40,    41,
      42,     0,     0,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    77,    38,    39,    40,    41,    42,     4,
       5,     6,     0,     0,     7,     0,     0,     0,     0,     0,
       0,    78,     8,     0,     0,     0,     0,     0,     9,     0,
      10,     0,     0,     0,    11,    45,    12,    13,     4,     5,
       6,     0,     0,     7,     0,     0,     0,     0,     4,     5,
       6,     8,     0,     7,     0,     0,     0,     9,     0,    10,
       0,     8,     0,    11,     0,    12,    13,     9,     0,    10,
       0,     0,     0,    11,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,     0,    38,    39,    40,    41,    42,
       0,     0,     0,    44,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,     0,    38,    39,    40,    41,    42,
      28,    29,    30,    31,    28,    29,    30,    31,     0,     0,
       0,    38,    39,    40,    41,    42,     0,    40,    41,    42,
      28,     0,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    40,    41,    42
  };

  const signed char
  parser::yycheck_[] =
  {
       7,     8,     9,    10,    25,    25,     0,    14,    19,    20,
      21,    23,    33,    33,    23,     3,     4,     5,     3,     3,
       5,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    24,    72,    13,    24,
      11,    49,    -1,    -1,    -1,    52,    53,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      19,    20,    21,    -1,    -1,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    34,    17,    18,    19,    20,
      21,    -1,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    34,    17,    18,    19,    20,    21,     3,
       4,     5,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    16,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      24,    -1,    -1,    -1,    28,    29,    30,    31,     3,     4,
       5,    -1,    -1,     8,    -1,    -1,    -1,    -1,     3,     4,
       5,    16,    -1,     8,    -1,    -1,    -1,    22,    -1,    24,
      -1,    16,    -1,    28,    -1,    30,    31,    22,    -1,    24,
      -1,    -1,    -1,    28,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    25,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    18,    19,    20,    21,
       6,     7,     8,     9,     6,     7,     8,     9,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    -1,    19,    20,    21,
       6,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21
  };

  const signed char
  parser::yystos_[] =
  {
       0,    38,    44,     0,     3,     4,     5,     8,    16,    22,
      24,    28,    30,    31,    42,    43,    45,    45,    45,    45,
      45,    44,     3,     5,    24,    41,    41,    45,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    17,    18,
      19,    20,    21,    34,    25,    29,     3,     4,     5,    24,
      39,    40,    23,    23,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,     3,
      39,    25,    33,    45,    45,    25,    40,    34,    34
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    37,    38,    39,    39,    40,    40,    40,    40,    41,
      41,    41,    42,    43,    43,    43,    44,    44,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     3,     1,     1,     1,     2,     3,     1,
       1,     3,     1,     2,     5,     5,     2,     0,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     1,     1,     3,
       3
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    86,    86,    90,    96,   103,   107,   111,   116,   124,
     128,   132,   140,   147,   152,   157,   165,   171,   175,   180,
     185,   190,   195,   200,   205,   210,   215,   220,   225,   230,
     235,   240,   245,   250,   255,   260,   265,   270,   274,   278,
     283
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 8 "meta/barser.y"
} // pec
#line 1719 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"

#line 290 "meta/barser.y"
