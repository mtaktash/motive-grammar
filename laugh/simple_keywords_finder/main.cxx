#encoding "utf-8"    // сообщаем парсеру о том, в какой кодировке написана грамматика
#GRAMMAR_ROOT S      // указываем корневой нетерминал грамматики

LaughVerbs -> Verb<kwtype="глагол-смеха">;	
LaughNouns -> Noun<kwtype="существительное-смеха">;	


S -> Word* Comma* Word* LaughVerbs Word* Comma* Word*;
S -> Word* Comma* Word* LaughNouns Word* Comma* Word*;

