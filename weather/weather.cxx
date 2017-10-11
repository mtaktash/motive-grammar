#encoding "utf-8"    // сообщаем парсеру о том, в какой кодировке написана грамматика
#GRAMMAR_ROOT S      // указываем корневой нетерминал грамматики

NounHotWeather -> Word<kwtype="погода_сущ">;  
AdjHotWeather -> Word<kwtype="погода_прил">;

S -> Word* Comma* Adj<gnc-agr[1]>+ NounHotWeather<gnc-agr[1]> Comma* Word*;
S -> Word* Comma* AdjHotWeather<gnc-agr[1]>+ Noun<gnc-agr[1]> Comma* Word*;