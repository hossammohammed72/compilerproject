<h1>compilerproject</h2>
<h2> language description</h2>
<h4>char</h4><span> = "a"|"b"|"c"|"d"|"e"|"f"|"g"|"h"|"i"|"j"|"k"|"l"|"m"|"n"|"o"|"p"|"q"|"r"|"s"|"t"|"u"|"v"|"w"|"x"|"y"|"z";</span>
<h4>num</h4><span>  = "0"|"1"|"2"|"3"|"4"|"5"|"6"|"7"|"8"|"9";</span>
<h4>operator<h4><span> = "+" | "_" | "/" | "*";</span>
<h4>loperator</h4><span>= ">" | "<" | "==" | "&" | "!";</span>
<h4>schar</h4><span> = "_" | "$";</span>
<h4>assign</h4><span> = "=" ;</span>
<h4>term</h4><span> = variable | num;</span>
<h4>variable </h4><span> = char,{char|num};</span>
<h4>exp</h4><span> = variable,assign,term,{oper,term},";";</span>
<h4>decl</h4><span> = "set",variable,"as","datatype",";";</span>
<h4>if-stat</h4><span> = "if","(",{booleanexp},")","{",{exp},"}";</span>
<h4>boolean-exp</h4><span> = (team|char),{lop,(term|char)};</span>
