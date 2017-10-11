#encoding "utf-8"    // сообщаем парсеру о том, в какой кодировке написана грамматика
#GRAMMAR_ROOT S      // указываем корневой нетерминал грамматики

ProperName ->  Word<h-reg1>+;                  
Who -> ProperName | Noun; 	

LaughVerbs -> Verb<kwtype="глагол-смеха">;	
LaughNouns -> Noun<kwtype="существительное-смеха">;	

LaughWithVerb -> Adv* Word* LaughVerbs Word* Adv*;
LaughWithNoun -> Verb Adj* LaughNouns;
LaughAction -> LaughWithVerb | LaughWithNoun;
S -> Word* Comma* Who LaughAction Comma* Word*;
S -> Word* Comma* LaughAction Who Comma* Word*;

