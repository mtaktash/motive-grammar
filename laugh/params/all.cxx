#encoding "utf-8"    // сообщаем парсеру о том, в какой кодировке написана грамматика
#GRAMMAR_ROOT S      // указываем корневой нетерминал грамматики

ProperName ->  Word<h-reg1>+;                  
Who -> ProperName | Noun; 	

LaughVerbs -> Verb<kwtype="глагол-смеха">;	
LaughNouns -> Noun<kwtype="существительное-смеха">;	

LaughWithVerb -> Adv* Word* LaughVerbs Word* Adv*;
LaughWithNoun -> Verb Adj* LaughNouns;

Laugh -> LaughWithVerb | LaughWithNoun;

S -> Word* Comma* Who Laugh Comma* Word*;








// // существительные
// S ->  Adj+ LaughNouns;  
// S ->  Verb LaughNouns;  
// S ->  Verb Adj+ LaughNouns;

// S ->  Person Verb LaughNouns;    
// S ->  Person Verb Adj+ LaughNouns;    


// // глаголы
// S ->  Person LaughVerbs;  
// S ->  Noun LaughVerbs;  
// // над чем
// S ->  Person LaughVerbs Prep Noun;  

// // как  
// S ->  Person Adv LaughVerbs;  
// S ->  Noun Adv LaughVerbs;   


