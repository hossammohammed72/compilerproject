<h1>compilerproject</h2> 
<br><h4>char</h4> = "a"|"b"|"c"|"d"|"e"|"f"|"g"|"h"|"i"|"j"|"k"|"l"|"m"|"n"|"o"|"p"|"q"|"r"|"s"|"t"|"u"|"v"|"w"|"x"|"y"|"z";
<br><h4>num</h4>  = "0"|"1"|"2"|"3"|"4"|"5"|"6"|"7"|"8"|"9";</br>
<br><h4>operator<h4> = "+" | "_" | "/" | "*";</br>
<br>loperator</h4>= ">" | "<" | "==" | "&" | "!";</br>
<br><h4>schar</h4> = "_" | "$";</br>
<br><h4>assign</h4> = "=" ;</br>
<br><h4>term</h4> = variable | num;</br>
<br><h4>variable </h4> = char,{char|num};</br>
<br><h4>exp</h4> = variable,assign,term,{oper,term},";";</br>
<br><h4>decl</h4> = "set",variable,"as","datatype",";";</br>
<br><h4>if-stat</h4> = "if","(",{booleanexp},")","{",{exp},"}";</br>
<br><h4>boolean-exp</h4> = (team|char),{lop,(term|char)};</br>
