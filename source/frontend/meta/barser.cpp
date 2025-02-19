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
      case symbol_kind::S_top_level_expression: // top_level_expression
      case symbol_kind::S_block_expression: // block_expression
        value.YY_MOVE_OR_COPY< Child<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
      case symbol_kind::S_top_level_pattern: // top_level_pattern
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
      case symbol_kind::S_top_level_expression: // top_level_expression
      case symbol_kind::S_block_expression: // block_expression
        value.move< Child<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
      case symbol_kind::S_top_level_pattern: // top_level_pattern
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
      case symbol_kind::S_top_level_expression: // top_level_expression
      case symbol_kind::S_block_expression: // block_expression
        value.copy< Child<Expression> > (that.value);
        break;

      case symbol_kind::S_pattern: // pattern
      case symbol_kind::S_top_level_pattern: // top_level_pattern
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
      case symbol_kind::S_top_level_expression: // top_level_expression
      case symbol_kind::S_block_expression: // block_expression
        value.move< Child<Expression> > (that.value);
        break;

      case symbol_kind::S_pattern: // pattern
      case symbol_kind::S_top_level_pattern: // top_level_pattern
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
      case symbol_kind::S_top_level_expression: // top_level_expression
      case symbol_kind::S_block_expression: // block_expression
        yylhs.value.emplace< Child<Expression> > ();
        break;

      case symbol_kind::S_pattern: // pattern
      case symbol_kind::S_top_level_pattern: // top_level_pattern
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
#line 95 "meta/barser.y"
                                 { ret = std::move(yystack_[0].value.as < std::vector<Child<Statement>> > ()); }
#line 720 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 3: // statement_list: statement_list statement
#line 99 "meta/barser.y"
                                           {
        yylhs.value.as < std::vector<Child<Statement>> > () = std::move(yystack_[1].value.as < std::vector<Child<Statement>> > ());
        yylhs.value.as < std::vector<Child<Statement>> > ().emplace_back(std::move(yystack_[0].value.as < Child<Statement> > ()));
        yylhs.location.begin = yystack_[1].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 731 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 4: // statement_list: %empty
#line 105 "meta/barser.y"
             {}
#line 737 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 5: // type: "type identifier"
#line 109 "meta/barser.y"
                 {
        yylhs.value.as < Child<Type> > () = make<Type>(std::move(yystack_[0].value.as < std::string > ()));
        yylhs.location = yystack_[0].location;
    }
#line 746 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 6: // statement: top_level_expression ";"
#line 116 "meta/barser.y"
                                     {
        yylhs.value.as < Child<Statement> > () = make<ExpressionStatement>(std::move(yystack_[1].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[1].location.begin;
        yylhs.location.end = yystack_[1].location.end;
    }
#line 756 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 7: // statement: "let" top_level_pattern "=" expression ";"
#line 121 "meta/barser.y"
                                                            {
        yylhs.value.as < Child<Statement> > () = make<VariableDefinition>(VariableDefinition::Mutability::Immutable, std::move(yystack_[3].value.as < Child<Pattern> > ()), std::move(yystack_[1].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[4].location.begin;
        yylhs.location.end = yystack_[1].location.end;
    }
#line 766 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 8: // statement: "var" top_level_pattern "=" expression ";"
#line 126 "meta/barser.y"
                                                            {
        yylhs.value.as < Child<Statement> > () = make<VariableDefinition>(VariableDefinition::Mutability::Mutable, std::move(yystack_[3].value.as < Child<Pattern> > ()), std::move(yystack_[1].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[4].location.begin;
        yylhs.location.end = yystack_[1].location.end;
    }
#line 776 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 9: // statement: block_expression
#line 131 "meta/barser.y"
                             {
        yylhs.value.as < Child<Statement> > () = make<ExpressionStatement>(std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location = yystack_[0].location;
    }
#line 785 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 10: // expression: expression "+" expression
#line 138 "meta/barser.y"
                                             {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Add, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 795 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 11: // expression: expression "*" expression
#line 143 "meta/barser.y"
                                             {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Multiply, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 805 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 12: // expression: expression "-" expression
#line 148 "meta/barser.y"
                                             {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Subtract, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 815 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 13: // expression: expression "/" expression
#line 153 "meta/barser.y"
                                             {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Divide, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 825 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 14: // expression: expression "==" expression
#line 158 "meta/barser.y"
                                              {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Equals, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 835 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 15: // expression: expression "<" expression
#line 163 "meta/barser.y"
                                             {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::LittleThan, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 845 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 16: // expression: expression ">" expression
#line 168 "meta/barser.y"
                                             {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::GreaterThan, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 855 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 17: // expression: expression "<=" expression
#line 173 "meta/barser.y"
                                              {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::LittleEquals, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 865 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 18: // expression: expression ">=" expression
#line 178 "meta/barser.y"
                                              {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::GreaterEquals, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 875 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 19: // expression: expression "!=" expression
#line 183 "meta/barser.y"
                                              {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::NotEquals, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 885 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 20: // expression: expression "and" expression
#line 188 "meta/barser.y"
                                               {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::And, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 895 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 21: // expression: expression "or" expression
#line 193 "meta/barser.y"
                                              {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Or, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 905 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 22: // expression: expression "&" expression
#line 198 "meta/barser.y"
                                             {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Band, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 915 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 23: // expression: expression "|" expression
#line 203 "meta/barser.y"
                                             {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Bor, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 925 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 24: // expression: expression "xor" expression
#line 208 "meta/barser.y"
                                               {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Xor, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 935 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 25: // expression: "-" expression
#line 213 "meta/barser.y"
                                       {
        yylhs.value.as < Child<Expression> > () = make<Unary>(Unary::Operator::Negate, std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[1].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 945 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 26: // expression: "not" expression
#line 218 "meta/barser.y"
                                         {
        yylhs.value.as < Child<Expression> > () = make<Unary>(Unary::Operator::Not, std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[1].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 955 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 27: // expression: "~" expression
#line 223 "meta/barser.y"
                                       {
        yylhs.value.as < Child<Expression> > () = make<Unary>(Unary::Operator::Bnot, std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[1].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 965 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 28: // expression: type expression
#line 228 "meta/barser.y"
                                          {
        yylhs.value.as < Child<Expression> > () = make<Cast>(std::move(yystack_[1].value.as < Child<Type> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[1].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 975 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 29: // expression: "identifier"
#line 233 "meta/barser.y"
              {
        yylhs.value.as < Child<Expression> > () = make<Identifier>(yystack_[0].value.as < std::string > ());
        yylhs.location = yystack_[0].location;
    }
#line 984 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 30: // expression: "constant identifier"
#line 237 "meta/barser.y"
                    {
        yylhs.value.as < Child<Expression> > () = make<Identifier>(yystack_[0].value.as < std::string > ());
        yylhs.location = yystack_[0].location;
    }
#line 993 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 31: // expression: "(" expression ")"
#line 241 "meta/barser.y"
                               {
        yylhs.value.as < Child<Expression> > () = std::move(yystack_[1].value.as < Child<Expression> > ());
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1003 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 32: // expression: block_expression
#line 246 "meta/barser.y"
                             {
        yylhs.value.as < Child<Expression> > () = std::move(yystack_[0].value.as < Child<Expression> > ());
        yylhs.location = yystack_[0].location;
    }
#line 1012 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 33: // top_level_expression: top_level_expression "+" top_level_expression
#line 253 "meta/barser.y"
                                                                 {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Add, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1022 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 34: // top_level_expression: top_level_expression "*" top_level_expression
#line 258 "meta/barser.y"
                                                                 {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Multiply, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1032 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 35: // top_level_expression: top_level_expression "-" top_level_expression
#line 263 "meta/barser.y"
                                                                 {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Subtract, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1042 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 36: // top_level_expression: top_level_expression "/" top_level_expression
#line 268 "meta/barser.y"
                                                                 {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Divide, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1052 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 37: // top_level_expression: top_level_expression "==" top_level_expression
#line 273 "meta/barser.y"
                                                                  {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Equals, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1062 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 38: // top_level_expression: top_level_expression "<" top_level_expression
#line 278 "meta/barser.y"
                                                                 {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::LittleThan, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1072 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 39: // top_level_expression: top_level_expression ">" top_level_expression
#line 283 "meta/barser.y"
                                                                 {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::GreaterThan, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1082 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 40: // top_level_expression: top_level_expression "<=" top_level_expression
#line 288 "meta/barser.y"
                                                                  {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::LittleEquals, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1092 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 41: // top_level_expression: top_level_expression ">=" top_level_expression
#line 293 "meta/barser.y"
                                                                  {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::GreaterEquals, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1102 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 42: // top_level_expression: top_level_expression "!=" top_level_expression
#line 298 "meta/barser.y"
                                                                  {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::NotEquals, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1112 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 43: // top_level_expression: top_level_expression "and" top_level_expression
#line 303 "meta/barser.y"
                                                                   {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::And, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1122 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 44: // top_level_expression: top_level_expression "or" top_level_expression
#line 308 "meta/barser.y"
                                                                  {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Or, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1132 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 45: // top_level_expression: top_level_expression "&" top_level_expression
#line 313 "meta/barser.y"
                                                                 {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Band, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1142 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 46: // top_level_expression: top_level_expression "|" top_level_expression
#line 318 "meta/barser.y"
                                                                 {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Bor, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1152 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 47: // top_level_expression: top_level_expression "xor" top_level_expression
#line 323 "meta/barser.y"
                                                                   {
        yylhs.value.as < Child<Expression> > () = make<Binary>(Binary::Operator::Xor, std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1162 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 48: // top_level_expression: "-" top_level_expression
#line 328 "meta/barser.y"
                                                 {
        yylhs.value.as < Child<Expression> > () = make<Unary>(Unary::Operator::Negate, std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[1].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1172 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 49: // top_level_expression: "not" top_level_expression
#line 333 "meta/barser.y"
                                                   {
        yylhs.value.as < Child<Expression> > () = make<Unary>(Unary::Operator::Not, std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[1].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1182 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 50: // top_level_expression: "~" top_level_expression
#line 338 "meta/barser.y"
                                                 {
        yylhs.value.as < Child<Expression> > () = make<Unary>(Unary::Operator::Bnot, std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[1].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1192 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 51: // top_level_expression: type top_level_expression
#line 343 "meta/barser.y"
                                                    {
        yylhs.value.as < Child<Expression> > () = make<Cast>(std::move(yystack_[1].value.as < Child<Type> > ()), std::move(yystack_[0].value.as < Child<Expression> > ()));
        yylhs.location.begin = yystack_[1].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1202 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 52: // top_level_expression: "identifier"
#line 348 "meta/barser.y"
              {
        yylhs.value.as < Child<Expression> > () = make<Identifier>(yystack_[0].value.as < std::string > ());
        yylhs.location = yystack_[0].location;
    }
#line 1211 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 53: // top_level_expression: "constant identifier"
#line 352 "meta/barser.y"
                    {
        yylhs.value.as < Child<Expression> > () = make<Identifier>(yystack_[0].value.as < std::string > ());
        yylhs.location = yystack_[0].location;
    }
#line 1220 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 54: // top_level_expression: "(" expression ")"
#line 356 "meta/barser.y"
                               {
        yylhs.value.as < Child<Expression> > () = std::move(yystack_[1].value.as < Child<Expression> > ());
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1230 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 55: // block_expression: "{" statement_list "}"
#line 364 "meta/barser.y"
                                         {
        yylhs.value.as < Child<Expression> > () = make<Block>(std::move(yystack_[1].value.as < std::vector<Child<Statement>> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1240 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 56: // block_expression: "if" "(" expression ")" statement
#line 369 "meta/barser.y"
                                                         {
        yylhs.value.as < Child<Expression> > () = make<Conditional>(std::move(yystack_[2].value.as < Child<Expression> > ()), std::move(yystack_[0].value.as < Child<Statement> > ()), nullptr);
        yylhs.location.begin = yystack_[4].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1250 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 57: // block_expression: "if" "(" expression ")" statement "else" statement
#line 374 "meta/barser.y"
                                                                                     {
        yylhs.value.as < Child<Expression> > () = make<Conditional>(std::move(yystack_[4].value.as < Child<Expression> > ()), std::move(yystack_[2].value.as < Child<Statement> > ()), std::move(yystack_[0].value.as < Child<Statement> > ()));
        yylhs.location.begin = yystack_[6].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1260 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 58: // pattern_list: pattern_list "," pattern
#line 382 "meta/barser.y"
                                          {
        yylhs.value.as < TuplePattern > () = std::move(yystack_[2].value.as < TuplePattern > ());
        yylhs.value.as < TuplePattern > ().elements.emplace_back(std::move(yystack_[0].value.as < Child<Pattern> > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1271 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 59: // pattern_list: pattern
#line 388 "meta/barser.y"
                   {
        yylhs.value.as < TuplePattern > ().elements.emplace_back(std::move(yystack_[0].value.as < Child<Pattern> > ()));
        yylhs.location = yystack_[0].location;
    }
#line 1280 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 60: // pattern: "identifier"
#line 395 "meta/barser.y"
             {
        yylhs.value.as < Child<Pattern> > () = make<IdentifierPattern>(nullptr, std::move(yystack_[0].value.as < std::string > ()));
        yylhs.location = yystack_[0].location;
    }
#line 1289 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 61: // pattern: "constant identifier"
#line 399 "meta/barser.y"
                   {
        yylhs.value.as < Child<Pattern> > () = make<IdentifierPattern>(nullptr, std::move(yystack_[0].value.as < std::string > ()));
        yylhs.location = yystack_[0].location;
    }
#line 1298 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 62: // pattern: "type identifier" "identifier"
#line 403 "meta/barser.y"
                                   {
        yylhs.value.as < Child<Pattern> > () = make<IdentifierPattern>(make<Type>(std::move(yystack_[1].value.as < std::string > ())), std::move(yystack_[0].value.as < std::string > ()));
        yylhs.location.begin = yystack_[1].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1308 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 63: // pattern: "(" pattern_list ")"
#line 408 "meta/barser.y"
                                 {
        yylhs.value.as < Child<Pattern> > () = make<TuplePattern>(std::move(yystack_[1].value.as < TuplePattern > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1318 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 64: // top_level_pattern: "identifier"
#line 416 "meta/barser.y"
             {
        yylhs.value.as < Child<Pattern> > () = make<IdentifierPattern>(nullptr, std::move(yystack_[0].value.as < std::string > ()));
        yylhs.location = yystack_[0].location;
    }
#line 1327 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 65: // top_level_pattern: "constant identifier"
#line 420 "meta/barser.y"
                   {
        yylhs.value.as < Child<Pattern> > () = make<IdentifierPattern>(nullptr, std::move(yystack_[0].value.as < std::string > ()));
        yylhs.location = yystack_[0].location;
    }
#line 1336 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;

  case 66: // top_level_pattern: "(" pattern_list ")"
#line 424 "meta/barser.y"
                                 {
        yylhs.value.as < Child<Pattern> > () = make<TuplePattern>(std::move(yystack_[1].value.as < TuplePattern > ()));
        yylhs.location.begin = yystack_[2].location.begin;
        yylhs.location.end = yystack_[0].location.end;
    }
#line 1346 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"
    break;


#line 1350 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"

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
  "(", ")", "[", "]", "{", "}", "if", "else", "let", "var", "const", ",",
  ";", "CAST", "UNARY", "$accept", "program", "statement_list", "type",
  "statement", "expression", "top_level_expression", "block_expression",
  "pattern_list", "pattern", "top_level_pattern", YY_NULLPTR
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


  const signed char parser::yypact_ninf_ = -116;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
    -116,     3,   197,  -116,  -116,  -116,  -116,   235,   235,   235,
     228,  -116,   -20,    67,    67,   235,  -116,   123,  -116,  -116,
    -116,  -116,  -116,  -116,   228,   228,   228,   228,   228,   254,
    -116,   182,   228,  -116,  -116,     7,   -15,   -14,    75,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,  -116,  -116,  -116,  -116,   274,   314,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,  -116,  -116,   294,  -116,    18,
    -116,     7,   -10,  -116,   228,   228,    14,   355,   355,    14,
     330,   330,   330,   330,   330,   330,   188,   188,  -116,  -116,
    -116,  -116,    59,   359,   359,    59,   335,   335,   335,   335,
     335,   335,   351,   351,  -116,  -116,  -116,   197,  -116,    -3,
    -116,     7,   143,   163,    -5,  -116,  -116,  -116,  -116,   197,
    -116
  };

  const signed char
  parser::yydefact_[] =
  {
       4,     0,     2,     1,    52,     5,    53,     0,     0,     0,
       0,     4,     0,     0,     0,     0,     3,     0,     9,    48,
      49,    50,    29,    30,     0,     0,     0,     0,     0,     0,
      32,     0,     0,    64,    65,     0,     0,     0,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,    25,    26,    27,     0,    28,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,    55,     0,    60,     0,
      61,     0,     0,    59,     0,     0,    34,    33,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    31,    11,    10,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     0,    62,     0,
      66,     0,     0,     0,    56,    63,    58,     7,     8,     0,
      57
  };

  const signed char
  parser::yypgoto_[] =
  {
    -116,  -116,    12,    -2,  -115,    -8,    60,    -1,   -54,   -93,
      22
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     1,     2,    28,    16,    29,    17,    30,    82,    83,
      36
  };

  const unsigned char
  parser::yytable_[] =
  {
      15,    18,   124,     3,    32,    15,    15,    15,    84,    85,
      78,    79,    80,    15,   130,   120,    55,    56,    57,    58,
      59,   118,   125,    31,    77,   121,   129,   119,   126,    15,
      18,    81,   121,    51,    52,    53,    37,    15,    15,    15,
      15,    15,    15,    15,    15,    15,    15,    15,    15,    15,
      15,    15,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,    19,    20,    21,
      33,     0,    34,     0,     0,    38,   122,   123,    72,    73,
      74,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    35,    49,    50,    51,    52,    53,     0,     0,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,     0,    15,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,    18,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
      49,    50,    51,    52,    53,     0,     0,     0,     0,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    54,
      70,    71,    72,    73,    74,     0,     0,     0,     0,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,   127,
      70,    71,    72,    73,    74,     4,     5,     6,     0,     0,
       7,     0,     0,     0,    39,    40,    41,    42,     8,   128,
       4,     5,     6,     0,     9,     7,    10,    51,    52,    53,
      11,    76,    12,     8,    13,    14,     0,     0,     0,     9,
       0,    10,     0,     0,     0,    11,     0,    12,     0,    13,
      14,    22,     5,    23,     0,     0,    24,     0,     4,     5,
       6,     0,     0,     7,    25,     0,     0,     0,     0,     0,
      26,     8,    27,     0,     0,     0,    11,     9,    12,    10,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,    70,    71,    72,    73,    74,     0,     0,     0,    75,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,    70,    71,    72,    73,    74,     0,     0,     0,   101,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,    70,    71,    72,    73,    74,     0,     0,     0,   117,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,    70,    71,    72,    73,    74,    39,    40,    41,    42,
       0,    60,    61,    62,    63,     0,     0,    49,    50,    51,
      52,    53,    70,    71,    72,    73,    74,    60,    61,    62,
      63,    39,     0,     0,    42,    60,     0,     0,    63,     0,
      72,    73,    74,     0,    51,    52,    53,     0,    72,    73,
      74
  };

  const short
  parser::yycheck_[] =
  {
       2,     2,   117,     0,    24,     7,     8,     9,    23,    23,
       3,     4,     5,    15,   129,    25,    24,    25,    26,    27,
      28,     3,    25,    11,    32,    35,    31,    81,   121,    31,
      31,    24,    35,    19,    20,    21,    14,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,     7,     8,     9,
       3,    -1,     5,    -1,    -1,    15,    84,    85,    19,    20,
      21,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    24,    17,    18,    19,    20,    21,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,   117,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   129,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    36,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    36,
      17,    18,    19,    20,    21,     3,     4,     5,    -1,    -1,
       8,    -1,    -1,    -1,     6,     7,     8,     9,    16,    36,
       3,     4,     5,    -1,    22,     8,    24,    19,    20,    21,
      28,    29,    30,    16,    32,    33,    -1,    -1,    -1,    22,
      -1,    24,    -1,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,     3,     4,     5,    -1,    -1,     8,    -1,     3,     4,
       5,    -1,    -1,     8,    16,    -1,    -1,    -1,    -1,    -1,
      22,    16,    24,    -1,    -1,    -1,    28,    22,    30,    24,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,    18,    19,    20,    21,    -1,    -1,    -1,    25,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,    18,    19,    20,    21,    -1,    -1,    -1,    25,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,    18,    19,    20,    21,    -1,    -1,    -1,    25,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,    18,    19,    20,    21,     6,     7,     8,     9,
      -1,     6,     7,     8,     9,    -1,    -1,    17,    18,    19,
      20,    21,    17,    18,    19,    20,    21,     6,     7,     8,
       9,     6,    -1,    -1,     9,     6,    -1,    -1,     9,    -1,
      19,    20,    21,    -1,    19,    20,    21,    -1,    19,    20,
      21
  };

  const signed char
  parser::yystos_[] =
  {
       0,    40,    41,     0,     3,     4,     5,     8,    16,    22,
      24,    28,    30,    32,    33,    42,    43,    45,    46,    45,
      45,    45,     3,     5,     8,    16,    22,    24,    42,    44,
      46,    41,    24,     3,     5,    24,    49,    49,    45,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    17,
      18,    19,    20,    21,    36,    44,    44,    44,    44,    44,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      17,    18,    19,    20,    21,    25,    29,    44,     3,     4,
       5,    24,    47,    48,    23,    23,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    25,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    25,     3,    47,
      25,    35,    44,    44,    43,    25,    48,    36,    36,    31,
      43
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    39,    40,    41,    41,    42,    43,    43,    43,    43,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    46,    46,    46,    47,    47,
      48,    48,    48,    48,    49,    49,    49
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     1,     2,     5,     5,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     1,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     1,     1,     3,     3,     5,     7,     3,     1,
       1,     1,     2,     3,     1,     1,     3
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    95,    95,    99,   105,   109,   116,   121,   126,   131,
     138,   143,   148,   153,   158,   163,   168,   173,   178,   183,
     188,   193,   198,   203,   208,   213,   218,   223,   228,   233,
     237,   241,   246,   253,   258,   263,   268,   273,   278,   283,
     288,   293,   298,   303,   308,   313,   318,   323,   328,   333,
     338,   343,   348,   352,   356,   364,   369,   374,   382,   388,
     395,   399,   403,   408,   416,   420,   424
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
#line 2042 "D:/Desktop/Programlama/cpp/pec/source/frontend/meta/barser.cpp"

#line 431 "meta/barser.y"
